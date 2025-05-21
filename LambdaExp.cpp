#include <iostream>

/*
LAMBDAS are treated by compilers as functors, the captures become the member variables and the funciton defintiion is defined
inside operator()
EVEN when we do [=], here all vars are captured by value, except this is captured by reference here too

LAMDA return type can be explicitily specified using funciton pointer or std::__HAVE_FUNCTION_MULTI_VERSIONING
std::function<int(int, int)> lambda = [](int a, int b){return a+b;}

function pointer
int(*lambda)(int, int) = [](int a, int b){return a + b;}, with captured variables using funciton pointers becomes complex
*/
class Person{
    int age;
    public:
    void SetAge(int ageVal)
    {
        //HERE this is captured by reference
        [=]()
        {
            age = ageVal + 10;
        }();
        std::cout << "age "<< age << std::endl;
    }

};
int main()
{
    Person p;
    p.SetAge(99);

    //SIMPLE LAMBDA
    [](){
        std::cout <<"Simple Lambda\n";
    }();

    int a = 9;
    int b = 9;
    auto sumOrMultiply = [&](int sumOrMultiply)
    {
        if (sumOrMultiply == 1)
        {
            return a * b;
        }
        else 
        {
            return a + b;
        }
    };

    std::cout << sumOrMultiply(1) << std::endl; //PRINTS 81
    //AFTER CHANGING VAR
    a = 0;
    std::cout << sumOrMultiply(1) << std::endl;//PRINTS 0

    auto sumOrMultiplyVal = [=](int sumOrMultiply)
    {
        if (sumOrMultiply == 1)
        {
            return a * b;
        }
        else 
        {
            return a + b;
        }
    };

    a = 9;
    std::cout << sumOrMultiplyVal(1) << std::endl; //PRINTS 0

}