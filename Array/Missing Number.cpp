class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int total_sum = n * (n + 1) / 2;
        int present_sum = 0;

        for (int i : nums) {
            present_sum += i;
        }

        return total_sum - present_sum;
    }
};


missing number
