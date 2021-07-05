#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Observer
{
  public:
    virtual void notify(string s) = 0; // se impone interfaz a los observadores
};

class Observer1: public Observer
{
  public:
    virtual void notify(string s) override {
        cout << "Observer 1. status:" + s +"\n";
        }
    //métodos propios de la clase Observer1
};

class Observer2: public Observer
{
  public:
    virtual void notify(string s) override {
        cout << "Observer 2. status:" + s +"\n";
        }
    //métodos propios de la clase Observer2
};

class Subject
{
  private:
    std::vector <Observer*> observers_;  // suscriptores
    string status_; // sujeto de suscripción
  public:
    void register_observer(Observer& o)
    {
      observers_.push_back(&o);
    }
    void notify_observers()
    {
      for (Observer* o : observers_) {
        o->notify(status_);
      }
    }
    void setStatus(string s){
        status_=s;
        notify_observers();
    }
};

int main(void){
  string new_status;
  Observer1 o1;
  Observer2 o2;
  Subject s1; //Subject
  
  s1.register_observer(o1);
  s1.register_observer(o2);

  s1.setStatus("hola");
  cout << "Input new status: ";
  getline(cin, new_status,'\n');
  s1.setStatus(new_status);
}