class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res=0,cur=0,s=0;
        unordered_set<int> see;
        for(int e=0;e<nums.size();e++){
            while(see.find(nums[e]) != see.end()){
                see.erase(nums[s]);
                cur -= nums[s];
                s++;
            }
            cur += nums[e];
            see.insert(nums[e]);
            res = max(res,cur);
        }
        return res;
    }
};