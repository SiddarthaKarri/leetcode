class Solution {
public:
    bool chk(int n){
        while(n){
            if(n%10==0)
                return 0;
            n/=10;
        }
        return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res(2);
        for(int i=1;i<n;i++)
            if(chk(i) && chk(n-i)){
                res={i,n-i};
                break;
            }
        return res;
    }
};