class Solution {
public:
    bool check(string &s,string ans,int k){
        int j=0,m=ans.size();
        for(int i=0;i<s.size();i++){
            if(s[i]==ans[j])
                j++;
            if(j==m){
                k--;
                if(k==0) return true;
                j=0;
            } 
        }
        return k<=0;
    }

    string solver(string &s,string &ans,int k){
        int val=0;
        string r="";
        for(char ch='z';ch>='a';ch--){
            if(check(s,ans+ch,k)){
                ans+=ch;
                string temp=ch+solver(s,ans,k);
                if(val<temp.size()){
                    r=temp;
                    val=temp.size();
                }
                ans.pop_back();
            }
        }
        return r;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        return solver(s,ans,k);
    }
};