class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> suffix(26, 0);
        vector<int> prefix(26, 0);
        unordered_set<string> uniq;
        for (char ch : s)
            suffix[ch - 'a']++;
        for (int i = 0; i < n; i++) {
            suffix[s[i] - 'a']--;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (prefix[ch - 'a'] > 0 && suffix[ch - 'a'] > 0) {
                    string palindrome = string(1, ch) + s[i] + string(1, ch);
                    uniq.insert(palindrome);
                }
            }
            prefix[s[i] - 'a']++;
        }
        return uniq.size();
    }
};