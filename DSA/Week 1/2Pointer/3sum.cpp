class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::sort(nums.begin(), nums.end()); // sort so two-pointer approach works

        vector<vector<int>> result; // stores all unique triplets
        int n = nums.size();

        for (int i = 0; i < n; i++) // i is the fixed leftmost element
        {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate i values

            int left = i + 1;  // start just after i
            int right = n - 1; // start at the end

            while (left < right) // two pointers move inward
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]}); // found a triplet
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left-1]) left++;   // skip duplicate left values
                    while (left < right && nums[right] == nums[right+1]) right--; // skip duplicate right values
                }
                else if (sum < 0) // sum too small, need larger value
                {
                    left++;
                }
                else // sum too large, need smaller value
                {
                    right--;
                }
            }
        }
        return result;
    }
};