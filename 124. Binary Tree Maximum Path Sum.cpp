class Solution {
public:
    int maxPathSum(TreeNode* root, int& maxsum) {
        if (!root) {
            return 0;
        }
        int left = max(maxPathSum(root->left, maxsum), 0);
        int right = max(maxPathSum(root->right, maxsum), 0);
        maxsum = max(maxsum, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        maxPathSum(root, maxsum);
        return maxsum;
    }
};
