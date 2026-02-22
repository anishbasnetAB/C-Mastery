class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int threshold{static_cast<int>(nums.size()/2)};

        unordered_map<int,int> numsMap;

        for(int i:nums) //simple hashmap, frequency counter
        {
            if(numsMap.count(i))
            {
                numsMap[i]=numsMap[i]+1;
            }
            else
                numsMap[i]=1;
        }
        for(auto& pair:numsMap) //returning the highest value
        {
            if(pair.second>threshold)
                return pair.first;
        }
        return 0;
    }
};