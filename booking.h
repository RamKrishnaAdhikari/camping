#ifndef BOOKING_H
#define BOOKING_H
#include<vector>
#include<string>

class booking
{
public:
    booking();
    booking(int from,int to,const std::vector<std::string>&visitors,double costpernight);
    int getfrom()const;
    int getto()const;
    int getvisitorsize()const;
    void setpay();
    bool getpayed()const;
    std::vector<std::string>getvisitors()const;
private:
    int from;
    int to;
    std::vector<std::string>visitors;
    double gesamtkosten;
    bool payed;
};


#endif // BOOKING_H
