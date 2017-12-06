递归版本：
class Solution {
public:
int TreeDepth(TreeNode* pRoot)
{
if(pRoot==NULL) return 0;
int leftDepth=1+(pRoot->left==NULL? 0:TreeDepth(pRoot->left));
int rightDepth=1+(pRoot->right==NULL? 0:TreeDepth(pRoot->right));
return leftDepth>=rightDepth? leftDepth:rightDepth;
}
};
或者：
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        return pRoot? max(TreeDepth(pRoot->left)+1,TreeDepth(pRoot->right)+1):0;
    }
};
​非递归版本
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL) return 0;
        int leftDepth=1+(pRoot->left==NULL? 0:TreeDepth(pRoot->left));
        int rightDepth=1+(pRoot->right==NULL? 0:TreeDepth(pRoot->right));
        return leftDepth>=rightDepth? leftDepth:rightDepth;
    }
};
