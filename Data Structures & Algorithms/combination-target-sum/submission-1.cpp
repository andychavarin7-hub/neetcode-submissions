class Solution {
   public:
    void createSumArray(int i, int csum, std::vector<int>& nums, std::vector<std::vector<int>>& res,
                        std::vector<int>& tset, int target) {
        
        //std::cout << "current values in set: ";
        //for (auto v : tset) {
        //    std::cout << v << ", ";
       // }
       // std::cout << " = " << csum << "\n";

        if (csum == target) {
            res.push_back(tset);
            return;
        }

        if (i >= nums.size() || csum > target) {
            return;
        }


        tset.push_back(nums[i]);
        createSumArray(i, csum + nums[i], nums, res, tset, target);
        
        tset.pop_back();
        createSumArray(i + 1, csum, nums, res, tset, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> tset;

        createSumArray(0, 0, nums, res, tset, target);

        return res;
    }
};
