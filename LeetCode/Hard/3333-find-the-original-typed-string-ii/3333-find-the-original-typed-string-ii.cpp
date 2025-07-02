// TLE is sucking
// optimised my solution using GPT
class Solution {
    const int MOD = 1e9 + 7;
public:
    int possibleStringCount(string word, int k) {
        vector<int> groups;
        for (int i = 0; i < word.size();) {
            int j = i;
            while (j < word.size() && word[j] == word[i]) ++j;
            groups.push_back(j - i);
            i = j;
        }
        long long total = 1;
        for (int g : groups) total = (total * g) % MOD;
        if (groups.size() >= k) return total;
        int maxLen = min((int)word.size(), k);
        vector<long long> dp(maxLen + 1, 0);
        dp[0] = 1;
        for (int g : groups) {
            vector<long long> prefix(maxLen + 2, 0);
            for (int i = 0; i <= maxLen; ++i)
                prefix[i + 1] = (prefix[i] + dp[i]) % MOD;
            vector<long long> newDp(maxLen + 1, 0);
            for (int len = 0; len <= maxLen; ++len) {
                int lo = max(0, len - g);
                newDp[len] = (prefix[len] - prefix[lo] + MOD) % MOD;
            }
            dp.swap(newDp);
        }
        long long invalid = 0;
        for (int i = 0; i < k; ++i)
            invalid = (invalid + dp[i]) % MOD;

        return (total - invalid + MOD) % MOD;
    }
};