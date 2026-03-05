class Solution {
public:
    string removeStars(string s) {
        stack<int> sk;
        for(auto i:s){
            if(i=='*')
                sk.pop();
            else
                sk.push(i);
        }
        string res;
        while(!sk.empty()){
            res += sk.top();
            sk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};