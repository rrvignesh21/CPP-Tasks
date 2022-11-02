#include<iostream>
using namespace std;
/* Create an application for mobile phone price detection using abstract class and virtual functions using C++. */
class MobileBrand{
    protected:
    string BrandName;
    public:
    virtual string getBrandName() = 0;
    virtual string getName() = 0;
    virtual double getPrice() = 0;
};

class Apple : public MobileBrand{
    protected:
    string ModelName;
    double price; 
    public:
    Apple(){
        this->BrandName = "Apple";
    }
    string getBrandName(){
        return (this->BrandName);
    }
};
class Apple6A : public Apple{

    public:
    Apple6A(){
        this->ModelName = "Apple6A";
        this->price = 12423.99;
    }
    string getName(){
        return (this->ModelName);
    }
    double getPrice(){
        return (this->price);
    }
};
class Apple9 : public Apple{
    public:
    Apple9(){
        this->ModelName = "Apple9";
        this->price = 60499.99;
    }
    string getName(){
        return (this->ModelName);
    }
    double getPrice(){
        return (this->price);
    }

};
class Apple12A : public Apple{
    public:
    Apple12A(){
        this->ModelName = "Apple12A";
        this->price = 80599.55;
    }
    string getName(){
        return (this->ModelName);
    }
    double getPrice(){
        return (this->price);
    }

};
class Samsung : public MobileBrand{
    protected:
    string ModelName;
    double price;
    public:
    Samsung(){
        this->BrandName = "Samsung";
    }

    string getBrandName(){
        return (this->BrandName);
    }
};
class Samsung_S10 : public Samsung{
    public:
    Samsung_S10(){
        this->ModelName = "Samsung S10";
        this->price = 9999.99;
    }
    string getName(){
        return (this->ModelName);
    }
    double getPrice(){
        return (this->price);
    }

};
class Samsung_S20 : public Samsung{
    public:
    Samsung_S20(){
        this->ModelName = "Samsung S20";
        this->price = 19999.99;
    }
    string getName(){
        return (this->ModelName);
    }
    double getPrice(){
        return (this->price);
    }

};
class Samsung_S30 : public Samsung{
    public:
    Samsung_S30(){
        this->ModelName = "Samsung S30";
        this->price = 29999.99;
    }
    string getName(){
        return (this->ModelName);
    }
    double getPrice(){
        return (this->price);
    }
};
int main(){
    cout << "Enter the Brand Name : ";
    string input_BrandName;
    getline(cin,input_BrandName);
    string input_ModelName;
    Apple *apple;
    Samsung *samsung;
    cout << "enter Model Name : ";
    getline(cin,input_ModelName);
    apple = new Apple12A();
    samsung = new Samsung_S10();
//    cout << A->getBrandName() << "  " << A->getName() << endl;   
    if (apple->getBrandName() == input_BrandName){
        if(input_ModelName == apple->getName()){
            cout << "Price : " << apple->getPrice() << endl;
        }   
        else{
            apple = new Apple6A();
            if(input_ModelName == apple->getName()){
                cout << "Price : " << apple->getPrice() << endl;
            }
            else{
                apple = new Apple9();
                if(input_ModelName == apple->getName()){
                    cout << "Price : " << apple->getPrice() << endl;
                }   
                else{
                    cout << "There no model named "<< input_ModelName << " is here";
                }
            }  
        }
    }
    else if (samsung->getBrandName() == input_BrandName){
        if(input_ModelName == samsung->getName()){
            cout << "Price : " << samsung->getPrice() << endl;
        }   
        else{
            samsung = new Samsung_S20();
            if(input_ModelName == samsung->getName()){
                cout << "Price : " << samsung->getPrice() << endl;
            }
            else{
                samsung = new Samsung_S30();
                if(input_ModelName == samsung->getName()){
                    cout << "Price : " << samsung->getPrice() << endl;
                }
                else{
                    cout << "There no model named "<< input_ModelName << " is here";
                }   
            }  
        }
    }
    else{
        cout << "There no brand named "<< input_BrandName << " is here";

    }
    delete apple;
}