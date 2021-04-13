剑指 Offer 38. 字符串的排列

class Solution {
public:

    void GetString(string &s,vector<string> &ret,string temp,vector<int> flag)
    {
        if(temp.size()==s.size())
        {
            ret.push_back(temp);
            return ;
        }

        for(int i=0;i<s.size();i++)
        {
            if(i>0&&s[i]==s[i-1]&&flag[i-1]==0||flag[i]==1)//falg[i]去同一子集的重，另外一个去同一层的同
            continue;

            temp.push_back(s[i]);//添加元素
            flag[i]=1;//标记

            GetString(s,ret,temp,flag);
            flag[i]=0;//回溯
            temp.erase(temp.size()-1);
        }
    }
    vector<string> permutation(string s) {
        
        sort(s.begin(),s.end());//排序去重
        vector<string> ret;
        string temp;
        vector<int> flag(s.size(),0);
        GetString(s,ret,temp,flag);
        return ret;
    }
};