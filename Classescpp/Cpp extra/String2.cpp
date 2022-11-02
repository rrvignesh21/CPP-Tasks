#include<iostream>
using namespace std;

class String{
    char *str;
    int length;
    public:
    String(){

    }
    String(char input[]){
        int i = 0;
        while (input[i]!= '\0')
        {
            i++;
        }
        this->length = i+1;
        this->str = new char(this->length);
        i = 0;
        while (input[i]!= '\0')
        {
            *(str+i) = input[i];
            i++;
        }
        *(str+i) = '\0';
    }
    String(String &copy_String){
        // this->length = copy_String.size() + 1;
        // this->str = new char(this->length);
        // this->str = copy_String.getasChar();
         this->operator=(copy_String);
    }
    ~String(){
        delete this->str;
    }
    char* getasChar(){
        return (this->str);
    }
    void operator = (char input[]){
        int i = 0;
        while (input[i]!= '\0')
        {
            i++;
        }
        this->length = i+1;
        this->str = new char(this->length);
        i = 0;
        while (input[i]!= '\0')
        {
            *(str+i) = input[i];
            i++;
        }
        *(str+i) = '\0';
    }
    void operator = (String input){
        int i = 0;
        while (input[i]!= '\0')
        {
            i++;
        }
        this->length = i+1;
        this->str = new char(this->length);
        i = 0;
        while (input[i]!= '\0')
        {
            *(str+i) = input[i];
            i++;
        }
        *(str+i) = '\0';
    }
    void displayString(){
        cout << this->str << endl;
    }
    int size(){
        return ((this->length)-1); 
    }
    void resize(int size){
        this->str = new char[size];
    }
    String operator + (String string2){
        String cancatString;
        int index = 0;
        char temp[(this->length + string2.size())];
        while (this->operator[](index) != '\0')
        {
            temp[index] = this->operator[](index);
            index++;
        }
        int string2index = 0;
        while (string2[string2index] != '\0')
        {
            temp[index] = string2[string2index];
            index++;
            string2index++;
        }
        temp[index] = '\0';
        cancatString = temp;
        return cancatString;      
    }
    char operator [] (int index){       
        return (this->str[index]);
    }
    void cancat(String string2){
        this->operator = (this->operator +(string2));        
    }
    int find(String &input_string){ //Return the index of starting of the string or return -1 if not found
        int input_index = 0;
        int index = 0;
        while (input_string[input_index] != '\0')
        {   
            if(this->operator[](index) == '\0'){
                return -1;
            }
            if((input_string[input_index] == this->operator[](index))){
                input_index++;
                index++;
            }
            else{
                input_index = 0;
                index++;
            }
        }
        return ((index - 1) - (input_string.size() - 1));
         
    }
    bool isEqual(String &compare_string){ // Return True if string is Equal
        int index = 0;
        while(compare_string[index] != '\0'){
            if(compare_string[index] != this->operator[](index)){
                return false;
            }
            else{
                index++;
                continue;
            }
        }
        return true;
    }
    int findchar(char character){ // Return Number of occurence of character in the String
        int count = 0;
        int index = 0;
        while(this->operator[](index) != '\0'){
            if(this->operator[](index) == character){
                count++;
                index++;
            }
            else{
                index++;
                continue;
            }
        }
        return count;

    }
    void push(char input_character){
        this->length = this->length + 1;
        this->str = (char *)realloc(this->str,this->length);
        this->str[this->length-2] = input_character;
        this->str[this->length-1] = '\0';
    }
    char pop(){
        char pop_char;
        pop_char = this->str[this->length-2]; 
        this->str[this->length-2] = '\0';
        this->length = this->length - 1;
        this->str = (char *)realloc(this->str,this->length);
        return pop_char;
    }
    void reverse(){ // reverse string by Swaping 
        int length = (this->length) - 1 ;
        for(int i = 0;i< length/2;i++){
            swap(this->str[i],this->str[length-i-1]);
        }
    }
    String slicing(int start,int jump,int stop){
        String sliced_string;          
        if(stop > this->size() || start > stop ){
            cout << "Check the start and stop index";
            return sliced_string;
        }
        char temp[(stop - start)+1];
          int tempindex = 0;  
            for(int i = start;i < stop;i = i + jump){
                temp[tempindex] = this->str[i];
                tempindex++;
            }
            temp[tempindex] = '\0';          
            sliced_string = (temp);
            return sliced_string;        
    }
    void swapString(String &swap_string){
        String temp_string = this->getasChar();
        this->operator=(swap_string.getasChar());
        swap_string = temp_string.getasChar();
    }
};

int main(){
    String st = "hello";
    st = "hello how are you";
    st.displayString();
    
    char some[] = "there"; 
    String findstr = "hello";
    findstr = "raja"; 
    findstr.displayString();
    findstr = "this is a string";
    findstr.displayString();
    String otherString = "hello there is";
    // otherString.displayString();
    // cout << otherString.find(findstr) << endl;  
    // findstr.displayString();
    // cout << otherString.findchar('e') << endl;
    // cout << "Size before push : "<< otherString.size() << endl;
    // otherString.push('o');
    // cout << "Size After push : " << otherString.size() << endl;
    // otherString.displayString();
    // cout << "poped : " << otherString.pop() << endl;
    // otherString.displayString();
    // cout << "Size After pop : " << otherString.size() << endl;
    // otherString.reverse();
    // otherString.displayString();
    // otherString.slicing(4,1,13).displayString();
    //Slicing
    // String somestring = otherString.slicing(4,1,13);
    // String secogslce;
    // secogslce = otherString.slicing(2,1,10);
    // secogslce.displayString();
    // somestring.displayString();
    
   
//Swapping
    // String swap1string = "hello";
    // String swap2string = "HI";
    // cout << "Before swap : " << endl;
    // swap1string.displayString();
    // swap2string.displayString();
    // cout << "After swapping : "<<endl;
    // swap1string.swapString(swap2string);
    // swap1string.displayString();
    // swap2string.displayString();   
       
    //int size = st.size();
    //cout << size << endl;
    //st.displayString();
    // String CatString = (findstr + otherString);
    // CatString.displayString();
    // findstr.cancat(otherString);
    // findstr.displayString();
    // cout << "Using + : ";
    // CatString.displayString();
    // String S1 = "the";
    // String S2 = "the";
    // cout << S1.isEqual(S2) << endl;
    // cout << "Length : " << S1.size() << endl;
    cout << findstr[1] << endl;

}