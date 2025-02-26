#include <iostream>

class String
{
        public:
    std::string m_name;


    String(){std::cout << "String Default constructor\n";}
    String(std::string name):m_name(name){
        std::cout << "String parameterised constructor \n";}
    String(const String& other){
        std::cout << "String copy constructor \n";
        if (this != &other)
        {
            this->m_name = other.m_name;
        }
    }
    String(String&& other)
    {
        std::cout <<"move constructor \n";
        if (this != &other)
        {
            this->m_name = other.m_name;
            other.m_name = "";
        }
    }

    String& operator=(const String& other)
    {
        std::cout <<"String = \n";
        if (this == &other)
        {
            return *this;
        }

        this->m_name = other.m_name;
        return *this;
    }

    String& operator=(String && other)
    {
        std::cout << "String move = \n";
        if (this == &other)
        {
            return *this;
        }

        this->m_name = other.m_name;
        other.m_name = "";
        return *this;
    }

};

class People
{
      public:
    String str;
  
    People(){
        std::cout <<"People default constructor \n";
    }
    People(String &str):str(std::move(str)){
        std::cout <<"People parameterised constructor\n";
    }
    People(String&& str):str(std::move(str)){
        std::cout <<"People parameterised move constructo \n";
    }
    People(const People& other)
    {
        std::cout <<"People copy constructo\n";
        if (this != &other)
        {
            this->str = other.str;
        }
    }
    People(People&& other)
    {
        std::cout <<"People move constructor \n";
        if (this != &other)
        {
            this->str = other.str;
          //  other.str = nullptr;
        }
    }
    People& operator=(const People& other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->str = other.str;
        return *this;
    }
    People& operator=(People&& other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->str = other.str;
       // other.str = nullptr;
        return *this;
    }
};

int main()
{
    String str("Madhavi");
    People p(str);
    std::cout << "People str "<< p.str.m_name << std::endl;
}