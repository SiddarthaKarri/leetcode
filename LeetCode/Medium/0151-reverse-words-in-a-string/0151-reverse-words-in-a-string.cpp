class Solution {
public:
    string reverseWords(string s) {
        // int left = 0;
        // int right = s.length() - 1;
        // while (left <= right && s[left] == ' ') {
        //     left++;
        // }
        // while (right >= left && s[right] == ' ') {
        //     right--;
        // }

        // string temp = "";
        // string ans = "";

        // while (left <= right) {
        //     char ch = s[left];
        //     if (ch != ' ') {
        //         temp += ch;
        //     } else if (ch == ' ' && !temp.empty()) {
        //         if (!ans.empty()) {
        //             ans = temp + " " + ans;
        //         } else {
        //             ans = temp;
        //         }
        //         temp = "";
        //     }
        //     left++;
        // }
        // if (!temp.empty()) {
        //     if (!ans.empty()) {
        //         ans = temp + " " + ans;
        //     } else {
        //         ans = temp;
        //     }
        // }

        // return ans;
        int n = s.length();
        rev(s, 0, n - 1);
        int i = 0, j = 0, start = 0, end = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j++;
            if (j == n) break;
            start = i;
            while (j < n && s[j] != ' ') 
                s[i++] = s[j++];
            end = i - 1;
            rev(s, start, end);
            if (j < n)
                s[i++] = ' ';
        }
        if (i > 0 && s[i - 1] == ' ') i--;
        return s.substr(0, i);
    }
    void rev(string &s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }
};