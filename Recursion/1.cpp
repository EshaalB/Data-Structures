//#include <iostream>
//#include <vector>
//using namespace std;
//void printRev(int n) {
//	if (n == 1) {
//		cout << n << " ";
//		return;
//	}
//	cout << n << " ";
//	return printRev(n - 1);
//
//}
////time complexity : (no of calls) * (work done in each call) in this case o(n)
//// space complexity: height of call stack *mem in each cell : o(n*k) o(n)
//int fact(int n) {
//
//	if (n == 1) return n;
//	return n * fact(n - 1);
//	/*int fact = 1;
//	for (int i = 1; i <= n; i++) fact = fact * i;
//	*/
//}
//int sum(int n) {
//
//	if (n == 1) return n;
//	return n + sum(n - 1);
//	/*int fact = 1;
//	for (int i = 1; i <= n; i++) fact = fact * i;
//	*/
//}
//int fib(int n) { // o(2^n)
//	/*if (n ==  0) return n;
//	return fib(n-1) + fib(n - 2);
//	cout << n << " ";*/
//	/*int start = 0;
//	int end = 1;
//	int result = 0;
//	cout << start<<" ";
//	cout << end<<" ";
//	for (int i = 2; i <= n; i++)  
//	{    
//		result = end + start;
//		cout << result << " ";
//		start = end;
//		end = result;
//
//	}
//	return result;*/
//	if (n == 0 || n == 1) {
//		return n;
//	};
//	return fib(n - 1) + fib(n - 2);
//}
//bool isSorted(vector<int>arr, int n) { //TC AND SC (O[N])
//	/*int end = n - 1;
//	for (int i = 0; i < end; i++,end--)
//	{
//		if (arr[i] > arr[end]) return false;
//	}
//	return true;*/
//	if (n == 0 ||n==1) return true;
//	if (arr[n-1] < arr[n - 2])return false;
//	return isSorted(arr, n - 1);
//	/*if (n == 0)return ;
//	if (arr[start] > arr[n]);
//	return isSorted(arr, n - 1);*/
//}
//int binarySearch(vector<int>arr, int start, int end, int target, int n) {
//	int mid = (start + end) / 2;
//	if (n == 0) return mid;
//	if (arr[mid] == target)
//		return mid;
//	if (target > arr[mid]) start = mid + 1;
//	else end = mid - 1;
//	return binarySearch(arr, start, end, target, n - 1);
//	
//}
//// 0 1 1 2 3  5 8 13 
//int main() {
//	int n = 5;
//	printRev(n);
//	int f= fact(n);
//	cout << endl;
//	cout << f << endl;
//	int s = sum(n);
//	cout << s << endl;
//	//int fibo = fib(n);
//	for (int i = 0; i < n; i++) cout << fib(i) << " ";
//	cout << endl;
//	vector <int> arr{ 3,2,3,5,1};
//	bool bhool = isSorted(arr, n);
//	cout << bhool << endl;
//	int start = 0;
//	int end = n - 1;
//	int target = 5;
//	int search = binarySearch(arr, start, end, target, n);
//	cout << "Target is found at index" << search << endl;
//	return 0;
//}