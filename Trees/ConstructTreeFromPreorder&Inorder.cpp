class Solution {
public:
    
    TreeNode* construct(vector<int>& preorder, int preStart, int preEnd,
                       vector<int>& inorder,int inStart, int inEnd, map<int,int>& mp){
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int elem = mp[root->val];
        int leftSubtree = elem-inStart;
        
        root->left = construct(preorder, preStart+1, preStart+leftSubtree, inorder, inStart, elem-1, mp);
        root->right = construct(preorder, preStart+leftSubtree+1, preEnd, inorder, elem+1, inEnd, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int idx=0;idx<inorder.size();idx++){
            mp[inorder[idx]]=idx;
        }
        int preStart=0, preEnd=preorder.size()-1;
        int inStart=0, inEnd=inorder.size()-1;
        
        return construct(preorder,preStart,preEnd,inorder,inStart,inEnd,mp);
    }
};