#include <iostream>
using namespace std;
#include <string>
#include <vector>
//给定一个字符串和一个字符串字典，找到字典里面最长的字符串，
//该字符串可以通过删除给定字符串的某些字符来得到,如果答案不止一个，
//返回长度最长且字典顺序最小的字符串,如果答案不存在,则返回空字符串
bool isSubstr(string s, string t)//判断t字符串是否是s的子序列
{
	int i = 0;//用来遍历s
	int j = 0;//用来遍历t
	while (i<s.size() && j<t.size())
	{
		if (s[i] == t[j])//继续在t这个字符串向后走继续判断
			j++;
		i++;
	}
	return j == t.size();//看是否存在s的长度比t的长度小的情况，就会导致i走完了s，但是j还没有走完t
}
string findLongestWord(string s, vector<string>& d) {
	string result = "";//结果字符串
	for (int i = 0; i<d.size(); ++i)//遍历d
		//由于最终要找到最长子序列，因此每次要与result的长度进行比较,如果每次遍历到的字符串比result的长度小或者长度相同但是result的字母顺序比遍历到的字符串字母顺序小，就要继续循环遍历
	{
		if (result.size()>d[i].size() || (result.size() == d[i].size() && result.compare(d[i])<0))
			continue;
		if (isSubstr(s, d[i]))//如果符合子序列要求
			result = d[i];
	}
	return result;
}
int main()
{
	string s = "abpcplea";
	vector<string> d = { "ale", "apple", "monkey", "plea" };
	string result = findLongestWord(s, d);
	cout << result << endl;
	return 0;
}