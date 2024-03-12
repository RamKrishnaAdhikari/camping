#ifndef CAMPING_H
#define CAMPING_H
#include"plot.h"


class camping
{
public:
    camping();
    camping(std::string name);
    void addplot();
    void addplot(plot* p);
    bool bookplot(int id,const std::vector<std::string>& guests,int from , int to,const std::vector<plot::feature>features);
    void display();
    void display(int from,int to);
    bool bookplot(const std::vector<std::string>& guests, int from , int to);
    void createreminders(int today);
private:

    std::string name;
    std::vector<plot*>plots;

};

#endif // CAMPING_H
