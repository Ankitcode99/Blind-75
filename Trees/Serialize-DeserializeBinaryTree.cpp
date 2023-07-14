class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";

        if(root==NULL)
            return ans;

        ans+=to_string(root->val)+",";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto curr = q.front();
            q.pop();

            if(!curr->left){
                ans+="#,";
            }else{
                ans += to_string(curr->left->val)+",";
                q.push(curr->left);
            }

            if(!curr->right){
                ans+="#,";
            }else{
                ans += to_string(curr->right->val)+",";
                q.push(curr->right);
            }
        }

        cout<<ans<<" ";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       
        if(data.size()==0)
            return NULL;

        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};