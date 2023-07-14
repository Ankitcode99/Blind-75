class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0,ans;
        TreeNode* curr=root;
        while(curr){
            if(curr->left == NULL){
                cnt+=1;
                if(cnt==k)
                    ans = curr->val;
                curr=curr->right;
            }else{
                TreeNode* pre = curr->left;
                while(pre->right!=NULL && pre->right!=curr){
                    pre = pre->right;
                }
                
                if(pre->right==NULL){
                    pre->right = curr;
                    curr = curr->left;
                }
                if(pre->right==curr){
                    pre->right=NULL;
                    cnt+=1;
                    if(cnt==k)
                        ans=curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};