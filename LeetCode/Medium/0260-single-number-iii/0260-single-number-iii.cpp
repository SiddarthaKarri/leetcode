class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long xorr=0;
        for(int i=0;i<nums.size();i++)
            xorr ^= nums[i];
        long long rm= (xorr&(xorr-1))^xorr;
        long long xorr1=0,xorr2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&rm)
                xorr1 ^= nums[i];
            else
                xorr2 ^= nums[i];
        }
        if(xorr1>xorr2)
            return {(int)xorr2,(int)xorr1};
        return {(int)xorr1,(int)xorr2};
    }
};