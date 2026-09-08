class Solution {
public:
    bool isAnagram(string s, string t) {
        // size is larger, so check zero size is not needed.
        if (s.size() == 0) return false;
        if (t.size() == 0) return false;

        // If size is not equal, two string is not anagrams.
        if (s.size() != t.size()) return false;

        // Solution 1:
        // 
        // Requirement:
        // 1. All charcters are lowercase English letter.
        // 
        
        // Method:
        // a. According to 1., the size of all characters could store in array with 26 size(a-z).
        // Array<char> mArr = {[], ..., []};
        // b. Count the characters in s array -- O(n). And minus the characters in t array -- O(n).
        // c. For loop check 26 elements are all zero then return true. Otherwise return false -- O(1).

        // Solution 2:
        //
        // Method:
        // a. Count characters numbers of s -- O(n) because hashmap insert O(1) and for loop size of s.
        // b. Minus characters numbers of t -- O(n) because hashmap insert O(1) and for loop size of t.
        unordered_map<char, int> char_counts;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (char_counts.contains(ch)) {
                int cnt = char_counts.at(ch);
                char_counts[ch] = cnt + 1;
            } else {
                char_counts[ch] = 1;
            }
        }
        
        for (int i = 0; i < t.size(); i++) {
            char ch = t[i];
            if (char_counts.contains(ch)) {
                int count = char_counts[ch];
                if (count == 0) return false;
                char_counts[ch] = count - 1;
            } else {
                return false;
            }
        }

        return true;
    }
};
