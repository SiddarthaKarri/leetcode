class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> maps;
        int res = 0;
        for (auto row : matrix) {
            string pattern;
            for (int cell : row) {
                char val = '0' + (row[0] == 0 ? cell : cell ^ 1);
                pattern.push_back(val);
            }
            int curr = ++maps[pattern];
            res = max(res, curr);
        }
        return res;
    }
};