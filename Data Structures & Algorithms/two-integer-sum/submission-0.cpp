class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> values;

        for (int it = 0; it < nums.size(); ++it) {
            int search = target - nums[it];

            if (values.find(search) != values.end()) {
                if (it< values[search])
                    return { it, values[search ] };
                else
                    return {values[search],it};
            } else {
                values[nums[it]] = it;
            }
        }

        return {0, 0};
    }
};
