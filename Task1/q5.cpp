#include<iostream>
using namespace std;
/* There are four different points on a plane: A(x1, y1), B(x2, y2), C(x3, y3) and D(x4, y4).
 Write a C++ program to check whether two straight lines AB and CD are orthogonal or not. 
 Input:
0 6
5 6
3 8
3 2
Output:
yes
 */
int main(){
    struct point{
        int x;
        int y;
    };
    typedef struct point point;
    point A,B,C,D;
    cout << "Enter A coordinate: ";
    cin >> A.x >> A.y;
    cout << "Enter B coordinate: ";
    cin >> B.x >> B.y;
    cout << "Enter C coordinate: ";
    cin >> C.x >> C.y;
    cout << "Enter D coordinate: ";
    cin >> D.x >> D.y;
    int slope_AB,slope_CD;
    if(B.x - A.x == 0 && D.x - C.x == 0){
        cout << "given line is not orhtogonal to each other -1";
    }
    else if(B.x - A.x  == 0){
        slope_CD = (D.y - C.y) / (D.x - C.x);
        if(slope_CD == 0){
        cout << "given line AB and CD is orthogonal to each other";
        }
        else{
        cout << "given line is not orhtogonal to each other";
        }
    }
    else if(D.x - C.x == 0){
        slope_AB = (B.y - A.y) / (B.x - A.x);
        if(slope_AB == 0){
        cout << "given line AB and CD is orthogonal to each other";
        }
        else{
        cout << "given line is not orhtogonal to each other";
        }
    
    }
    else{
    slope_AB = (B.y - A.y) / (B.x - A.x);
    slope_CD = (D.y - C.y) / (D.x - C.x);
    if(slope_AB * slope_CD == -1){    
            cout << "given line AB and CD is orthogonal";
    }
    else{
       cout << "given line is not orhtogonal to each other";
       }
    }
}