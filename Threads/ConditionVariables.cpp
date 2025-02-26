#include <condition_variable>
#include <thread>
#include <queue>
#include <iostream>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> dataQueue;
bool done = false;

void Producer()
{
    int i = 0;
    while(i < 100)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::lock_guard<std::mutex> lock(mtx);
        dataQueue.push(i);
        i++;
        cv.notify_one();
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();
}

void Consumer()
{
    while(1)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){return !dataQueue.empty() || done;});

        if (dataQueue.empty() && done)
        {
            break;
        }

        int item = dataQueue.front();
        dataQueue.pop();
        std::cout << "Conusmer " << item << std::endl;
    }
}

int main()
{
    std::thread t1(Producer);
    std::thread t2(Consumer);
    t1.join();
    t2.join();
}