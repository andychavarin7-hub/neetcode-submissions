class Solution {
public:
    int findMin(vector<int> &nums) {

        int lwbnd  = 0;
        int upbnd  = nums.size() -1;
        int midpnt = (upbnd + lwbnd)/2;
        int min = INT_MAX;
        int cnt =0;
        /*determine upper or lower half*/
        while(lwbnd <= upbnd){
            //std::cout << "upbnd  is: (" << upbnd <<": " << nums[upbnd] << "), ";
            //std::cout << "lwbnd  is: (" << lwbnd <<": " << nums[lwbnd] << "), ";
            //std::cout << "midpnt is: (" << midpnt <<": " << nums[midpnt] << ")\n";

            midpnt = (upbnd + lwbnd)/2;
            
            if( nums[midpnt] > nums[upbnd]){
                /*search this half */
                lwbnd = midpnt+1;
            } else {
                upbnd = midpnt -1;
            }
            min = std::min(min, nums[midpnt]);            
        }
       
        //std::cout << "final upbnd  is: (" << upbnd <<": " << nums[upbnd] << "), ";
        //std::cout << "lwbnd  is: (" << lwbnd <<": " << nums[lwbnd] << "), ";
        //std::cout << "midpnt is: (" << midpnt <<": " << nums[midpnt] << ")\n";



        return min;
    }
};
