/**
* 高级排序：
* 堆排序HeapSort
* 快速排序QuickSort
* 归并排序MergeSort
* 基数排序RadixSort
* 希尔排序ShellSort
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

template<class T,size_t N>
void PrintArr(T (&arr)[N]) {
    copy(arr,arr+N,ostream_iterator<T>(cout," "));
    cout << endl;
}

//堆排序:O(nlgn)
template<typename T,size_t N>
void HeapSort(T (&arr)[N]) {
    make_heap(arr,arr+N);
    sort_heap(arr,arr+N);
}
/// 时间复杂度O(n^1.5)
template<class T,size_t N>
void ShellSort(T (&arr)[N]) {
    int insert_num(0);
    size_t gap(N/2);
    while(gap >= 1) {
        for (size_t i = gap; i < N; ++i) {
            insert_num = arr[i];
            size_t j(i);
            while (j >= gap and insert_num < arr[j-gap]) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = insert_num;
        }
        gap /= 2;
    }
}

template<class T,size_t N>
void MergeSort(T (&arr)[N]) {
    T temp[N]; // 临时结果
    auto merge = [&](size_t first,size_t mid,size_t last) {
        size_t i(first),
               j(mid+1),//避免重复比较arr[mid]
               k(0);
        while (i <= mid and j <= last) {//数组arr[first,mid]与数组(mid,last]均没有全部归入数组temp中去
            if (arr[i] <= arr[j])       //如果arr[i]小于等于arr[j]
                temp[k++] = arr[i++];   //则将arr[i]的值赋给temp[k]，之后i,k各加一，表示后移一位
            else
                temp[k++] = arr[j++];   //否则，将arr[j]的值赋给temp[k]，j,k各加一
	    // temp[k++] = arr[i] <= arr[j]?arr[i++]:arr[j++];
        }
        while (i <= mid)                //表示数组arr(mid,last]已经全部归入temp数组中去了，而数组arr[first,mid]还有剩余
            temp[k++] = arr[i++];       //将数组arr[first,mid]剩下的值，逐一归入数组temp
        while (j <= last)               //表示数组arr[first,mid]已经全部归入到temp数组中去了，而数组(mid,high]还有剩余
            temp[k++] = arr[j++];       //将数组a[mid,high]剩下的值，逐一归入数组temp
	
        //if(j > last and i < mid)copy(arr+i,arr+mid+1,temp+k);
	//if(i > mid and j < last)copy(arr+j,arr+last+1,temp+k);
	
        for (i = 0; i < k; i++)         //将归并后的数组的值逐一赋给数组arr[first,end]
            arr[first + i] = temp[i];   //注意，应从arr[first+i]开始赋值
	// copy(temp,temp+(last-first+1),arr+first);
    };
    function<void(size_t,size_t)> sort
    = [&](size_t first,size_t last) {
        if(first < last) {
            size_t mid{(first+last)/2};
            sort(first,mid);  //对左边进行排序
            sort(mid+1,last);//对右边进行排序
            merge(first,mid,last);  //把排序好的数据合并
        }
    };

    // 执行比较
    sort(0,N-1);

    // 复制结果
    copy(begin(temp),end(temp),arr);
}

template<class T,size_t N>
void RadixSort(T (&arr)[N]) {
    const int radix(10); // 基数
    bool flag(true);
    queue<int> queues[radix]; // 桶
    for(size_t i=0,factor=1;flag;factor *= radix,i++) {
        for(size_t j=0; j<N; j++) { // 入桶
            queues[(arr[j]/factor)%radix].push(arr[j]);
	    flag = false;
	    flag |= (arr[j]/factor)%radix > 10;
        }
        for(size_t j=0,k=0; j<radix; j++) { // 出桶
            while(!queues[j].empty()) {
                arr[k++]=queues[j].front();
                queues[j].pop();
            }
        }
    }
}
template<class T,size_t N>
void QuickSort(T (&arr)[N]) {
    if(N < 2)return;
    function<void(ssize_t,ssize_t)> sort = [&](ssize_t low,ssize_t high){
        if(low >= high) {
            return;
        }
        ssize_t first(low),
                last(high),
                key(arr[first]);//用字表的第一个记录作为枢轴
        while(first < last) {
            while(first < last and arr[last] >= key) {
                --last;
            }

            arr[first] = arr[last];// 将比第一个小的移到低端

            while(first < last and arr[first] <= key) {
                ++first;
            }

            arr[last] = arr[first];// 将比第一个大的移到高端
        }
        arr[first] = key;//枢轴记录到位
        sort(low, first-1);
        sort(first+1, high);
    };
    sort(0,N-1);
}

template<class SortFunc>
void Test(SortFunc sort) {
    int good[] = {1,2,3,4,5,6,7,8,9};
    int bad[]  = {9,8,7,6,5,4,3,2,1};

    sort(good);
    PrintArr(good);
    sort(bad);
    PrintArr(bad);
}

int main() {
    cout << "HeapSort：" << endl;
    Test(HeapSort<int,9>);
    cout << "ShellSort：" << endl;
    Test(ShellSort<int,9>);
    cout << "MergeSort：" << endl;
    Test(MergeSort<int,9>);
    cout << "RadixSort：" << endl;
    Test(RadixSort<int,9>);
    cout << "QuickSort：" << endl;
    Test(QuickSort<int,9>);

}
