把数字翻译成字符串

class Solution {
public:
    int translateNum(int num) {
        if(num==0)
            return 1;

        string str=to_string(num);//将数字转换成字符串
        vector<int> ret(str.size(),0);
        ret[0]=1;

        for(int i=1;i<str.size();i++)
        {
            if(str[i-1]=='1')
            {
                if(i-2>=0)
                    ret[i]=ret[i-1]+ret[i-2];
                else
                    ret[i]=2;//当前为第二个数
            }
            else if(str[i-1]=='2'&&str[i]<='5')
            {  
                 if(i-2>=0)
                    ret[i]=ret[i-1]+ret[i-2];
                else
                    ret[i]=2;
            }
            else
                ret[i]=ret[i-1];
        }

        return *(ret.end()-1);
    }
};