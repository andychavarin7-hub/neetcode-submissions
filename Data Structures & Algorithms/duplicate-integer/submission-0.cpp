class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniqueVals;
        for (const int val : nums) {
            auto [it,add] =uniqueVals.insert(val);
            if (add){
            } else {
                return true;
            }
        }
        return false;
    }
};