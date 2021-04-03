1578.避免删除重复字母的最小删除成本

int minCost(char * s, int* cost, int costSize){
    int count=0;
    int prev_sub=0;
    int next_sub=1; 

    while(next_sub<costSize)
    {
        if(s[prev_sub]==s[next_sub])//相等
        {
            count+=(cost[prev_sub]>cost[next_sub]?cost[next_sub]:cost[prev_sub]);//删除最小的

            if(cost[prev_sub]<cost[next_sub])//删除的是前面的
            {
                prev_sub=next_sub;//防止到达中间已被删除字符
                next_sub++;
            }
            else//删除的是后面的
            {
                next_sub++;//只更新后面的坐标，防止连续多个字符出现
            }
        }
        else//不想等
        {
            prev_sub=next_sub;
            next_sub++;
        }
    }
    return count;

}