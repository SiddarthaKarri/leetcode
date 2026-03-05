class Solution {
public:
    int minOperations(string s) {
        int c1=0,c2=0;
        bool p1=0,p2=1;
        for(auto c:s){
            int ch= c-'0';
            // 1 start
            p1 = !p1;
            if(p1 != ch){
                c1++;
            }
            // 0 start
            p2 = !p2;
            if(p2 != ch)
                c2++;
        }
        return min(c1,c2);
    }
};