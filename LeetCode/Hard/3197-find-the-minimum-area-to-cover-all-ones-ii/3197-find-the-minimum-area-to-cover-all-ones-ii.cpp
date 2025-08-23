class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int rs = grid.size(), cs = grid[0].size();
        int ans = rs * cs * 3;
        for(int i=0;i<rs-2;i++){
            for(int j=i+1;j<rs-1;j++){
                int a = minimumArea(grid, 0, i, 0, cs-1);
                int b = minimumArea(grid, i+1, j, 0, cs-1);
                int c = minimumArea(grid, j+1, rs-1, 0, cs-1);
                ans = min(ans, a+b+c);
            }
        }
        for(int i=0;i<cs-2;i++){
            for(int j=i+1;j<cs-1;j++){
                int a = minimumArea(grid, 0, rs-1, 0, i);
                int b = minimumArea(grid, 0, rs-1, i+1, j);
                int c = minimumArea(grid, 0, rs-1, j+1, cs-1);
                ans = min(ans, a+b+c);
            }
        }
        for(int i=0;i<rs-1;i++){
            for(int j=0;j<cs-1;j++){
                int a = minimumArea(grid, 0, i, 0, cs-1);
                int b = minimumArea(grid, i+1, rs-1, 0, j);
                int c = minimumArea(grid, i+1, rs-1, j+1, cs-1);
                ans = min(ans, a+b+c);
                a = minimumArea(grid, i+1, rs-1, 0, cs-1);
                b = minimumArea(grid, 0, i, 0, j);
                c = minimumArea(grid, 0, i, j+1, cs-1);
                ans = min(ans, a+b+c);
                a = minimumArea(grid, 0, rs-1, 0, j);
                b = minimumArea(grid, 0, i, j+1, cs-1);
                c = minimumArea(grid, i+1, rs-1, j+1, cs-1);
                ans = min(ans, a+b+c);
                a = minimumArea(grid, 0, rs-1, j+1, cs-1);
                b = minimumArea(grid, 0, i, 0, j);
                c = minimumArea(grid, i+1, rs-1, 0, j);
                ans = min(ans, a+b+c);
            }
        }
        return ans;
    }

private:
    int minimumArea(vector<vector<int>>& grid, int si, int ei, int sj, int ej) {
        int top=grid.size(), left=grid[0].size(), btm=-1, right=-1;
        for(int i=si;i<=ei;i++){
            for(int j=sj;j<=ej;j++){
                if(grid[i][j]==1){
                    top=min(top,i);
                    btm=max(btm,i);
                    left=min(left,j);
                    right=max(right,j);
                }
            }
        }
        if(btm==-1) return 0;
        return (btm-top+1)*(right-left+1);
    }
};
