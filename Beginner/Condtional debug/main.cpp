#include <iostream>

#ifdef DEBUG
    #define DEBUG_LOG(msg) std::cout << "[DEBUG] " << msg << std::endl
#else
    #define DEBUG_LOG(msg)
#endif

int main() {
    DEBUG_LOG("Program started");
    
    int x = 10;
    DEBUG_LOG("x = " << x);
    
    std::cout << "Hello from production code" << std::endl;
    
    DEBUG_LOG("Program ending");
    return 0;
}

//g++ -DDEBUG -o debug_version main.cp
// Compile release: g++ -o release_version main.cpp
// Check file sizes: ls -lh debug_version release_version