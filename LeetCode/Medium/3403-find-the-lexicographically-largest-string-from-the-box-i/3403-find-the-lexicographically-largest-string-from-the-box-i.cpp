class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)
            return word;
        int n=word.size();
        string ans;
        for(int i=0;i<n;i++){
            int k=min(n-1,n-numFriends+1);
            string t = word.substr(i,k);
            if(t>ans)
                ans = t;
        }
        return ans;
    }
};