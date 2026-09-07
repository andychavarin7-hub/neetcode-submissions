class Solution {
public:
    bool isHappy(int n) {
        
        std::set<int> seenValues{};
        int tmp = n;
        while(tmp !=1){
            int squareSum =0;
            while(tmp){
                int rem = tmp- (tmp/10)*10;
                squareSum += rem*rem;
                tmp = (tmp/10);
                //std::cout << "rem is:" << rem << ": square sum: " << squareSum << "\n";
            }
            tmp = squareSum;

            if (auto it = seenValues.insert(tmp); !it.second){
                return false;
            }
        }

        return true;
    }
};
