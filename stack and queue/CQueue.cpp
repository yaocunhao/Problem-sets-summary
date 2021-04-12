剑指 Offer 09. 用两个栈实现队列

class CQueue {
public:
    CQueue() {}//默认调用自定义类型的构造函数
    
    void appendTail(int value) {
        _st1.push(value);//入到栈1

    }
    
    int deleteHead() {
        if(_st1.empty()&&_st2.empty())//两个栈都为空，则表示没有数据
        return -1;

        if(_st2.empty())//栈2为空，则从栈1倒入数据
        {
            while(!_st1.empty())
            {
                _st2.push(_st1.top());
                _st1.pop();
            }
        }
        int val=_st2.top();
        _st2.pop();
        return val;
    }

private:
    stack<int> _st1;
    stack<int> _st2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */