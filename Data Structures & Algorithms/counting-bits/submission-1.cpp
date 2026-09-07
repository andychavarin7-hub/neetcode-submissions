class Solution {
public:
    vector<int> countBits(int n) {

        std::vector<int> retBits(n+1);
        int prev=0;

        for(auto ii =1; ii<=n; ii++){
            retBits[ii] =((retBits[ii>>1] + (int)(ii&0x1) ));
        }
        return retBits;
    }
};
