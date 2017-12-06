class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()!=vin.size()) cout<<"输入有错"<<endl;
        if(pre.empty()||vin.empty()) return NULL;
        int index=0,len=pre.size();
        while(index!=len&&vin[index]!=pre[0]) index++;
        if(index==len) return NULL;
        TreeNode* node=new TreeNode(pre[0]);
        node->left=reConstructBinaryTree(vector<int>(&pre[1],&pre[index+1]),vector<int>(&vin[0],&vin[index]));
        node->right=reConstructBinaryTree(vector<int>(&pre[index+1],&pre[len]),vector<int>(&vin[index+1],&vin[len]));
        return node;
    }
};

class Solution {
public:
    TreeNode* reConstruct(vector<int> pre,vector<int> vin,int pbegin,int vbegin,int lenTree){
        if(lenTree==0) return NULL;
        int index=0;
        while((index+vbegin)!=lenTree&&vin[vbegin+index]!=pre[pbegin]) index++;
        if(index==lenTree) return NULL;
        TreeNode* node=new TreeNode(pre[pbegin]);
        node->left=reConstruct(pre,vin,pbegin+1,vbegin,index);
        node->right=reConstruct(pre,vin,pbegin+index+1,vbegin+index+1,lenTree-index-1);
        return node;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstruct(pre,vin,0,0,pre.size());
    }
};

class Solution {
public:
     TreeNode* reConstruct(vector<int> pre,vector<int> vin,int pbegin,int vbegin,int lenTree){
        if(lenTree<=0) return NULL;
        int index=0;
        while(index!=lenTree&&vin[vbegin+index]!=pre[pbegin]) index++;
        if(index==lenTree) {cout<<"输入有错"<<endl;return NULL;}
        TreeNode* node=new TreeNode(pre[pbegin]);
        node->left=index>0? reConstruct(pre,vin,pbegin+1,vbegin,index):NULL;
        node->right=lenTree>index-1? reConstruct(pre,vin,pbegin+index+1,vbegin+index+1,lenTree-index-1):NULL;
        return node;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
         return reConstruct(pre,vin,0,0,pre.size());
    }
};
