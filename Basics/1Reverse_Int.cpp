#include <iostream>
using namespace std;

int rev(int x){

    int tx=x;
    int rev=0;
    while(tx!=0){

        int pop=tx%10;
        tx=tx/10;

        rev=rev*10 + pop;

    }


    return rev;
}

int main(){

    cout<<"rev of 123 is "<< rev(-123);
    
    return 0;
}