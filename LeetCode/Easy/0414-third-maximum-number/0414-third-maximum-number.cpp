class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(),
                  std::greater<int>()); // descending order
        if (nums.size() <= 2)
            return nums[0];
        int cnt = 1;
        int maxx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != maxx) {
                maxx = nums[i];
                cnt++;
                if (cnt == 3)
                    return maxx;
            }
        }
        return nums[0];
    }
};