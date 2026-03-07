class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int siz = 1<<n;
        vector<vector<int>> ans;
        for(int num=0;num<siz;num++){
            vector<int> subset;
            for(int i=0;i<n;i++) 
                if(num & (1<<i))
                    subset.push_back(nums[i]);
            ans.push_back(subset);
        }
        return ans;
    }
};