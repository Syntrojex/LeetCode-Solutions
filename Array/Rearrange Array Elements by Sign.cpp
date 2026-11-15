class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);

        int posIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        int negIndex = 1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] < 0) {
                ans[negIndex] = nums[j];
                negIndex += 2;
            }
        }

        return ans;
    }
};
