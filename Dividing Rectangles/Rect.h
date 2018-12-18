#ifndef RECT_H_INCLUDED
#define RECT_H_INCLUDED
#include <iostream>


class Rect{

    public:
        Rect(){}
        Rect(int a, int b, int c, int d)
            {
                BC[0]=a;
                BC[1]=b;
                UC[0]=c;
                UC[1]=d;
            }
        void getBC(int b[2]){b[0]=BC[0]; b[1]=BC[1];}
        void getUC(int u[2]){u[0]=UC[0]; u[1]=UC[1];}

        void display(){std::cout<<"("<<BC[0]<<","<<BC[1]<<") to ("<<UC[0]<<","<<UC[1]<<")"<<std::endl;}


    private:

        int BC[2];
        int UC[2];

};

#endif // RECT_H_INCLUDED
