#include <memory>
#include <iostream>
//write our own unique pointer

template <typename T>
class UniquePtr
{
    T* ptr{nullptr};
    public:
    explicit UniquePtr(T* obj):ptr(obj){}
    UniquePtr(UniquePtr& other) = delete;
    UniquePtr& operator=(const UniquePtr& other) = delete;

    UniquePtr(UniquePtr&& other):ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other)
    {
        if (this != &other)
        {
            delete ptr;
            this->ptr = other.ptr;
            other.ptr = nullptr;
        }

        return *this;
    }

    ~UniquePtr()
    {
        std::cout << " ptr deleted";
        delete ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    T& operator*()
    {
        return *ptr;
    }

    void Release()
    {
        if (ptr != nullptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }

};


template <typename T>
class UniquePtr<T[]>
{
    T* ptr{nullptr};
    public:
    UniquePtr(T* obj):ptr(obj){}
    UniquePtr(UniquePtr& other) = delete;
    UniquePtr& operator=(const UniquePtr& other) = delete;

    UniquePtr(UniquePtr&& other):ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other)
    {
        if (this != &other)
        {
            delete[] ptr;
            this->ptr = other.ptr;
            other.ptr = nullptr;
        }

        return *this;
    }

    ~UniquePtr()
    {
        std::cout << " ptr deleted";
        delete[] ptr;
    }

    T& operator[](int i)
    {
        return ptr[i];
    }
    T* operator->()
    {
        return ptr;
    }

    T& operator*()
    {
        return *ptr;
    }



};

template<typename T>
class SmartPtr
{

};
class Person{
    public:
    int n;
};
int main()
{
    UniquePtr<Person> p(new Person());
    p->n = 9;
    std::cout << " ptr n value " << p->n << std::endl;
    UniquePtr<int[]> arr(new int[5]);
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
}