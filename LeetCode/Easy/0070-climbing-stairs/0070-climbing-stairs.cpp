class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n; 
        int secnd = 1, frst = 2, cnt = 0;
        // vector<int> dp(n+1);
        // dp[0]=dp[1]=1;
        // for(int i=2;i<=n;i++)
        //     dp[i]=dp[i-1]+dp[i-2];
        // return dp[n];
        for (int i = 3; i <= n; i++) {
            cnt = frst + secnd;
            secnd = frst;
            frst = cnt;
        }
        return cnt;
    }
};