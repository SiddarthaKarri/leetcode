class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<bool> chk(n,false),key(n,false),used(n,false);
        queue<int> q;
        for(int b:initialBoxes){
            chk[b]=1;
            q.push(b);
        }
        int tot=0,changed=1;
        while(changed){
            changed=0;
            int size=q.size();
            queue<int> temp;
            while(!q.empty()){
                int box=q.front();
                q.pop();
                if(used[box]) continue;
                if(status[box]==0 && !key[box]){
                    temp.push(box);
                    continue;
                }
                used[box]=1;
                tot += candies[box];
                changed = 1;
                for(int k:keys[box]){
                    key[k]=1;
                    if(chk[k])
                        q.push(k);
                }
                for(int b:containedBoxes[box]){
                    chk[b]=1;
                    q.push(b);
                }
            }
            q=temp;
        }
        return tot;
    }
};