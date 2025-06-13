class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = nums[n - 1] - nums[0];
        while (low < high) {
            int mid = low + (high - low) / 2, pairs = 0;
            for (int i = 1; i < n; ++i) {
                if (mid >= nums[i] - nums[i - 1]) {
                    ++pairs, ++i;
                }
            }
            if (pairs >= p) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};