class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        vector<int> dx = {-1,1,0,0}, dy={0,0,1,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x=it.second.first, y=it.second.second;
            int dis = it.first;
            if(x==n-1 && y==m-1)
                return dis;
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int newD =max(dis,abs(heights[nx][ny]-heights[x][y]));
                    if(newD < dist[nx][ny]){
                        dist[nx][ny] = newD;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};