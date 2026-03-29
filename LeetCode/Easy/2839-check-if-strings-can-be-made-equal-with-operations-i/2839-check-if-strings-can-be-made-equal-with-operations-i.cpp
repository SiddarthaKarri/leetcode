class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string s11 = s1;
        swap(s11[0],s11[2]);
        if(s11 == s2) 
            return true;
        s11 = s1;
        swap(s11[1], s11[3]);
        if(s11 == s2) 
            return true;
        s11 = s1;
        swap(s11[0], s11[2]);
        swap(s11[1], s11[3]);
        if(s11 == s2) 
            return true;
        return s1 == s2;
    }
};