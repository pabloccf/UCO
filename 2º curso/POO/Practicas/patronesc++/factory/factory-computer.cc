#include <iostream>
#include <string>
using namespace std;

class Computer {
 public:
     virtual void Run() = 0;
     virtual void Stop() = 0;
     virtual ~Computer() {}; /* without this, you do not call Laptop or Desktop destructor in this example! */
};

class Laptop: public Computer {
 public:
     Laptop(){cout << "laptop created\n";}
     void Run() override {mHibernating = false;}; 
     void Stop() override {mHibernating = true;}; 
     virtual ~Laptop() {}; /* because we have virtual functions, we need virtual destructor */
 private:
     bool mHibernating; // Whether or not the machine is hibernating
};

class Desktop: public Computer {
 public:
     Desktop(){cout << "desktop created\n";}
     void Run() override {mOn = true;}; 
     void Stop() override {mOn = false;}; 
     virtual ~Desktop() {};
 private:
     bool mOn; // Whether or not the machine has been turned on
};


 class ComputerFactory {    // Utility Factory Class
  public:
    //Factory Method
    static Computer *newComputer(const std::string &description){
         if(description == "laptop")
             return new Laptop;
         if(description == "desktop")
             return new Desktop;
         return nullptr;
    }
};

int main(void)  // No depende de las clases derivadas
{
Computer *c;
string description = "laptop";// “laptop” o “desktop”

c = ComputerFactory::newComputer(description);
delete c;

description = "desktop";// “laptop” o “desktop”
c = ComputerFactory::newComputer(description);
delete c;
}