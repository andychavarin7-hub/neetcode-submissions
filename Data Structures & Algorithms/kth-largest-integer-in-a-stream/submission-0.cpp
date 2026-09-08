class KthLargest {
   public:
    int size_k = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqueue{};

    KthLargest(int k, vector<int>& nums) {
        size_k = k;
        for (auto val : nums) {
            pqueue.push(val);
            if (pqueue.size() > size_k) {
                pqueue.pop();
            }
        }
    }

    int add(int val) {
        pqueue.push(val);
        if (pqueue.size() > size_k) {
            pqueue.pop();
        }
        return pqueue.top();
    }
};
