class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> preSumMap;
        preSumMap[0] = 1;
        long long sum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            long long rem = sum-k;
            if(preSumMap.find(rem) != preSumMap.end())
                cnt += preSumMap[rem];
            preSumMap[sum]++;
        }
        return cnt;
    }
};