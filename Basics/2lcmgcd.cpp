#include <iostream>
using namespace std;
#include <vector>



class Solution {
  public:
        int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    int lcmofab(int a, int b, int gcd){
        return (a*b)/gcd;
    }
        
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        
        vector<int> v(2);
        
        int lcm;
        int gcdv=gcd(a,b);
        lcm=lcmofab(a,b,gcdv);
        
        
        
        v[0]=lcm;
        v[1]=gcdv;
        
        return v;
        
        
        
        
        
        
    }
};

int main(){

    Solution s1;

    vector<int> sol(2);
    
    sol=s1.lcmAndGcd(5,10);


    cout<<"Lcm of "<<"5 and 10 is "<<sol[0]<<endl;
    cout<<"gcd of "<<"5 and 10 is "<<sol[1]<<endl;
    
    
    return 0;
}