316.去除重复字母

char * removeDuplicateLetters(char * s){
    int len=strlen(s);
    if(len==1)
    return s;

    int num[26]={0};
    for(int i=0;i<len;i++)//统计出现次数
    {
        num[s[i]-'a']++;
    }
    int flag[26]={0};//0表示没有入栈

    char *stack=(char *)malloc(sizeof(char)*(len+1));
    int top=0;

    for(int i=0;i<len;i++)
    {
        if(top!=0&&flag[s[i]-'a']==0&&s[i]<stack[top-1]&&num[stack[top-1]-'a']>1)//栈顶大于来的元素且栈顶元素有重复个数
            {
                 num[stack[top-1]-'a']--;//个数减1
                 flag[stack[top-1]-'a']=0;//表示栈内没有该元素
                 flag[s[i]-'a']=1;//表示栈内有了该元素

                stack[top-1]=s[i];//覆盖

                while(top>1&&stack[top-2]>stack[top-1]&&num[stack[top-2]-'a']>1)//入栈后比前面小且前面的还有
                {
                    num[stack[top-2]-'a']--;//一定要放在上面，否则位置已经换了
                    flag[stack[top-2]-'a']=0;
                    stack[top-2]=stack[top-1];
                    top--;
                }
            }
        else
        { 
            if(flag[s[i]-'a']==0)//目前栈内没有该元素则填入
           {
               stack[top++]=s[i];//填入
               flag[s[i]-'a']=1;
           }
           else
           num[s[i]-'a']--;//不入栈，个数少一个
        }   
    }
    stack[top]='\0';
    return stack;
    
}