#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "Starting work NOW!"; // NO newline at all
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    std::cout << "Finished work NOW!\n";
    
    return 0;
}