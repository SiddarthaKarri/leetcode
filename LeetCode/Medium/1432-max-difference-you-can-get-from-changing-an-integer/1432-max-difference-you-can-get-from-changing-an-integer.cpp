class Solution {
public:
    int maxDiff(int num) {
        string s1=to_string(num);
        string t=s1;
        int n=s1.size();
        int i;
        for(i=0;i<n;i++)
            if(s1[i]!='9')
                break;
        char chk=s1[i];
        for(int i=0;i<n;i++)
            if(s1[i]==chk)
                s1[i]='9';
        char chk2=t[0],rep='1';
        if(chk2=='1'){
            for(int i=1;i<n;i++)
                if(t[i]!='0' && t[i]!='1'){
                    chk2 = t[i];
                    rep='0';
                    break;
                }
        } else 
            rep='1';
        for(int i=0;i<n;i++)
            if(t[i]==chk2)
                t[i]=rep;
        return stoi(s1)-stoi(t);
    }
};