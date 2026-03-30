class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int> xs;
        for(auto &p : points)
            xs.push_back(p[0]);
        sort(xs.begin(), xs.end());
        int cnt=0,i=0,n=xs.size();
        while(i<n){
            cnt++;
            int cv = xs[i]+w;
            while(i<n && xs[i]<=cv)
                i++;
        }

        return cnt;
    }
};