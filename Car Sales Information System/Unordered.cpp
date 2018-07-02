#include "Unordered.h"
#include "linkedlisttype.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Unordered::Unordered()
{

}

Unordered::~Unordered()
{

}

//Insert at the beginning of the list
void Unordered::insertFirst(int enginenumber_i,string carname_i,string colour_i,int displacement_i,double carprice_sp_i,double carprice_rp_i,double carprice_otrp_i)
{
    nodetype *newNode;
    newNode= new nodetype;
    newNode->key_carinfo.enginenumber_l=enginenumber_i;
    newNode->key_carinfo.carname_l=carname_i;
    newNode->key_carinfo.colour_l=colour_i;
    newNode->key_carinfo.displacement_l=displacement_i;
    newNode->key_carinfo.carprice_sp_l=carprice_sp_i;
    newNode->key_carinfo.carprice_rp_l=carprice_rp_i;
    newNode->key_carinfo.carprice_otrp_l=carprice_otrp_i;
    newNode->link=first;
    first=newNode;

    if(last==NULL)
    {
        last=newNode;
    }

}

//Insert at the end of the list
void Unordered::insertLast(int enginenumber_i,string carname_i,string colour_i,int displacement_i,double carprice_sp_i,double carprice_rp_i,double carprice_otrp_i)
{
    nodetype *newNode;
    newNode= new nodetype;
    newNode->key_carinfo.enginenumber_l=enginenumber_i;
    newNode->key_carinfo.carname_l=carname_i;
    newNode->key_carinfo.colour_l=colour_i;
    newNode->key_carinfo.displacement_l=displacement_i;
    newNode->key_carinfo.carprice_sp_l=carprice_sp_i;
    newNode->key_carinfo.carprice_rp_l=carprice_rp_i;
    newNode->key_carinfo.carprice_otrp_l=carprice_otrp_i;
    newNode->link=NULL;

    if(first==NULL)
    {
        first=newNode;
        last=newNode;

    }
    else
    {
        last->link=newNode;
        last=newNode;
    }


}

//Delete Node
void Unordered::deleteNode_u(int engine_delete)
{
    nodetype *current;
    nodetype *trailcurrent;
    bool found;

    if(first==NULL)
    {
        cout <<endl;
    }
    else
    {
        if(first->key_carinfo.enginenumber_l==engine_delete)
        {
            current=first;
            first=first->link;
            count_sales--;
            if(first==NULL)
            {
                last=NULL;
            }
            delete current;
        }
        else
        {
            found=false;
            trailcurrent=first;
            current=first->link;
            while(current!= NULL&& !found)
            {
                if(current->key_carinfo.enginenumber_l !=engine_delete)
                {
                    trailcurrent=current;
                    current=current->link;
                }
                else
                {
                    found=true;
                }
            }
            if(found)
            {
                trailcurrent->link=current->link;
                count_sales--;
                if(last==current)
                {
                    last=trailcurrent;
                }
                delete current;
            }
            else
            {
                cout <<"Invalid Engine Number!The Data is not in the list!" <<endl;
            }
        }
    }
}


void Unordered::overwritefile(ofstream& outputF) //Write to textfile
{
    outputF.open("CarData.txt"); //Make CarData.txt blank
    outputF.close();
    nodetype *current;
    current=first;
    outputF.open("CarData.txt");
    while(current!=NULL) //Output the data to CarData.txt
    {
        outputF <<fixed <<setprecision(2);
        if(current==last)
        {
            outputF <<current->key_carinfo.enginenumber_l <<"\n" <<current->key_carinfo.carname_l <<"\n" <<current->key_carinfo.colour_l <<"\n" <<current->key_carinfo.displacement_l <<"\n" <<current->key_carinfo.carprice_sp_l<<"\n" <<current->key_carinfo.carprice_rp_l
                    <<"\n" <<current->key_carinfo.carprice_otrp_l;
            break;
        }
        outputF <<current->key_carinfo.enginenumber_l <<"\n" <<current->key_carinfo.carname_l <<"\n" <<current->key_carinfo.colour_l <<"\n" <<current->key_carinfo.displacement_l <<"\n" <<current->key_carinfo.carprice_sp_l<<"\n" <<current->key_carinfo.carprice_rp_l
                <<"\n" <<current->key_carinfo.carprice_otrp_l <<"\n" <<"\n";
        current=current->link;
    }
    outputF.close();
}
