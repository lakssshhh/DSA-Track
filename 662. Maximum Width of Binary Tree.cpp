class Solution {
public:
 typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,ll>>q;
       q.push({root,0});
       ll maxWidth = 0;
       while(!q.empty()){
        ll L = q.front().second;
        ll R = q.back().second;
        maxWidth = max(maxWidth,R-L+1);
       
       int n = q.size();
       while(n--){
        TreeNode* curr = q.front().first;
        ll idx = q.front().second;
        q.pop();
        if(curr->left){
            q.push({curr->left,2*idx+1});
        }
        if(curr->right){
            q.push({curr->right,2*idx+2});
        }
       }
       }
      return maxWidth;

    }
};
