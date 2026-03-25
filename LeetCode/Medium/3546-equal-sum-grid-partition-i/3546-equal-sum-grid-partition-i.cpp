class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<long long> rs(m,0),cs(n,0);
        long long sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rs[i]+=grid[i][j];
                cs[j]+=grid[i][j];
                sum+=grid[i][j];
            }
        }
        if(sum%2)
            return 0;
        if(chk(rs,sum) || chk(cs,sum))
            return 1;
        return 0;
    }
    bool chk(vector<long long>& ar,long long sum){
        long long l=ar[0],r=sum-l;
        for(int i=1;i<ar.size();i++){
            if(l==r)
                return 1;
            else if(l>r)
                return 0;
            l+=ar[i];
            r-=ar[i];
        }
        return 0;
    }
};