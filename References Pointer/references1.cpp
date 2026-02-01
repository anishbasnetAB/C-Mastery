// Declares an integer variable x with value 10
// Creates a reference ref to x
// Prints both x and ref
// Modifies x to 20
// Prints both again
// Modifies ref to 30
// Prints both again
#include <iostream>



int main()
{

    int x{10};
    int& ref{x};

    std::cout<<x<<" "<<ref<<"\n";

    x=20;

    std::cout<<x<<" "<<ref<<"\n";

    ref=30;

    std::cout<<x<<" "<<ref<<"\n";

    return 0;

}