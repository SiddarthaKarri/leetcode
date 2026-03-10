class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& time:times){
            int u=time[0],v=time[1],w=time[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int nd=it.second;
            for(auto& [nb,wt]:adj[nd]){
                if(time+wt<dist[nb]){
                    dist[nb]=time+wt;
                    pq.push({dist[nb],nb});
                }
            }
        }
        int ans =*max_element(dist.begin()+1,dist.end());
        return ans==INT_MAX?-1:ans;
    }
};