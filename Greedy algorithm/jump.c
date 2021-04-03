45.跳跃游戏

int jump(int* nums, int numsSize){
    if(numsSize==1)
    return 0;

    int count=0;//记录跳跃次数
    int max=0;//记录可以跳多远
    int sub=0;//记录最适宜的下标
    int i=0;

    while(i<numsSize)
    {
        if(nums[i]+i>=numsSize-1)//当前点可以直接跳往终点
           {    count++;//跳往终点也需要一步
                return count;
           }
        //不能直接跳往终点，则继续求一下个最优解

        sub=0;
        max=0;
        for(int j=1;j<=nums[i];j++)
        {
           if((nums[i+j]+j)>max)//下一步的距离加上当前步的距离达到最远处
            {
                max=nums[i+j]+j;//记录可以达到的最远距离
                sub=j;//记录跳多远
            }
        }

        count++;//跳一次
        i=i+sub;//更新到跳跃位置

    }
    return count;//更新完位置之后直接跳出了

}