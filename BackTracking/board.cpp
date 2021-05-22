#include <iostream>
#include <vector>
using namespace std;

void board(vector<vector<int>>&arr,int row,int col,vector<int>&ret,vector<int>&temp)
{
    if(row<0||row>=arr.size()||col<0||col>=arr[0].size()||arr[row][col]==1)
            return ;//越界或者遇到墙壁

    //将当前坐标添加进去
    ret.push_back(row);
    ret.push_back(col);
    
  if((row==arr.size()-1)&&(col==arr[0].size()-1))//到达最终位置
  {
      temp=ret;
      return ;
  }
    
    
    board(arr,row+1,col,ret,temp);//往下走
    board(arr,row,col+1,ret,temp);//往右走
    
    //回溯
    ret.pop_back();
    ret.pop_back();
}


int main()
{
    int row,col;
    while(cin>>row)
    {
        cin>>col;
        vector<vector<int>>arr(row,vector<int>(col,0));
        int num;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>num;
                arr[i][j]=num;
            }
        }
        
        vector<int> ret;
        vector<int> temp;
        board(arr,0,0,temp,ret);
        
        for(int i=0;i<ret.size();i+=2)
        {
            cout<<"("<<ret[i]<<","<<ret[i+1]<<")"<<endl;
        }
    }
    return 0;
}