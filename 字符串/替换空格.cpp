链接：https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423?toCommentId=1119873
来源：牛客网

要是开辟新的空间的话会超出内存，所以什么新建什么队列就算了
class Solution {
public:
void replaceSpace(char *str,int length) {
//参数检查
if(str==NULL||length==0) return;
//不能开辟新的空间，只能从后往前替换
int numBlank=0,originLength=0,newLength,i=0;
while(str[i]!='\0'){
originLength++;
if(str[i]==' ') numBlank++;
++i;
}
newLength=originLength+numBlank*2;
if(newLength>length) return;
while(newLength>originLength&&originLength>=0){//相等时无需替换了,old初始位置为'\0'，这个位置也要替换
if(str[originLength]!=' ') str[newLength--]=str[originLength];
else{
str[newLength--]='0';
str[newLength--]='2';
str[newLength--]='%';
}
originLength--;
}
}
};
纯指针操作的话：
class Solution {
public:
void replaceSpace(char *str,int length) {
//参数检查
if(str==NULL||length==0) return;
//不能开辟新的空间，只能从后往前替换
char *p=str,*q=str;
while(*p!='\0'){
if(*p==' ') q+=2;
p++;q++;
}
while(p<q&&p>=str){
if(*p!=' ') *(q--)=*(p--);
else{
*(q--)='0';
*(q--)='2';
*(q--)='%';
p--;
}
}
}
};

来个简单点的，就是空间复杂度提高了
class Solution {
public:
void replaceSpace(char *str,int length) {
//参数检查
if(str==NULL||length==0) return;
//不能开辟新的空间，只能从后往前替换
vector<char> vec;
int i=0,index=0;
for(i=0;str[i]!='\0';i++) vec.push_back(str[i]);//i是长度
for(int j=0;j<i;j++)
{
if(vec[j]!=' ') str[index++]=vec[j];
else{
str[index++]='%';
str[index++]='2';
str[index++]='0';
}
}
str[index]='\0';
}
};
要从前到后 o(n*n)复杂度的话效果也还可以
class Solution {
public:
    void replaceSpace(char *str,int length) {
        //参数检查
        if(str==NULL||length==0) return;
        //不能开辟新的空间，只能从后往前替换
       for(int i=0;str[i]!='\0';){
           if(str[i]==' '){
               //进行移位
               for(int j=strlen(str)+2;j-2>i;j--)
                   str[j]=str[j-2];
               str[i++]='%';
               str[i++]='2';
               str[i++]='0';
           }
           else i++;
       }
    }
};
