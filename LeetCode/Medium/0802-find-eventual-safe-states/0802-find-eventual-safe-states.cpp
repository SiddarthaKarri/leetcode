class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> inD(graph.size(), 0);
        for(int i=0;i<graph.size();i++){
            for(auto pre:graph[i]) {
                adj[pre].push_back(i);
                inD[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(inD[i]==0)
                q.push(i);
        }
        vector<int> safe;
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            safe.push_back(nd);
            for(auto nei:adj[nd]){
                inD[nei]--;
                if(inD[nei]==0)
                    q.push(nei);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};