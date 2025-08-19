class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt =0,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
                if(i==nums.size()-1)
                    ans += ((cnt*(cnt+1))/2);
            } else{
                ans += ((cnt*(cnt+1))/2);
                cnt = 0;
            }
        }
        return ans;
    }
}; 