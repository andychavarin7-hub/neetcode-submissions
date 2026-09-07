class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        /* assuming we've rolled over */
        std::vector<int> tmpResult = digits;
        std::vector<int> answer(1);

        int it = digits.size() - 1;
        ++tmpResult.back();
        while (it >0){
            if(tmpResult[it] < 10){
                break;
            }
            ++tmpResult[it - 1];
            tmpResult[it]%=10;
            --it;
        }
        if (tmpResult[0] > 9){
           answer[0] = 1;
           tmpResult[0]%=10;
           std::copy(tmpResult.begin(),tmpResult.end(), back_inserter(answer));
           return answer;

        }   

        return tmpResult;

    }
};
