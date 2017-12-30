链接：https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5?toCommentId=1128352
来源：牛客网

class Solution {
public:
TreeNode* Convert(TreeNode* pRootOfTree)
{
/*
1.采用中序遍历的思想，递归处理左子树，使其成为双向链表，返回头结点，即最右边的节点，最小
2.找到左子树链表最右边的节点，让根节点的left指针指向她，该点的right指针指向根节点
3.递归处理右子树，使其成为双向链表，返回头结点，即最左边的节点，最小
4.找到右子树链表最左边的节点（不需要找），让根节点的right指针指向她，该节点的left指针指向她
最后返回的头结点是左子树双向链表的头结点
*/
//叶子节点或者空节点直接返回
if(pRootOfTree==NULL||(pRootOfTree->left==NULL&&pRootOfTree->right==NULL)) return pRootOfTree;
TreeNode *leftHead=NULL,*rightHead=NULL,*p=NULL;
if(pRootOfTree->left!=NULL)
leftHead=Convert(pRootOfTree->left);//返回左子树链表头结点
if(leftHead!=NULL){
p=leftHead;//用p来找到最右边的节点
while(p->right!=NULL) p=p->right;
pRootOfTree->left=p;
p->right=pRootOfTree;
}
if(pRootOfTree->right!=NULL)
rightHead=Convert(pRootOfTree->right);
if(rightHead!=NULL){
pRootOfTree->right=rightHead;
rightHead->left=pRootOfTree;
}
return leftHead!=NULL? leftHead:pRootOfTree;
}
};
class Solution {
private:
    TreeNode* ListLastNode;//新增一个节点，表示最后一个节点，左子树最后一个节点
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        /*
        1.采用中序遍历的思想，递归处理左子树，使其成为双向链表，返回头结点，即最右边的节点，最小
        2.找到左子树链表最右边的节点，让根节点的left指针指向她，该点的right指针指向根节点
        3.递归处理右子树，使其成为双向链表，返回头结点，即最左边的节点，最小
        4.找到右子树链表最左边的节点（不需要找），让根节点的right指针指向她，该节点的left指针指向她
        最后返回的头结点是左子树双向链表的头结点
        */
        //叶子节点或者空节点直接返回
        if(pRootOfTree==NULL) return NULL;
        if(pRootOfTree->left==NULL&&pRootOfTree->right==NULL){
            //根为叶子节点，此时最后一个节点就是他自己啦
            ListLastNode=pRootOfTree;return pRootOfTree;
        }
        TreeNode *leftHead=NULL,*rightHead=NULL,*p=NULL;
        if(pRootOfTree->left!=NULL)
            leftHead=Convert(pRootOfTree->left);//返回左子树链表头结点
        if(leftHead!=NULL){
            /*p=leftHead;//用p来找到最右边的节点
            while(p->right!=NULL) p=p->right;
            pRootOfTree->left=p;
            p->right=pRootOfTree;*/
            pRootOfTree->left=ListLastNode;
            ListLastNode->right=pRootOfTree;
        }
        ListLastNode=pRootOfTree;//变为根节点
        if(pRootOfTree->right!=NULL)
            rightHead=Convert(pRootOfTree->right);
        if(rightHead!=NULL){
            pRootOfTree->right=rightHead;
            rightHead->left=pRootOfTree;
        }
        return leftHead!=NULL? leftHead:pRootOfTree;
    }
};


class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return NULL;
        //非递归中序遍历
        TreeNode *prev=NULL,*head=NULL,*p=pRootOfTree;//p是指示指针
        stack<TreeNode*> S;
        while(true){
            //沿着左子树下行
            while(p!=NULL){
                S.push(p);p=p->left;
            }
            if(S.empty()) break;
            p=S.top();//此次要遍历的节点
            S.pop();
            //处理头结点
            if(head==NULL) head=p;
            else{
                prev->right=p;
                p->left=prev;
            }
            prev=p;//记录当前节点作为下一次的当前节点
            p=p->right;//调用同样的模块处理右子树
        }
        return head;
    }
};