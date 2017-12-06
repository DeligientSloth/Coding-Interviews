class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL) return;
        if(pRoot->left==NULL&&pRoot->right==NULL) return;
        //if(!pRoot||(pRoot->left==NULL&&pRoot->right==NULL)) return;
        TreeNode* temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
        if(pRoot->left!=NULL) Mirror(pRoot->left);
        if(pRoot->right!=NULL) Mirror(pRoot->right);
    }
};
