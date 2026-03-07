class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int num:nums){
            ones = (ones^num) & ~twos;
            twos = (twos^num) & ~ones;
        }
        return ones;
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<nums.size();i+=3){
        //     if(nums[i-1]!=nums[i])
        //         return nums[i-1];
        // }
        // return nums[nums.size()-1];
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