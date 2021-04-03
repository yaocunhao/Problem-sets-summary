455.饼干分发
int Compar(int *x,int *y)
{
    return *x-*y;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
   
   qsort(g,gSize,sizeof(int),Compar);
    qsort(s,sSize,sizeof(int),Compar);

    //先满足局部最优解，即用最小的饼干，满足胃口最小的孩子
    int count=0;//计数器，记录满足了多少个孩子
    int sub=0;//孩子数组下标

    for(int i=0;i<sSize;i++)
    {
        if(sub>=gSize)//没有孩子了
        return count;

        if(s[i]>=g[sub])//当前孩子满足了
        {
            count++;
            sub++;
        }     
    }
      return count;
}