class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long maxsum = 0;
        int leastsum = INT_MAX;
        int cntN = 0;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                maxsum += abs(val);
                leastsum = min(leastsum, abs(val));
                if (val < 0)
                    cntN++; 
            }
        }
        if (cntN % 2 == 1)
            maxsum -= 2 * leastsum;
        return maxsum;
    }
};