剑指 Offer 30. 包含min函数的栈

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()//会自动调用构造函数 
    {}
    
    void push(int x) {
        _st.push(x);
        if(_minst.empty()||x<=_minst.top())
        _minst.push(x);
    }
    
    void pop() {
        if(_st.top()==_minst.top())
            _minst.pop();
        _st.pop();
    }
    
    int top() {
        return _st.top();

    }
    
    int min() {
        return _minst.top();

    }

private:
    stack<int> _st;
    stack<int> _minst;
};
