#include <iostream>
#include <vector>
#include <string>
#include "pythonds3/cppds/stack.hpp"
#include "pythonds3/cppds/linked_list.hpp"
using namespace std;
 
int main() {
    cout << "C++ 標準  : " << __cplusplus << "  (201703 = C++17)" << endl;
    cout << "g++ 版本  : " << __GNUC__ << "." << __GNUC_MINOR__ << endl;
 
    Stack<int> s;
    s.push(42);
    s.push(7);
    cout << "Stack     : pop=" << s.pop() << " peek=" << s.peek() << " size=" << s.size() << endl;
 
    UnorderedList<int> lst;
    lst.add(31);
    lst.add(17);
    cout << "LinkedList: size=" << lst.size() << " search(31)=" << lst.search(31) << endl;
 
    cout << "環境檢查通過，可以開始第 01 章。" << endl;
    return 0;
}