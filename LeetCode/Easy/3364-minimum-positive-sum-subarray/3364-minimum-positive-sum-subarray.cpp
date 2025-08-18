class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        for (int i = l; i <= r; i++) {
            for (int j = 0; j <= nums.size() - i; j++) {
                int sum = 0;
                for (int k = j; k < j + i; k++)
                    sum += nums[k];
                if (sum > 0)
                    mini = min(mini, sum);
            }
        }
        if (mini == INT_MAX)
            return -1;
        return mini;
    }
};