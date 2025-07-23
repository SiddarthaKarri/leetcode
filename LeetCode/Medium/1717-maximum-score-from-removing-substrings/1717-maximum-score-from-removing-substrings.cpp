class Solution {
public:
    int rmv(string& s, char first, char second, int score) {
        stack<char> st;
        int pts = 0;
        for(char c:s) {
            if(!st.empty() && st.top()==first && c==second) {
                st.pop();
                pts += score;
            }else
                st.push(c);
        }
        s.clear();
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return pts;
    }

    int maximumGain(string s, int x, int y) {
        int tot = 0;
        if(x>=y){
            tot += rmv(s, 'a', 'b', x);
            tot += rmv(s, 'b', 'a', y);
        }else{
            tot += rmv(s, 'b', 'a', y);
            tot += rmv(s, 'a', 'b', x);
        }
        return tot;
    }
};
