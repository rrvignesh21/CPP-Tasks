#include<iostream>
using namespace std;
/* Write a C++ program that accepts sales unit price and sales quantity of various items and
 computes total sales amount and the average sales quantity.
 All input values must be greater than or equal to 0 and less than or equal to 1,000, and the number of pairs of sales unit and sales quantity does not exceed 100.
 If a fraction occurs in the average of the sales quantity, round the first decimal place. */
struct items
{   
    int unit_price;
    int sales_quantity;
};
typedef struct items item;

int main(){
    int number_of_items;
    cout << "Enter number of items : ";
    cin >> number_of_items;
    item items[number_of_items];
    for(int i = 0;i < number_of_items;i++){
        cout << "Enter unit price of "<< i + 1 << " item : ";
        cin >> items[i].unit_price;
        cout << "Enter sales quantity of "<< i+1 << " item : ";
        cin >> items[i].sales_quantity;
    }
    int total_sales_amount;
    double average_sales_quantity;
    int temptotal = 0;
    for(int i = 0;i < number_of_items;i++){
        temptotal += items[i].sales_quantity;
        total_sales_amount += (items[i].sales_quantity)*(items[i].unit_price);
    }
    average_sales_quantity = temptotal / (float)number_of_items;
    cout << "Total Sales Amount : " << total_sales_amount << endl;
    cout << "Average Sales Quantity : " << average_sales_quantity << endl;
}