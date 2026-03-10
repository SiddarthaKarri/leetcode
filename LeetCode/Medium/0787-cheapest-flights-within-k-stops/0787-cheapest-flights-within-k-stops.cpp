class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it:flights)
            adj[it[0]].push_back({it[1], it[2]});
        queue<pair<int,pair<int,int>>> q;
        vector<int> dis(n,1e9);
        dis[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stp = it.first;
            int nd=it.second.first, cst=it.second.second;
            if(stp>k)
                continue;
            for(auto neigh:adj[nd]){
                int nN = neigh.first;
                int eW = neigh.second;
                if(cst+eW<dis[nN] && stp<=k){
                    dis[nN] = cst+eW;
                    q.push({stp+1,{nN,dis[nN]}});
                }
            }
        }
        if(dis[dst]==1e9)
            return -1;
        return dis[dst];
    }
};