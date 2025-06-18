class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                cur |= nums[j];
                if (cur >= k) {
                    mini = min(mini, j - i + 1);
                    break;
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};