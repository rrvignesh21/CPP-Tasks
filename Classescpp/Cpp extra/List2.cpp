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
    List(T input_data){
        this->push(input_data);    
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
        T temp = this->data[this->size - 1];
        this->size = this->size - 1;
        this->data = (T *)realloc(this->data,this->size);
        return (temp);
    }
    void insert(T insert_data,int position){
        this->size = this->size + 1;
        this->data = (T *)realloc(this->data,this->size);
        int i;
        for(i = this->size;i >=position;i--){
            this->data[i] = this->data[i-1];
        }
        this->data[position] = insert_data;
    }
    int length(){
        return (this->size);
    }
    class iterator{
        T *ptr;
        public:
        iterator(){

        }
        iterator(T *addr){
            this->ptr = addr;
        }
        void operator = (T *addr){
            this->ptr = addr;
        }
        T operator * (){
            // cout << "inner : " << *this->ptr << endl;
            return *this->ptr;
        }
        void operator ++(){
            *this->ptr = *this->ptr + 1;
        }
        void operator --(){
            *this->ptr = *this->ptr - 1;
        }
    };
    T* begin(){
        return (this->data);
    }
    T* end(){
        return (this->data + (this->length() - 1));
    }
};

int main(){
    List<int>lst;
    lst.push(1);
    lst.push(2);
    lst.push(3);
    lst.push(4);
    lst.push(5);
    lst.push(6);
    lst.push(7);
    lst.push(8);
    lst.insert(9,2);
    lst.display();
    lst.pop();
    lst.display();
    cout << "Using iterator  : "<<endl;
    List<int>::iterator ptr;
    ptr = lst.begin();
    int *ptr2 = lst.begin();
    cout << "2nd : " << *ptr2 << endl;
    cout << "1 : " << *ptr << endl;
    ++ptr;
    cout << "2 : " << *ptr << endl;
    List<int>::iterator ptr3;
    ptr3 = lst.end();
    cout << "End : "<<*ptr3 << endl; 
    cout << lst.length() << endl;
    List<int>::iterator poit = lst.end();
    cout << "Construct : " << *poit << endl;
}