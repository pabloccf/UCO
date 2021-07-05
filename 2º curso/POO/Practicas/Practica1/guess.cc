#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(){
    srand(time(NULL));
    int i;
    int r=(rand()%10)+1;
    bool encontrado=false;

    while(!encontrado){
        cout<<"Introduce un numero"<<endl;
        cin>>i;
        if(i<r){
            cout<<"Es mayor"<<endl;
        }

        else if(i>r){
            cout<<"Es menor"<<endl;
        }

        else{
            encontrado=true;
        }
    }
         
    cout<<"Si, era el "<<r<<endl;
}
