class Solution {
public:
    int sumOfSquares(int num) {
        int sum = 0;
        while(num > 0) {
            int rem = num % 10;
            num = num / 10;
            sum += rem*rem;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSquares(sumOfSquares(n));

        while(slow != fast) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }

        return slow == 1;
    }
};
