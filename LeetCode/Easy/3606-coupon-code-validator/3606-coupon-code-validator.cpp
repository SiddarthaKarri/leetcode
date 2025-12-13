class Solution {
public:
    bool check(string& s){
        if(s.empty()) return false;
        for(char c:s)
            if(!((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || (c=='_'))) 
                return false;
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<string> chk = {"electronics", "grocery", "pharmacy", "restaurant"};
        map<string,vector<string>> mp;
        vector<string> res;
        for(int i=0;i<n;i++)
            if(isActive[i])
                if(find(chk.begin(),chk.end(),businessLine[i])!=chk.end())
                    if(check(code[i]))
                        mp[businessLine[i]].push_back(code[i]);
        for(string cat:chk){
            sort(mp[cat].begin(),mp[cat].end());
            for(string& s:mp[cat])
                res.push_back(s);
        }
        return res;
    }
};