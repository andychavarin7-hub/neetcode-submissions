class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        const int row_sz = grid.size();
        const int col_sz = grid[0].size();
        int nIslands = 0;

        /* note this is where i would store my x,y coordinates of my next search if
         * i happen to identify and island */

        std::queue<std::pair<int, int>> nextIsland{};

        for (int row = 0; row < row_sz; ++row) {
            for (int col = 0; col < col_sz; ++col) {
                char val =grid[row][col];

                if (val == '0') {
                    continue;
                } else {
                    /* else we've reached an island */
                    /* assuming i can replace and don't need to track a visited node list */
                    nextIsland.push({row, col});
                    grid[row][col] = '0';
                    nIslands++;
                }

                while (!nextIsland.empty()) {
                    /*search left, right, up, down */
                    auto [c_row, c_col] = nextIsland.front();
                    nextIsland.pop();

                    if (((c_row + 1) < row_sz) && grid[c_row + 1][c_col] == '1') {
                        /*island boundary */
                        nextIsland.push({c_row+1,c_col});
                        grid[c_row + 1][c_col] = '0';
                        
                    }
                    if ( c_row > 0 && grid[c_row - 1][c_col] == '1') {
                        /*island boundary */
                        nextIsland.push({c_row-1,c_col});
                        grid[c_row - 1][c_col] = '0';
                        
                    }
                    if (((c_col + 1) < col_sz) && grid[c_row][c_col + 1] == '1') {
                        /*island boundary */
                        nextIsland.push({c_row,c_col+1});
                        grid[c_row][c_col + 1] = '0';
                    }

                    if (c_col > 0 && grid[c_row][c_col - 1] == '1') {
                        /*island boundary */
                        nextIsland.push({c_row,c_col-1});
                        grid[c_row][c_col - 1] = '0';
                    }
                }
            }
        }

        return nIslands;
    }
};
