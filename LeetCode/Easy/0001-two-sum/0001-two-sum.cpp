class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index;
        for (int i = 0; i < nums.size(); i++) {
            int current_num = nums[i];
            int complement = target - current_num;
            if (num_to_index.count(complement)) {
                return {num_to_index[complement], i};
            }
            num_to_index[current_num] = i;
        }
        return {};
    }
};