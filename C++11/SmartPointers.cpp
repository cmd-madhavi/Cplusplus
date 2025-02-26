#include <memory>

/*
While doing smart pointers implementation , make the reference count int* type since all 
shared pointers that are sharing the resource should point to same memory and increase/decrease the counter there
*/
class Person
{

};
int main()
{
    std::unique_ptr<int> ptrI(new int);
    *ptrI  = 8;
    std::unique_ptr<int[]> ptrIArr(new int(9));
//ERROR     std::unique_ptr<int> ptr = new int; //no suitable conversion constructor exists 

    std::unique_ptr<Person> personObj = std::make_unique<Person>();

    std::shared_ptr<Person> sharedPtr = std::make_shared<Person>();
}