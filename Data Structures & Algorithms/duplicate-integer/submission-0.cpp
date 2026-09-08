class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mSet = {};
        for (int i = 0; i < nums.size(); i++) {
            if (mSet.contains(nums[i])) {
                return true;
            }
            mSet.insert(nums[i]);
        }

        return false;
    }
};