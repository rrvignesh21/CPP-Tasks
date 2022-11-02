#include<iostream>
#include<fstream>
#include<ranges>
#include<vector>
#include<list>
#include<filesystem>
using namespace std;

class Customer{
    int id;
    string name;
    int phoneNumber;
    int no_Of_Product_Bought;
};

class Rating{
    double rating;
    public:
    Rating(){
        this->rating;
    }
    void setRating(string name){
        try
        {
lb1:    cout << "Rate the "<< name << " out of 0 - 5 : ";
        if(!(cin >> rating)){
            throw "Invalid data\nuse integers or double ";
        }
        if(rating > 5 | rating < 0){
            cout << "enter valid rating ";
            goto lb1;
        }
        }
        catch(const char *errorchar){
            cout << errorchar << endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }       
    }
    double getRating(){
        return (this->rating);
    }
};
// struct Product{
//     double price;
//     int quantity;
//     string brandName;
//     string electronicsType;
//     string modelName;
// };
class Product{
    protected:
    double price;
    int quantity;
    Rating rating;
    public:
    virtual double getPrice() = 0;
    virtual int getQuantity() = 0;
    virtual void setPrice(double setprice) = 0;
    virtual void setQuantity(int setquantity) = 0;
    virtual void buyProduct(int numberof) = 0;
    virtual void displayProduct() = 0;
};
class Electronics:public Product{
    string brandName;
    string electronicsType;
    string modelName;
    public:
    // Electronics(Electronics &copy){
    //     this->brandName = copy.getBrandName();
    //     this->electronicsType = copy.getElectonicsType();
    //     this->modelName = copy.getmodelName();
    //     this->price = copy.getPrice();
    //     this->quantity = copy.getQuantity();
    // }
    Electronics(){

    }
    Electronics(string type){
        this->electronicsType = type;
    }
    void setBrandName(string Brandname){
        this->brandName = Brandname;
    }
    void setmodelName(string Modelname){
        this->modelName = Modelname;
    }
    string getBrandName(){
        return(this->brandName);
    }
    string getmodelName(){
        return(this->modelName);
    }
    string getElectonicsType(){
        return(this->electronicsType);
    }
    double getPrice(){
        return (this->price);
    }
    int getQuantity(){
        return (this->quantity);
    }
    void setPrice(double setprice){
        this->price = setprice;
    }
    void setQuantity(int setquantity){
        this->quantity = setquantity;
    }
    void buyProduct(int numberof){
        this->quantity = this->quantity - numberof;
    }
    void displayProduct(){
        cout << "Type : " << this->electronicsType << endl;
        cout <<"Brand : " << this->brandName << "\n";
        cout << "Model : " <<  this->modelName << "\n";
        cout << "Cost : " << this->price << "\n";
        cout << "No of prod : " <<  this->quantity << "\n";         
    }
};



// class Edible{
    

// };
// class Fruit{
//     string fruitName;
//     public:
//     void setfruitName(string Name){
//         this->fruitName = Name;
//     }    
// };
// class Clothes{
//     string size;

// };

class Admin{
    
