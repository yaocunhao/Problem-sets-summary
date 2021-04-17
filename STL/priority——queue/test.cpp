#include "priority_queue.hpp"

void test1()
{
		vector<int> arr;
		arr.push_back(1);
		arr.push_back(2);
		arr.push_back(3);
		arr.push_back(4);
		arr.push_back(5);

		priority_queue <int, vector<int>, greater<int> > heap(arr.begin(), arr.end());
		heap.push(143);
		heap.push(5452);
		heap.push(453);
		heap.push(44);
		heap.push(565);
		heap.push(62);
		while (!heap.empty())
		{
			cout << heap.top() << " ";
			heap.pop();
		}
		cout << endl;

}

namespace my
{
	void test2()
	{
		vector<int> arr;
		arr.push_back(1);
		arr.push_back(2);
		arr.push_back(3);
		arr.push_back(4);
		arr.push_back(5);

		priority_queue <int,vector<int>,Less<int>> heap(arr.begin(),arr.end());
		heap.push(143);
		heap.push(5452);
		heap.push(453);
		heap.push(44);
		heap.push(565);
		heap.push(62);
		while (!heap.empty())
		{
			cout << heap.top() << " ";
			heap.pop();
		}
		cout << endl;

	}
}

int main()
{
	test1();
	my::test2();


	getchar();
	return 0;
}