class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        struct customCompare {
            bool operator()(std::pair<int, int> lhs, std::pair<int, int> rhs) {
                return lhs.second > rhs.second;
            };
        };

        std::unordered_map<int, int> freqMap{};
        std::vector<int> returnFreq;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, customCompare> mstFreq{};

        for (auto val : nums) {
            ++freqMap[val];
        }

        /* frequency map built, need to determine the most freq elements */
        for (auto [item, cnt] : freqMap) {
            mstFreq.push({item, cnt});
            if (mstFreq.size() > k) {
                mstFreq.pop();
            }
        }

        for (; !mstFreq.empty(); mstFreq.pop()) {
            returnFreq.push_back(mstFreq.top().first);
        }

        return returnFreq;
    }
};
