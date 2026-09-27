class Solution {
public:
    void solve(TreeNode* root, vector<int>& res, int lvl) {
        if (root == NULL) {
            return;
        }

        if (res.size() == lvl) {
            res.push_back(root->val);
        }

        solve(root->right, res, lvl + 1);
        solve(root->left, res, lvl + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        solve(root, res, 0);
        return res;
    }
};
