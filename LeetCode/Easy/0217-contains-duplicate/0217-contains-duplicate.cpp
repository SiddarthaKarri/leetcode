class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int> res(nums.begin(), nums.end());
        // return res.size() < nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};