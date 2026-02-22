#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool checkDuplicate(const vector<int>& nums)
{
    unordered_set<int> newSet; //creating unordered hash to store values
    for(int i:nums)
    {
        if(newSet.count(i)) //if already exist return true
        {
            return true;
        }
        newSet.insert(i); //if not keep adding
    }
    return false;
    
}


int main() {
    //checking duplicate
    vector<int> nums={1,23,3,43,2,3,23};
    cout<<checkDuplicate(nums);
    return 0;
}