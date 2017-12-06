class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        int index=0,len=sequence.size();
        bool isBstLeft=true,isBstRight=true;
        while(sequence[index]<sequence[len-1]) {
            index++;//index:右子树第一个节点
        }
        while(index<=len-2)//检查右子树
        {
            if(sequence[index]<sequence[len-1]) return false;
            index++;
        }

        //0->index-1: 右子树，index->size()-2：左子树
        if(index!=0)
            isBstLeft=VerifySquenceOfBST(vector<int>(&sequence[0],&sequence[index]));
        if(index<len-1)
            isBstRight=VerifySquenceOfBST(vector<int>(&sequence[index],&sequence[len]));
        return isBstLeft&&isBstRight;

    }
};
