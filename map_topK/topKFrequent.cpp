typedef map<string,int>::iterator count_it;

typedef struct com
{
    bool operator()(count_it &x,count_it &y)
    {
        if(x->second!=y->second)
            return x->second > y->second;
        else//出现频率相同，按照字母顺序排->即ASCII
            return x->first < y->first;
    }
}Greater;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> count_map;

        //统计单词出现次数
        for(auto&e:words)
        {
            count_map[e]++;
        }

        priority_queue<count_it,vector<count_it>,Greater> heap;

        count_it it=count_map.begin();
        while(it!=count_map.end())
        {
            if(heap.size()<k)
                heap.push(it);
            else
            {
                if(it->second>heap.top()->second)
                {
                    heap.pop();
                    heap.push(it);
                }
            }
            it++;
        }
        vector<string> ret;
        while(!heap.empty())
        {
            ret.push_back(heap.top()->first);
            heap.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};