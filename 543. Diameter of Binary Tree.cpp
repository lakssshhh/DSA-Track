class Solution {
public:
    int maxDepth(TreeNode* root, int& diameter) {
    if (!root) {
        return 0;
    }
    int left = maxDepth(root->left, diameter);
    int right = maxDepth(root->right, diameter);
    diameter = max(diameter, left + right);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
}
};
