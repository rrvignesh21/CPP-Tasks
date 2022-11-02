#include<iostream>
#include<vector>
#include<array>
#include<set>
#include<map>
using namespace std;

template <class T>
class Vector{

};
template<class A>
void someFunc(A a){
    cout << "SOME" ;    
}

template<class A,class... T>
int someFunc(A a,T...var){
    cout << a << " ";    
    someFunc(var...);
}
// template<class ...T>
// class multi{
//     T *a;
//     public:
//     multi(T&& ...t){
//         // forward<T>(t);
//         a = t;
//         cout << *a << endl;
//     }

// };
template<class T>
class SomeClass{
    const T *data;
    int length;
    public:
    SomeClass(initializer_list<T> a){
        this->data = a.begin();
        for(auto i = a.begin();i != a.end();i++){
            this->length++;
        }
    }
    T operator () (int index){
        return *(this->data+index);
    }
    void display(){
        for(int i = 0;i < this->length;i++){
            cout << *(this->data+i) << " ";
        }
        cout << "\n";
    }
    int size(){
        return this->length;
    }
};

int main(){
    // array<char,3> CArray;

    // vector <string> SVector = {"heklo","Hello","HI","AABBCC","dsf"};
    // SVector.push_back("something");
    // cout << "Size : " << SVector.size() << endl;
    // cout << "Capacity : " << SVector.capacity() << endl;
    // SVector.shrink_to_fit();
    // cout << "Capacity : " << SVector.capacity() << endl;
    // SVector[2].pop_back();
    // SVector.insert(SVector.begin()+3,"CCAA");
    // auto ptr = SVector.cbegin();
    // for(ptr;ptr != SVector.cend();ptr++){
    //     cout << *ptr << " ";
    // }
    // someFunc(1,2,3,45,5,6,7);
    SomeClass<int> c = {1,2,3,4};
    c.display();
    cout << "SIZE : "<< c.size() << endl;
    cout << c(2) << endl;
    // multi<int> m; 
}