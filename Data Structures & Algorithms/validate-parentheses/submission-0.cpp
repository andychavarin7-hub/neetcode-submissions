class Solution {
public:
    bool isValid(string s) {
        std::stack<char> validParan {};
        std::unordered_map <char,char> paranMap {
            {'}', '{'},{')','('},{']','['}
        };

        for(char c: s){
            if(c == '(' || c == '[' || c == '{'){
                validParan.push(c);
            } else if(validParan.empty()){
                return false;
            } else{
                char match = paranMap[c];

                if(validParan.top()!= match){
                    return false;
                } else{
                    validParan.pop();
                 }
            }
        }

        return validParan.empty();
        
    }
};
