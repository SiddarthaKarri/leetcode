class Solution {
public:
    char shifts(char c, int sh=1) {
        return 'a'+((c-'a'+sh)%26);
    }
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            string gen="";
            for(auto c:word)
                gen += shifts(c);
            word+=gen;
        }
        return word[k-1];
    }
};