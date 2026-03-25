class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        int maxi = 1;
        for(string word:words){
            dp[word] = 1;
            for(int i=0;i<word.size();i++){
                string prev = word.substr(0,i)+word.substr(i+1);
                if(dp.count(prev))
                    dp[word] = max(dp[word],dp[prev]+1);
            }
            maxi = max(maxi, dp[word]);
        }
        return maxi;
    }
};