#include <iostream>
#include <string>
class Dog
{
    std::string name;
    int n;
    int *p;
    public:
    Dog()
    {
        name = "dog";
        n = 0;
        p = &n;
    }
    const std::string& GetName()
    {
        return name;
    }
    void SetPtr(int num) const{
        //p = &num; //error
        *p = 9;
    }
};

void PrintName(std::string& str)
{
    std::cout <<" non const "<< str<<std::endl;
}
void PrintName(const std::string& str)
{
    std::cout << "const "<< str << std::endl;
}
int main()
{
    std::string st = "New world";;
    PrintName(st);
    PrintName("Hello");
}