#include <iostream>

template<class type>

class MiClase{
    private:
        type x_;
        type y_;
    public:
        MiClase(type a, type b){
            x_=a;
            y_=b;
        }

        type suma(){
            return x_+y_;
        }

        type resta(){
            return x_-y_;
        }

        type multiplicacion(){
            return x_*y_;
        }

        type division(){
            return x_/y_;
        }
};

int main(){
    MiClase<int> enteros(15, 5);
    MiClase<double> doubles(2.3798, 4.7632);

    std::cout<<"Suma entera= "<<enteros.suma()<<std::endl;
    std::cout<<"Resta entera= "<<enteros.resta()<<std::endl;
    std::cout<<"Multiplicacion entera= "<<enteros.multiplicacion()<<std::endl;
    std::cout<<"Division entera= "<<enteros.division()<<std::endl;

    std::cout<<"Suma doubles= "<<doubles.suma()<<std::endl;
    std::cout<<"Resta doubles= "<<doubles.resta()<<std::endl;
    std::cout<<"Multiplicacion doubles= "<<doubles.multiplicacion()<<std::endl;
    std::cout<<"Division doubles= "<<doubles.division()<<std::endl;

    return 0;
}

