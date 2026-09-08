class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        std::priority_queue<int,std::vector<int>,std::less<int>> stoneQueue;

        for(auto s:stones){
            stoneQueue.push(s);
        }
        int h1 = 0;
        int h2 = 0;
        while(stoneQueue.size() >=2){

            h1 = stoneQueue.top();
            stoneQueue.pop();
            
            h2 = stoneQueue.top();
            stoneQueue.pop();

            if(h1 == h2){
                continue;
            } else {
                int nweight = (h1>h2)? h1-h2: h2-h1;
                stoneQueue.push(nweight);
            }
        }
        return stoneQueue.empty()? 0: stoneQueue.top();
    }
};
