class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(auto i:nums)
            maxi |= i;
        return bt(nums,maxi,0,0);
    }
    int bt(vector<int> nums,int maxi,int i,int cur){
        if(i==nums.size())
            return cur==maxi?1:0;
        if(cur==maxi)
            return 1<<(nums.size()-i);
        return bt(nums,maxi,i+1,cur|nums[i]) + bt(nums,maxi,i+1,cur);
    }
};