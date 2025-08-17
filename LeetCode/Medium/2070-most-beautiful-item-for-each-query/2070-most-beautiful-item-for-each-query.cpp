class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        for (int i = 1; i < items.size(); i++)
            items[i][1] = max(items[i - 1][1], items[i][1]);
        int num = queries.size();
        vector<int> res(num);
        for (int i = 0; i < num; i++) {
            int left = 0, right = items.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (items[mid][0] > queries[i])
                    right = mid;
                else
                    left = mid + 1;
            }
            if (left > 0)
                res[i] = items[left - 1][1];
        }

        return res;
    }
};