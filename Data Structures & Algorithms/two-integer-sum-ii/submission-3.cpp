class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        /* values are in increasing order, no add space allowed */
        /* our constraints impose numbers has at least 2 elems */
        int left =0;
        int right = numbers.size() - 1;
        int diff;
        
        while(left < right){
            diff = numbers[left] + numbers[right] - target;
            if(diff > 0) { 
                --right;  
            } else if (diff < 0){
                ++left;
            } else {
                /*we found the values*/
                return {left + 1,right + 1};
            }
        }
        return {0,0};
    }
};
