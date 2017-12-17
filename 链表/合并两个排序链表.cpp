链接：https://www.nowcoder.com/questionTerminal/d8b6b4358f774294a89de2a6ac4d9337
来源：牛客网

用递归的方法做：
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode *pNode;
        if(pHead1->val<=pHead2->val){
            pNode=new ListNode(pHead1->val);
            pNode->next=Merge(pHead1->next,pHead2);
        }
        else{
            pNode=new ListNode(pHead2->val);
            pNode->next=Merge(pHead1,pHead2->next);
        }
        return pNode;
    }
};
非递归版本
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode *pNode=NULL,*pHead=NULL;
        while(pHead1!=NULL&&pHead2!=NULL){
            if(pHead1->val<=pHead2->val){
               if(pHead==NULL){
                   pNode=new ListNode(pHead1->val);
                   pHead=pNode;
               }else{
                   pNode->next=new ListNode(pHead1->val);
                   pNode=pNode->next;
               }
                pHead1=pHead1->next;
            }
            else{
                if(pHead==NULL){
                   pNode=new ListNode(pHead2->val);
                   pHead=pNode;
               }else{
                   pNode->next=new ListNode(pHead2->val);
                   pNode=pNode->next;
               }
                pHead2=pHead2->next;
            }
        }
        if(!pHead1) pNode->next=pHead2;
        if(!pHead2) pNode->next=pHead1;
        return pHead;
    }
};
其实不需要new新的节点。。。用原来的节点就可以了：
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode *pNode=NULL,*pHead=NULL;
        while(pHead1!=NULL&&pHead2!=NULL){
            if(pHead1->val<=pHead2->val){
               if(pHead==NULL){
                   pNode=pHead1;
                   pHead=pNode;
               }else{
                   pNode->next=pHead1;
                   pNode=pNode->next;
               }
                pHead1=pHead1->next;
            }
            else{
                if(pHead==NULL){
                   pNode=pHead2;
                   pHead=pNode;
               }else{
                   pNode->next=pHead2;
                   pNode=pNode->next;
               }
                pHead2=pHead2->next;
            }
        }
        if(!pHead1) pNode->next=pHead2;
        if(!pHead2) pNode->next=pHead1;
        return pHead;
    }
};
class Solution {
public:
     ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode *pNode;
        if(pHead1->val<=pHead2->val){
            pNode=pHead1;
            pNode->next=Merge(pHead1->next,pHead2);
        }
        else{
            pNode=pHead2;
            pNode->next=Merge(pHead1,pHead2->next);
        }
        return pNode;
    }
};

class Solution {
public:
     ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
         if(!pHead1) return pHead2;
         if(!pHead2) return pHead1;
         ListNode *pNode,*pHead;
        //先建立头结点
         if(pHead1->val<=pHead2->val){
             //pHead=pHead1;
             pHead=new ListNode(pHead1->val);
             pHead1=pHead1->next;
         }else{
             //pHead=pHead2;
             pHead=new ListNode(pHead2->val);
             pHead2=pHead2->next;
         }
         pNode=pHead;
         while(pHead1!=NULL&&pHead2!=NULL){
             if(pHead1->val<=pHead2->val){
                 //pNode->next=pHead1;
                 pNode->next=new ListNode(pHead1->val);
                 pNode=pNode->next;
                 pHead1=pHead1->next;
         }else{
                 //pNode->next=pHead2;
                 pNode->next=new ListNode(pHead2->val);
                 pNode=pNode->next;
                 pHead2=pHead2->next;
             }
         }
         //检查是否还有漏下的
         while(pHead1!=NULL){
             //pNode->next=pHead1;
             pNode->next=new ListNode(pHead1->val);
             pNode=pNode->next;
             pHead1=pHead1->next;
         }
         while(pHead2!=NULL){
             //pNode->next=pHead2;
             pNode->next=new ListNode(pHead2->val);
             pNode=pNode->next;
             pHead2=pHead2->next;
         }
         return pHead;
    }
};

