class Solution {
   public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> str1;

        for (auto ch : s) {
            ++str1[ch];
        }
        for (auto ch : t) {
            if (str1.find(ch) == str1.end()) {
                return false;
            }
            --str1[ch];
        }

        for (auto [_, cnt] : str1) {
            if (cnt != 0) {
                return false;
            }
        }

        return true;
    }
};
