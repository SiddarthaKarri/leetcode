class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,vector<int>> diag;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                diag[i-j].push_back(grid[i][j]);
        for(auto& [k,v]:diag)
            if(k<0) 
                sort(v.begin(),v.end(),greater<int>());
            else 
                sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                auto &v=diag[i-j];
                grid[i][j]=v.back();
                v.pop_back();
            }
        return grid;
    }
};
