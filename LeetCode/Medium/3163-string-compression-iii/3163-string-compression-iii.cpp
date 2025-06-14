class Solution {
public:
    string compressedString(string word) {
        const int n = word.length();
        string ans;
        for (int i = 0; i < n;) {
            char curr = word[i];
            int count = 0;
            while (i <= n && word[i] == curr && count < 9) {
                i++;
                count++;
            }
            ans += to_string(count) + curr;
        }
        return ans;
    }
};
