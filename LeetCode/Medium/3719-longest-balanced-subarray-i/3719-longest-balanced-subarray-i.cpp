class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxLn=0,n=nums.size();
        for(auto l=0;l<n;l++){
            unordered_set<int> even,odd;
            for(int r=l;r<n;r++){
                if(nums[r]%2==0)
                    even.insert(nums[r]);
                else
                    odd.insert(nums[r]);
                if(even.size()==odd.size())
                    maxLn= max(maxLn,r-l+1);
            }
        }
        return maxLn;
    }
};