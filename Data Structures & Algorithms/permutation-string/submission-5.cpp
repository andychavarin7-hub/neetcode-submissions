class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        /*we're searching for s2 in s1 */
        std::array<int, 26> search_s1{0};
        std::array<int, 26> search_s2{0};

        for (char c : s1) {
            ++search_s1[c - 'a'];
        }

        /*frequency count of s1 */
        int left = 0;
        for (int right = 0; right < s2.size(); ++right) {
            /*compute frequency count of sub string */
            left = right - s1.size();
            if (left < 0) {
                ++search_s2[s2[right] - 'a'];
            } else {
                ++search_s2[s2[right] - 'a'];
                --search_s2[s2[left] - 'a'];
            }

            if (search_s1 == search_s2) {
                return true;
            }
        }
        return false;
    }
};
