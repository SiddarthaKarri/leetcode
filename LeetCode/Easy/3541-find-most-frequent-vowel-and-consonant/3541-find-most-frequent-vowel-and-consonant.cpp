class Solution {
public:
    int maxFreqSum(string s) {
        int fv=0,fc=0;
        vector<int> fq(26,0);
        for(auto i:s){
            fq[i-'a']++;
        }
        for(auto i:s){
            if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u')
                fv = max(fv,fq[i-'a']);
            else
                fc = max(fc,fq[i-'a']);
        }
        return fv+fc;
    }
};