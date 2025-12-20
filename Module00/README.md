# Module 00 – C++ basics

This README gives concise explanations and examples for the concepts covered in this module. The snippets assume modern C++ (C++11+) and default to portable, standard-library features.

## Introduction
C++ blends low-level control (memory/layout) with high-level abstractions (classes, templates). You pay only for what you use: abstractions compile down to efficient machine code when written idiomatically.

## Namespaces
Namespaces group related names and prevent collisions.
```cpp
namespace math { double add(double a, double b); }
int main() { return math::add(2, 3); }
```
Prefer explicit `namespace` blocks over `using namespace ...` in headers; in `.cpp` files a limited `using` for a specific symbol is fine.

## Stdio streams
C++ iostreams wrap standard I/O with type safety and formatting.
```cpp
#include <iostream>
std::cout << "Hello " << 42 << '\n';
int x; std::cin >> x;
```
`std::cerr` targets errors; `std::clog` for buffered logging. Flushing happens on `\n` when `std::ios::sync_with_stdio(false)` is default (usually true when mixing with C stdio).

## Class and instance
A `class` defines a user type; objects are instances with their own state.
```cpp
class Point { double x_, y_; }; // declaration
Point p; // instance with default-initialized members
```

## Member attributes and member functions
Members hold state; member functions operate on that state.
```cpp
class Counter {
  int value_;
public:
  void increment() { ++value_; }
  int value() const { return value_; }
};
```
Encapsulate data: keep members private and expose behavior via functions.

## This
Inside a non-static member function, `this` is a pointer to the current object. It disambiguates member names and enables chaining.
```cpp
class Widget {
  int id_{};
public:
  Widget& setId(int id) { this->id_ = id; return *this; }
};
```

## Initialization list
Constructor initializer lists set base classes and members before the body runs.
```cpp
class User {
  const int id_;
  std::string name_;
public:
  User(int id, std::string name) : id_(id), name_(std::move(name)) {}
};
```
Prefer initialization over assignment in the body; required for `const` members and references.

## Const
`const` enforces immutability at the interface level.
- Objects: `const int x = 3;`
- Pointers: `const int* p` (pointee const), `int* const p` (pointer const), `const int* const p` (both).
- Member functions: `int size() const;` promises not to modify observable state.
Use `mutable` sparingly for cached data modified inside `const` functions.

## Visibility
Access specifiers control visibility inside a class: `public`, `protected`, `private` (default for `class`). Favor minimal exposure; keep invariants enforceable.

## Class vs struct
`struct` defaults to public members; `class` defaults to private. Otherwise they are identical. Use `struct` for plain data aggregates or simple tags; use `class` when you want encapsulation by default.

## Accessors
Getter/setter pairs expose internal state; design them intentionally.
```cpp
class Person {
  std::string name_;
public:
  const std::string& name() const { return name_; }
  void setName(std::string v) { name_ = std::move(v); }
};
```
Prefer returning `const&` for heavy types; for scalars return by value. Avoid unnecessary setters—provide operations that maintain invariants instead.

## Comparisons
Implement comparison operators to define value semantics.
```cpp
#include <tuple>
bool operator==(const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
bool operator<(const Point& a, const Point& b) { return std::tie(a.x, a.y) < std::tie(b.x, b.y); }
```
C++20 offers `operator<=>` to auto-generate the rest. Keep comparisons consistent with hashing if objects are used in unordered containers.

## Non member attributes and non member functions
Members belong to a class; non-members live in a namespace and are not tied to any object layout.
```cpp
struct Box { double w, h; };
double area(const Box& b) { return b.w * b.h; } // non-member
```
Use non-member free functions when they conceptually operate on multiple types or preserve encapsulation (friend if access is required).

## Pointers to members
Pointers-to-members reference a field or method offset within a class and are used with an instance.
```cpp
struct Item { int id; void reset() { id = 0; } };
int Item::* idPtr = &Item::id;
void (Item::* resetPtr)() = &Item::reset;
Item it{42};
int value = it.*idPtr;      // 42
(it.*resetPtr)();            // calls reset on it
```
Useful for callbacks, reflection-like tables, or configurable access without exposing raw offsets.

## Conclusion
These fundamentals underpin idiomatic C++: encapsulate state, initialize early, use `const` pervasively, and prefer clear ownership and visibility boundaries. Build small, testable classes and favor free functions when they better express intent.
