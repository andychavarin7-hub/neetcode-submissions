class Solution {
   public:
    int characterReplacement(string s, int k) {
        std::array<int, 27> stringFreq{0};

        /*only caps letters here */
        int left = 0;
        int maxFreq = 0;

        for (int right = 0; right < s.size(); ++right) {
            ++stringFreq[s[right] - 'A']; /* my frequency map */
            maxFreq = std::max(stringFreq[s[right] - 'A'], maxFreq);
            
           //std::cout << "max freq: " << maxFreq << std::endl;
            if ((maxFreq + k) <= (right - left)) {
                /*reshrink the window */
                --stringFreq[s[left]- 'A'];
                left++;
            }

            /*established a freq range */
        }

        return ((maxFreq + k) > s.size())?  s.size(): maxFreq + k;
    }
};
