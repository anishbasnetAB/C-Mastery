class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> newVector;
        for(int i:nums) //first securing order for non 0 numbers
        {
            if(i!=0)
                newVector.push_back(i);
        }
        for(int i:nums) //pushing 0's at the last after we get proper order of non 0's
        {
            if(i==0)
                newVector.push_back(i);
        }
        nums=newVector;
    }
};