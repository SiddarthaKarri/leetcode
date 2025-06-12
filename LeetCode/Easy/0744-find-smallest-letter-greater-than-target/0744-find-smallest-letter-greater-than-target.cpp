class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size();
        char ch = '\0';
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] <= target)
                low = mid + 1;
            else {
                ch = letters[mid];
                high = mid;
            }
        }
        return (ch != '\0') ? ch : letters[0];
    }
};