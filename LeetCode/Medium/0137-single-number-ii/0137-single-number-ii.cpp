class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i] && nums[i]==nums[i+1])
                continue;
            else
                return i-1;
        }
        return -1;
        // int res = 0;
        // for(int i=0;i<32;i++){
        //     int sum = 0;
        //     for(int num:nums)
        //         if(num & (1<<i))
        //             sum++;
        //     if(sum%3==1)
        //         res |= (1 << i);
        // }
        // return res;
    }
};