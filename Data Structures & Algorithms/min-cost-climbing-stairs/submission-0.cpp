class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        const int sz = cost.size();
        std::vector<int> cache = cost;
        for(auto ii=2; ii < cost.size(); ++ii){
            if(ii == 2){
                cache[ii] = cost[ii] + std::min(cost[0],cost[1]);
            } else{
                cache[ii] = cost[ii] + std::min(cache[ii-2], cache[ii-1]);
            }  
        }

        for(auto v: cache){
            std::cout << "min cache size is : " << v << std::endl;
        }
        /* because of our constriants we're guarnteed that cost is at minimum size 2*/

        int minCost =0;
        if(sz > 1) {
            minCost = std::min( cache[sz-1], cache[sz-2]);
        } else if (sz > 0){
            minCost = cache[sz-1];
        } else {
            /*do nothing */
        }

        return minCost;
    }
};
