class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = INT_MIN;

        int currWater = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int width = right - left;

            int h = min(height[left], height[right]);

            currWater = width * h;

            maxWater = max(currWater, maxWater);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
