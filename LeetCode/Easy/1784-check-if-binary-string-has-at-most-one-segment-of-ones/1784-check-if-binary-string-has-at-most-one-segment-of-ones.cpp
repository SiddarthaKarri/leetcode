class Solution {
public:
    bool checkOnesSegment(string s) {
        bool chk=1;
        int cnt=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='1' && (i==0 ||s[i-1]=='0'))
                chk=0,cnt++;
        if(cnt<=1)
            return true;
        return false;
    }
};