class Solution {
public:
    int numSub(string s) {
        long long cur=0,res=0;
        int MOD = 1e9+7;
        for(char c:s){
            if(c=='1')
                cur = (cur+1)%MOD;
            else
                cur=0;
            res = (cur+res)%MOD;
        }
        return res;
    }
};