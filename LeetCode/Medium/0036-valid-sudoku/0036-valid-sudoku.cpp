class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> box(9, vector<int>(10, 0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c=='.') continue;
                int num = c - '0';
                int boxId = (i/3)*3+(j/3);
                if (row[i][num] || col[j][num] || box[boxId][num])
                    return false;
                row[i][num] = 1;
                col[j][num] = 1;
                box[boxId][num] = 1;
            }
        }
        return true;
    }
};