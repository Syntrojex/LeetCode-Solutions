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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> nums;

        inorder(root, nums);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }

        return true;
    }
};


/**
Node based
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& nums) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root);
        inorder(root->right, nums);
    }

    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> nums;

        inorder(root, nums);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i]->val <= nums[i - 1]->val) {
                return false;
            }
        }

        return true;
    }
};
