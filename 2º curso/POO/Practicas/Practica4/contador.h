#ifndef CONTADOR_H
#define CONTADOR_H

#include <list>

class Contador{
    private:
        int valor_;
        int min_;
        int max_;
        std::list<int> hist_;

    public:
        Contador(int valor=0, int min=0, int max=1000){
            valor_=valor;
            min_=min;
            max_=max;
            if(min>max||valor<min||valor>max){
                min_=0;
                max_=1000;
                valor_=0;
            }
            hist_.push_back(valor_);
        }

        bool undo(int n=1){
            if((unsigned int)n>hist_.size()-1||n<1){
                return false;
            }

            for (int i = 0; i < n; i++){
                hist_.pop_back();
            }
            valor_=hist_.back();
            return true;
        }

        void rangeValue(){
            if(valor_>max_){
                valor_=max_;
            }
            else if(valor_<min_){
                valor_=min_;
            }
        }

        int get() const{
            return valor_;
        }
        
        int getmin() const{
            return min_;
        }

        void setmin(int min){
            min_=min;
        }

        int getmax() const{
            return max_;
        }

        void setmax(int max){
            max_=max;
        }

        Contador operator=(int x);
        Contador operator=(const Contador &c);
        Contador operator++(void);
        Contador operator++(int);
        Contador operator--(void);
        Contador operator--(int);
        Contador operator+(int x);
        friend Contador operator+(int x, const Contador &c);
        Contador operator-(int x);
        friend Contador operator-(int x, const Contador &c);
};

#endif