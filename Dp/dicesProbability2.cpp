class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> ret(6,1.0/6.0);//当n为1的时候

        for(int i=1;i<n;i++)//控制骰子数
        {
            vector<double> temp(ret.size()+5,0); 
            for(int j=1;j<=6;j++)//控制骰子出现的点数
            {
                int sub=j-1;
                for(int k=0;k<ret.size();k++)//控制少一颗骰子时，所有数出现的概率
                {
                    temp[sub++]+=ret[k]/6;
                }
            }
            ret=temp;//进行迭代
        }
        return ret;
    }
};