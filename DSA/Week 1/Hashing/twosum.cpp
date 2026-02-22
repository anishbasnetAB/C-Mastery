class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store {value : index}
        unordered_map<int, int> map;

        // Traverse through the array
        for (int i = 0; i < nums.size(); i++) {

            // Calculate the complement (the number we need to find)
            // e.g., target = 9, nums[i] = 2, complement = 9 - 2 = 7
            int complement = target - nums[i];

            // Check if complement already exists in the map
            if (map.find(complement) != map.end()) {
                // Found the pair! Return both indices
                return {map[complement], i};
            }

            // Store current number and its index in the map
            // e.g., map[2] = 0 (value 2 is at index 0)
            map[nums[i]] = i;
        }

        // No solution found (won't reach here as per constraints)
        return {};
    }
};