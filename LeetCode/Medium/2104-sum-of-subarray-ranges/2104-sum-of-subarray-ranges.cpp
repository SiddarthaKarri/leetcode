class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum =
            calculateSum(nums);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= -1;
        }
        long long minSum =
            calculateSum(nums);
        return maxSum + minSum;
    }
    long long calculateSum(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> left(n,-1); // psee
        vector<int> right(n, n); //nse
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            sum += (long long)(i - left[i]) * (right[i] - i) * nums[i];
        }
        return sum;
    }
};