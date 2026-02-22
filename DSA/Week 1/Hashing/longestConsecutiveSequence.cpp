class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::unordered_set<int> set1(nums.begin(),nums.end());
        int longest{0};
        for(int i : set1)
        {
            if(!set1.count(i-1)) //start from 1st of the sequence
            {
                int currentNum =i;
                int streak =1;

                while(set1.count(currentNum+1))
                {
                    currentNum++;
                    streak++;
                }
            longest = std::max(longest,streak);
            }
        }
        return longest;
    }
};