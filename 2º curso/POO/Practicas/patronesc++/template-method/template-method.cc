// Base class has the template method design pattern
#include <iostream>
using namespace std;

class Base
{
    private:
    void a(){cout << "a  ";}
    void c(){cout << "c  ";}
    void e(){cout << "e  ";}
    // Steps requiring peculiar implementations are "placeholders" in base class
    virtual void ph1() = 0;
    virtual void ph2() = 0;  
  public:
    // Standardize the skeleton of an algorithm in a base class "template method"
    void execute()
    {
        a();
        ph1();
        c();
        ph2();
        e();
    }
    virtual ~Base(){};  // Declarar el destructor virtual es obligatorio
                          // si se redefine en la clase derivada.
                          // Por ello suele ponerse por si acaso.
};

class One: public Base
{
    public:
    // Derived classes implement placeholder methods
     void ph1() override{cout << "b  ";}
     void ph2() override{cout << "d  ";}
};

class Two: public Base
{   
    public:
    // Derived classes implement placeholder methods
     void ph1() override{cout << "2  ";}
     void ph2() override{cout << "4  ";}
};

int main()
{
  Base *array[] = {new One(), new Two()};
  for (int i = 0; i < 2; i++)
  {
    array[i]->execute();
    cout << '\n';
  }
}
