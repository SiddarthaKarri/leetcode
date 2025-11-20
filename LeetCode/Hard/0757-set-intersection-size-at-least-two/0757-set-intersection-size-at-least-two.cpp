class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1]==b[1]) 
                return a[0]>b[0];
            return a[1]<b[1];
        });
        int p1=-1, p2=-1, count=0; 
        for(auto &in:intervals){
            int start=in[0], end=in[1];
            bool has_p1 = (p1>=start), has_p2 = (p2>=start);
            if(has_p1&&has_p2)
                continue;
            if(has_p2){
                count += 1;
                p1 = p2;
                p2 = end;
            }else{
                count += 2;
                p1 = end - 1;
                p2 = end;
            }
        }
        return count;
    }
};