#include <iostream>
using namespace std;
#include <map>
//删除map中key为2的倍数的value
int main()
{
	map<int, int>* m = new map<int, int>;
	m->insert(make_pair(2, 1));
	m->insert(make_pair(3, 2));
	m->insert(make_pair(4, 3));
	m->insert(make_pair(5, 4));
	for (auto it = m->begin(); it != m->end(); ++it)
	{
		int k = it->first;
		if (k % 2 == 0)
			m->erase(it++);
		else
			it++;
	}
	for (auto it = m->begin(); it != m->end(); it++)
		cout << it->first << ":" << it->second << endl;
	return 0;
}