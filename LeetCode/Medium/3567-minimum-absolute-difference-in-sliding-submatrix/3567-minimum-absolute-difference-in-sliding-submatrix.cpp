class Solution {
public:
    int getMin(const vector<vector<int>>& grid, int k, int x, int y) {
        vector<int> temp;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                temp.push_back(grid[x + i][y + j]);
        sort(temp.begin(), temp.end());
        int diff = INT_MAX;
        for (int i = 1; i < k * k; ++i)
            if (temp[i] != temp[i - 1])
                diff = min(diff, temp[i] - temp[i - 1]);
        return diff == INT_MAX ? 0 : diff;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i <= m - k; ++i)
            for (int j = 0; j <= n - k; ++j)
                ans[i][j] = getMin(grid, k, i, j);
        return ans;
    }
};