#include <iostream>

//this = "Who called me?"
//
//*this = "The actual object that called me"
//
//return *this = "Return myself so you can call more methods on me"
//
//this->member = "My member, not someone else's"

class Calculator{
	int Value = 0;
	public:
	void add(int x){Value += x;}
	void substract(int x){Value -= x;}
	int getValue(){return Value;}
};

int main()
{
	Calculator calc;

	calc.add(5);
	calc.substract(5);
	calc.add(10);

std::cout <<  "Result: " << calc.getValue() << std::endl;
}

// b = a 
// b.opreator=(a)
//
//copy constuctor cerating a new object
//copy assinment replacing an existing object
// A b = a;
// b = a
// bexaus it allowd chaining 
//
