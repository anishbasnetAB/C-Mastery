class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> uniqueNums;

        for(int n:nums) //inserting elements into unique set
            uniqueNums.insert(n);

        for(int i=0;i<=uniqueNums.size();i++) //return the number that is missing.
        {
            if(uniqueNums.count(i)==0){
                return i;
            }
        }
        return 0;
    }
};