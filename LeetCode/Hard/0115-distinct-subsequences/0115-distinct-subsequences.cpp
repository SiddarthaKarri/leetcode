class Solution {
public:
    int memoo(int i,int j,string &s,string &t,vector<vector<int>> &dp) {
        if(j==t.size()) 
            return 1;
        if(i==s.size()) 
            return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if(s[i]==t[j]){
            int take = memoo(i+1,j+1,s,t,dp);
            int notTake = memoo(i+1,j,s,t,dp);
            return dp[i][j] = take+notTake;
        } else
            return dp[i][j] = memoo(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return memoo(0,0,s,t,dp);
    }
};