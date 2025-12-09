class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int md=1e9+7,sizee=nums.size(),solu=0;
        unordered_map<int,int> bak,ft;
        int q=0;
        while(q<sizee){
            ft[nums[q]]++;
            q++;
        }
        int f=0;
        while(f<sizee){
            ft[nums[f]]--;
            int hah=nums[f]*2;
            int itu=bak[hah],atu=ft[hah];
            solu=(solu+1LL*itu*atu%md)%md;
            bak[nums[f]]++;
            f++;
        }
        return solu;
    }
};