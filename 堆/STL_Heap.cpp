#include <iostream>     // cout
#include <algorithm>    // make_heap, pop_heap, push_heap, sort_heap
#include <vector>       // vector

using namespace std;

void PrintVector(vector<int> const& v){
  cout << "Root:" << v.front() << endl;
  for(auto e:v){
    cout << e ;
    if(v.back()!=e) cout<<',';
  }
  cout << endl;
}

int main () {
  {
    vector<int> v{10,20,30,5,15};

    cout << "初始化" << endl;
    make_heap (v.begin(),v.end());
    PrintVector(v);

    cout << "删除根" << endl;
    pop_heap (v.begin(),v.end()); v.pop_back();
    PrintVector(v);

    cout << "插入99" << endl;
    v.push_back(99); push_heap (v.begin(),v.end());
    PrintVector(v);

    cout << "排序" << endl;
    sort_heap (v.begin(),v.end());
    PrintVector(v);
  }
  { 
    vector<int> v{10,20,30,5,15};

    cout << "初始化" << endl;
    make_heap (v.begin(),v.end(),greater<int>());
    PrintVector(v);

    cout << "删除根" << endl;
    pop_heap (v.begin(),v.end(),greater<int>()); v.pop_back();
    PrintVector(v);

    cout << "插入99" << endl;
    v.push_back(99); push_heap (v.begin(),v.end(),greater<int>());
    PrintVector(v);

    cout << "排序" << endl;
    sort_heap (v.begin(),v.end(),greater<int>());
    PrintVector(v);
  }
  return 0;
}
