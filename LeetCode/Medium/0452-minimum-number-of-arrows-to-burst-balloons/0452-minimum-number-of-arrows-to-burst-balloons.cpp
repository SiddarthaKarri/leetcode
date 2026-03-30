class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> v;
        for(int i = 0; i < points.size(); i++)
            v.push_back({points[i][0], points[i][1]});
        sort(v.begin(), v.end(), cmp);
        int cnt=1,end=v[0].second;
        for(int i=1;i<v.size();i++){
            if(v[i].first>end){
                cnt++;
                end = v[i].second;
            }
        }
        return cnt;
    }
};