class Solution {
public:
    bool chk(vector<int>& arr, int k, int n) {
        for (int i = 0; i + 2 * k - 1 < n; i++) {
            if (arr[i] >= k && arr[i + k] >= k)
                return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                arr[i] = arr[i + 1] + 1;
        }
        int l = 1, r = n / 2, res = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (chk(arr, mid, n)) {
                res = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return res;
    }
};