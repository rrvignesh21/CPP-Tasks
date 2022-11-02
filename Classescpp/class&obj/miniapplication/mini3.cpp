#include<iostream>
#include<fstream>
#include<vector>
#include<filesystem>
#include<string>
using namespace std;

class Customer{
    int id;
    string username;
    string password;
    string name;
    string phoneNumber;
    int no_Of_Product_Bought;
    string last_Bought_product;
    public:
    Customer()
    {   
        this->last_Bought_product = "-";
        this->no_Of_Product_Bought = 0;
    }
    void setid(int userid){
        this->id = userid;
    }
    void setusername(string userName){
        this->username = userName;
    }
    void setpassword(string password){
        this->password = password;
    }
    void setName(string name){
        this->name = name;
    }
    void setphoneNumber(string userNumber){
        this->phoneNumber = userNumber ;
    }
    void setNo_Of_Product_Bought(int No_Of_Product){
        this->no_Of_Product_Bought += No_Of_Product;
    }
    void setLast_Bought_Product(string productName){
        this->last_Bought_product = productName;
    }
    int getId(){
        return (this->id);
    }
    string getName(){
        return (this->name);
    }
    string getUserName(){
        return (this->username);
    }
    string getpassword(){
        return (this->password);
    }
    string getPhoneNumber(){
        return (this->phoneNumber);
    }
    int getNo_Of_Product_Bought(){
        return (this->no_Of_Product_Bought);
    }
    string getLast_Bought_Product(){
        return (this->last_Bought_product);
    }
    friend std::ostream & operator << (std::ostream &out, const Customer & customer);
    friend std::istream & operator >> (std::istream &in,  Customer &customer);
    void displayInfo(){
        cout << "NAME : "<<this->name << endl;
        cout << "PHONE Number : "<< this->phoneNumber << endl;
        cout << "No of product Bought : "<< this->no_Of_Product_Bought << endl;
        cout << "Last Bought Product : "<< this->last_Bought_product << endl;
    }
};
std::ostream & operator << (std::ostream &out, const Customer &customer){
    out << customer.id << "\n" << customer.username << "\n" << customer.password << "\n" << customer.name << "\n" << customer.phoneNumber << "\n" << customer.no_Of_Product_Bought << "\n" << customer.last_Bought_product << endl;
    return out;

}
std::istream & operator >> (std::istream &in,  Customer &customer){
    in >> customer.id;
    in >> customer.username;
    in >> customer.password;
    in >> customer.name;
    in >> customer.phoneNumber;
    in >> customer.no_Of_Product_Bought;
    in >> customer.last_Bought_product;
    return in;
}

class Product{
    protected:
    double price;
    int quantity;
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
        cout << "No of product : " <<  this->quantity << "\n";         
    }
    friend std::ostream & operator << (std::ostream &out, const Electronics & electronics);
    friend std::istream & operator >> (std::istream &in,  Electronics &electronics);
};

std::ostream & operator << (std::ostream &out, const Electronics &electronics){
    out << electronics.electronicsType << "\n" << electronics.brandName << "\n" << electronics.modelName << "\n" << electronics.price << "\n" << electronics.quantity <<endl;
    return out;
}
std::istream & operator >> (std::istream &in,  Electronics &electronics){
    in >> electronics.electronicsType;
    in >> electronics.brandName;
    in >> electronics.modelName;
    in >> electronics.price;
    in >> electronics.quantity;
    return in;
}

class Admin{
    
    public:
    void createNewProduct(){ //Create new brand of product from a existing catogary
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
                ofstream BrandFile("Products/"+productCategory+"/"+BrandName+".txt",ios::app | ios::binary);
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
                    BrandFile << mobiles;
                    // list_of_products.push_back(mobiles);
                }
                BrandFile.close();
            }
            else{
                throw ("There is no product Category as given");
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
                Electronics test;
                
                while (BrandFile >> test)
                {
                    cout << "Type : "<< test.getElectonicsType() << "\n";
                    cout <<"Brand : " << test.getBrandName() << "\n";
                    cout << "Model : " <<  test.getmodelName() << "\n";
                    cout << "Cost : " << test.getPrice() << "\n";
                    cout << "No of prod : " <<  test.getQuantity() << "\n";
                    cout << "---------------------------------------------------------------------\n";                     
                }
                BrandFile.close();
                }
                else{
                    throw ("there is no brand Named as mentioned");                
                }
            }
            else{
                throw ("There is no product Category as given ");
            }
        }
        catch(const char * errorchar)
        {
            cout << errorchar << endl;
        }  
    }
};


