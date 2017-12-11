class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k==0) return NULL;//倒数第0各节点毫无意义
        ListNode *pAHead=pListHead,*pBehind=pListHead;
        for(int i=1;i<=k-1;i++)//k>=2,k=1时，为尾节点，phead与pbehind一个位置
            if(pAHead->next!=NULL) pAHead=pAHead->next;
            else return NULL;
        while(pAHead->next!=NULL){
            pAHead=pAHead->next;pBehind=pBehind->next;
        }
        return pBehind;
    }
};
