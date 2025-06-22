class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n=s.size();
        for(int i=0;i<n;i+=k){
            string s1 = s.substr(i,k);
            while(s1.size()<k)
                s1 += fill;
            res.push_back(s1);
        }
        return res;
    }
};