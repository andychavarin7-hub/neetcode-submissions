class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        
        std::unordered_set<char> longsubstr{};
        int maxlen = 0;
        int left =0;
        for (int right = 0; right < s.size(); ++right) {
            if(auto ret = longsubstr.insert(s[right]); !ret.second){
                /*character was present in the map, advance left*/
                //std::cout << "failed int " << c << std::endl;
                while( s[left] != s[right]){
                    //std::cout << "deletion of " << s[left] << std::endl;
                    auto it = longsubstr.find(s[left]);
                    longsubstr.erase(it);
                    left++;
                }
                left++;
            }
            maxlen = std::max(maxlen, right-left + 1);
        }
        return maxlen;
    }
};
