#include<iostream>
using namespace std;

int main(){
    // make calculator using switch case statement

    cout<<"type a for add, s for sub, m for multiply and d for divide \n";

    char o;

    cin>>o;

    cout<<"enter two numbers that you want to add\n";

    int a,b;

    cin>>a>>b;

   

    switch(o){
        case 'a':
        cout<<a+b;

        break;

        case 's':
        cout<<a-b;

        break;

        case 'd':
        if (b!=0){
            cout<<a/b;
        }
        else{
            cout<<"can't divide by 0 sry";
        }
        
        break;

        case 'm':
        cout<<a*b;
        break;

        default:
        cout<<"invalid operation";
        break;
    }

    return 0;


}