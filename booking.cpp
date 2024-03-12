#include "booking.h"

booking::booking() {}
booking::booking(int from,int to,const std::vector<std::string>&visitors,double costpernight):
    from(from),to(to),visitors(visitors),gesamtkosten((to-from)*costpernight),payed(false){}

int booking::getfrom()const{
    return from;
}
int booking::getto()const{
    return to;
}
int booking::getvisitorsize()const{
    return visitors.size();
}

void booking:: setpay(){
    payed=true;
}
bool booking::getpayed()const{
    return payed;
}
std::vector<std::string> booking:: getvisitors()const {
    return visitors;
}
