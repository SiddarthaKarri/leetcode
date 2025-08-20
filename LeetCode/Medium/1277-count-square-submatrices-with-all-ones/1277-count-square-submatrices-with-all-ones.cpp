class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        set<pair<int,int>> ones;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]==1)
                    ones.insert({i,j});
        int total=ones.size(), size=1;
        set<pair<int,int>> curr=ones;
        while(!curr.empty()){
            size++;
            set<pair<int,int>> next;
            for(auto &cell:curr){
                int r=cell.first, c=cell.second;
                if(r+size-1>=m||c+size-1>=n) continue;
                bool valid=true;
                for(int j=c;j<=c+size-1;j++)
                    if(ones.find({r+size-1,j})==ones.end()){valid=false;break;}
                if(valid){
                    for(int i=r;i<=r+size-1;i++)
                        if(ones.find({i,c+size-1})==ones.end()){valid=false;break;}
                }
                if(valid){next.insert({r,c});total++;}
            }
            curr=move(next);
        }
        return total;
    }
};
