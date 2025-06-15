class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxi = (1 << maximumBit) - 1;
        int xors = 0;
        for (int num : nums)
            xors ^= num;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = xors^maxi;
            xors ^= nums[n - 1 - i];
        }
        return res;
    }
};