class Solution {
public:
    int maxProfit(vector<int>& prices) {

        /*sliding window approach. */
        int left = 0;
        int right =0;
        int maxProfit =0;

        for(int i =1; i< (prices.size()); ++i){
            
            if( prices[i] < prices[left]){
                /*advance the window found a lower sale price */
                left = i;
                right = i;
            }

            if(prices[i]> prices[right]){
                /*found a higher sale price*/
                right = i;
            }
            maxProfit = std::max(prices[right] - prices[left], maxProfit);
        }

        return maxProfit;
    }
};
