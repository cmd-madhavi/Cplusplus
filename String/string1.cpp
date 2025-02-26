#include <iostream>
#include <string>

using namespace std;
int main()
{
    //constructors

    string s1 = "Hello";
    string s2("Hello", 3);//Hel here 3 is size
    string s3(s1, 2); //llo here 2 is beginning
    string s4(s1,2,2); //ll beginning, size
    string s5(6, 'a'); //aaaaaa
    string s6({'a', 'b'}) ;//ab initialize list

    s1.size(); s1.length();
    s1.capacity(); //capacity >= size;
    s1.reserve(6);//if orgCapacity >= reserve nothing happens, else change capacity
    s1.resize(2); //He changes size
    s1.resize(9, '*');//the extra chars become * instead of null character


    s1[2];//l it return a reference to the character
    s1.at(2);//throw exception of out-of_range
    s1[4];//it doesn't throw out of range error, behavior it is undefined if out of range
    s1.front();
    s1.back();
    s1.push_back('f');
    s1.pop_back();
    s1.begin();

    string s7(s1.begin(), s1.end()+3);

    s1.assign("Wisdom");
    s2.assign("Wisdom", 2);//when first param is c_str then second param is size

    s2.append("def");
    s2.insert(2, "mountain"); //2 is the starting position where we want ot insert
    s1.replace(2, 5, s2, 0,2);//s1 starting from 2 with size 5 will be replace by s2 starting from 0 with size 2
    s1.erase(1,4);//position 1 to size 4

    s1 = "abc";
    s1.c_str();//abc\0
    s1.swap(s2);

} 