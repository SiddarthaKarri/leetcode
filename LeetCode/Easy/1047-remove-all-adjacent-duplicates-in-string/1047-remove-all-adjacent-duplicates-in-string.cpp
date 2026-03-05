class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ss;
        string res;
        for(auto i:s){
            if(!ss.empty() && ss.top()==i)
                ss.pop();
            else
                ss.push(i);
        }
        while(!ss.empty()){
            res += ss.top();
            ss.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};