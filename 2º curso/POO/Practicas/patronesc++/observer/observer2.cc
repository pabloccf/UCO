#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Observer
{
  public:
    virtual void update()=0;
    virtual ~Observer(){};
};

class Subject
{
  private:
    std::vector <Observer*> observers_;
  public:
    void register_observer(Observer& o)
    {
      observers_.push_back(&o);
    }
    void notify_observers()
    {
      for (Observer* o : observers_) {  // C++ range-based ‘for’ loops
        o->update();
      }
    }
    virtual ~Subject(){};
};

// Podría haber distintos subjects.
// Nosotros haremos solo 1.
class SubjectData1: public Subject{
  private:
  string a_,b_,c_;
  public:
  string geta(){return a_;}
  string getb(){return b_;}
  string getc(){return c_;}
  void set(string a, string b, string c){
    a_=a;
    b_=b;
    c_=c;
    notify_observers();
    }
};

class Observer1: public Observer
{
  private:
  SubjectData1& s_;
  public:
    Observer1(SubjectData1& s):s_(s){};
    virtual void update() override {
        cout << "Observer 1. " + s_.geta() +
                "," + s_.getb()+ "," + s_.getc() + "\n";
        }
};

class Observer2: public Observer
{
  private:
  SubjectData1& s_;
  public:
    Observer2(SubjectData1& s):s_(s){};
    virtual void update() override {
      cout << "Observer 2. " + s_.geta() +
                "," + s_.getb()+ "," + s_.getc() + "\n";
        }
};


int main(void){
  SubjectData1 data;  // Podría ser SubjectData2, SubjectData3, etc.
  Observer1 o1(data); 
  Observer2 o2(data);
  cout << "Attaching observers \n";
  data.register_observer(o1);
  data.register_observer(o2);

  cout << "changing subject status 1\n";
  data.set("juan", "ana", "pedro");

  cout << "changing subject status 2\n";
  data.set("maria", "luis", "julia");
}