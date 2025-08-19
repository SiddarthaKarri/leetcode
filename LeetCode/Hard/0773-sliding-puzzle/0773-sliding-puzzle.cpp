class Solution {
public:
    int directions[4] = {-1, 1, -3, 3};
    string target = "123450";
    string boardToString(const vector<vector<int>>& board) {
        string result = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++)
                result += to_string(board[i][j]);
        }
        return result;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = boardToString(board);
        if (start == target)
            return 0;
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({start, 0});
        visited.insert(start);
        while (!q.empty()) {
            auto [current, moves] = q.front();
            q.pop();
            int zeroPos = current.find('0');
            for (int dir : directions) {
                int newPos = zeroPos + dir;
                if (newPos < 0 || newPos >= 6 || (dir == -1 && zeroPos % 3 == 0) || (dir == 1 && zeroPos % 3 == 2))
                    continue;
                string next = current;
                swap(next[zeroPos], next[newPos]);
                if (next == target)
                    return moves + 1;
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};