#include <string>
#include <vector>
#include <iostream>
// class Person
// {
//     std::string* ptr;
//     public:
//     Person(const std::string str)
//     {
//         ptr = new std::string(str);
//     }
//     Person(Person& other)
//     {
//         ptr = new std::string(other.GetName());


//     }
//     ~Person()
//     {
//         delete ptr;
//     }

//     std::string GetName()
//     {
//         return *ptr;
//     }

//     operator std::string const ()
//     {
//         return *ptr;
//     }
// };
class Animal
{
    public:
    virtual void PublicFunc()
    {
        std::cout <<"public base\n";
    }
    protected:
    virtual void ProtFunc()
    {
        std::cout <<"base protected\n";
    }
};
class Dog : public Animal
{
    std::string& name;
    public:
    Dog(std::string& str):name(str)
    {

    }

    virtual void PublicFunc() override
    {
        std::cout <<"dericed pu";
    }
    virtual void ProtFunc() override
    {
        std::cout <<"protected become public\n";
    }

};

int main()
{

     std::string st = "utopia";
     Dog d1(st);
     Dog d2 = d1;
    d1.ProtFunc();
    // std::vector<Person*> vP;
    // vP.push_back(new Person("mad"));
    // vP[0]->GetName();
    // Person p2("kp");
    // std::string str = *vP[0];

}