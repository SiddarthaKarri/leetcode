class Solution {
public:
    bool chk(vector<int> nums, int curr, int dir) {
        int n = nums.size();
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0)
                curr += dir;
            else {
                nums[curr]--;
                dir = -dir;
                curr += dir;
            }
        }
        for (int x : nums) {
            if (x != 0)
                return false;
        }
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (chk(nums, i, 1))
                    cnt++;
                if (chk(nums, i, -1))
                    cnt++;
            }
        }
        return cnt;
    }
};