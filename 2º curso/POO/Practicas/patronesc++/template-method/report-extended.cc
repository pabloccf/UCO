// Extending Report class the wrong way
#include <iostream>
#include <string>
using namespace std;

class Report{
  private:
    string title, text;
  public:
    Report(string ti, string te):title(ti),text(te){}
    void output_report(string format){
        if (format=="html"){
        cout << "<html>";
        cout << "  <head>";
        cout << "    <title> " + title + "</title>";
        cout << "  </head>";
        cout << "  <body>";
        cout << " <p> " + text + "</p>";
        cout << "  </body>";
        cout << "</html>";
        return;
        }
        if (format=="text"){
        cout << "**** "+ title +" ****\n";
        cout << text;
        return;
        }

    }
};

int main(void){
 Report r("Design Pattern", 
          "Separate Out the Things That Change from Those That Stay The Same");
 r.output_report("text");   
 cout << endl;
 r.output_report("html");   
}