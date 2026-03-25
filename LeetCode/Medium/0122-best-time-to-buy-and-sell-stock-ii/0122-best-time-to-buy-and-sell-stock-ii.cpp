class Solution {
public:
    // long memo(vector<int>& a,int ind,int buy,vector<vector<long>>& dp){
    //     if(ind==a.size())
    //         return 0;
    //     if(dp[ind][buy]!=-1)
    //         return dp[ind][buy];
    //     long pft=0;
    //     if(buy==0)
    //         pft = max(memo(a,ind+1,0,dp),-a[ind]+memo(a,ind+1,1,dp));
    //     if(buy==1)
    //         pft = max(memo(a,ind+1,1,dp),a[ind]+memo(a,ind+1,0,dp));
    //     return dp[ind][buy]=pft;
    // }
    int maxProfit(vector<int>& prices) {
        // vector<vector<long>> dp(prices.size(),vector<long>(2,-1));
        // if(prices.size()==0)
        //     return 0;
        // return memo(prices,0,0,dp);
        int n=prices.size();
        vector<vector<long>> dp(n+1,vector<long>(2,-1));
        dp[n][0]=0;
        dp[n][1]=0;
        long pft=0;
        for(int ind=n-1;ind>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0)
                    pft = max(dp[ind+1][0], -prices[ind]+dp[ind+1][1]);
                if(buy==1)
                    pft = max(dp[ind+1][1], prices[ind]+dp[ind+1][0]);
            }
        }
        return pft;
    }
};