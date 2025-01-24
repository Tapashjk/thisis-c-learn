
// this helps you tho waht inner and outer loop klooks like:
// #include <iostream>
// using namespace std;
// int main()
// {
//     int i,j;
//     for(i=1;i<=2;i++){
//         cout<<"     outer loop:"<<i<<"\n";
//         for(j=1;j<=5;j++){
//         cout<<"inner loop :"<<j<<endl;
//         }
//     }

//     return 0;
// }

//     *
//    **
//   ***
//  ****
// *****
//  ****
//   ***
//    **
//     *



// #include <iostream>
// using namespace std;
// int main(){
//     int i,j,k;
     
//     // lower paert of the dimond
//     for(i=5;i>=1;i--){
//         // cout<<i;
//         for (j=5;j>i;j--){
//             cout<<" ";
//         }
//         for(k=i;k>0;k--){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     for(i=5;i>0;i--){
//         for(j=2;j<i;j++){
//             cout<<" ";
//         }
//         for(k=5;k>=i-1;k--){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
    
     
//     return 0;
   
// }



#include <iostream>
using namespace std;

int main() {
    int i, j, k;

    // Upper part of the diamond
    for (i = 5; i >= 1; i--) {
        for (j = 5; j > i; j--) {
            cout << " ";
        }
        for (k = i; k > 0; k--) {
            cout << "* ";
        }
        cout << endl;
    }

    // Lower part of the diamond
    for (i = 1; i <= 5; i++) {  // Changed i=5 to i=2 to start from the correct row
        if (i==1){
            continue;
        }else{
        for (j = 5; j > i; j--) {
            cout << " ";
        }
        for (k = i; k > i-i; k--) {
            cout <<"* ";
        }
        cout << endl;
    }
    }

    return 0;
}