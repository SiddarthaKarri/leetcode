class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        string doubles = s + s;
        return doubles.find(goal) != string::npos;
    }
};