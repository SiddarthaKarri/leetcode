class Solution {
public:
    int maxDifference(string s) {
        vector<int> frq(26);
        int maxi = 0, mini = s.size();
        for (char c:s) frq[c-'a']++;
        for (int i=0;i<26;i++){
            if(frq[i]%2!=0) maxi = max(maxi,frq[i]);
            if(frq[i]%2==0 && frq[i]> 0) mini = min(mini,frq[i]);
        } 
        return maxi - mini;
    }
};