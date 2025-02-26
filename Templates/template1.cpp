#include <iostream>
#include <string>
#include <vector>

template<typename T>
void Print(T val)
{
    std::cout << val << std::endl;
}

template<typename T, int n>
void PrintN(T val)
{
    for (int i=0; i<n; i++)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

template<typename T, int n>
class Array
{
    T arr[n];
    int idx;
    public:
    Array():idx(0){
        for (int i=0; i<n; i++)
        {
            arr[i] = 0;
        }
    }
    void AddVal(T val)
    {
        if (idx >= n)
        {
            std::cout << "out of Bounds\n";
        }
        arr[idx] = val;
        idx++;
    }
    void Print()
    {
        std::cout <<"Print array "<< std::endl;
        for (auto val : arr)
        {
            std::cout << val << std::endl;
        }
    }

};
int main()
{
Print("hello");
PrintN<int, 4>(6);

Array<int, 4> arr;
arr.AddVal(2);
arr.AddVal(6);
arr.AddVal(9);
arr.Print();
}