class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> mpp(26);
        for (int i = 0; i < 26; i++)
            mpp[i] = 'a' + i;
        for (int r = 0; r < 26; r++) {
            for (int i = 0; i < s1.length(); ++i) {
                char c1 = mpp[s1[i] - 'a'],c2 = mpp[s2[i] - 'a'];
                char smallest = min(c1, c2),largest = max(c1, c2);
                for (int j = 0; j < 26; j++)
                    if (mpp[j] == largest)
                        mpp[j] = smallest;
            }
        }
        string res;
        for (char c : baseStr)
            res += mpp[c - 'a'];
        return res;
    }
};