#include <iostream>

int countVowels(const std::string& str) //function couts the number of vowels
{
    int counter{};
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == 'a' || str[i] == 'e' ||str[i] == 'i' ||str[i] == 'o' ||str[i] == 'u' )
        {
            counter++;
        }
    }
    std::cout<<"Sentence has "<<counter<<" vowels \n";
    return 0;
}

int countConsonants(const std::string& str) //function counts the number of consonants
{
    int counter{};
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' )
        {
            counter++;
        }
    }
    std::cout<<"Sentence has "<<counter<<" consonants \n";
    return 0;
}

int countDigits(const std::string& str) // function counts the number of digits the function has
{ 
    int counter{};
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            counter++;
        }
    }
    std::cout<<"Sentence has "<<counter<<" digits \n";
    return 0;
}

int countSpaces(const std::string& str) // function counts the number of spaces
{
    int counter{};
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==' ')
        {
            counter++;
        }
    }
    std::cout<<"Sentence has "<<counter<<" digits \n";
    return 0;
}

std::string reverseString(const std::string& str)  // function reverses the string 
{
    std::string reversed{};
    for(int i = str.length() -1; i>=0; i--)
    {
        reversed += str[i];
    }
    std::cout<<"Reversed sentence is "<<reversed<<" \n";
    return reversed;
}

bool isPalindrome(const std::string& str)  // checks palindrome
{
    std::string reversed{};
    for(int i = str.length()-1; i>=0; i--)
    {
        reversed += str[i];
    }
    std::cout<<"checking palindrome "<<" user input "<<str<<" reversed "<<reversed<<" \n";
    if(str==reversed) return true;
    return false;
}

int main()
{
    std::cout<<"Enter a sentence :\n";
    std::string userInput{};
    std::getline(std::cin, userInput); // saving user input 
    std::string userInputLower{};  // new string to save user input in lower case 
    //incase we need in future
    
    for(int i = 0;i<userInput.length(); i++) // well i just learned c++ does not have any buildin Func 
                                            // convert all at once.
    {
        userInputLower += std::tolower(userInput[i]);
    }
    std::cout<<userInputLower<<"\n";

    //user input with no space
    std::string noSpaceUserInput{};
    for(int i = 0;i<userInputLower.length(); i++)
    {
        if(userInput[i] != ' ')
        {
             noSpaceUserInput += userInputLower[i];
        }
    }
    std::cout<<noSpaceUserInput<<"\n";

    countVowels(noSpaceUserInput); //to count vowels
    countConsonants(noSpaceUserInput); //to count consonets
    countDigits(noSpaceUserInput); //to count digits
    countSpaces(userInputLower); // counts spaces
    reverseString(userInput); //reverses the string
    std::cout<<isPalindrome(noSpaceUserInput); //checking if it is palindrome or not

    return 0;
}
