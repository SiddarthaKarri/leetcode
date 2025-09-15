class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        bool yo=1;
        int cnt=0;
        for(int i=0;i<=text.size();i++){
            if(i==text.size() || text[i]==' '){
                if(yo)
                    cnt++;
                yo=1;
            }else{
                if(broken.count(text[i]))
                    yo=0;
            }
        }
        return cnt;
    }
};