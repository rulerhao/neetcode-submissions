class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // # Lowercase English Letters
        
        // n: vector size
        // m: str size.
        // Add one str to count table: O(m)
        // Add all strs to count table: n * O(m)
        // The max count table size would be n(Because all distinct)
        // forEach (strs) to search same table to put in array: n x n -> O(n^2)

        unordered_map<string, vector<string>> count_tables;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            string key = str;
            sort(key.begin(), key.end());
            count_tables[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& [key, str_list] : count_tables) {
            res.push_back(str_list);
        }

        return res;
    }
};
