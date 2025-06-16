class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mx = *max_element(nums.begin(), nums.end());
        int sz = mx + k + 2;
        vector<int> f(sz, 0);
        for (int n : nums)
            f[n]++;
        vector<int> p(sz, 0);
        p[0] = f[0];
        for (int i = 1; i < sz; ++i)
            p[i] = p[i - 1] + f[i];
        int res = 0;
        for (int x = 0; x < sz; ++x) {
            if (f[x] == 0 && numOperations == 0)
                continue;
            int l = max(0, x - k);
            int r = min(sz - 1, x + k);
            int totalRange = p[r] - (l > 0 ? p[l - 1] : 0);

            int canAdj = totalRange - f[x];
            int total = f[x] + min(numOperations, canAdj);
            res = max(res, total);
        }
        return res;
    }
};