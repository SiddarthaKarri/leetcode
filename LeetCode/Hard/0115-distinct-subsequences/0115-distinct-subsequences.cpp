class Solution {
public:
    // int memoo(int i,int j,string &s,string &t,vector<vector<int>> &dp) {
    //     if(j==t.size()) 
    //         return 1;
    //     if(i==s.size()) 
    //         return 0;
    //     if(dp[i][j]!=-1) 
    //         return dp[i][j];
    //     if(s[i]==t[j]){
    //         int take = memoo(i+1,j+1,s,t,dp);
    //         int notTake = memoo(i+1,j,s,t,dp);
    //         return dp[i][j] = take+notTake;
    //     } else
    //         return dp[i][j] = memoo(i+1,j,s,t,dp);
    // }
    int numDistinct(string s, string t) {
        // vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        // return memoo(0,0,s,t,dp);

        // tabulation
        int n=s.size(),m=t.size();
        // vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        // for(int i=0;i<=n;i++)
        //     dp[i][m] = 1;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         if(s[i]==t[j])
        //             dp[i][j] = dp[i+1][j+1]+dp[i+1][j];
        //         else
        //             dp[i][j] = dp[i+1][j];
        //     }
        // }
        // return dp[0][0];

        // optimal
        vector<unsigned long long> dp(m+1,0);
        dp[m] = 1;
        for(int i=n-1;i>=0;i--){
            vector<unsigned long long> curr = dp;
            for(int j=m-1;j>=0;j--)
                if(s[i]==t[j])
                    curr[j] = dp[j+1]+dp[j];
                else
                    curr[j] = dp[j];
            dp = curr;
        }
        return (int)dp[0];
    }
};