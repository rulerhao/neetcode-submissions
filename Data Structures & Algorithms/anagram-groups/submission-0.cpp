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

        map<vector<int>, vector<string>> count_tables;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            vector<int> count_table(26, 0);
            for (int j = 0; j < str.size(); j++) {
                char ch = str[j];
                count_table[ch - 'a'] = count_table[ch - 'a'] + 1;
            }

            count_tables[count_table].push_back(str);
        }

        vector<vector<string>> res;

        for (auto& [count_table, str_list] : count_tables) {
            res.push_back(str_list);
        }

        return res;
    }
};
