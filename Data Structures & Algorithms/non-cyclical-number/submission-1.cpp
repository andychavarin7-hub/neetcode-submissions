class Solution {
   public:
    int squaredSum(int n) {
        int squareSum = 0;
        while (n) {
            int rem = n - (n / 10) * 10;
            squareSum += rem * rem;
            n = (n / 10);
        }
        return squareSum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = squaredSum(slow);
        while (slow != 1 && slow != fast) {
           slow = squaredSum(slow);
           fast = squaredSum(fast);
           fast = squaredSum(fast);
        }

        return (slow == 1)? true:false;
    }
};
