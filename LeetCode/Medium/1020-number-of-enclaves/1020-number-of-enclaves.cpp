class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++) 
                if(i==0 || j==0 || i==n-1 || j==m-1) 
                    if(grid[i][j]==1){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
        vector<int> dx={-1,0,+1,0}, dy={0,+1,0,-1};
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx = row+dx[k], ny = col+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1 && vis[i][j]==0) 
                    cnt++;
        return cnt;
    }
};