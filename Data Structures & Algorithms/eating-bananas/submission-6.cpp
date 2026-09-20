class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int upperbnd = 0;
        for(auto elem: piles){
            upperbnd = std::max(upperbnd,elem);
        }

        std::cout << "max k rate is : " << upperbnd << std::endl;

        int lowerbnd = 1;
        int midbnd =0;
        int cnt = 0;
        int res =0;
        while( lowerbnd<= upperbnd){
            midbnd =  (upperbnd + lowerbnd)/2;
            //std::cout << "neew k rate is : " << midbnd;
            long long time =0;
            for(auto elem:piles){
                time += (elem + midbnd - 1)/midbnd; //round up
            }

            if(time <= h){
                /*tooo fast slow down */\
                res = midbnd;
                upperbnd = midbnd - 1;
                //std::cout << ", too fast" << std::endl;
            } else if (time > h){
                /*not fast enough */
                lowerbnd  = midbnd + 1;
                //std::cout << ", too slow" << std::endl;
            } 
        }

        return lowerbnd;    
    }

};
