class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size(), ans = INT_MIN;
        vector<vector<int>> ps(n+1, vector<int>(5, 0));
        for(int i=0;i<n;i++)
            for(int d=0;d<5;d++)
                ps[i+1][d] = ps[i][d] + (s[i]-'0'==d);
        for(int a=0;a<5;a++){
            for(int b=0;b<5;b++){
                if(a==b) continue;
                vector<array<int,2>> pre(2, {INT_MAX/2, INT_MAX/2});
                int j = 0;
                for(int i=0;i<n;i++){
                    int cntA = ps[i+1][a], cntB = ps[i+1][b];
                    while(j < i && i - j + 1 >= k &&
                          cntA > ps[j][a] && cntB > ps[j][b]) {
                        int pa = ps[j][a] % 2, pb = ps[j][b] % 2;
                        pre[pa][pb] = min(pre[pa][pb], ps[j][a] - ps[j][b]);
                        ++j;
                    }
                    int pa = cntA % 2, pb = cntB % 2;
                    int curr = cntA - cntB;
                    ans = max(ans, curr - pre[pa^1][pb]);
                }
            }
        }
        return ans;
    }
};