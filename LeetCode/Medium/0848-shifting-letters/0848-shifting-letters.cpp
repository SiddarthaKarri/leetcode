class Solution {
public:
    char shift(char c, long long x=1) {
        return 'a'+((c-'a'+x)%26);
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        string res;
        // vector<long long> prefix(s.length(),0);
        long long sum=0;
        for(int i=0;i<shifts.size();i++)
            sum += shifts[i];
        // prefix[0] = sum;
        // for(int i=1;i<shifts.size();i++)
        //     prefix[i] = (prefix[i-1]-shifts[i-1]);
        for(int i=0;i<s.length();i++){
            char c = shift(s[i],sum);
            sum-=shifts[i];
            res+=c;
        }
        return res;
    }
};