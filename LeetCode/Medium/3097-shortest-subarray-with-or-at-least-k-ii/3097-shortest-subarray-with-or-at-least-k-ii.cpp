class Solution {
public:
    void addj(int val, vector<int>& bitC, bool add) {
        int i = 0;
        while (val > 0) {
            bitC[i] += (add ? 1 : -1) * val % 2;
            val /= 2;
            i++;
        }
    }
    bool greaterK(int k, vector<int> bitC) {
        int bitV = 0;
        for (int i = 0; i < 32; i++) {
            bitV += (bitC[i] ? 1 : 0) * pow(2, i);
        }
        return (bitV >= k);
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitCount(32, 0);
        int i = 0, j = 0, ans = INT_MAX;
        while (j < n) {
            addj(nums[j], bitCount, true);
            while (greaterK(k, bitCount) && i <= j) {
                ans = min(ans, j - i + 1);
                addj(nums[i], bitCount, false);
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};