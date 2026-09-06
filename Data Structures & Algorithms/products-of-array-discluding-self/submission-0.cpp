class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t inSz = nums.size();
        std::vector<int> solution(inSz,1);
        
        int prefix =1;
        int suffix =1;
        for(int ii =0; ii < inSz; ++ii){
            solution[ii] = solution[ii]*prefix;
            prefix  = prefix*nums[ii];
            
            solution[inSz-ii-1] = solution[inSz-ii-1]*suffix;
            suffix = suffix*nums[inSz - ii -1];
        }

        return solution;
    }
};
