class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
        //     return a[1] < b[1];
        // });
        // int cnt = 1,lst = pairs[0][1];
        // for(int i=1;i<pairs.size();i++){
        //     if(pairs[i][0]>lst){
        //         cnt++;
        //         lst = pairs[i][1];
        //     }
        // }
        // return cnt;
        
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++) 
                if(pairs[j][1] < pairs[i][0]) 
                    dp[i] = max(dp[i],dp[j]+1);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};