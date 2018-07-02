#ifndef UNORDERED_H
#define UNORDERED_H
#include <string>
#include <stdlib.h>
#include <fstream>
#include "linkedlisttype.h"

class Unordered : public linkedlisttype
{
public:
    void insertFirst(int,std::string,std::string,int,double,double,double);
    void insertLast(int,std::string,std::string,int,double,double,double );
    void deleteNode_u(int);
    void overwritefile(std::ofstream&);
    Unordered();
    ~Unordered();
protected:

private:
};

#endif // UNORDERED_H
