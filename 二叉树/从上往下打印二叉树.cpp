class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<int> result;
        if(root!=NULL) Q.push(root);
        while(Q.empty()==false)
        {
            TreeNode* node=Q.front();
            result.push_back(node->val);
            Q.pop();
            if(node->left!=NULL) Q.push(node->left);
            if(node->right!=NULL) Q.push(node->right);
        }
        return result;
    }
};
