class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> numsMap;

        for(int n:nums) //adding in map
            numsMap[n]++;
        
        for(auto& pair:numsMap) //checking which satisfy our condition
        {
            if(pair.second<2)
                return pair.first;
        }
        return -1;
    }
};