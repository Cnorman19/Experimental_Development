#include "Rect.h"
#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

void refine(int n){


        fstream fout;
        fout.open("rectangles.dat",ios::out);
        default_random_engine gen(time(NULL));

        Rect * rptr;
        rptr = new Rect(1,1,10,10);
        cout << "\nOriginal Rectangle: " ;
        rptr->display();

        list<Rect>rectangles;
        list<Rect>::iterator ritr;

        rectangles.push_back(*rptr);
        ritr=rectangles.begin();

        int bc[2];
        int uc[2];
        int cx;
        int cy;
        for(int i=0; i < n; i++)
        {
        ritr=rectangles.begin();
        ritr->getBC(bc);
        ritr->getUC(uc);
        uniform_real_distribution<double> xdist(bc[0],uc[0]);
        uniform_real_distribution<double> ydist(bc[1],uc[1]);

        cx = xdist(gen);
        cy = ydist(gen);

        cout<<"Randomly Selected Point = ("<<cx<<","<<cy<<")"<<endl << endl;

        cout << "New sub rectangles: " << endl;
        cout << "--------------------------------------------------" << endl;
        rptr = new Rect(bc[0],bc[1],cx,cy);
        rectangles.push_back(*rptr);
        rptr->display();

        rptr = new Rect(cx,bc[0],uc[0],cy);
        rectangles.push_back(*rptr);
        rptr->display();

        rptr = new Rect(bc[0],cy,cx,uc[1]);
        rectangles.push_back(*rptr);
        rptr->display();

        rptr = new Rect(cx,cy,uc[0],uc[1]);
        rectangles.push_back(*rptr);
        rptr->display();
        rectangles.pop_front();
        }

        ritr=rectangles.begin();
        while(ritr!=rectangles.end())
        {
            ritr->getBC(bc);
            ritr->getUC(uc);
            fout<<bc[0]<<" "<<bc[1]<<endl;
            fout<<uc[0]<<" "<<bc[1]<<endl;
            fout<<uc[0]<<" "<<uc[1]<<endl;
            fout<<bc[0]<<" "<<uc[1]<<endl;
            fout<<bc[0]<<" "<<bc[1]<<endl<<endl;
            ritr++;
        }
        fout.close();



}


int main()
{
    int x = 0;
    ///User input(number of times user wishes to refine)
    int numOfRefines = 0;
    cout << "How many times would you like to refine?" << endl;
    cin >> numOfRefines;
    ///---------------------------------------------------------

    refine(numOfRefines);
    return 0; //end of main
}

