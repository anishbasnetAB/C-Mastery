// Write a program with a few variables. 
// Use #ifdef DEBUG to print their values. 
// Compile it twice (with and without -DDEBUG) and confirm the output changes.

int main()
{
    int abc{10};
    int xyz{15};

    #ifdef DEBUG
        std::cout<<""
}