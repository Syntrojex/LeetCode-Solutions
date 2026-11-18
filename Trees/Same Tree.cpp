class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Agar dono null hain to same hi howe na is liye true
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // Agar ek null hai aur doosra nahi ya values alag hain to false
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
