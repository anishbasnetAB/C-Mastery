class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

    unordered_set<int> seen;
    seen.reserve(nums.size()); // pre-allocate to avoid rehashing
    for (int val : nums) {
        if (!seen.insert(val).second) // insert returns {iterator, bool}
            return true;
    }
    return false;
    }
};