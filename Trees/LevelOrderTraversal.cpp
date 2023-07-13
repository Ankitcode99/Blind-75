class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return ans;
        
        solve(root,0);
        return ans;
    }
    void solve(TreeNode* node,int lev)
    {
        if(!node)
            return;
        if(lev==ans.size())
            ans.push_back({});
        
        ans[lev].push_back(node->val);
        solve(node->left,lev+1);
        solve(node->right,lev+1);
    }
};