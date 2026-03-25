class Solution {
public:
    // int memo(vector<int>& Arr,int n,int ind,int buy,int cap,vector<vector<vector<int>>>& dp){
    //     if(ind==n||cap==0)
    //         return 0;
    //     if(dp[ind][buy][cap]!=-1)
    //         return dp[ind][buy][cap];
    //     int profit;
    //     if(buy==0)
    //         profit = max(memo(Arr,n,ind+1,0,cap,dp), -Arr[ind]+memo(Arr,n,ind+1,1,cap,dp));
    //     if(buy==1)
    //         profit = max(memo(Arr,n,ind+1,1,cap,dp), Arr[ind]+memo(Arr,n,ind+1,0,cap-1,dp));
    //     return dp[ind][buy][cap] = profit;
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return memo(prices,n,0,0,k,dp);
        // tabu
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // opt
        // vector<vector<int>> ahead(2, vector<int>(3, 0));
        // vector<vector<int>> cur(2, vector<int>(3, 0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy==0)
                        dp[ind][buy][cap] = max(dp[ind+1][0][cap], -prices[ind]+dp[ind+1][1][cap]);
                        // cur[buy][cap] = max(ahead[0][cap],-prices[ind] + ahead[1][cap]);
                    if(buy==1)
                        dp[ind][buy][cap] = max(dp[ind+1][1][cap],prices[ind]+dp[ind+1][0][cap-1]);
                        // cur[buy][cap] = max(ahead[1][cap], prices[ind] + ahead[0][cap - 1]);
                }
            }
            // ahead = cur;
        }
        return dp[0][0][k];
        // return cur[0][2];
    }
};