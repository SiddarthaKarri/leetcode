class Solution {
public:
    // just copied as i got 507/602, yet to understand.
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>> freq(26);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (!freq[j].empty()) {
                        s[freq[j].top()] = '*';
                        freq[j].pop();
                        break;
                    }
                }
            } else {
                freq[s[i] - 'a'].push(i);
            }
        }
        string result = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                result += s[i];
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     string clearStars(string s) {
//         stack<char> stk;
//         stack<char> minstk;
//         for(char c:s){
//             if(c=='*'){
//                 char sm=minstk.top();
//                 stack<char> temp;
//                 while(stk.top()!=sm){
//                     temp.push(stk.top());
//                     stk.pop();
//                     minstk.pop();
//                 }
//                 stk.pop();
//                 minstk.pop();
//                 while(!temp.empty()){
//                     char t=temp.top();
//                     temp.pop();
//                     stk.push(t);
//                     if(minstk.empty())
//                         minstk.push(t);
//                     else 
//                         minstk.push(min(t,minstk.top()));
//                 }
//             }else{
//                 stk.push(c);
//                 if(minstk.empty())
//                     minstk.push(c);
//                 else 
//                     minstk.push(min(c,minstk.top()));
//             }
//         }
//         string res;
//         while(!stk.empty()){
//             res=stk.top()+res;
//             stk.pop();
//         }
//         return res;
//     }
// };
