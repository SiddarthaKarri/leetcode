class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        vector<int> row(mat.size(),0),col(mat[0].size(),0);
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                if(mat[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                if(mat[i][j]==1 && row[i]==1 && col[j]==1)
                    cnt++;
        return cnt;
    }
};