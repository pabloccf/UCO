#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component { 
  private:
      string name_;
  public:
   Component(string name):name_(name){}
   string getName(){return name_;}
   void setName(string name){name_=name;}
   virtual void renameComponent(string){}
   virtual void catComponent(){} 
   virtual ~Component(){}
}; 

class File: public Component{  // Leaf
  public:
    File(string name):Component(name){}
    void renameComponent(string name){setName(name);}
    void catComponent(){cout << "cat file: " << getName() <<endl;}
};

class Directory: public Component{ // Composite
  private:
    vector <Component*> components_;
  public:
    Directory(string name):Component(name){}
    void renameComponent(string name){setName(name);}
    void catComponent(){
        cout << "cat Directory: " << getName() << endl;
        for (Component* o: components_)
            o->catComponent();

            //cout << o->getName() << endl;

        }
    void addComponent(Component* a){
        components_.push_back(a);
    }  
};

int main(void){
    Directory d("root");
    Directory subdir("sub-directory");
    File f1("datos.txt");
    File f2("nombres.txt");
    File f3("f3.txt"), f4("f4.txt"), f5("f5.txt");
    cout << "dirname = " << d.getName() << endl; 
    cout << "filename1 = " << f1.getName() << endl; 
    cout << "filename2 = " << f2.getName() << endl;
    cout << "--------------------------------\n";
    d.addComponent(&f1);
    d.addComponent(&f2);
    d.addComponent(&subdir);
    subdir.addComponent(&f3);
    subdir.addComponent(&f4);
    subdir.addComponent(&f5);
    //Managing dir and files the same way
    d.renameComponent("ROOT");
    f1.renameComponent("Datos.txt");
    f2.renameComponent("Nombres.txt");
    cout << "dirname = " << d.getName() << endl; 
    cout << "filename1 = " << f1.getName() << endl; 
    cout << "filename2 = " << f2.getName() << endl; 
    cout << "--------------------------------\n";
    //Now with runtime polymorphism
    cout << "COMPOSITE IGUAL SEA UN FICHERO \n";
    Component *p;
    p=&f1; 
    p->catComponent();
    cout << "--------------------------------\n";
    cout << "COMPOSITE IGUAL SEA UN SUBDIRECTORIO \n";
    p=&subdir;
    p->catComponent();
    cout << "--------------------------------\n";
    cout << "COMPOSITE IGUAL SEA TODO EL ARBOL \n";
    p=&d;
    p->catComponent();
}
