class Solution {
public:
    bool SymmetyLeftRight(TreeNode* left,TreeNode* right)
    {
        if(left==NULL&&right==NULL) return true;//两个都为空
        if(left==NULL||right==NULL) return false;//只有一个为空
        return left->val==right->val&&SymmetyLeftRight(left->left,right->right)&&SymmetyLeftRight(left->right,right->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL) return true;//树是空树
        return SymmetyLeftRight(pRoot->left,pRoot->right);
    }

};
