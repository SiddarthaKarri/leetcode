class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> cpy;
        cpy.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            if(nums[i]!=nums[i-1])
                cpy.push_back(nums[i]);
        int cnt =0;
        for(int i=1;i<cpy.size()-1;i++)
            if(cpy[i]>cpy[i-1] && cpy[i]>cpy[i+1] || cpy[i]<cpy[i-1] && cpy[i]<cpy[i+1])
                cnt++;
        return cnt;
    }
};