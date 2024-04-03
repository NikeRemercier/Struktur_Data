#include <iostream>
using namespace std;

int main(){
    int x = 3;
    int *y = &x;
    cout<<"alamat variable x :"<<&x<<endl;
    cout<<"nilai variable x :"<<x<<endl;
    cout<<"isi variable y :"<<y<<endl;
    cout<<"nilai yang tersimpan pada variable y :"<<*y<<endl;
    
}