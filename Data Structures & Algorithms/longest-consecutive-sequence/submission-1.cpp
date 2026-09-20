class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        //std::unordered_map<int, int> seqBegin{};
        std::map<int, int> seqBegin{};
        int maxLength =0;
        for (auto val : nums) {
            //std::cout << "map contents";
            //for (auto [val, cnt] : seqBegin) {
            //    std::cout << "(" << val << ", " << cnt << "), ";
            //}
            //std::cout << "\n";
            
            if (!seqBegin[val]) {
                seqBegin[val] = seqBegin[val-1] + seqBegin[val+1] + 1;
                seqBegin[val - seqBegin[val-1]] = seqBegin[val];
                seqBegin[val + seqBegin[val+1]] = seqBegin[val];
                maxLength = max(maxLength,seqBegin[val]);
            } 
        }

            //std::cout << "end map contents";
            //for (auto [val, cnt] : seqBegin) {
            //    std::cout << "(" << val << ", " << cnt << "), ";
            //}
            //std::cout << "\n";


        return maxLength;
    }
};
