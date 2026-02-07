class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size(),ans=0;
        stack<char> stk;
        for(int i=0;i<n;i++){
            if(!stk.empty() && stk.top()=='b' && s[i]=='a'){
                stk.pop();
                ans++;
            } else
                stk.push(s[i]);
        }
        return ans;
    }
};