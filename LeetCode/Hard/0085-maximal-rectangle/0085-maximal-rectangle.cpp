class Solution {
public:
     int maxInHistogram(vector<int>& arr) {
        stack<int> st;
        int maxA = 0;
        int n = arr.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int height = arr[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return 0;
        int col = matrix[0].size();
        vector<int> psum(col, 0);
        int maximum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1')
                    psum[j]++;
                if (matrix[i][j] == '0')
                    psum[j] = 0;
            }
            maximum = max(maximum, maxInHistogram(psum));
        }
        return maximum;
    }
};