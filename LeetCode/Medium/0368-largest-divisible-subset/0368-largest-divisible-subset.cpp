class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans,dp(n, 1),par(n,-1);
        int last = 0,maxi = 0;
        for(int i=0;i<n;i++){
            par[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                    dp[i] = dp[prev]+1;
                    par[i] = prev;
                }
            }
            if(dp[i]>maxi){
                last = i;
                maxi = dp[i];
            }
        }
        int i=last;
        while(par[i]!=i){
            ans.push_back(nums[i]);
            i = par[i]; 
        }
        ans.push_back(nums[i]);
        return ans;

        // sort(nums.begin(), nums.end());
        // vector<vector<int>> subsets(nums.size());
        // vector<int> res;
        // for (int i = 0; i < nums.size(); i++) {
        //     subsets[i] = {nums[i]};
        //     for (int j = 0; j < i; j++) {
        //         if (nums[i] % nums[j] == 0 &&
        //             subsets[j].size() + 1 > subsets[i].size()) {
        //             subsets[i] = subsets[j];
        //             subsets[i].push_back(nums[i]);
        //         }
        //     }
        //     if (subsets[i].size() > res.size())
        //         res = subsets[i];
        // }
        // return res;
    }
};