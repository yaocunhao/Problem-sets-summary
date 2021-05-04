岛屿数量


class Solution {
public:

    void Lable(vector<vector<char>> &grid,int x,int y)
    {
        if(x<0||x>=grid.size()||y>=grid[x].size()||grid[x][y]!='1')//不满足条件剪枝
            return ;

        grid[x][y]='2';
        //往四个方向走
        Lable(grid,x-1,y);
        Lable(grid,x+1,y);
        Lable(grid,x,y-1);
        Lable(grid,x,y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    Lable(grid,i,j);
                }
            }
        }

        return count;
    }
};