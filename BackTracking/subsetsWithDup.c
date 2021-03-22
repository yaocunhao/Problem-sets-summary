int* nums, int numsSize, int* returnSize, int** returnColumnSizes,int **ret,int *temp,int *flag,int temp_sub,int sub)
{
    //进行拷贝
    ret[*returnSize]=(int *)malloc(sizeof(int)*temp_sub);
    memcpy(ret[*returnSize],temp,temp_sub*sizeof(int));
    returnColumnSizes[0][*returnSize]=temp_sub;
    (*returnSize)++;

    for(int i=sub;i<numsSize;i++)
    {
        if(i-1>=0&&nums[i-1]==nums[i]&&flag[i-1]==0)
            continue;
        
        temp[temp_sub]=nums[i];
        flag[i]=1;//进行标记

        GetNum( nums,  numsSize, returnSize, returnColumnSizes,ret,temp,flag,temp_sub+1,i+1);
        flag[i]=0;//回溯
    }
}

int Compare(int *x,int *y)
{
    return *x-*y;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

qsort(nums,numsSize,sizeof(int),Compare);//排序

//开辟数组空间
int **ret=(int **)malloc(sizeof(int*)*2000);
*returnSize=0;
returnColumnSizes[0]=(int *)calloc(2000,sizeof(int));
int *temp=(int *)malloc(sizeof(int)*1000);
int flag[1000]={0};//标记数组

GetNum( nums,  numsSize, returnSize, returnColumnSizes,ret,temp,flag,0,0);

return ret;

}
