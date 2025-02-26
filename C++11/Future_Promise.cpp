#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <string>


void Print(std::promise<std::string>&& printPromise)
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout <<"Print statement " <<std::endl;
    std::string msg = "Hello Promises and Future";
    printPromise.set_value(msg);
}
int main()
{ 
    std::promise<std::string> msgPromise;
    std::future<std::string> msgFuture = msgPromise.get_future();
    std::thread t1(Print, std::move(msgPromise));
  //  std::cout <<msgFuture.get() <<std::endl;
    std::cout <<"Completed\n";
    t1.join();
}