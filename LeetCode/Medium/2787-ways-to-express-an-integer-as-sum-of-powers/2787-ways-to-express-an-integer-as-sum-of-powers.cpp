class Solution {
public:
    static const int MOD = 1'000'000'007;
    int numberOfWays(int n, int x) {
        vector<long long> dp(n + 1);
        dp[0] = 1; 
        for (int i = 1;pow(i, x) <= n; i++) {
            int power = (int)pow(i, x);
            for (int sum = n; sum >= power; sum--) {
                dp[sum] = (dp[sum] + dp[sum - power]) % MOD;
            }
        } return (int) dp[n];
    }
};