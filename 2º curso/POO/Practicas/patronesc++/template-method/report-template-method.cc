// Extending Report class the GOOD way
// Report class with a template method prepared for many formats
#include <iostream>
#include <string>
using namespace std;

class Report{
  protected:
    string title, text;
  public:
    Report(string ti, string te):title(ti),text(te){}
    virtual ~Report(){};  // Declarar el destructor virtual es obligatorio
                          // si se redefine en la clase derivada.
                          // Por ello suele ponerse por si acaso.
    //Begin placeholders
    virtual void output_start()=0;
    virtual void output_head(){cout << "Abstract method not yet implemented.";};
    virtual void output_body_start(){cout << "Abstract method not yet implemented.";};
    virtual void output_body(){cout << "Abstract method not yet implemented.";};
    virtual void output_body_end(){cout << "Abstract method not yet implemented.";};
    virtual void output_end(){cout << "Abstract method not yet implemented.";};
    //End placeholders
    void output_report(){ //Template method prepared for many formats
      output_start();
      output_head();
      output_body_start();
      output_body();
      output_body_end();
      output_end();
    }

};

class HTMLReport: public Report{
  public:
    HTMLReport(string ti, string te):Report(ti,te){}
    void output_start() override {cout << "<html>";}
    void output_head() override {cout << " <head><title>" + title + "</title></head>";}
    void output_body_start() override {cout << " <body>";}
    void output_body() override {cout << "<p> " + text + "</p>";}
    void output_body_end() override {cout << "</body>";}
    void output_end() override {cout << " </html>";}
};

class TXTReport: public Report{
  public:
    TXTReport(string ti, string te):Report(ti,te){}
    void output_start() override {}
    void output_head() override {cout << "**** " + title + " ****";}
    void output_body_start() override {}
    void output_body() override {cout << text;}
    void output_body_end() override {}
    void output_end() override {}    
};

int main(void){
 HTMLReport hr("Design Pattern", 
          "Separate Out the Things That Change from Those That Stay The Same");
 TXTReport tr("Design Pattern", 
          "Separate Out the Things That Change from Those That Stay The Same");         
 hr.output_report();   // Calling template method 
 cout << endl;
 tr.output_report();   // Calling the same template method 
}
