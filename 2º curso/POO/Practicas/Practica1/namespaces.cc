#include <iostream>

using namespace std;

namespace n1{
    int a;
    int b;
} // namespace n1

namespace n2{
    int a;
    int c;
} // namespace n2

int main(void){
    int a=55;
    n1::a=0;
    n2::a=2;
    cout<<"n1::a = "<<n1::a<<endl;
    cout<<"n2::a = "<<n2::a<<endl;
    cout<<"a = "<<a<<endl;
}