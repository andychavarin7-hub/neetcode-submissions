class Solution {
public:
    int hammingWeight(uint32_t n) {

        /*val is alreayd unsigned */
        int ret =0;
        while(n){
            ret += n&0x01;
            n=n>>1;
        }

        return ret;
    }
};
