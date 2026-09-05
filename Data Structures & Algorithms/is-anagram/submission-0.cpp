class Solution {
   public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> str1;
        std::unordered_map<char, int> str2;
        for (auto ch : s) {
            ++str1[ch];
        }
        for (auto ch : t) {
            ++str2[ch];
        }

        if (str1.size() != str2.size()) return false;

        for (auto [ch, cnt] : str1) {
            if (str2.find(ch) == str2.end()) {
                return false;
            }

            if (str2[ch] != cnt) {
                return false;
            }
        }

        return true;
    };
};