class UserManagement{

    public:

    void createUser(Customer &newuser){ //Create New User when register process is successfull 
    if(fopen("Customers.txt","r")){ //if there is already user exist
        fstream userFile("Customers.txt",ios::app|ios::binary);
        fstream no_of_user("userCount.txt",ios::in);  // for keep count of number of users in the Application
        int usercount;
        no_of_user >> usercount;
        usercount = usercount + 1;
        no_of_user.close();
        // int iuserCount = stoi(usercount);
        // iuserCount = iuserCount + 1;
        newuser.setid(usercount);
        fstream no_of_user1("userCount.txt",ios::out);
        no_of_user1 << usercount;
        userFile << newuser;
        userFile.close();
        no_of_user1.close();
    }
    else{ // if there is no user exist
        fstream userFile("Customers.txt",ios::app|ios::binary);
        fstream no_of_user("userCount.txt",ios::out);
        no_of_user << 1 << "\n";
        newuser.setid(1);
        userFile << newuser;
    }
}
    int loginCheck(string username,string password){
    ifstream UserFile("Customers.txt",ios::in);
    Customer user;
    while (UserFile >> user)
    {   
        if((user.getUserName() == username) & (user.getpassword() == password)){
            return user.getId();
        }
        else{
            continue;
        }
    }
    return -1;    
}

    bool checkAldreadyExistUsers(string username,string PhoneNumber){

    fstream UserFile("Customers.txt",ios::in);
    Customer user;
    while(UserFile >> user){
        if((user.getUserName() == username) & (user.getPhoneNumber() == PhoneNumber)){
            return false;
        }
        if(user.getName() == username){
            if(user.getPhoneNumber() != PhoneNumber){
                continue;
            }
        }        
    }
    return true;
}

