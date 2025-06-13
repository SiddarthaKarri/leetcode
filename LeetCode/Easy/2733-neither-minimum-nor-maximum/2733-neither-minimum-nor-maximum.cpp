class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        // std::sort(nums.begin(), nums.end(), std::greater<int>());
        // if (nums.size() <= 2)
        //     return -1;
        // return nums[1];
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        for (auto i : nums) {
            if (i != mini && i != maxi)
                return i;
        }
        return -1;
    }
};