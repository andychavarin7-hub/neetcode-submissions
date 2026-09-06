class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> solution;
        const int sz = nums.size();

        /* sort values and skip repetitives here */
        std::sort(nums.begin(), nums.end());

        for (int it = 0; it < sz; ++it) {
            int left = it + 1;
            int right = sz - 1;

            if (it > 0 && nums[it] == nums[it - 1]) {
                continue;
            }

            while (left < right) {
                /*numbers are sorted here we can look for the sum as before*/
                int sum = nums[it] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    solution.push_back({nums[it], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }

        return solution;
    }
};
