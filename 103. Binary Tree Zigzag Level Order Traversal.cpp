class Solution {
public:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    bool ltor = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> levelValues;
        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front();
            q.pop();
            levelValues.push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        if (!ltor) {
            reverse(levelValues.begin(), levelValues.end());
        }
        ans.push_back(levelValues);
        ltor = !ltor;
    }
    return ans;
}
};
