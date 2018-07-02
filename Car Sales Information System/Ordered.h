#ifndef ORDERED_H
#define ORDERED_H
#include "linkedlisttype.h"

class Ordered : public linkedlisttype
{
public:
    Ordered();
    ~Ordered();
    void insertNode(int,std::string,std::string,int,double,double,double);
    void deleteNode_O(int);
    void search_display_O(int);
    void print();
    void printlistreverse(); //print the list in reverse order
    bool checkunique(int); //check the uniqueness of engine number
    void summarise();
    void summariseprice_otrp();
    void summariseengine();
    void printforsummarise(nodetype*);


protected:

private:
    void reverseprint(nodetype*);
    //This function is called by printlistreverse() and is needed to print the list in reverse order
};

#endif // ORDERED_H
