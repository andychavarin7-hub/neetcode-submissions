class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> search{};

        /*note that the grid is guarnteed to be at min 1,1 */

        const int rowsz = grid.size();
        const int colsz = grid[0].size();
        int maxSize =0;

        for (auto ii = 0; ii < rowsz; ++ii) {
            for (auto jj = 0; jj < colsz; ++jj) {

                int maxTemp = 0;
                if(grid[ii][jj] == 1){
                    /*found an island pop into our head */
                    search.push({ii,jj});
                    grid[ii][jj] = 0;
                    ++maxTemp;
                }
                
                while(!search.empty()){
                    auto [nrow, ncol] = search.front();
                    search.pop();

                    /*search left */
                    if( nrow > 0 && grid[nrow - 1][ncol] == 1 ){
                        ++maxTemp;
                        grid[nrow-1][ncol] = 0;
                        search.push({nrow - 1, ncol});
                    }
                    /*search left */
                    if( (nrow + 1) < rowsz && grid[nrow + 1][ncol] == 1 ){
                        ++maxTemp;
                        grid[nrow + 1][ncol] = 0;
                        search.push({nrow + 1, ncol});
                    }

                    if( ncol > 0 && grid[nrow][ncol - 1] == 1 ){
                        ++maxTemp;
                        grid[nrow][ncol - 1] = 0;
                        search.push({nrow, ncol - 1});
                    }
                    
                    if( (ncol +1) < colsz && grid[nrow][ncol + 1] == 1 ){
                        ++maxTemp;
                        grid[nrow][ncol + 1] = 0;
                        search.push({nrow, ncol + 1});
                    }
                }

                maxSize = std::max(maxSize, maxTemp);

            }
        }


        return maxSize;
    }
};
