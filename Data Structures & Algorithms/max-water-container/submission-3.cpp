class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        std::vector<int>::iterator itLft = height.begin();
        std::vector<int>::iterator itRgt = height.end() -1 ;

        while (itRgt > itLft) {
            maxArea = std::max(maxArea, std::min(*itLft, *itRgt)*static_cast<int>(itRgt -itLft));

            /*if left >right we should increase the right until we have a matching height */
            /* if left < right we should increase left until we have a matching height */
            if (*itLft< *itRgt) {
                    ++itLft;
            } else {
                --itRgt;
            }
            
        }
        return maxArea;
    }
};
