剑指 Offer 59 - II. 队列的最大值

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(_qmax.empty())
        return -1;

        return _qmax.front();
    }
    
    void push_back(int value) {

        while(!_qmax.empty()&&value>_qmax.back())//队列不为空，且新入的元素大于前面的元素
            _qmax.pop_back();

            _qmax.push_back(value);

        _q.push(value);
    }
    
    int pop_front() {
        if(_q.empty())
        return -1;

        if(_q.front()==_qmax.front())
            _qmax.pop_front();

           int num=_q.front();
            _q.pop();
            return num;
    }

    private:
    queue<int> _q;
    deque<int> _qmax;
};

