#include <iostream>


class Example {
	std::string _name;
	std::string _age;
	std::string _val1;
	public:
	std::string val1;

	Example();
	Example(const Example& ex);
	~Example();

	void set_Name(std::string name);
	std::string get_Name() const;
			
};

Example::Example():_name(""), _age(""),_val1(""),val1(""){
std::cout << "Defualt constructor called" << std::endl;
}

Example::Example(const Example& ex) :_name(ex._name), _age(ex._age),_val1(ex._val1),val1(ex.val1)
{
	
std::cout << "Copy  constructor called" << std::endl;
}
Example::~Example(){
	std::cout << "Destructor called for " << _name << std::endl;
}

void Example::set_Name(std::string name)
{
	this->_name = name;
}

std::string Example::get_Name() const{
	return(_name);
}

int main()
{
		std::cout << "=== Creating object a ===" << std::endl;
	Example a ;
	a.set_Name("Alice");
	a.val1 = "public value";

	std::cout << "\n== Creating object b as a copy of a == " << std::endl;
	Example b = a;

	std::cout << "\n== Modified b == " << std::endl;
	b.set_Name("Bob");
	b.val1 = "Modified public value";
	

	std::cout << "\n==Creating object c using copy== " << std::endl;
	Example c(a);
	

	std::cout << "\n== Values ==" << std::endl;
	std::cout << "a.name " << a.get_Name() << ", a.val1  " << a.val1 << std::endl;
	std::cout << "b.name " << b.get_Name() << ", b.val1  " << b.val1 << std::endl;
	std::cout << "c.name " << c.get_Name() << ", c.val1  " << c.val1 << std::endl;
}




























