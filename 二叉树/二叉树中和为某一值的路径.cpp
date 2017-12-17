构建辅助栈用深度优先查找，到达叶子节点的时候判断
class Solution {
private:
    vector<int> vec;//辅助栈，当到达叶子节点而且等于的时候，将栈内添加到返回矩阵
    vector<vector<int>> pathMatrix;
public:
    void myFindPath(TreeNode* root,int expectNumber,int cursum)
    {
        if(root==NULL) return;
        cursum+=root->val;
        vec.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){//到达叶子节点了
            if(cursum==expectNumber) pathMatrix.push_back(vec);
        }
        if(root->left!=NULL) myFindPath(root->left,expectNumber,cursum);
        if(root->right!=NULL) myFindPath(root->right,expectNumber,cursum);
        //cursum-=root->val;//可以减去可以不减去，返回时不会影响上层节点的值
        vec.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL) return pathMatrix;
        int cursum=0;
        myFindPath(root,expectNumber,cursum);
        return pathMatrix;
    }
};
参考第一位仁兄的简单写法
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
private:
    vector<int> vec;//辅助栈，当到达叶子节点而且等于的时候，将栈内添加到返回矩阵
    vector<vector<int>> pathMatrix;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL) return pathMatrix;
        vec.push_back(root->val);
        expectNumber-=root->val;//影响这一层的target值
        if((root->left==NULL&&root->right==NULL)&&expectNumber==0)
            pathMatrix.push_back(vec);
        if(root->left!=NULL) FindPath(root->left,expectNumber);
        if(root->right!=NULL) FindPath(root->right,expectNumber);
        vec.pop_back();
        return pathMatrix;
    }
};
​​