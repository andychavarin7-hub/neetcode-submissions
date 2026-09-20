class Solution {
   public:
    int search(vector<int>& nums, int target) {
        const int sz = nums.size() - 1;
        int upper = sz;
        int lower = 0;
        int mid = 0;

        while (lower < upper) {
            /*find the pivot */
            mid = (lower + upper) / 2;
            if (nums[mid] > nums[upper]) {
                lower = mid + 1;
            } else {
                upper = mid;
            }
        }
        //std::cout << "Found the pivot: " << lower << ", " << nums[lower] << "\n";
        upper = sz;
        if (target >= nums[lower] && target <= nums[upper]) {
            /*upper half */
        } else {
            /*lower half*/
            upper = lower - 1;
            lower = 0;
        }

        while (lower <= upper) {
            mid = (upper + lower) / 2;
            if (target < nums[mid]) {
                upper = mid - 1;
            } else if (target > nums[mid]) {
                lower = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
