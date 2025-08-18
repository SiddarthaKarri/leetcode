class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length(), res = n;
        vector<int> cnt(3);
        for (char c : s)
            cnt[c - 'a']++;
        if (cnt[0] < k || cnt[1] < k || cnt[2] < k)
            return -1;
        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']--;
            while (cnt[s[r] - 'a'] < k)
                cnt[s[l++] - 'a']++;
            res = min(res, n - (r - l + 1));
        }
        return res;
    }
};