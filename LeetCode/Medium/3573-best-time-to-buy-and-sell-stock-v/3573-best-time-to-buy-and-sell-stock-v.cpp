class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        long long NEG= -(1LL<<60),res=0;
        int size=prices.size();
        vector<vector<long long>> dp(k+1,vector<long long>(3,NEG));
        dp[k][0]=0;
        for(int x=0;x<size;x++){
            vector<vector<long long>> temp=dp;
            for(int t=k;t>=0;t--){
                if(dp[t][0]>NEG && t>0){
                    temp[t][1]=max(temp[t][1],dp[t][0]-prices[x]);
                    temp[t][2]=max(temp[t][2],dp[t][0]+prices[x]);
                }
                if(dp[t][1]>NEG && t>0){
                    temp[t-1][0]=max(temp[t-1][0],dp[t][1]+prices[x]);
                }
                if(dp[t][2]>NEG && t>0){
                    temp[t-1][0]=max(temp[t-1][0],dp[t][2]-prices[x]);
                }
            }
            dp=temp;
        }
        for(int a=0;a<=k;a++)
            res=max(res,dp[a][0]);
        return res;
    }
};