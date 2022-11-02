#include<iostream>
using namespace std;
/* Create a record management application using inner classes and inheritance using c++. */
class Library{

    class Book{
        string bookName;
        int bookId;
        string authorName;
        bool status;
        public:
        void setBookDetails(){
            cout << "Enter Book Name : ";
            getline(cin,this->bookName);
            cin.ignore();
            cout << "Enter Author Name : ";
            getline(cin,this->authorName);
            cin.ignore();
            this->setStatus(true);
        }
        string getBookName(){
            return(this->bookName);
        }
        string getAuthorName(){
            return (this->authorName);
        }
        int getBookId(){
            return(this->bookId);
        }
        void setStatus(bool status){
            this->status = status;
        }
        bool getStatus(){
            return (this->status);
        }
        void setBookId(int id){
            this->bookId = id;
        }
        void getBookDetails(){
            cout << "Book id : " << this->bookId << endl;
            cout << "Book Name : " << this->bookName << endl;
            cout << "Author Name : " << this->authorName << endl;
            if(!this->status){
                cout << "Issued[Not Available]" << endl;
            }
            else{
                cout << "Available" << endl; 
            }
        }
    };
    int No_of_Books;
    Book *book;
    public:
    Library(){
        cout << "Enter Number of Books : ";
        cin >> this->No_of_Books;
        book = new Book[this->No_of_Books];
    }
    void createlibrary(){
        cout << "Enter Book  Details : " << endl;
        for(int i = 0;i<this->No_of_Books;i++){
            cout << "Book " << i+1 << endl;
            this->book[i].setBookId(i+1);
            this->book[i].setBookDetails();
        }
    }
    void issuedBookDetails(){
        cout << "Issued Books"<<endl;
        for(int i = 0;i<this->No_of_Books;i++){
            if(!this->book[i].getStatus()){
               this->book[i].getBookDetails();
            }
        }
    }
    void issueBook(){
        int bookid;
        cout << "Enter the book Id : ";
        cin >> bookid;
        for(int i = 0;i<this->No_of_Books;i++){
            if(this->book[i].getBookId() == bookid){
                this->book[i].setStatus(false);
                cout << this->book[i].getBookName() << " is issued."<< endl;
            }
        }
    }
    void returnbook(){
        int bookid;
        cout << "Enter the book Id : ";
        cin >> bookid;
        for(int i = 0;i<this->No_of_Books;i++){
            if(this->book[i].getBookId() == bookid){
                this->book[i].setStatus(true);
                cout << this->book[i].getBookName() << " is returned."<< endl;
            }
        }
    }
    void displayIssuedBook(){
        for(int  i = 0;i < this->No_of_Books;i++){
            if(!this->book[i].getStatus()){
                this->book[i].getBookDetails();
                cout << "---------------------------------------\n";
            }
        }
    }
    void displayAvailableBook(){
        for(int  i = 0;i < this->No_of_Books;i++){
            if(this->book[i].getStatus()){
                this->book[i].getBookDetails();
                cout << "---------------------------------------\n";
            }
        }
    }
    void viewLibrary(){
        cout << "Library Books "<< endl;
        for(int i = 0;i<this->No_of_Books;i++){
            this->book[i].getBookDetails();
            cout << "---------------------------------------\n";
        }
    }
    int searchBookbyName(string bookName){
        for(int i = 0;i<this->No_of_Books;i++){
            if(this->book[i].getBookName() == bookName){
                cout << "Book Found " << endl;
                cout << "Book id : "<< this->book[i].getBookId() << endl;
                cout << "Book Name : " << this->book[i].getBookName() << endl;
                cout << "Book Author Name : "<< this->book[i].getAuthorName() << endl;
                return 1;
            }
        }
        cout << bookName << "is not available in this library." << endl;
        return 0;
    }
    int searchBookbyAuthorName(string authorName){
        int no_of_Book = 0;
        for(int i = 0;i<this->No_of_Books;i++){
            if(this->book[i].getAuthorName() == authorName){
                cout << "Book Found " << endl;
                cout << "Book id : "<< this->book[i].getBookId() << endl;
                cout << "Book Name : " << this->book[i].getBookName() << endl;
                cout << "Book Author Name : "<< this->book[i].getAuthorName() << endl;
                cout << "---------------------------------------\n";
                no_of_Book++;
            }
        }
        if(no_of_Book == 0){
            cout << authorName << "'s book is not found." <<endl;
        }
        return 0;
    } 
    int searchBookbyId(int id){
        for(int i = 0;i<this->No_of_Books;i++){
            if(this->book[i].getBookId() == id){
                cout << "Book Found " << endl;
                cout << "Book id : "<< this->book[i].getBookId() << endl;
                cout << "Book Name : " << this->book[i].getBookName() << endl;
                cout << "Book Author Name : "<< this->book[i].getAuthorName() << endl;
                return 1;
            }
        }
        cout << id << "book is not available in this library." << endl;
        return 0;
    }   
};

int main(){
    int option;
    string searchedAuthorName;
    string searchedBookName;
    Library library;
    int fg = 1;
    while(fg){
    cout << "1.create Libary\n2.View Library\n3.search Books\n4.Issue Book\n5.Return Book\n6.Exit\n";
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case (1):
        library.createlibrary();
        break;
    case (2):
        int choice2;
        cout << "1.Display All Books\n2.Display Issued Books\n3.Display Available Books\n" << endl;
        cin >> choice2;
        if(choice2 == 1){
            library.viewLibrary();
        }
        if (choice2 == 2){
            library.displayIssuedBook();
        }
        if (choice2 == 3){
            library.displayAvailableBook();
        }
    break;
    case (3):
        int searchby;
        cout <<"1.Search By Author Name\n2.Search By Book Name\n3.Search By Book Id \n";
        cin >> searchby;

        switch(searchby)
        {
        case (1):
            cout << "Enter Book Author Name : ";
            cin >> searchedAuthorName;
            library.searchBookbyAuthorName(searchedAuthorName);            
            break;
        case (2):
            cout << "Enter Book Name : ";
            cin >> searchedBookName;
            library.searchBookbyName(searchedBookName);
            break;
        case (3):
            int searchedId;
            cout << "Enter Book Id : ";
            cin >> searchedId;
            library.searchBookbyId(searchedId);
            break;
        default:
            break;
        }
        break;
    case 4:
        library.issueBook();
        break;
    case 5:
        library.returnbook();
        break;
    case 6:
        fg = 0;
        break;
    default:
        break;
        }
    }
}