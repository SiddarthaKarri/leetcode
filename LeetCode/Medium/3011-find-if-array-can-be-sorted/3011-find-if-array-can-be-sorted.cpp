class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int premax = 0;
        int current = 0;
        int len = nums.size();
        while (current < len) {
            int next = current + 1;
            int currentPopCount = __builtin_popcount(nums[current]);
            int cmin = nums[current], cmax = nums[current];
            while (next < len && __builtin_popcount(nums[next]) == currentPopCount) {
                cmin = min(cmin, nums[next]);
                cmax = max(cmax, nums[next]);
                next++;
            }
            if (premax > cmin)
                return false;
            premax = cmax;
            current = next;
        }
        return true;
    }
};