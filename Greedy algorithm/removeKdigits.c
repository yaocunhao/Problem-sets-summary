移掉K位数

char * removeKdigits(char * num, int k){
   if(k==0)
   return num;
   
   int len=strlen(num);
    if(k>=len)
    return "0";

    char *stack=(char *)calloc(len,sizeof(char));
    int top=0;
    
    for(int i=0;i<len;i++)
    {
        if(top!=0&&num[i]<stack[top-1]&&k)//覆盖
        {
            stack[top-1]=num[i];
            k--;
            while(top>1&&stack[top-1]<stack[top-2]&&k)//两个相同的挨着
            {
                stack[top-2]=stack[top-1];
                top--;
                k--;
            }
        }
        else//直接填写在后面
        stack[top++]=num[i];
    }

    //已经全部入栈

    stack[top-k]='\0';
    int sub=0;
    while(sub!=top&&stack[sub]=='0')//去除前面所有的0
    {
        sub++;
    }
    if(sub==top)//栈内全是0
    return "0";
    return stack+sub; 

}
