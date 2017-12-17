class Solution {
public:
    bool SubTreeMatch(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2==NULL) return true;
        if(pRoot1==NULL) return false;
        if(pRoot1->val!=pRoot2->val) return false;
        return SubTreeMatch(pRoot1->left,pRoot2->left)&&SubTreeMatch(pRoot1->right,pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL||pRoot2==NULL) return false;
        bool result=false;
        result=SubTreeMatch(pRoot1,pRoot2);
        if(result==false) result=HasSubtree(pRoot1->left,pRoot2);
        if(result==false) result=HasSubtree(pRoot1->right,pRoot2);
        return result;
    }
};