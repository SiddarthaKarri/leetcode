class Solution {
public:
    // int m,n;
    // vector<vector<pair<long long,long long>>> dp;
    // vector<vector<int>> g;
    // pair<long long,long long> f(int i,int j){
    //     if(i>=m||j>=n) 
    //         return {LLONG_MIN,LLONG_MAX};
    //     if(i==m-1&&j==n-1) 
    //         return {g[i][j],g[i][j]};
    //     if(dp[i][j].first!=LLONG_MIN) 
    //         return dp[i][j];
    //     auto d=f(i+1,j);
    //     auto r=f(i,j+1);
    //     long long v=g[i][j],mx=LLONG_MIN,mn=LLONG_MAX;
    //     if(d.first!=LLONG_MIN){
    //         mx=max({mx,d.first*v,d.second*v});
    //         mn=min({mn,d.first*v,d.second*v});
    //     }
    //     if(r.first!=LLONG_MIN){
    //         mx=max({mx,r.first*v,r.second*v});
    //         mn=min({mn,r.first*v,r.second*v});
    //     }
    //     return dp[i][j]={mx,mn};
    // }

    int maxProductPath(vector<vector<int>>& grid) {
        // g=grid;
        // m=g.size(),n=g[0].size();
        // dp.assign(m,vector<pair<long long,long long>>(n,{LLONG_MIN,LLONG_MIN}));
        // auto res=f(0,0);
        // if(res.first<0) 
        //     return -1;
        // return res.first%1000000007;

        // tabulation
        int m=grid.size(),n=grid[0].size();
        vector<vector<pair<long long,long long>>> dp(m,vector<pair<long long,long long>>(n));
        dp[0][0]={grid[0][0],grid[0][0]};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) 
                    continue;
                long long v=grid[i][j],mx=LLONG_MIN,mn=LLONG_MAX;
                if(i>0){
                    auto [a,b]=dp[i-1][j];
                    mx=max({mx,a*v,b*v});
                    mn=min({mn,a*v,b*v});
                }
                if(j>0){
                    auto [a,b]=dp[i][j-1];
                    mx=max({mx,a*v,b*v});
                    mn=min({mn,a*v,b*v});
                }
                dp[i][j]={mx,mn};
            }
        }
        long long ans=dp[m-1][n-1].first;
        if(ans<0) 
            return -1;
        return ans%1000000007;
    }
};