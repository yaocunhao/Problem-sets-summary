17.电话号码的字母组合
class Solution {
public:
    void Getstr( vector<string> &ret,string &digits,string str[],string &temp,int size,int sub)
    {
        if(temp.size()==digits.size())//获取了所有元素
            {
                ret.push_back(temp);
                return ;
            }

        for(int i=sub;i<digits.size();i++)
        {
            while(size<str[digits[i]-'0'].size())
            {
                temp.push_back(str[digits[i]-'0'][size++]);//插入元素

                Getstr(ret,digits,str,temp,0,i+1);//换下一个元素  

                temp.pop_back();//回溯

            }
        }
        
    }
    vector<string> letterCombinations(string digits) {
        //所有组合，每个元素都需要出现，利用回溯法解决  

        vector<string>ret;

        if(digits.size()==0)
        return ret;
       
        string str[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string temp;

        Getstr(ret,digits,str,temp,0,0);

        return ret;
    }
};