#include <thread>
#include <iostream>
#include <chrono>

void PrintFunc()
{
    std::cout << "Hi\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

void Sum(int n)
{
    int sumVal = 0;
    for (int i=0; i<n; i++)
    {
        if (i % 50 == 0)
        {
            std::cout << "sum "<< sumVal << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        sumVal+= i;
    }
}

class SumClass
{
    int n;
    public:
    SumClass() = default;
    SumClass(int n):n(n){}
    void PrintSum()
    {
        int sumVal = 0;
        for (int i=0; i<n; i++)
        {
            if (i % 50 == 0)
            {
                std::cout << "Class sum with no Arg "<< sumVal << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(3));
            }
            sumVal+= i;
        }
    }
    static void PrintSumWithArg(int val)
    {
        int sumVal = 0;
        for (int i=0; i<val; i++)
        {
            if (i % 50 == 0)
            {
                std::cout << "Class sum with Arg "<< sumVal << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(3));
            }
            sumVal+= i;
        }
    }    

};
int main()
{
    std::thread t1(PrintFunc);
    std::thread t2(Sum, 1000);
    SumClass sObj{1000};
    std::thread t4(&SumClass::PrintSum, &sObj);
    std::thread t5(&SumClass::PrintSumWithArg, 1000);
    //same sum as above but in lambda
    auto lambda = [](int n){
    int sumVal = 0;
    for (int i=0; i<n; i++)
    {
        if (i % 50 == 0)
        {
            std::cout << "Lambda sum "<< sumVal << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        sumVal+= i;
    }
    };

    std::thread t3(lambda, 1000);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}