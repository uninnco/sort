/**
* 基本排序:
* 插入排序InsertSort
* 选择排序SelectSort
* 冒泡排序BubbleSort
* 梳排序CombSort
*/

#include <iostream>
#include <iterator>

using namespace std;

template<class T,size_t N>
void PrintArr(T (&arr)[N]) {
    copy(arr,arr+N,ostream_iterator<T>(cout," "));
    cout << endl;
}

///时间复杂度：O(n^2)
template<class T,size_t N>
void InsertSort(T (&arr)[N]) {
    for(ssize_t i=0,j; i<N; i++) {
        T temp(arr[i]);
        for(j=i; j>0 and temp < arr[j-1]; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

///时间复杂度：O(n^2)
template<class T,size_t N>
void SelectSort(T (&arr)[N]) {
    for(size_t i=0,j,least; i<N-1; i++) {
        for(j=i+1,least = i; j<N; j++) {
            if(arr[j] < arr[least]) {
                least = j;
            }
        }
        swap(arr[least],arr[i]);
    }
}

///时间复杂度：O(n^2)
template<class T,size_t N>
void BubbleSort(T (&arr)[N]) {
    for (int i=0; i<N; i++) {
        for (int j=N-1; j>i; j--) {
            if(arr[j]<arr[j-1])swap(arr[j], arr[j-1]);
        }
    }
}
template<class T,size_t N>
void CombSort(T (&arr)[N]) {
    size_t gap(N) ;
    bool swapped(true);
    while(gap > 1 or swapped) {
        if(gap > 1) {
            gap = static_cast<size_t>(gap/1.3) ;
        }
        size_t i(0);
        swapped = false ;
        while(i + gap < N) {
            if(arr[i] > arr[i+gap]) {
                swap(arr[i],arr[i+gap]) ;
                swapped = true ;
            }
            i++ ;
        }
    }
}

template<class SortFunc>
void Test(SortFunc sort) {
    int good[] = {1,2,3,4,5,6,7,8,9};
    int bad[]  = {9,8,7,6,5,4,3,2,1};

    // cout << "InsertSort:"<<endl;
    sort(good);
    PrintArr(good);
    sort(bad);
    PrintArr(bad);
}

int main() {
    cout << "InsertSort：" << endl;
    Test(InsertSort<int,9>);
    cout << "SelectSort：" << endl;
    Test(SelectSort<int,9>);
    cout << "BubbleSort：" << endl;
    Test(BubbleSort<int,9>);
    cout << "CombSort：" << endl;
    Test(CombSort<int,9>);
}
