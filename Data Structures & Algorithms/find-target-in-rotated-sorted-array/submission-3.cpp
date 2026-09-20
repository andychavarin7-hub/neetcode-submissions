class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int upper = nums.size() - 1;
        int lower = 0;
        int mid = 0;
        int found = -1;

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
        int pvt = lower;
        upper = nums.size() - 1;
        lower = 0;
        if (target >= nums[pvt] && target <= nums[upper]) {
            /*upper half */
            lower = pvt;
        } else {
            /*lower half*/
            upper = pvt - 1;
        }

        while (lower <= upper) {
            mid = (upper + lower) / 2;

            if (target < nums[mid]) {
                upper = mid - 1;
            } else if (target > nums[mid]) {
                lower = mid + 1;
            } else {
                found = mid;
                break;
            }
        }

        return found;
    }
};
