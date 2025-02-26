//FROM C++20 onwards we have semaphore library, before we needed to use third party or POSIX or WINDOWS API
#include <semaphore>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>


std::counting_semaphore<3> sem(3);
std::binary_semaphore sem(1);

void task(int id)
{
    sem.acquire();
    std::cout << "Hello "<< id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    sem.release();
}
int main()
{
    std::vector<std::thread> t;

    for (int i = 0; i<8; i++)
    {
        //if we use push_back here then we need to move thread object, since thread objects are not copyable
        //we don't need to explicitly do std::move, it will be done by std::thread constructor
        t.emplace_back(std::thread(task, i));
    }

    for (auto &tObj : t)
    {
        tObj.join();
    }

}