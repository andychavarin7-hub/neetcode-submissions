class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> tempStack{};
        std::vector<int> days(temperatures.size());

        for( int right =0 ; right < temperatures.size(); ++right){

            if(tempStack.empty()){
                tempStack.push({right, temperatures[right]});
            }

            while(!tempStack.empty()){

                auto [tday, ttemp] = tempStack.top();
                if(temperatures[right] > ttemp){
                    tempStack.pop();
                    days[tday] = right - tday;
                } else {
                    break;
                }
            }

            tempStack.push({right,temperatures[right]});

        }
        return days;
    }
};
