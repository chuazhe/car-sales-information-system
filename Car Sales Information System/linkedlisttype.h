#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include <string>


struct carinfo //Store Car Information
{
    int enginenumber_l;
    std::string carname_l;
    std::string colour_l;
    int displacement_l;
    double carprice_sp_l;
    double carprice_rp_l;
    double carprice_otrp_l;
};

struct nodetype
{
    nodetype *link;
    carinfo key_carinfo;

};

class linkedlisttype
{
public:
    linkedlisttype();
    ~linkedlisttype();
    void destroylist();
    int getcount();
protected:
    int count_sales;
    nodetype *first;
    nodetype *last;

};

#endif // LINKEDLISTTYPE_H
