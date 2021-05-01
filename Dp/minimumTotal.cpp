三角形最小路径和

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j==0)
                triangle[i][j]+=triangle[i-1][j];
                else if(j==triangle[i].size()-1)
                triangle[i][j]+=triangle[i-1][j-1];
                else
                triangle[i][j]+=fmin(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        
        int sub=triangle.size()-1;
        int sum=triangle[sub][0];
        for(int i=0;i<triangle[sub].size();i++)
        {
            sum=fmin(sum,triangle[sub][i]);
        }

        return sum;

    }
};