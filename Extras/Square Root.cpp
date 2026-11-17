class Solution {
public:
    int mySqrt(int x) {
        long k = 1;
        while (k * k <= x) {
            k++;
        }
        return k - 1;
    }
};
