class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> ans(temperatures.size());
        for (int i=0;i<temperatures.size();i++){
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int idx=stk.top();
                stk.pop();
                ans[idx] = i-idx;
            }
            stk.push(i);
        }
        return ans;
    }
};