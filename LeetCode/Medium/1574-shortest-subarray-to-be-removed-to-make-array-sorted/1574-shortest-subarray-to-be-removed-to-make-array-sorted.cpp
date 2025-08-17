class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low + 1 < n && arr[low] <= arr[low + 1])
            low++;
        if (low == n - 1)
            return 0;
        while (high > 0 && arr[high - 1] <= arr[high])
            high--;
        int cnt = min(n - low - 1, high);
        for (int l = 0, r = high; l <= low; l++) {
            while (r < n && arr[r] < arr[l])
                r++;
            cnt = min(cnt, r - l - 1);
        }
        return cnt;
    }
};