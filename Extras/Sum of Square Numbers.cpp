class Solution {
public:
    bool judgeSquareSum(int c) {
        int sq = sqrt(c);
        vector<long long> arr;
        
        for (int i = 0; i <= sq; i++) {
            arr.push_back(i);
        }
        
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            long long num1 = arr[left] * arr[left];
            long long num2 = arr[right] * arr[right];
            long long sum = num1 + num2;
            
            if (sum == c) {
                return true;
            } else if (sum < c) {
                left++;
            } else {
                right--;
            }
        }
        
        return false;
    }
};
