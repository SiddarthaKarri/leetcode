class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0,cnt =0;
        for(int i:nums){
            if(i==0){
                cnt++;
                ans += cnt;
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
}; 