#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int value = 67;

    //cmath
    cout << "##cmath" << endl;
    cout << "int(value): " << value << endl;
    cout << "sqrt(value): " << sqrt(value) << endl;
    cout << "pow(value, 2): " << pow(value, 2) << endl;
    cout << endl;

    //*pointer = &value / newvalue = value
    int *pointer = &value;
    int newvalue = value;
    cout << "##pointer and newvalue" << endl;
    cout << "*pointer = &value / newvalue = value" <<endl;
    cout << "(val): " << value << endl; //67
    cout << "(&val): " << &value << endl; //0X 
    cout << "(*ptr): " << *pointer << endl; //67
    cout << "(ptr): " << pointer << endl; //0X
    cout << "(&ptr): " << &pointer << endl; //0X
    cout << "(nval): " << newvalue << endl; //67
    cout << "(&nval): " << &newvalue << endl; //0X
    cout << endl;

    //vector
    cout << "##vector" << endl;
    vector<double> vector = {3, 2, 1};
        cout << "(vec<double>): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl << endl;

        //vector index & front/back/begin/end
    cout << "####vector index & front/back/begin/end" << endl;
    cout << "(vec[0]): " << vector[0] << endl;
    cout << "(vec[1]): " << vector[1] << endl;
    cout << "(vec[2]): " << vector[2] << endl;
    cout << "> (vec[3]): " << vector[3] << " <" << endl;
    cout << "- DANGER: no bounds checking — this compiles and silently reads garbage!"<< endl;
    cout << "(vec.at(0))): " << vector.at(0) << endl;
    cout << "(vec.at(1))): " << vector.at(1) << endl;
    cout << "(vec.at(2))): " << vector.at(2) << endl;
    try{
        cout << "> (vec.at(3))): " << vector.at(3) << endl;
    } catch (exception& e) {
        cout << "Caught exception: " << e.what() << " <" << endl;
    }
    cout << "- DANGER: bounds undefined — this throws an exception!"<< endl;
    cout << "(vec.size()): " << vector.size() << endl;
    cout << "(vec.front()): " << vector.front() << endl;
    cout << "(*vec.begin()): " << (*vector.begin()) << endl;
    cout << "(vec.back()): " << vector.back() << endl;
    cout << "(*(vec.end()-1)): " << *(vector.end()-1) << endl;
    cout << "> (*vec.end()): " << (*vector.end()) << " <" << endl;
    cout << "- DANGER: no bounds checking — this compiles and silently reads garbage!"<< endl;
    cout << endl;

        //vector search index
    cout << "####vector search index" << endl;
    cout << "(&vec[0]): " << &vector[0] << "    (vec[0]): " << vector[0] << endl;
    cout << "(&vec[1]): " << &vector[1] << "    (vec[1]): " << vector[1] << endl;
    cout << "(&vec[2]): " << &vector[2] << "    (vec[2]): " << vector[2] << endl;
    for (double item : vector) {
        if (find(vector.begin(), vector.end(), item) != vector.end()) {
    
        cout << "(item): " << item << "    (mem)(vec.find(beg,end," << item << ")): " << &(*find(vector.begin(), vector.end(), item)) <<  "    (index)(dis(beg,vec.find(beg,end," << item << "))): " << distance(vector.begin(), find(vector.begin(), vector.end(), item)) << endl ;
        } else {
        cout << "can't find" << endl;
    }
    }

        //vector insert/erase
    cout << endl << "####vector insert/erase" << endl;
    vector.insert(vector.begin(), 4);
    cout << "(vec.insert(vec.begin(), 4)): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl;
    vector.erase(vector.begin());
    cout << "(vec.erase(vec.begin())): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl;
    vector.insert(vector.begin() + 2, 2.5);
    cout << "(vec.insert(vec.begin() + 2, 2.5)): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl;
    vector.erase(vector.begin() + 3);
    cout << "(vec.erase(vec.begin() + 3)): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl;
    vector.push_back(0);
    cout << "(vec.push_back(0)): ";
    for (double item : vector) {    
        cout << item << " ";
    }
    vector.pop_back();
    cout << endl << "(vec.pop_back()): ";
    for (double item : vector) {
        cout << item << " ";
    }
    sort(vector.begin(), vector.end());
    cout << endl << "(vec.sort(vec.begin(), vec.end())): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl;
    reverse(vector.begin(), vector.end());
    cout << "(vec.reverse(vec.begin(), vec.end())): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl;
    vector.clear();
    cout << "(vec.clear()): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl;
    //strings
    cout << endl << "##strings" << endl;
    vector = {1, 2};
        cout << "(vec<double>): ";
    for (double item : vector) {
        cout << item << " ";
    }
    cout << endl;
    cout << "(&vec[0]): " << &vector[0] << "    (vec[0]): " << vector[0] << endl;
    cout << "(&vec[1]): " << &vector[1] << "    (vec[1]): " << vector[1] << endl;
    stringstream ssvec0, ssvec1;
    ssvec0 << &vector[0];
    ssvec1 << &vector[1];
    string vec0 = ssvec0.str();
    string vec1 = ssvec1.str();
    cout << "(stringstream ssvec0,ssvec1)   (ssvec0,1 << &vector0,1)"<< endl;
    for (int i = 0; i < vec0.length(); i++) {
        cout << "(vec0["<< i << "]): " << vec0[i] << "    (vec1["<< i << "]): " << vec1[i] <<endl;
    }
    cout << "(vec0.substr(12, 2)): " << vec0.substr(12, 2) << endl;
    cout << "(vec1.substr(12, 2)): " << vec1.substr(12, 2) << endl;
    return 0;

}