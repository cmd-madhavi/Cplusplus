#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

/*
THERE ARE DIFFERENT TYPES of MUTEX
1. mutex
2. recursive_mutex
3. timed_mutex try_lock_for(), after the given time can try again(in a loop, like wait for some time and then try again) or leave
4. recursive_timed_mutex    
5. shared_mutex - multiple thread can read, but write will be only by one at a time
std::shared_mutex stmtx;
std::shared_lock<shared_mutex> lock(stmtx);
std::unique_lock<shared_mutex> lock(stmtx); //for writing


std::lock_guard<std::mutex> lock(mtx);
std::scoped_lock lock(mtx1, mtx2); - template class that accept any number of arguments and deduces the type of mutexes automatically
so need to write like std::scoped_lock<mutex>
*/
static int num = 0;
std::mutex mtx;
std::__thread_id prev_thread_id;
std::__thread_id curr_thread_id;
void func()
{
    int count = 100000;
    while(count--)
    {
        mtx.lock();

        curr_thread_id = std::this_thread::get_id();
        if (prev_thread_id != curr_thread_id)
        {
            std::cout <<"wow " <<prev_thread_id << " "<<curr_thread_id <<std::endl;
        }
        num++;
        prev_thread_id = std::this_thread::get_id();
        mtx.unlock();
    }
}
int main()
{
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();
    std::cout << num;
}
