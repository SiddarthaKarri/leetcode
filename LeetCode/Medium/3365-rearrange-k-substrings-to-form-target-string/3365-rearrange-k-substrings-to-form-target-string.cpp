class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.length();
        if (n % k != 0)
            return false;
        int size = n / k;
        unordered_map<string, int> s1, t1;
        for (int i = 0; i < n; i += size) {
            string ss = s.substr(i, size);
            string tt = t.substr(i, size);
            s1[ss]++;
            t1[tt]++;
        }
        return s1 == t1;
    }
};