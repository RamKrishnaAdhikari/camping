#include "plot.h"

plot::plot() {}
plot::plot(int id,int size,double costpernight):
    id(id),size(size),costpernight(costpernight){}
plot::plot(int id,int size,double costpernight,const std::vector<feature>&features):
    id(id),size(size),costpernight(costpernight),features(features){}
int plot::getid()const{
    return id;
}
double plot::getcostpernight()const{
    return costpernight;

}

std::vector<booking> plot::getbooking()const
{
    return bookings;
}

int plot::getsize()const{
    return size;
}
std::vector<plot::feature> plot::getfeatures()const{
    return features;
}
bool plot::bookingpossible(int from,int to,int visitors){
    if(size<visitors*4){
        return false;
    }
    for(const auto& b : bookings){
        if((b.getfrom()>from)&&(b.getto()<to)){
            return false;
        }
        if((b.getfrom()<from)&&(b.getto()<to)){
            return false;
        }
        if((b.getfrom()>from)&&(b.getto()>to)){
            return false;

            }
        if((b.getfrom()<from)&&(b.getto()<to)){
                return false;
            }
    }

    return true;
}
bool plot::bookingpossible(int from,int to,int visitors,const std::vector<feature>&features){
    if(size<visitors*4){
        return false;
    }
    int count= 0 ;
    for(const auto & feat : this->features){
        for(const auto& f : features){
            if(feat == f){
                count++;
            }
        }
    }
    if(count!= features.size()){
        return false;
    }

    for(const auto& b : bookings){
        if((b.getfrom()>from)&&(b.getto()<to)){
            return false;
        }
        if((b.getfrom()<from)&&(b.getto()<to)){
            return false;
        }
        if((b.getfrom()>from)&&(b.getto()>to)){
            return false;

        }
        if((b.getfrom()<from)&&(b.getto()<to)){
            return false;
        }
    }

    return true;
}
void plot::book(const booking& b){
    if(bookingpossible(b.getfrom(),b.getto(),b.getvisitorsize())){
        bookings.push_back(b) ;
    }
    }
