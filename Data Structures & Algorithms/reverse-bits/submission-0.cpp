class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {

        int ret = 0;
        int cnt = 0;
        while (n) {
            ret= ret| ((n&0x1)<<(31-cnt));
            cnt++;
            n = n>>1;
        }

        return ret;
    }
};
