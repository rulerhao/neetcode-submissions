class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Exactly one pair

        // Hashmap would be best
        // O(1) * O(n) TC
        // O(n) SC

        unordered_map<int, int> num_idx;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int diff = target - num;
            if (num_idx.contains(diff)) {
                return {num_idx[diff], i};
            }
            if (num_idx.contains(num)) continue;
            num_idx[num] = i;
        }

        return {-1, -1};
    }
};

