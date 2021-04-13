剑指 Offer 58 - II. 左旋转字符串


class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string str1(s.begin(),s.begin()+n);//获取前n个字符
        string str2(s.begin()+n,s.end());//获得后面的字符
        str2+=str1;
        return str2;

    }
};