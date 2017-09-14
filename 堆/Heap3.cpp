/**
* @note 添加/删除堆数据
*/
#include <iostream>     // cout
#include <vector>

using namespace std;

template<class T,size_t N>
void PrintArray(const T (&arr)[N],size_t len = N){
	cout << '{';
	size_t i(0);
	for(auto d:arr){
		cout << d;
		if(++i != len) {
			cout<<',';
		}else{
			break;
		}
	}
	cout << '}';
}

/**
* @brief 判断数组是否堆
*/
template<class T>
bool IsHeap(vector<T> const&arr){
	size_t len = arr.size();
	if(1 == len){
		return true;
	}
	for(size_t i=0,last=len/2-1;i<=last;i++){
		if(arr[i] < arr[i*2+1]){
			return false;
		}
		if(i*2+2<len and arr[i] < arr[i*2+2]){
			return false;
		}
	}
	return true;
}
/**
* @brief 添加数据
*/
template<class T>
void PushHeap(vector<T>& arr,int data){
	arr.push_back(data);
	for(ssize_t i=arr.size()/2-1;i>=0;i--){
		size_t cur(i);
		do{
			// 父节点值小于左子结点
			if(cur*2+2<arr.size() and arr[cur] < arr[cur*2+2]){
				if(arr[cur*2+1] < arr[cur*2+2]){
					swap(arr[cur],arr[cur*2+2]);
					cur = cur*2+2;
				}else{
					swap(arr[cur],arr[cur*2+1]);
					cur = cur*2+1;
				}
			// 父节点值小于左子结点(包含只有左节点的情况)
			}else if(cur*2+1<arr.size() and arr[cur] < arr[cur*2+1]){
				swap(arr[cur],arr[cur*2+1]);
				cur = cur*2+1;
			}else{
				break;
			}
		}while(cur < arr.size());
		// PrintArray(arr);
		// cout << endl;
	}
}

/**
* @brief 删除数据
*/
template<class T>
T PopHeap(vector<T>& arr){
	swap(arr.front(),arr.back());
	T res = arr.back();
	arr.pop_back();
	for(ssize_t i=arr.size()/2-1;i>=0;i--){
		size_t cur(i);
		do{
			// 父节点值小于左子结点
			if(cur*2+2<arr.size() and arr[cur] < arr[cur*2+2]){
				if(arr[cur*2+1] < arr[cur*2+2]){
					swap(arr[cur],arr[cur*2+2]);
					cur = cur*2+2;
				}else{
					swap(arr[cur],arr[cur*2+1]);
					cur = cur*2+1;
				}
			// 父节点值小于左子结点(包含只有左节点的情况)
			}else if(cur*2+1<arr.size() and arr[cur] < arr[cur*2+1]){
				swap(arr[cur],arr[cur*2+1]);
				cur = cur*2+1;
			}else{
				break;
			}
		}while(cur < arr.size());
		// PrintArray(arr);
		// cout << endl;
	}
	return res;
}

template<class T>
void Test(vector<T> const&vec){
	cout << '{';
	size_t i(0);
	for(auto d:vec){
		cout << d;
		if(++i != vec.size()) {
			cout<<',';
		}else{
			break;
		}
	}
	cout << '}';
	cout << IsHeap(vec) << endl;
}
int main(){
	cout <<boolalpha;
	{
		vector<int> vec{20,10,15,8,7,13,14,2,5,6};
		PushHeap(vec,15);
		Test(vec);
	}	
	{
		vector<int> vec{20,10,15,8,7,13,14,2,5,6};
		cout << "PopHeap:" << PopHeap(vec) << endl;
		Test(vec);
	}

}