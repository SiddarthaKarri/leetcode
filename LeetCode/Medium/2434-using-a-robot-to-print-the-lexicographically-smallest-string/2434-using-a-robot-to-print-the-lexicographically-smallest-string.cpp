class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        stack<char> stk;
        string res;
        char m = 'a';
        for (char c : s) {
            stk.push(c);
            cnt[c - 'a']--;
            while (m <= 'z' && cnt[m - 'a'] == 0) m++;
            while (!stk.empty() && stk.top() <= m) {
                res += stk.top();
                stk.pop();
            }
        }
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
