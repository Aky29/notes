#include<iostream>

using namespace std;

int main(){
    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int b[12];
    int k;
    cin >> k;
    for(int i =0 ; i<11;i++){
        b[i] = a[i];
    }
    b[11] = k;
    for(int i =0 ; i<12;i++){
        cout << b[i]<<endl;
    }
    return 0;
}
