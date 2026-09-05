class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        std::unordered_map<std::string, std::vector<std::string>> groups;


        for(auto item: strs){
            std::string keyVal=item;
            /*constraints pose only lowercase letter, */
            std::sort(keyVal.begin(),keyVal.end());

            if(groups.find(keyVal)!=groups.end()){
                groups[keyVal].push_back(item); 
            } else{
                groups.emplace(keyVal,std::vector<std::string>{item});
            }
        }
        std::vector<std::vector<std::string>> result {};

        for(auto [_, items]: groups){
            result.push_back( std::move(items));
        }

        return result;
        
    }
};