    bool buyProduct(string productType,string productCompanyName,int idofproduct){
    fstream productFileRead("Products/" + productType + "/" + productCompanyName + ".txt",ios::in);
    Electronics product;
    vector<Electronics> productList;
    while (productFileRead >> product)
    {
        productList.push_back(product);
    }
    productFileRead.close();

    if(idofproduct > productList.size() | idofproduct <= 0){
            return false;
        }
    else{
            if(productList[idofproduct-1].getQuantity() == 0){
                cout << "OUT OF STOCK!!";
                return false;
            }
            else{
            fstream productFileWrite("Products/" + productType + "/" + productCompanyName + ".txt",ios::out);
            productList[idofproduct - 1].buyProduct(1);
            for(Electronics tempproduct : productList){
                productFileWrite << tempproduct;
            }
            productFileWrite.close();
            return true;
            }
        }
}
    bool checkPhoneNumber(string PhoneNumber){
    if(PhoneNumber.length() != 10){
        return false;
    }
    for(int i = 0;i < PhoneNumber.length();i++){
        if(isdigit(PhoneNumber[i])){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
        }

    void updateUserFile(vector<Customer> userlist){
    fstream userFile("Customers.txt",ios::out);
    
    for(int i = 0;i < userlist.size();i++){
        userFile << userlist[i];
        }
    userFile.close();
    }
};

class Cart{
    int customerId;
    int productId;
    Electronics cartproduct;
    public:
    void setCustomerId(int id){
        this->customerId = id;
    }
    void setProductId(int id){
        this->productId = id;
    }
    void setCartProduct(Electronics product){
        this->cartproduct = product;
    }
    int getCustomerId(){
        return this->customerId;
    }
    int getProductId(){
        return this->productId;
    }
    Electronics getCartProduct(){
        return this->cartproduct;
    }
    friend std::ostream & operator << (std::ostream &out, const Cart & product);
    friend std::istream & operator >> (std::istream &in,  Cart &product);
};
std::ostream & operator << (std::ostream &out, const Cart & product){
    out << product.customerId << "\n" << product.productId << "\n" << product.cartproduct << endl;
    return out; 
}
std::istream & operator >> (std::istream &in,  Cart &product){
    in >> product.customerId;
    in >> product.productId;
    in >> product.cartproduct;
    return in;
}

class CartManagement{
    public:
    void addProductToCart(Cart &product){
        fstream cartfile("Cart.txt",ios::app);
        cartfile << product;
        cartfile.close();
    }

    void displayCartOfSpecificUser(int userId){
        fstream cartfile("Cart.txt",ios::in);
        Cart temp;
        int usercartcount = 1;
        while(cartfile >> temp){
            if(userId == temp.getCustomerId()){
                cout << usercartcount << " " << temp.getCartProduct().getmodelName() << "\t$" << temp.getCartProduct().getPrice() << "\n";
                usercartcount++;
            }
        }
    }

    bool buy(int userid,int productid,int cartid,vector<Customer> &user){
        fstream cartfile("Cart.txt",ios::in);
        Cart temp;
        vector<Cart> cartlist;
        UserManagement manageuser;
        while(cartfile >> temp){
            cartlist.push_back(temp);
        }
        cartfile.close();
        int userprocductcount = 0;
        int bought = 0;
        for(int i = 0;i < cartlist.size();i++){
            if(cartlist[i].getCustomerId() == userid){
                userprocductcount++;
            }
            if(((cartlist[i].getCustomerId() == userid)&(cartlist[i].getProductId() == productid)) & (cartid == userprocductcount)){
                manageuser.buyProduct(cartlist[i].getCartProduct().getElectonicsType(),cartlist[i].getCartProduct().getBrandName(),cartlist[i].getProductId());
                user.at(userid - 1).setLast_Bought_Product(cartlist[i].getCartProduct().getmodelName());
                user.at(userid - 1).setNo_Of_Product_Bought(1);
                manageuser.updateUserFile(user);
                this->deleteCart(userid,productid,cartid);
                bought = 1;
            }
        }
        cartfile.close();
        if(bought == 1){
            return true;
        }
        else{
            return false;
        }        
    }
    vector<Cart> returnSpecificCartList(int userId){
        fstream cartfile("Cart.txt",ios::in);
        Cart temp;
        vector<Cart> cartlist;
        while (cartfile >> temp)
        {
            if(temp.getCustomerId() == userId){
                cartlist.push_back(temp);
            }
            else{
                continue;
            }
        }
        cartfile.close();
        return cartlist;
    }
    bool deleteCart(int userid,int productid,int cartid){
        fstream cartfile("Cart.txt",ios::in);
        Cart temp;
        vector<Cart> cartlist;
        while(cartfile >> temp){
            cartlist.push_back(temp);
        }
        cartfile.close();
        cartfile.open("Cart.txt",ios::out);
        int userprocductcount = 0;
        int deleted = 0;
        for(int i = 0;i < cartlist.size();i++){
            if(cartlist[i].getCustomerId() == userid){
                userprocductcount++;
            }
            if(((cartlist[i].getCustomerId() == userid)&(cartlist[i].getProductId() == productid)) & (cartid == userprocductcount)){
                deleted = 1;
                continue;
            }
            else{
                cartfile << cartlist[i];
            }
        }
        cartfile.close();
        if(deleted == 1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){     

    try{
    Customer newUser;
    UserManagement manage;
    CartManagement cartmanage;

    bool flag = true;
    while(flag){
        cout << "\t\t\t1.Login\n\t\t\t2.Register\n\t\t\t3.exit\n";
        int option;
        
    if(!(cin >> option)){
            throw "Invalid entry";
        }
    if(option == 1){
        string phonenumber;
        string name;
        cout << "Enter Login Id : ";
        cin >> name;
        cin.ignore();
        cout << "Enter Phone Number(Password) : ";
        getline(cin,phonenumber);
        int login_result = manage.loginCheck(name,phonenumber);
        fstream userFile("Customers.txt",ios::in);
        vector<Customer> user;
        Customer tempUser;
        while(userFile >> tempUser){
                user.push_back(tempUser);
        }
            userFile.close();
        if(login_result > 0){
            
            bool loginzone = true;
            while(loginzone){
            cout << "\t\t\t1.Shopping\n\t\t\t2.userDetails\n\t\t\t3.view cart\n\t\t\t4.logout\n";
            int useroption;
            if(!(cin >> useroption)){
                throw "Invalid entry !!";
            }
            if(useroption == 1){
            bool flag2 = true;
            while(flag2){
            cout << "\t\t\t1.Mobile\n\t\t\t2.back";
            int suboption;
            if(!(cin >> suboption)){
                throw "Invalid entry";
            }
            if(suboption == 1){
                cout << "\t\t\t1.Samsung\n\t\t\t2.Apple\n\t\t\t3.Mi\n\n";
                int suboption2;
                if(!(cin >> suboption2)){
                throw "Invalid entry";
                }
                if(suboption2 == 1){
                    fstream Samsung("Products/Mobiles/Samsung.txt",ios::in);
                    Electronics samsungMobile;
                    vector<Electronics> samsunglist;
                    int option1 = 1;
                    while (Samsung >> samsungMobile)
                    {
                        if(samsungMobile.getQuantity() == 0){
                            cout << "\t\t\t" << option1 << ". " << samsungMobile.getmodelName() << " Price : " << samsungMobile.getPrice() << "(OUT OF STOCK)"<< "\n"; 
                        }
                        else{
                        cout << "\t\t\t" << option1 << ". " << samsungMobile.getmodelName() << " Price : " << samsungMobile.getPrice()<< "\n"; 
                        }
                        samsunglist.push_back(samsungMobile);
                        option1++;
                    }
                    cout << "\n";
                    Samsung.close();
                    int buyoption;
                    if(!(cin >> buyoption)){
                    throw "Invalid entry";
                    }
                    int buy_or_cart;
                    cout << "\t\t\t1.Buy\n\t\t\t2.Add to Cart\n";
                    if(!(cin >> buy_or_cart)){
                    throw "Invalid entry";
                    }
                    if(buy_or_cart == 1){
                    if(manage.buyProduct("Mobiles","Samsung",buyoption)){
                        user[login_result - 1].setNo_Of_Product_Bought(1);
                        user[login_result - 1].setLast_Bought_Product(samsunglist[buyoption - 1].getmodelName());
                        manage.updateUserFile(user);
                        cout << "Product bought\n";
                    }
                    else{
                        cout << "\ncoudn't buy this product.\n";
                        }
                    }
                    else if(buy_or_cart == 2){
                        Cart tempcart;
                        tempcart.setCustomerId(login_result);
                        tempcart.setProductId(buyoption);
                        tempcart.setCartProduct(samsunglist[buyoption - 1]);
                        cartmanage.addProductToCart(tempcart);
                    }
                    else{
                        flag2 = false;
                    }
                }
                else if(suboption2 == 2){
                    fstream Apple("Products/Mobiles/Apple.txt",ios::in);
                    Electronics appleMobile;
                    vector<Electronics> applelist;
                    int option1 = 1;
                    while (Apple >> appleMobile)
                    {
                        if(appleMobile.getQuantity() == 0){
                        cout << "\t\t\t" << option1 << ". " << appleMobile.getmodelName() << " Price : " << appleMobile.getPrice() << "(OUT OF STOCK)" << "\n";
                        }
                        else{
                        cout << "\t\t\t" << option1 << ". " << appleMobile.getmodelName() << " Price : " << appleMobile.getPrice()<< "\n"; 
                        }
                        applelist.push_back(appleMobile);
                        option1++;
                    }
                    cout << "\n";
                    Apple.close();
                    int buyoption;
                    if(!(cin >> buyoption)){
                    throw "Invalid entry";
                    }
                    cout << "\t\t\t1.Buy\t\t\t2.Add to Cart\n";
                    int buy_or_cart;
                    if(!(cin >> buy_or_cart)){
                        throw "Invalid entry";
                    }
                    if(buy_or_cart == 1){
                    if(manage.buyProduct("Mobiles","Apple",buyoption)){
                        user[login_result - 1].setNo_Of_Product_Bought(1);
                        user[login_result - 1].setLast_Bought_Product(applelist[buyoption - 1].getmodelName());
                        manage.updateUserFile(user);
                        cout << "Product bought\n";
                    }
                     else{
                        cout << "\nInvalid option";
                        }
                    }
                    else if(buy_or_cart == 2){
                        Cart tempcart;
                        tempcart.setCustomerId(login_result);
                        tempcart.setProductId(buyoption);
                        tempcart.setCartProduct(applelist[buyoption - 1]);
                        cartmanage.addProductToCart(tempcart);
                    }
                    else{
                        flag2 = false;
                    }
                }
                else if(suboption2 == 3){
                    fstream Mi("Products/Mobiles/Mi.txt",ios::in);
                    Electronics miMobile;
                    vector<Electronics> milist;
                    int option1 = 1;
                    while (Mi >> miMobile)
                    {
                        if(miMobile.getQuantity() == 0){
                        cout << "\t\t\t" << option1 << ". " << miMobile.getmodelName() << " Price : " << miMobile.getPrice() << "(OUT OF STOCKS)" << "\n"; 
                        }
                        else{
                        cout << "\t\t\t" << option1 << ". " << miMobile.getmodelName() << " Price : " << miMobile.getPrice()<< "\n"; 
                        }
                        milist.push_back(miMobile);
                        option1++;
                    }
                    cout << "\n";
                    Mi.close();
                    int buyoption;
                    if(!(cin >> buyoption)){
                        throw "Invalid entry";
                    }
                    cout << "\t\t\t1.Buy\t\t\t2.Add to Cart\n";
                    int buy_or_cart;
                    if(!(cin >> buy_or_cart)){
                        throw "Invalid entry";
                    }
                    if(buy_or_cart == 1){
                    if(manage.buyProduct("Mobiles","Mi",buyoption)){
                        user[login_result - 1].setNo_Of_Product_Bought(1);
                        user[login_result - 1].setLast_Bought_Product(milist[buyoption - 1].getmodelName());
                        manage.updateUserFile(user);
                        cout << "Product bought\n";
                    }
                    else{
                        cout << "Invalid option";
                        }
                    }
                    else if(buy_or_cart == 2){
                        Cart tempcart;
                        tempcart.setCustomerId(login_result);
                        tempcart.setProductId(buyoption);
                        tempcart.setCartProduct(milist[buyoption - 1]);
                        cartmanage.addProductToCart(tempcart);
                    }
                    else{
                        flag2 = false;
                    }
                    
                }
            }
            else if(suboption == 2){
                flag2 = false;
            }
        }
            }
            else if(useroption == 2){
                cout <<"Name : " << user[login_result - 1].getName() << "\n";
                cout << "Phone Number : " << user[login_result - 1].getPhoneNumber() << "\n";
                cout << "Product Bought recently : " << user[login_result - 1].getLast_Bought_Product() << "\n";
                cout << "No of Product Bought : "<< user[login_result - 1].getNo_Of_Product_Bought() << "\n";
            }
            else if(useroption == 3){
                cartmanage.displayCartOfSpecificUser(login_result);
                cout << "Enter option : ";
                int cartoption;
                if(!(cin >> cartoption)){
                    throw "Invalid entry";
                }
                cout << "\t\t\t1.Buy\t\t\t2.delete\n";
                int buyOrdeleteCart;
                cin >> buyOrdeleteCart;
                vector<Cart> usercartlist = cartmanage.returnSpecificCartList(login_result);
                if(buyOrdeleteCart == 1){
                    cartmanage.buy(login_result,usercartlist[cartoption - 1].getProductId(),cartoption,user);
                    cout << "Bought\n";
                }
                else if(buyOrdeleteCart == 2){
                    cartmanage.deleteCart(login_result,usercartlist[cartoption - 1].getProductId(),cartoption);
                    cout << "Cart deleted\n";
                }
                else{
                    cout << "Invalid option \n";
                }
            }
            else if(useroption == 4){
                loginzone = false;
            }
        }
    }   
        else{
            cout << "Invalid id or Password" << endl;
        }        
    }
    else if(option == 2){
        string phonenumber;
        string name;
        Customer newUser;
        // newUser.setid(id);
        cout << "Enter your Name : ";
        cin >> name;
        newUser.setName(name);
 lb2:   cout << "Enter Phone Number : ";
        cin >> phonenumber;

        if(manage.checkPhoneNumber(phonenumber)){
            newUser.setphoneNumber(phonenumber);
        }
        else{
            cout << "Invalid Phone Number" << endl;
            goto lb2;
        }
        if(manage.checkAldreadyExistUsers(name,phonenumber)){
            manage.createUser(newUser);
        }
        else{
            cout << "User Already exist\n";
        }
    }
    else if(option == 3){
        flag = false;
        }
    }
}
    catch(const char * errorchar){
        cout << errorchar << endl;
    }
    // Admin admin;
    // admin.createNewProduct();
    // admin.displayProduct();
    
}




