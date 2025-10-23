class Solution {
public:
    int beautySum(string s) {
        int n=s.length(),sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> fq;
            for(int j=i;j<n;j++){
                fq[s[j]]++;
                int mini=INT_MAX,maxi=INT_MIN;
                for(auto i:fq){
                    mini = min(mini,i.second);
                    maxi = max(maxi,i.second);
                }
                sum += maxi-mini;
            }
        }
        return sum;
    }
};