#include <iostream>
#include <vector>
#include<string>
using namespace std;
void subset(string s,string ans,int index) {
	if (index==s.size()) {
	    cout << ans << endl;
		return;
	}
	    subset(s, ans+s[index], index + 1);
		subset(s, ans, index + 1);
}
void subset1(vector<int> &arr, vector<int> &ansArr, int index) {
	if (index == arr.size()) {
		for (int val: ansArr)
		{
			cout << val << endl;   
		}
		cout << endl;
		return;
	}
	ansArr.push_back(arr[index]);
	subset1(arr, ansArr, index + 1);
	ansArr.pop_back();
	subset1(arr, ansArr, index + 1);
}

 
int main() {
	string s ="abcd";
	vector<int> arr = { 1,2,2 };
	vector<int>ansArr;
	string ans = " ";
	int index = 0;
	subset(s, ans, index);
	subset1(arr, ansArr, index);


	return 0;
}