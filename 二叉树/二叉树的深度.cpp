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
      //非递归解法
        if(pRoot==NULL) return 0;
        queue<TreeNode*> Q;
        Q.push(pRoot);
        int depth=0,nodeNumber=0;

        while(!Q.empty()){
            depth++;
            nodeNumber=Q.size();
            while(nodeNumber!=0){
                TreeNode* node=Q.front();
                Q.pop();
                if(node->left!=NULL) Q.push(node->left);
                if(node->right!=NULL) Q.push(node->right);
                nodeNumber--;
            }
        }
        return depth;
    }
};
添加笔记
