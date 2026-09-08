class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        std::stack<int> values {};

        for(auto s: tokens){
            if(s == "+" || s == "*" || s =="-" || s == "/"){
                if(values.size() > 1 ){
                    int a = values.top();
                    values.pop();
                    int b = values.top();
                    values.pop();
                    if(s == "+"){
                        b = b + a;
                    } else if(s == "*"){
                        b = b * a;
                    } else if(s == "-"){
                        b = b - a;
                    } else{
                        b =b / a;
                    }
                    values.push(b);
                } else{
                    break;
                }
            } else {
                values.push(std::atoi(s.c_str()));
            }

        }
        return values.top();
    }
};
