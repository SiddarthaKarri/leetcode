class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inD(numCourses, 0);
        vector<int> res;
        for(auto& pre:prerequisites) {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            inD[a]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inD[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            res.push_back(nd);
            for(auto nei:adj[nd]){
                inD[nei]--;
                if(inD[nei]==0)
                    q.push(nei);
            }
        }
        if(res.size()==numCourses)
            return res;
        return {};
    }
};