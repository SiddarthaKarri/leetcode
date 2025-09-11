class Solution {
public:
    string sortVowels(string s) {
        string v="aeiouAEIOU",tmp;
        auto isv=[&](char c){
            return v.find(c)!=string::npos;
        };
        for(char c:s) 
            if(isv(c)) 
                tmp+=c;
        sort(tmp.begin(),tmp.end());
        int j=0;
        for(int i=0;i<s.size();i++) 
            if(isv(s[i])) 
                s[i]=tmp[j++];
        return s;
    }
};
