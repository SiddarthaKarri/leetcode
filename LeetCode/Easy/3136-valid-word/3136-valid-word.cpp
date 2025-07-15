class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return 0;
        bool cons = 0, vo = 0;
        for(char c : word) {
            if(!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
                return 0;
            if(c >= 'A' && c <= 'Z') 
                c = c + ('a' - 'A');
            if((c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
                cons = 1;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
                vo = 1;
        }
        if(!vo || !cons) 
            return 0;
        return 1;
    }
};
