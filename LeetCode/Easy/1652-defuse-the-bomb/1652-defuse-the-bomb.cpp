class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        vector<int> prefix(2 * n + 1, 0); 
        for (int i = 0; i < 2 * n; i++)
            prefix[i + 1] = prefix[i] + code[i % n];
        for (int i = 0; i < n; ++i) {
            if (k > 0)
                res[i] = prefix[i + k + 1] - prefix[i + 1];
            else
                res[i] = prefix[i + n] - prefix[i + k + n];
        }
        return res;

    }
};