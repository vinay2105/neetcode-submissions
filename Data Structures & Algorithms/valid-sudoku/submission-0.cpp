class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<int>> r;
        unordered_map<int, unordered_set<int>> c;
        unordered_map<int, unordered_set<int>> s;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') 
                    continue;

                int n = board[i][j] - '0';

                int box = (i / 3) * 3 + (j / 3);

                if(r[i].find(n) != r[i].end() ||
                   c[j].find(n) != c[j].end() ||
                   s[box].find(n) != s[box].end()) {
                    return false;
                }

                r[i].insert(n);
                c[j].insert(n);
                s[box].insert(n);
            }
        }

        return true;
    }
};