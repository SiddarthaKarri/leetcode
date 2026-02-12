class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int count = 0;
                bool ok = true;
                for (int f : freq) {
                    if (f > 0) {
                        if (count == 0) count = f;
                        else if (f != count) { ok = false; break; }
                    }
                }
                if (ok) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};