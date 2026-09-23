class Solution {
public:
    std::vector<std::vector<int>> res;
    int cTarget = 0;

    void recursiveSum(int csum, int i, std::vector<int>& nums, std::vector<int> &tset) {

        //std::cout << "val: ";
        //for(auto v:tset){
        //    std::cout << v << ", ";
        //}
        //std::cout << " = " << csum << std::endl;

        if(csum == cTarget){
            res.push_back(tset);
            return;
        }

        if ( i >=nums.size() || csum > cTarget){
            return;
        }




        tset.push_back(nums[i]);
        recursiveSum(csum+nums[i],i+1,nums,tset);

        tset.pop_back();
        while( (i+1) < nums.size() && nums[i]==nums[i+1]){
            ++i;
        }
        recursiveSum(csum,i+1,nums,tset);

    };

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<int> tset;
        cTarget =target;
        std::sort(candidates.begin(),candidates.end());
        recursiveSum(0,0,candidates,tset);

        return res;
    }
};
