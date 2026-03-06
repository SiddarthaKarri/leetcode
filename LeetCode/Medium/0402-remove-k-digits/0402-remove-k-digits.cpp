class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        if (st.empty())
            return "0";
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        if (res.empty())
            return "0";
        vector<int> fq(10,0);
        for(char i:res){
            int c=i-'0';
            fq[c]++;
        }
        if(res.size()==fq[0])
            return "0";
        while (res.size() != 0 && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};