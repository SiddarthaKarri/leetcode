class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (char c : s) {
            int rLen = res.size();
            if (rLen > 1 && res[rLen - 1] == c &&
                res[rLen - 2] == c)
                continue;
            res.push_back(c);
        }
        return res;
    }
};