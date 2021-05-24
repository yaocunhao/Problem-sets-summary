class Fruit
{
  private:
    vector<string> _str;
    int _k;

  public:
    
    Fruit(vector<string> &str,int k)
    :_str(str)
     ,_k(k)
    {}

    void TopK()
    {
      map<string,int> count_map;
      
      typedef map<string,int>::iterator count_it;//重定义迭代器


      for(auto&e:_str)//统计水果的次数
      {
        count_map[e]++;
      }

      vector<count_it> arr;
      count_it it=count_map.begin();
      while(it!=count_map.end())//将map中迭代器放入数组之中
      {
        arr.push_back(it);
        it++;
      }

      typedef struct Com//仿函数
      { 
        bool operator()(count_it &x,count_it y)
        {
          return x->second > y->second;
        }
      }compare;

      sort(arr.begin(),arr.end(),compare());//排升序
      

      while(_k--)//输出内容
      {
        cout<<arr[_k]->first<<" "<<arr[_k]->second<<endl;
      }
  }
};
