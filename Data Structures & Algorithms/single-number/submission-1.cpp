class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0;
        for(auto v: nums){
            seenOnce = seenOnce^v;
        }

        return seenOnce;
    }
};
