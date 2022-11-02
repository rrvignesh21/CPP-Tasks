#include<iostream>
using namespace std;

template<class T>
class List{
    T *data;
    int size;
    public:
    List(){
        this->size = 0;
    }
    ~List(){
        delete[] data;
    }
    // List(T input_data){
    //     this->size = 0;
    //     for(T temp : input_data){
    //         this->size++;
    //     }
    //    this->data = new T (this->size)
    //     for(int i = 0; i<this->size();i++){
    //         this->data[i] = input_data[i];
    //     }
    // }
    void display(){
        cout << "Display func";
        int i;
        int length = this->size;
        for(i = 0; i < length; i++){
            cout << this->data[i] << " ";
        }
        cout << "\n";
    }
    void push(T push_data){
        this->size = this->size + 1;
        this->data = (T *)realloc(this->data,this->size);
        this->data[this->size-1] = push_data;
    }
    T pop(){
        cout << "pop func";
        T temp = this->data[this->size - 1];
        this->size = this->size - 1;
        this->data = (T *)realloc(this->data,this->size);
        this->display();
        return (temp);
    }
    int length(){
        return (this->size);
    }

};

int main(){
    List<int> lst;
    lst.push(1);
    lst.push(34);
    lst.push(6);
    lst.push(4);
    lst.push(7);
    lst.push(8);
    lst.push(9);
    lst.push(10);
    lst.display();
    // lst.pop();
    // cout << "Pop : " << lst.pop() << endl;
    // lst.display();
    cout << lst.length() << endl;
}