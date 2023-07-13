
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool identical=true;
        solve(p,q,identical);
        return identical;
    }
    
    bool solve(TreeNode* p, TreeNode* q, bool& identical){
        if((p==NULL && q) || (p && q==NULL))
            return identical=false;
        if(p==NULL && q==NULL)
            return true;
        if(p->val!=q->val)
            return identical = false;
        
        bool left = solve(p->left,q->left,identical);
        bool right = solve(p->right,q->right,identical);
        
        if(!left || !right)
            return identical = false;
        return true;
    }
};