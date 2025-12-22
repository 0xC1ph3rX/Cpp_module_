# The Ultimate Guide to Fixed-Point Numbers & C++ Module 02

This guide is for developers who want to understand exactly what happens at the hardware level, every bit, every shift, and every mathematical proof behind the `Fixed` class.

---

## 1. The Raw Reality: Pure Bit Representation

In a computer, a 32-bit signed integer (`int`) is stored using **Two's Complement**.
- **Bit 31 (MSB)**: Sign bit (0 for positive, 1 for negative).
- **Bits 0-30**: Magnitude (with encoding for negative).

### The "Imaginary" Binary Point
Usually, for an `int`, we imagine the decimal point is at the very end: `XXXXXXXX.` (Position 0).
In our `Fixed` class, we move that imaginary point **8 bits to the left**: `XXXXXX.XXXXXXX` (Position 8).

---

## 2. Mathematical Proof of Shifting

### Base-X Shifting Rule
In Decimal (Base-10):
- `123 * 10^2` is `12300` (Shift left 2 spots).
- `123 / 10^2` is `1.23` (Shift right 2 spots).

In Binary (Base-2):
- `X * 2^n` is `X << n` (Shift left `n` bits).
- `X / 2^n` is `X >> n` (Shift right `n` bits).

### Our Scaling Factor
We want 8 bits for fractions. So we multiply everything by $2^8 = 256$.
This moves our decimal values into the integer range so the CPU can calculate them instantly.

---

## 3. Deep Dive: Floating-Point to Fixed-Point

### Why `roundf`?
Floating-point numbers (`0.1`, `0.2`) often have infinite binary representations (like $1/3 = 0.333...$ in decimal).
When we multiply `0.1 * 256`, we get `25.6`.
- Without rounding: `(int)25.6 = 25`. (Error: **0.6**)
- With rounding: `roundf(25.6) = 26`. (Error: **0.4**)
**Expert Rule**: Always round to the nearest representable integer to minimize the "Quantization Error".

### Binary Walkthrough: 42.42
1. **Integer Part**: `42` -> `00101010`
2. **Fractional Part**: `0.42`
   - $0.42 * 2 = 0.84$ -> **0**
   - $0.84 * 2 = 1.68$ -> **1**
   - $0.68 * 2 = 1.36$ -> **1**
   - $0.36 * 2 = 0.72$ -> **0**
   - $0.72 * 2 = 1.44$ -> **1**
   - $1.44 * 2 = 0.88$ -> **0**
   - $0.88 * 2 = 1.76$ -> **1**
   - $0.76 * 2 = 1.52$ -> **1**
   Result: `.01101011`

Combined 32-bit representation:
`00000000 00000000 00101010 10101011` (Raw value: **10860**)
Calculated back: $10860 / 256 = 42.421875$.

---

## 4. The Arithmetic Bit-Correction

### Multiplication: $(A \times B) \gg 8$
Why?
Let $A_{fix} = A \times 2^8$ and $B_{fix} = B \times 2^8$.
$A_{fix} \times B_{fix} = (A \times B) \times 2^{16}$
Our format requires $2^8$. So we must divide by $2^8$ once:
$\frac{(A \times B) \times 2^{16}}{2^8} = (A \times B) \times 2^8$ (**Back to correct format**).

### Division: $(A \ll 8) / B$
Why?
$\frac{A_{fix}}{B_{fix}} = \frac{A \times 2^8}{B \times 2^8} = \frac{A}{B}$ (Standard integer, scaling lost!)
To keep scaling, we multiply the numerator by $2^8$ first:
$\frac{(A \times 2^8) \times 2^8}{B \times 2^8} = \frac{A}{B} \times 2^8$ (**Scaling preserved**).

---

## 5. Why the "8 bits" standard? (Trade-offs)

The "Precision vs. Range" trade-off is the most important decision in Fixed-Point design.

### Scenario A: 4 bits (Fast, low precision)
- Resolution: $1/16 = 0.0625$
- Max range: High

### Scenario B: 16 bits (High precision, low range)
- Resolution: $1/65536 = 0.000015$
- Max range: Max value is $2^{31} / 2^{16} = 32767$. You can't even store the number 40,000!

### Scenario C: 8 bits (The "Sweet Spot")
- Resolution: **0.0039**
- Max range: ~**8.3 Million**.
This fits most common graphics and physics calculations.

---

## 6. C++ Expert Corner: OCF & Ad-hoc Polymorphism

### Ad-hoc Polymorphism (Overloading)
This is "Ad-hoc" because it doesn't use a common interface (inheritance).
- `Fixed a;` -> Calls Default Constructor.
- `Fixed b(10);` -> Calls Int Constructor.
- `Fixed c(10.5f);` -> Calls Float Constructor.
The compiler chooses the correct code path at **compile time** based on the signature.

### Orthodox Canonical Form (OCF)
Since our `Fixed` class doesn't use `new`/`delete`, why OCF?
**Expert Answer**: Because a class should be **predictable**. If you forget the copy constructor, C++ provides a default one. While safe for primitive types, it's a "bad habit". By explicitly defining all four (Default, Copy, Assignment, Destructor), you guarantee exactly how the raw bits are handled during every lifecycle event.

---

## 7. The Smallest Representable Value ($\epsilon$)
In Exercise 02, incrementing by "the smallest representable $\epsilon$" simply means adding **1** to the raw `_fixedPointValue`.
- Raw `1` = $1 / 256 = 0.00390625$.
- This is the absolute smallest non-zero value we can hold.

---

## Summary for the Defense
If the evaluator asks you: **"Why did you multiply by 256?"**
You answer: *"Because 256 is $2^8$. Multiplying by a power of 2 allows us to use bitwise shifts, which are the fastest operations on a CPU, to represent decimal parts within a standard signed integer."*
