// copied
// come back in 120 days
class Solution {
public:
    // returns sum of ops(x) for x = 1..n
    long long getOperations(long long n) {
        if (n <= 0) return 0;
        long long res = 0;
        long long power = 1;   // current 4^k
        long long ops = 0;     // ops value for numbers in [power, 4*power - 1] is ops+1
        while (power <= n) {
            long long L = power;
            long long R = min(n, power * 4 - 1);
            ++ops; // numbers in this block need `ops` divisions
            res += (R - L + 1) * ops;
            if (power > LLONG_MAX / 4) break; // safety (not needed for constraints)
            power *= 4;
        }
        return res;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long total = getOperations(r) - getOperations(l - 1);
            ans += (total + 1) / 2; // ceil(total/2)
        }
        return ans;
    }
};
