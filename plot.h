#ifndef PLOT_H
#define PLOT_H
#include"booking.h"

class plot
{
public:
    enum feature{power,water,riverside};
    plot();
    plot(int id,int size,double costpernight);
    plot(int idd, int sisze, double costpernight,const std::vector<feature>& features);
    bool bookingpossible(int from,int to,int visitors);
    bool bookingpossible(int from,int to,int visitors,const std::vector<feature>&features);
    void book(const booking& b);
    int getid()const;
    double getcostpernight()const;
    std::vector<booking>getbooking()const;
    int getsize()const;
    std::vector<feature>getfeatures()const;
private:

    int id;
    int size;
    double costpernight;
    std::vector<booking>bookings;
    std::vector<feature>features;
};

#endif // PLOT_H
