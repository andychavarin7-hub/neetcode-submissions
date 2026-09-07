class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* assuming there wasn't (m) mem constraint where m is size of longest substr, use map to track loc */
        std::unordered_map<char,int> longsubstr{};
        int maxlen = 0;
        int left =0;

        for (int right = 0; right < s.size(); ++right) {
            if(auto ret = longsubstr.find(s[right]); ret != longsubstr.end()){
                /*find the left loc that caused this */
                left = std::max( ret->second + 1 ,left);
            }
            longsubstr[s[right]] = right;
             
            maxlen = std::max(maxlen, right-left + 1);
        }

        return maxlen;
    }
};
