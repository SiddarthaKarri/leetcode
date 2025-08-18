class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        for (auto& guard : guards)
            grid[guard[0]][guard[1]] = 2;
        for (auto& wall : walls)
            grid[wall[0]][wall[1]] = 2;
        int directions[5] = {-1, 0, 1, 0, -1};
        for (auto& guard : guards) {
            for (int k = 0; k < 4; k++) {
                int x = guard[0], y = guard[1];
                int dx = directions[k], dy = directions[k + 1];
                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && grid[x + dx][y + dy] < 2) {
                    x += dx;
                    y += dy;
                    grid[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    ans++;
            }
        }
        return ans;
    }
};