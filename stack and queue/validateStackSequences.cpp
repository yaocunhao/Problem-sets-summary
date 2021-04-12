剑指 Offer 31. 栈的压入、弹出序列

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> _enter;
        int sub1=0;
        int sub2=0;
        while(sub1 < pushed.size() && sub2 < popped.size() )
        {
            if(_enter.empty()||_enter.top()!=popped[sub2])//为空或者不等
            _enter.push(pushed[sub1++]);

            while(!_enter.empty() && _enter.top()==popped[sub2]&&sub2<popped.size())//相等则出栈
            {
                sub2++;
                _enter.pop();
            }
        }
        if(_enter.empty())
        return true;
        return false;
    }
};