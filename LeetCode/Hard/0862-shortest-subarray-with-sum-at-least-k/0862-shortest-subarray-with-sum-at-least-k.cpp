class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int> arr(n + 1);
        int l = 0, r = 0;
        int lens = n + 1;
        for (int i = 0; i < prefix.size(); i++) {
            while (r > l && prefix[i] >= prefix[arr[l]] + k)
                lens = min(lens, i - arr[l++]);
            while (r > l && prefix[i] <= prefix[arr[r - 1]])
                r--;
            arr[r++] = i;
        }
        return lens <= n ? lens : -1;
    }
};