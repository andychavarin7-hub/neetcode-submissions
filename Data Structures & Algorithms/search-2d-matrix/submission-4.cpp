class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // slow O(mn) solution
        const int rowsz = matrix.size() - 1;
        const int colsz = (matrix[0].size() > 1)? matrix[0].size() - 1:0;

        // quick identification for row then  find column
        int lowPointer =0;
        int topPointer = rowsz;
        int midPointer =0;
        
        while(lowPointer <= topPointer){
            midPointer= lowPointer + (topPointer-lowPointer)/2;
            if(target < matrix[midPointer][0]){
                /*lower half, no change to lowerpointer */
                topPointer = midPointer - 1;
            } else if (target > matrix[midPointer][0]){
                /*upper half */
                lowPointer = midPointer + 1;
            } else {
                /*if we find it */
                return true;
            }
        }
        
        /*worst case look through the rows even if we didnot idenfity an existing row*/
        int tempRow = (lowPointer + topPointer)/2;
        //std::cout << "it we have found is : " << tempRow << std::endl;
       //std::cout << "it we have found is : " << ((lowPointer + topPointer)/2) << std::endl;
        //std::cout << "low we have found is : " << lowPointer << std::endl;
        //std::cout << "up we have found is : " << topPointer << std::endl;
        
        lowPointer =0;
        topPointer= colsz;

        while(lowPointer <= topPointer){
            midPointer= lowPointer + (topPointer-lowPointer)/2;
            if(target < matrix[tempRow][midPointer]){
                /*lower half, no change to lowerpointer */
                topPointer = midPointer - 1;
            } else if (target > matrix[tempRow][midPointer]){
                /*upper half */
                lowPointer = midPointer + 1;
            } else {
                /*if we find it */
                return true;
            }
        }
        return false;
    };
};
