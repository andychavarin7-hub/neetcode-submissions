class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.size() < 1) {
            return 0;
        }
        int area = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        while (left <= right) {
            if (leftMax <= rightMax) {
                /**process left max */
                leftMax = std::max(height[left], leftMax);
                area += (leftMax - height[left]);
                left++;
            } else {
                /**process right  max */
                rightMax = std::max(height[right], rightMax);
                area += (rightMax - height[right]);
                right--;
            }
        }
        return area;
    }
};
