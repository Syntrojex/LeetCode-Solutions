class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result; // Base case agar tree khali ho

        vector<int> nums;
        inorder(root, nums);

        int maxFreq = 0;
        int currentFreq = 0;
        int currentNum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            // Agar same number chal raha hai to frequency++
            if (nums[i] == currentNum) {
                currentFreq++;
            } else {
                // Naya number shuru hua, to purane wale ki frequency check karo aur naye par switch karo
                currentNum = nums[i];
                currentFreq = 1;
            }

            // Agar yeh ab tak ka sab se zyada anay wala number hai
            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
                result.clear(); // Purane saare modes khatam, kyunke naya king mil gaya
                result.push_back(currentNum);
            } 
            // Agar yeh bhi barabar dafa aaya hai jitna pehle wala aaya tha
            else if (currentFreq == maxFreq) {
                result.push_back(currentNum);
            }
        }

        return result;
    }
};
