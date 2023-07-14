
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        if (isIdentical(root, subRoot)) {
            return true;
        } 

        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if (!root or !subRoot) {
            return root == nullptr and subRoot == nullptr;
        }

        return root->val == subRoot->val and isIdentical(root->left, subRoot->left) and isIdentical(root->right, subRoot->right);
    }
};