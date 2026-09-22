class Solution {
public:

    void createSubSet(int i, std::vector<int>&nums, std::vector<std::vector<int>>& res, std::vector<int> &subset){

        if(nums.size() == i){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        createSubSet(i + 1,nums,res,subset);

        subset.pop_back();
        createSubSet(i + 1,nums,res,subset);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> subset;
        createSubSet(0,nums,result,subset);

        return result;
    }
};
