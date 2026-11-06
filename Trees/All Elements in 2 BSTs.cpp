/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums1) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, nums1);
        nums1.push_back(root->val);
        inorder(root->right, nums1);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1;
        vector<int> nums2;

        inorder(root1, nums1);
        inorder(root2, nums2);

        int size1 = nums1.size();
        int size2 = nums2.size();
        int size3 = size1 + size2;

        vector<int> nums3(size3);

        int k = 0;
        for (int i = 0; i < size1; i++) {
            nums3[k] = nums1[i];
            k++;
        }

        for (int j = 0; j < size2; j++) {
            nums3[k] = nums2[j];
            k++;
        }

        sort(nums3.begin(), nums3.end());

        return nums3;
    }
};
