class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rs=grid.size(),cs=grid[0].size();
        int top=rs,left=cs,btm=-1,right=-1;
        for(int i=0;i<rs;i++)
            for(int j=0;j<cs;j++)
                if(grid[i][j]==1){
                    top = min(top,i);
                    btm=max(btm,i);
                    left=min(left,j);
                    right=max(right,j);
                }
        return (btm-top+1)*(right-left+1);
    }
};