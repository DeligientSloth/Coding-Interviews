链接：https://www.nowcoder.com/questionTerminal/beb5aa231adc45b2a5dcc5b62c93f593
来源：牛客网

这个就是快速排序里面的分区算法，不过做了一点改变，不是直接交换，而是采用插入排序的思想，移动偶数端，找到奇数的位置再插入
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int p=-1,q=0;//p指向上一个奇数位，q遍历找到奇数位，插入到p的下一个位置中，p->q之间都是偶数
        while(q<array.size()){
            if((array[q]&1)!=0)//是奇数
            {
                //q与p+1之间交换位置，p原本指向的奇数位，p和q之间都是偶数，因此交换p的下一个偶数位
                p=p+1;
                int temp=array[q];
                for(int index=q;index-1>=p;index--) array[index]=array[index-1];
                array[p]=temp;
            }
          q++;//q继续遍历
        }
    }
};
下面这种方法是一样的：
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int pEvenIndex=0,pOddIndex=0;
        while(pEvenIndex<array.size()&&pOddIndex<array.size()){
            while(pEvenIndex<array.size()&&(array[pEvenIndex]&1)) pEvenIndex++;
            pOddIndex=pEvenIndex+1;
            while(pOddIndex<array.size()&&!(array[pOddIndex]&1)) pOddIndex++;
            if(pOddIndex<array.size())
            {
                int temp=array[pOddIndex];
                for(int k=pOddIndex;k-1>=pEvenIndex;k--) array[k]=array[k-1];
                array[pEvenIndex]=temp;
                pEvenIndex++;
            }
        }
    }
};
使用stablepartition其实是开辟了新的空间
bool isOdd(int n){ return (n&1)!=0;}
class Solution {
public:
    void reOrderArray(vector<int> &array) {
       stable_partition(array.begin(),array.end(),isOdd);
    }
};
于是写了一下开辟新的内存空间的写法，这样时间复杂度和空间复杂度都是o(n)了
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> vec;
        for(auto v:array)
            if(v&1) vec.push_back(v);
        for(auto v:array)
            if(!(v&1)) vec.push_back(v);
        array=vec;
    }
};
