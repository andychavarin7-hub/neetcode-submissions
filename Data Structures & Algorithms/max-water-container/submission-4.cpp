class Solution {
public:
    int maxArea(vector<int>& heights) {

        int maxVal = 0;

        /*height length is a minimum 2 */
        int left = 0;
        int tmpHeight = 0;
        int right = heights.size() -1;


        while(left<right){
            tmpHeight = std::min(heights[left],heights[right]);
            maxVal = std::max(maxVal, tmpHeight*(right - left));

            /*if left >right we should increase the right until we have a matching height */
            /* if left < right we should increase left until we have a matching height */

            if( heights[left]< heights[right]){
                left++;
            } else{
                right--;
            }
        }

        return maxVal;
        
    }
};
