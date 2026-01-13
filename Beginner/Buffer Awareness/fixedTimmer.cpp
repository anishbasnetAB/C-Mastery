#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    std::cout<<"Starting timer now : "<<std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Timer worked after 2 secs."<<std::flush;
    return 0;
}