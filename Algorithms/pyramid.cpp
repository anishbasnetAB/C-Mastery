#include <iostream>
int main() {
  int x = 5;
  
  for(int i=1;i<=x;i++)
  {
    // Print leading spaces once per row
    for(int k=0; k<x-i; k++)
    {
      std::cout<<" ";
    }
    
    // Print stars
    for(int j=0;j<i;j++)
    {
      std::cout<<"* ";
    }
    
    std::cout<<"\n";
  }
}