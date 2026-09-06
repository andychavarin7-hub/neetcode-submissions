class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /* board are always 9x9 */
        std::array<std::unordered_set<int>, 9> rowsCheck{};
        std::array<std::unordered_set<int>, 9> colCheck{};
        std::array<std::unordered_set<int>, 9> minorGrid{};

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char ch = board[row][col];
                if (ch == '.') {
                    continue;
                }

                if (auto val = colCheck[row].emplace(ch); val.second == false) {
                    return false; /*duplicate column values */
                }

                if (auto val = rowsCheck[col].emplace(ch); val.second == false) {
                    return false; /*duplicate row values */
                }

                /*check all three minor grids */
                int xycord = (col/3) + 3*(row/3); /*cheesey with the math here to determine sub grids */
                
                if (auto val = minorGrid[xycord].emplace(ch); val.second == false) {
                    return false; /*duplicate row values */
                }

            }
        }

        return true;
    }
};