    public:
    void createNewProduct(){
        string productCategory;
        cout << "Enter the product Category : ";
        cin >> productCategory;
        fstream productFile;
        try
        {
            if(filesystem::exists("Products/"+productCategory)){
                string BrandName;
                cout << "Enter " << productCategory <<"'s Brand Name : ";
                cin >> BrandName;
                ofstream BrandFile("Products/"+productCategory+"/"+BrandName+".txt",ios::out);
                int No_of_Models;
                cout << "Enter No of Models : ";
                cin >> No_of_Models;
                // vector<Electronics> list_of_products;
                for(int i = 0;i<No_of_Models;i++){
                    cout << "ENTRY "<< i+1 << endl;
                    Electronics mobiles(productCategory);
                    mobiles.setBrandName(BrandName);
                    string modelName;
                    cout << "Enter Model Name : ";
                    cin >> modelName;
                    mobiles.setmodelName(modelName);
                    cin.ignore();
                    double price;
                    cout << "Enter price of "<< mobiles.getBrandName() << "'s " << mobiles.getmodelName() << " : ";
                    cin >> price;
                    mobiles.setPrice(price);
                    int quantity;
                    cout <<  "Enter quantity of "<< mobiles.getBrandName() << "'s " << mobiles.getmodelName() << "  : ";
                    cin >> quantity;
                    mobiles.setQuantity(quantity);
                    BrandFile << mobiles.getElectonicsType() << " " << mobiles.getBrandName() << " " << mobiles.getmodelName() << " " << mobiles.getPrice() << " " << mobiles.getQuantity() << "\n";
                    // list_of_products.push_back(mobiles);
                }
                BrandFile.close();
            }
            else{
                throw ("There is no product Category as " + productCategory);
            }
        }
        catch(const char * errorchar)
        {
            cout << errorchar << endl;
        }


    }
    void displayProduct(){
        string productCategory;
        cout << "Enter the product Category : ";
        cin >> productCategory;
        fstream productFile;
        try
        {
            if(filesystem::exists("Products/"+productCategory)){
                string BrandName;
                cout << "Enter " << productCategory <<"'s Brand Name : ";
                cin >> BrandName;
                if(filesystem::exists("Products/"+productCategory+"/" + BrandName + ".txt")){
                ifstream BrandFile("Products/"+productCategory+"/"+BrandName + ".txt",ios::in);
                // vector<Electronics> list_of_products;
                // BrandFile.read((char *)&list_of_products,sizeof(list_of_products));
                // list_of_products.size();
                // cout << "Outer : " << list_of_products[0].getmodelName() << "\n";
                // Electronics test;
                string bufferString;
                while (BrandFile >> bufferString)
                {
                    while(bufferString != "\n"){
                            cout << bufferString << endl;
                        }
                        cout << "\n";
                    // cout << "Type : "<< test.getElectonicsType() << "\n";
                    // cout <<"Brand : " << test.getBrandName() << "\n";
                    // cout << "Model : " <<  test.getmodelName() << "\n";
                    // cout << "Cost : " << test.getPrice() << "\n";
                    // cout << "No of prod : " <<  test.getQuantity() << "\n";
                    // test.displayProduct(); 
                    cout << "---------------------------------------------------------------------\n";                     
                }
                
                // for(int i = 0;i < list_of_products.size();i++){
                //     cout << "Type : "<< list_of_products[i].getElectonicsType() << "\n";
                //     cout <<"Brand : " << list_of_products[i].getBrandName() << "\n";
                //     cout << "Model : " <<  list_of_products[i].getmodelName() << "\n";
                //     cout << "Cost : " << list_of_products[i].getPrice() << "\n";
                //     cout << "No of prod : " <<  list_of_products[i].getQuantity() << "\n"; 
                //     cout << "---------------------------------------------------------------------\n";                  
                // }
                // for(auto i = list_of_products.begin();i != list_of_products.end();i++){
                //     Electronics appl = *i;
                //     cout << "Type : "<< appl.getElectonicsType() << "\n";
                //     cout <<"Brand : " << appl.getBrandName() << "\n";
                //     cout << "Model : " <<  appl.getmodelName() << "\n";
                //     cout << "Cost : " << appl.getPrice() << "\n";
                //     cout << "No of prod : " <<  appl.getQuantity() << "\n"; 
                //     cout << "---------------------------------------------------------------------\n"; 

                // }
                BrandFile.close();
                }
                else{
                    throw ("there is no brand Named "+ BrandName);                
                }
            }
            else{
                throw ("There is no product Category as " + productCategory);
            }
        }
        catch(const char * errorchar)
        {
            cout << errorchar << endl;
        }
        
    }
};
int main(){
    
    Admin admin;
    admin.createNewProduct();
    admin.displayProduct();

}
