class Solution {
public:
    vector<int> fnse(vector<int>& arr){
        stack<int> stk;
        int n=arr.size();
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()]>=arr[i])
                stk.pop();
            if(!stk.empty())
                nse[i] = stk.top();
            stk.push(i);
        }
        return nse;
    }
    vector<int> psee(vector<int>& arr){
        stack<int> stk;
        int n=arr.size();
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()]>arr[i])
                stk.pop();
            if(!stk.empty())
                pse[i] = stk.top();
            stk.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse = fnse(arr), pse=psee(arr);
        int to=0, mod=1e9+7;
        for(int i=0;i<n;i++){
            int left=i-nse[i], right=pse[i]-i;
            int val = (1LL*arr[i]*left*right)%mod;
            to = (to+val)%mod;
        }
        return to;
    }
};