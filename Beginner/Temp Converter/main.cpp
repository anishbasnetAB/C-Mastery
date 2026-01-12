#include <iostream> //This program converts temperature (Fahrenheit to Celsius or vice versa)

constexpr double FAHRENHEIT_SCALE_FACTOR = 1.8; // Constant gobal variables
constexpr double FAHRENHEIT_OFFSET = 32;


double celsiusToFahrenheit(double celsius) // Converts celsius to Fahrenheit
{
    return ((celsius*FAHRENHEIT_SCALE_FACTOR)+FAHRENHEIT_OFFSET );
}

double fahrenheitToCelsius(double fahrenheit) //convets Fahrenheit to celsius
{
    return ((fahrenheit-FAHRENHEIT_OFFSET )/FAHRENHEIT_SCALE_FACTOR);
}

int main()
{
    std::cout<<"This Program converts Temperature\n";
    std::cout<<"Choose Conversion: (Enter 1 or 2)\n";
    int userChoice{};
    std::cout<<"1. Celsius to Fahrenheit \n2. Fahrenheit to Celsius\n";
    std::cout<<"Enter Choice: ";
    if(!(std::cin>>userChoice) ||(userChoice<1) ||(userChoice>2))  // user input validation
    {
        std::cout<<"Wrong Input (valid input 1 or 2)";
        return 1;
    }

    double userTempValue{};
    std::cout<<"Enter temperature: ";
    std::cin>>userTempValue;

    double convertedValue{};
    if(userChoice==1)
    {
        convertedValue = celsiusToFahrenheit(userTempValue);
        std::cout<<userTempValue<<"°C = "<<convertedValue<<"°F  ";
    }
    else
    {
        convertedValue = fahrenheitToCelsius(userTempValue);
        std::cout<<userTempValue<<"°F = "<<convertedValue<<"°C  ";
    }
    
    return 0;
}