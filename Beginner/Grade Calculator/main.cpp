#include <iostream>

char getLetterGrade(int score)
{
    if(score>=90)
    {
        return 'A';
    }
    else if(score>=80 & score<=89)
    {   
        return 'B';
    }
    else if(score>=70 & score<=79)
    {
        return 'C';
    }
    else if(score>=60 & score<=69)
    {
        return 'D';
    }
    return 'F';
}

bool isPassing(char grade)
{
    if(grade =='F')
    {
        return false;
    }
    return true;
}

int main()
{
    int userGrade{};
    std::cout<<"Enter your grade (0-99) \n";
    if(!(std::cin>>userGrade) || userGrade<0 || userGrade>99)
    {
        std::cout<<"Invalid input, try again\n";
        return 1;
    }
    char userGrading{};
    userGrading = getLetterGrade(userGrade);
    std::cout<<"Your Grade is : "<<userGrading<<"\n";

    bool isPass{};
    isPass = isPassing(userGrading);
    if(isPass == true)
    {
        std::cout<<"Congratulations you passed. !!!!";
    }
    else
    {
        std::cout<<"You have failed. ";
    }
    return 0;
}