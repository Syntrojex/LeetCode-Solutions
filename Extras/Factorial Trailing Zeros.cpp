
class Solution {
public:
    int trailingZeroes(int n) {
        // Trailing zeroes are zeros that appear continuously
        // at the end (right side) of a number.
        int zeros = 0;

        while (n >= 5) {
            n /= 5;

            // Count the number of factors of 5.
            // This also accounts for extra factors from 25, 125, etc.
            zeros += n;
        }

        return zeros;
    }
};
