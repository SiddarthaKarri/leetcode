class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        for (int i = 2; i <= 1000; ++i) {
            bool chk = true;
            for (int x : primes) {
                if (i % x == 0) {
                    chk = false;
                    break;
                }
            }
            if (chk)
                primes.push_back(i);
        }
        int size = nums.size();
        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                continue;
            int idx = upper_bound(primes.begin(), primes.end(), nums[i] - nums[i + 1]) - primes.begin();
            if (idx == primes.size() || primes[idx] >= nums[i])
                return false;
            nums[i] -= primes[idx];
        }
        return true;
    }
};