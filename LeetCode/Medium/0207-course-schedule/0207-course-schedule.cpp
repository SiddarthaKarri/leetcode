class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inD(numCourses, 0);
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
        int cnt=0;
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            cnt++;
            for(auto nei:adj[nd]){
                inD[nei]--;
                if(inD[nei]==0)
                    q.push(nei);
            }
        }
        return cnt==numCourses;
    }
};