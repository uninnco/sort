/**
* @note 判断一个数组是否是堆
*/
#include <iostream>     // cout

using namespace std;

/**
* @brief 判断数组是否堆
*/
template<class T,size_t N>
bool IsHeap(T (&arr)[N]){
	for(size_t i=0,last=N/2-1;i<=last;i++){
		if(arr[i] < arr[i*2+1]){
			return false;
		}
		if(i*2+2<N and arr[i] < arr[i*2+2]){
			return false;
		}
	}
	return true;
}
int main(){
	cout <<boolalpha;
	{
		int arr[] = {10,2,9,1,0,8,7};
		cout << "{10,2,9,1,0,8,7}:" << IsHeap(arr) << endl;
	}
	{
		int arr[] = {10,9,8,7,2,0,1};
		cout << "{10,9,8,7,2,0,1}:" << IsHeap(arr) << endl;
	}
	{
		int arr[] = {10,7,9,0,1,2,8};
		cout << "{10,7,9,0,1,2,8}:" << IsHeap(arr) << endl;
	}
	{
		int arr[] = {15,12,6,11,10,2,3,1,8};
		cout << "{15,12,6,11,10,2,3,1,8}:" << IsHeap(arr) << endl;
	}
	{
		int arr[] = {15,12,6,11,10,2,3,1};
		cout << "{15,12,6,11,10,2,3,1}:" << IsHeap(arr) << endl;
	}
}