#include <iostream>
#include <string>
#include <vector>

class Base{
public:
void Print()
{
    std::cout <<"print Base\n";
}
};

class Derived : public Base
{
public:
void Print()
{
    std::cout <<"pirnt dervied\n";
}
};

int main()
{
    Derived d;
    static_cast<Base>(d).Print();
    dynamic_cast<Base*>(&d)->Print();
}