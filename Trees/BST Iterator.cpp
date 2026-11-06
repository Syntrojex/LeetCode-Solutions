class BSTIterator {
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

public:
    int index;
    vector<int> nums;
    BSTIterator(TreeNode* root) {
        inorder(root, nums);
        index = 0;
    }

    int next() { return nums[index++]; }

    bool hasNext() { return index < nums.size(); }
};
