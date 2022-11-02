#include<iostream>
using namespace std;

template<class T>
class List{
    T *data;
    int size;
    int capacity;
    public:
    List(){
        this->capacity = 4;
        this->size = 0;
        this->data = new T (this->capacity);
    }
    List(T input_data){
        this->push(input_data);    
    }
    ~List(){
        delete[] this->data;
    }

    void display(){
        int i;
        int length = this->size;
        for(i = 0; i < length; i++){
            cout << this->data[i] << " ";
        }
        cout << "\n";
    }
    void push(T push_data){
        if(this->size < this->capacity){
            this->data[this->size] = push_data;
            this->size++;        
        }
        else{
            T *temp = new T(this->capacity + 1);
            for(int i = 0;i < this->size;i++){
                *(temp+i) = *(this->data + i);
            }
            temp[size] = push_data;
            this->resize();
            this->data = temp;
            this->size++;
            // delete[] temp;
        }
    }

    void resize(){
        this->capacity = this->capacity * 2;
        delete[] this->data;
        this->data = new T (this->capacity);
    }
    T pop(){
        T temp = this->data[this->size - 1];
        this->size = this->size - 1;
        if(this->size < this->capacity / 2){
            this->capacity = this->capacity / 2;
            this->data = new T (this->capacity);
        }
        return (temp);
    }
    void insert(T insert_data,int position){
        this->size = this->size + 1;
        int i;
        if(this->size < this->capacity){
            cout << "IF inner "<<endl;
            for(i = this->size;i >=position;i--){
            this->data[i] = this->data[i-1];
        }
        this->data[position] = insert_data;
        }        
        else{
            cout << "ELSE inner "<<endl;
            T *temp = new T(this->capacity + 1);
            cout << "1 :\n ";
            for(int i = 0;i < this->size;i++){
                // cout << "2 : ";
                // cout <<*(temp+i) << " ";
                *(temp+i) = *(this->data + i);
            }
            for(i = this->size;i >=position;i--){
            *(temp+i) = *(temp+(i-1));
            }
            *(temp+position) = insert_data;
            // temp[size] = push_data;
            this->resize();
            this->data = temp;
            // this->size++;
            // delete[] temp;
        }
    }

    void remove(int position){
        int i;
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
    lst.insert(10101,1);
    lst.insert(12,3);
    lst.insert(12,3);
    lst.insert(12,3);
    // lst.insert(12,3);

    cout << "Before : ";
    lst.display();
    lst.push(4);
    lst.push(5);
    lst.push(6);
    lst.push(7);
    lst.push(8);
    lst.display();
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
    // List<string>list2;
    // list2.push("Hello");
    // list2.push("HI");


}