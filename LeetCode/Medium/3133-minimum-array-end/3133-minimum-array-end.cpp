class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        vector<int> xbit(64, 0);
        vector<int> nbit(64, 0);
        for (int i = 0; i < 32; i++) {
            xbit[i] = (x >> i) & 1;
            nbit[i] = (n >> i) & 1;
        }
        int i = 0, j = 0;
        while (i < 64) {
            if (xbit[i] == 1) {
                i++;
                continue;
            }
            xbit[i++] = nbit[j++];
        }
        long long ans = 0;
        for (int i = 0; i < 64; i++) {
            ans += xbit[i] * (1ll << i);
        }
        return ans;
        // long long ans = x;
        // long long k = n - 1;
        // for (int i = 0; i < 64; i++) {
        //     if (((1LL << i) & ans) == 0) {
        //         ans |= (k & 1LL) << i;
        //         k >>= 1;
        //         if (k == 0)
        //             break;
        //     }
        // }
        // return ans;
    }
};