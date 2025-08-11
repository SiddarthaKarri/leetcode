class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1'000'000'007;
        vector<int> powers;
        while (n > 0) {
            int lowBit = n & -n;
            powers.push_back(lowBit);
            n ^= lowBit;
        }
        int size = powers.size();
        vector<vector<int>> table(size,vector<int> (size,0));
        for (int row = 0; row < size; row++) {
            table[row][row] = powers[row];
            for (int col = row + 1; col < size; col++) {
                table[row][col] = (int)((long)table[row][col - 1] * powers[col] % MOD);
            }
        }
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int p = queries[i][0];
            int q = queries[i][1];
            result[i] = table[p][q];
        }
        return result;
    }
};