class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() -1;
        int mid = lower + (upper-lower)/2;
        

        while(lower<= upper ){
            mid = lower + (upper-lower)/2;
            if ( target < nums[mid]){
                /*lower bound remains */
                upper = mid - 1;

            } else if (target > nums[mid]){
                lower = mid + 1;
            } else {
                /*target found*/
                return mid;
            }   
        }
        
        return -1;
    }
};
