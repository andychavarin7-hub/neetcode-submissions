class Solution {
public:
    std::vector<std::vector<int>> result;
    int inSz = 0;
    void genSubSets(int i, std::vector<int> &nums, std::vector<int> tset){

        if( i == inSz){
            result.push_back(tset);
            return;
        }

        tset.push_back(nums[i]);
        
        genSubSets(i+1,nums,tset);
        while( ((i+ 1) < inSz) && (nums[i]== nums[i+1])){
            ++i;
        }
        tset.pop_back();
        genSubSets(i+1,nums,tset);
        

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        inSz = nums.size();

        std::sort(nums.begin(),nums.end());
        std::vector<int> tset;

        genSubSets(0,nums,tset);
        return result;
    }
};
