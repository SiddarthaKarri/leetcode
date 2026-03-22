class Solution {
public:
    // memo
    // int help(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){
    //     if(ind==0)
    //         return (T%arr[0]==0);
    //     if(dp[ind][T]!=-1)
    //         return dp[ind][T];
    //     int notpic = help(arr,ind-1,T,dp),pic = 0;
    //     if(arr[ind]<=T)
    //         pic = help(arr,ind,T-arr[ind],dp);
    //     return dp[ind][T] = notpic + pic;
    // }

    int change(int amount, vector<int>& coins) {
        // vector<unsigned long int> dp(amount+1,0);
        // dp[0]=1;
        // for(int c:coins)
        //     for(int i=c;i<=amount;i++)
        //         dp[i] += dp[i-c];
        // return dp[amount];
        int n=coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        // return help(coins,n-1,amount,dp);

        // tabulation
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,0));
        for(int i=0;i<=amount;i++)
            if(i%coins[0]==0)
                dp[0][i] = 1;
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                unsigned long long notpic = dp[ind-1][tar],pic=0;
                if(coins[ind]<=tar)
                    pic = dp[ind][tar-coins[ind]];
                dp[ind][tar] = notpic+pic;
            }
        }
        return dp[n-1][amount];
    }
};