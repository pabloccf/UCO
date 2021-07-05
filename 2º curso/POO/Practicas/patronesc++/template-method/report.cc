// Report class makes HTML only reports  
#include <iostream>
#include <string>
using namespace std;

class Report{
  private:
    string title, text;
  public:
    Report(string ti, string te):title(ti),text(te){}
    void output_report(){
        cout << "<html>";
        cout << "  <head>";
        cout << "    <title> " + title + "</title>";
        cout << "  </head>";
        cout << "  <body>";
        cout << " <p> " + text + "</p>";
        cout << "  </body>";
        cout << "</html>";
    }
};

int main(void){
 Report r("Design Pattern", 
          "Separate Out the Things That Change from Those That Stay The Same");
 r.output_report();   
}


