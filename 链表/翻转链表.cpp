class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL) return NULL;
        ListNode *pCur=pHead,*pPrev=NULL,*pNext=pHead->next;
        while(pCur!=NULL){
            pNext=pCur->next;
            pCur->next=pPrev;//不改变指向，只改变值
            pPrev=pCur;
            pCur=pNext;
        }
        return pPrev;
    }
};
