#include "linkedlisttype.h"
#include <iostream>

using namespace std;

linkedlisttype::linkedlisttype()
{
    first=NULL;
    last=NULL;
    count_sales=0;
}

linkedlisttype::~linkedlisttype()
{
    destroylist();
}


void linkedlisttype::destroylist()
{
    nodetype *temp;
    while(first !=NULL)
    {
        temp=first;
        first=first->link;
        delete temp;
    }
    last=NULL;

    count_sales=0;
}


int linkedlisttype::getcount()
{
    return count_sales;
}

