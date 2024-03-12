#include "camping.h"
#include<iostream>
using namespace std;
 static int id= 0;

camping::camping() {}
camping::camping(std::string name):name(name){}
void camping::addplot(){
    int iid;
    int size;
    double costpernight;
    std:: cin>>iid>>size>>costpernight;
    plots.push_back(new plot(id++,size,costpernight));
}

void camping::addplot(plot* p){
    plots.push_back(p);
}

bool camping::bookplot(int id,const std::vector<std::string>& guests,int from,int to, const std::vector<plot::feature>features){
    for(const auto& a : plots){
        if(a->getid()==id){



        if(a->bookingpossible(from,to,guests.size(),features)){
                a->book({from,to,guests,a->getcostpernight()});

            return true;
        }
        }

    }
    return true;
}

void camping::display(){
    for(const auto& p : plots){
        std:: cout<<"id der Parzelle ist"<<p->getid()<<endl;
        std::  cout<<"Die Grösse der Parzelle  ist "<<p->getsize()<<endl;
         std::  cout<<"Die Anzahl der Buchungen auf der Parzelle ist :"<<p->getbooking().size()<<endl;
    }

}

void camping :: display(int from, int to){
    for(const auto& p: plots){
        if(p->bookingpossible(from, to, 0)){
            cout<<"Id :"<<p->getid()<<endl;
            cout<<"grösse"<<p->getsize()<<endl;
                    cout<<"Anzahl: "<<p->getbooking().size()<<endl;
        }
    }

}

bool camping:: bookplot(const std::vector<std::string>&guests, int from, int to){
    for(const auto& p: plots){
        if(p->bookingpossible(from, to, guests.size())){
            p->book({from,to,guests,p->getcostpernight()});
            return true;
            cout<<"The id of the plot is :"<<p->getid()<<endl;
            break;
        }
    }
    return false;

}

void camping::createreminders(int today){
    for(const auto& p :plots){
        for(const auto&b :p->getbooking() ){
            if(b.getpayed()==false){
                if(b.getto()<today){
                    cout<<"id : "<<p->getid()<<endl;
                    cout<<"Kosten der Buchung: "<<(b.getfrom()-b.getto())*p->getcostpernight()<<endl;
                    cout<<"Namens des ersten Gastes "<<b.getvisitors().at(0)<<endl;
                }
            }

        }
    }
}
