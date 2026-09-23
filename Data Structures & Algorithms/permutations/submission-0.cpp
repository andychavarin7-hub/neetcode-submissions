class Solution {
   public:
    std::vector<std::vector<int>> result;
    int inSz = 0;

    void permutation(int i, vector<int>& nums, vector<int>& tset, std::vector<bool>& choose) {
        if (tset.size() == inSz) {
            result.push_back(tset);
            return;
        }

        for (int i = 0; i < inSz; ++i) {
            if (!choose[i]) {
                choose[i] = true;
                tset.push_back(nums[i]);
                permutation(1, nums, tset, choose);
                tset.pop_back();
                choose[i] = false;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        inSz = nums.size();
        std::vector<int> tset;
        std::vector<bool> choose(inSz,false);
        permutation(0, nums, tset, choose);
        return result;
    }
};
