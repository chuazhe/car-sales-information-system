#include "Ordered.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

Ordered::Ordered()
{

}

Ordered::~Ordered()
{

}

void Ordered ::insertNode(int enginenumber_i,string carname_i,string colour_i,int displacement_i,double carprice_sp_i,double carprice_rp_i,double carprice_otrp_i)
{
    nodetype *current;
    nodetype *trailcurrent;
    nodetype *newNode;

    bool found;
    newNode=new nodetype;
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
        count_sales++;
    }
    else
    {
        current=first;
        found=false;

        while(current!=NULL && !found)
        {
            if(current->key_carinfo.carprice_otrp_l<=carprice_otrp_i)
            {
                found =true;
            }
            else
            {
                trailcurrent=current;
                current=current->link;
            }
        }
        if(current==first)
        {
            newNode->link=first;
            first=newNode;
            count_sales++;
        }
        else
        {
            trailcurrent->link=newNode;
            newNode->link=current;
            if(current==NULL)
            {
                last=newNode;
            }
            count_sales++;
        }
    }
}

void Ordered ::deleteNode_O(int engine_delete)
{
    nodetype *current;
    nodetype *trailcurrent;
    bool found;
    string choice1;

    if(first==NULL)
    {
        cout <<"The list is empty!"<<endl;
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
            cout <<fixed <<setprecision(2) <<endl;
            cout <<"Engine Number: " <<current->key_carinfo.enginenumber_l <<endl;
            cout <<"Model Name: " <<current->key_carinfo.carname_l <<endl;
            cout <<"Colour: "<<current->key_carinfo.colour_l <<endl;
            cout <<"Displacement: " <<current->key_carinfo.displacement_l <<" CC"<<endl;
            cout <<"Selling Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_sp_l <<endl;
            cout <<"Retail Price without insurance Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_rp_l <<endl;
            cout <<"On the Road Price with insurance(Inclusive 6% GST): "<<current->key_carinfo.carprice_otrp_l <<endl<<endl;
            cout<<"********************************************************************************";
            cout <<"This data is being deleted!\n";
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
                cout <<fixed <<setprecision(2) <<endl;
                cout <<"Engine Number: " <<current->key_carinfo.enginenumber_l <<endl;
                cout <<"Model Name: " <<current->key_carinfo.carname_l <<endl;
                cout <<"Colour: "<<current->key_carinfo.colour_l <<endl;
                cout <<"Displacement: " <<current->key_carinfo.displacement_l <<" CC"<<endl;
                cout <<"Selling Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_sp_l <<endl;
                cout <<"Retail Price without insurance Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_rp_l <<endl;
                cout <<"On the Road Price with insurance(Inclusive 6% GST): "<<current->key_carinfo.carprice_otrp_l <<endl<<endl;
                cout<<"********************************************************************************";
                cout <<"This data is being deleted!\n";
                delete current;
            }
        }
    }
}


void Ordered::print()
{
    system("cls");
    nodetype *current;
    current=first;
    int i=1;
    while(current!=NULL)
    {
        cout <<fixed <<setprecision(2) <<endl;
        cout <<"Number: "<<i <<endl;
        cout <<"Engine Number: " <<current->key_carinfo.enginenumber_l <<endl;
        cout <<"Model Name: " <<current->key_carinfo.carname_l <<endl;
        cout <<"Colour: "<<current->key_carinfo.colour_l <<endl;
        cout <<"Displacement: " <<current->key_carinfo.displacement_l <<" CC"<<endl;
        cout <<"Selling Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_sp_l <<endl;
        cout <<"Retail Price without insurance Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_rp_l <<endl;
        cout <<"On the Road Price with insurance(Inclusive 6% GST): "<<current->key_carinfo.carprice_otrp_l <<endl<<endl;
        cout<<"********************************************************************************";
        i++;
        current=current->link;
    }

}

void Ordered::search_display_O(int searchkey) //search and display
{
    nodetype *current;
    bool found=false;

    current=first;

    while(current!=NULL && !found)
    {
        if(current->key_carinfo.enginenumber_l==searchkey)
        {
            found=true;
        }
        else
        {
            current=current->link;
        }
    }
    if(!found)
    {
        cout<<"The data requested is not in the list!" <<endl;
        return;
    }

    system("cls");
    cout <<fixed <<setprecision(2) <<endl;
    cout <<"Engine Number: " <<current->key_carinfo.enginenumber_l <<endl;
    cout <<"Model Name: " <<current->key_carinfo.carname_l <<endl;
    cout <<"Colour: "<<current->key_carinfo.colour_l <<endl;
    cout <<"Displacement: " <<current->key_carinfo.displacement_l <<" CC"<<endl;
    cout <<"Selling Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_sp_l <<endl;
    cout <<"Retail Price without insurance Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_rp_l <<endl;
    cout <<"On the Road Price with insurance(Inclusive 6% GST): "<<current->key_carinfo.carprice_otrp_l <<endl<<endl;
    cout<<"********************************************************************************";
}


void Ordered::printlistreverse()  //print the list in reverse order
{
    reverseprint(first);
    cout <<endl;
}

void Ordered::reverseprint(nodetype *current)  //needed to print the list in reverse order
{
    if(current!= NULL)
    {
        reverseprint(current->link);

        cout <<fixed <<setprecision(2) <<endl;
        cout <<"Engine Number: " <<current->key_carinfo.enginenumber_l <<endl;
        cout <<"Model Name: " <<current->key_carinfo.carname_l <<endl;
        cout <<"Colour: "<<current->key_carinfo.colour_l <<endl;
        cout <<"Displacement: " <<current->key_carinfo.displacement_l <<" CC"<<endl;
        cout <<"Selling Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_sp_l <<endl;
        cout <<"Retail Price without insurance Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_rp_l <<endl;
        cout <<"On the Road Price with insurance(Inclusive 6% GST): "<<current->key_carinfo.carprice_otrp_l <<endl<<endl;
        cout<<"********************************************************************************";
    }
}

bool Ordered::checkunique(int enginecheck)  //check the uniqueness of engine number
{
    nodetype *current;
    bool found=false;

    current=first;

    while(current!=NULL && !found)
    {
        if(current->key_carinfo.enginenumber_l==enginecheck)
        {
            found=true;
        }
        else
        {
            current=current->link;
        }
    }
    return found;
}

void Ordered::summarise() //summarise accoring to chosen criteria
{
    system("cls");
    nodetype *current;
    int count1=0;
    int count2=0;
    int count3=0;
    string choice1;
    int method;

    current=first;
    while(current!=NULL)
    {
        if(current->key_carinfo.displacement_l<1500)
        {
            count1++;
        }
        else if (current->key_carinfo.displacement_l>=1500 && current->key_carinfo.displacement_l<1800)
        {
            count2++;
        }
        else if(current->key_carinfo.displacement_l>=1800)
        {
            count3++;
        }
        current=current->link;
    }

    while(true)
    {

        cout <<"Car Information" <<endl;
        cout<<"********************************************************************************";
        cout <<"Displacement(CC)\t\t\t Number of Cars\n";
        cout <<"1-1499          \t\t\t " <<count1 <<endl;
        cout <<"1500-1799       \t\t\t " <<count2 <<endl;
        cout <<">=1800          \t\t\t " <<count3 <<endl <<endl;
        cout<<"********************************************************************************";

        current=first;

        cout <<"\n\nDo you want to display it?(Enter 99 to exit)\n";
        cout <<"Displacement(CC)\n";
        cout <<"1. 1-1499   "        <<endl;
        cout <<"2. 1500-1799  "     <<endl;
        cout <<"3. >=1800     "     <<endl <<endl <<"Choice:";
        getline(cin,choice1);
        if(atoi(choice1.c_str())==99)
        {
            break;
        }
        if(choice1.size()!=1)
        {
            method=0;
        }
        else
        {
            method=atoi(choice1.c_str());
        }
        if(method== 1 || method== 2||method==3)
        {
            break;
        }
        else
        {
            cout << "\nInvalid input,Try again!\n\n";
            system("PAUSE");
            system("cls");
        }
    }
    system("cls");
    switch (method)
    {
    case 1:
        while(current!=NULL)
        {
            if(current->key_carinfo.displacement_l<1500)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    case 2:
        while(current!=NULL)
        {
            if(current->key_carinfo.displacement_l>=1500 && current->key_carinfo.displacement_l<1800)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    case 3:
        while(current!=NULL)
        {
            if(current->key_carinfo.displacement_l>=1800)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    }
    system("PAUSE");
}

void Ordered::summariseprice_otrp()
{
    system("cls");
    nodetype *current;
    int count1=0;
    int count2=0;
    int count3=0;
    string choice1;
    int method;
    current=first;
    while(current!=NULL)
    {
        if(current->key_carinfo.carprice_otrp_l<100000)
        {
            count1++;
        }
        else if (current->key_carinfo.carprice_otrp_l>=100000 && current->key_carinfo.carprice_otrp_l<150000)
        {
            count2++;
        }
        else if(current->key_carinfo.carprice_otrp_l>=150000)
        {
            count3++;
        }
        current=current->link;
    }
    while(true)
    {

        cout <<"Car Information" <<endl;
        cout<<"********************************************************************************";
        cout <<"On The Road Price  \t\t\t Number of Cars\n";
        cout <<"MYR1-99999             \t\t\t " <<count1 <<endl;
        cout <<"MYR100000-149999       \t\t\t " <<count2 <<endl;
        cout <<">=MYR150000            \t\t\t " <<count3 <<endl<<endl;
        cout<<"********************************************************************************";
        current=first;

        cout <<"\n\nDo you want to display it?(Enter 99 to exit)\n";
        cout <<"On The Road Price\n";
        cout <<"1. MYR1-99999  "        <<endl;
        cout <<"2. MYR100000-149999   "     <<endl;
        cout <<"3. >=MYR150000      "     <<endl <<endl <<"Choice:";
        getline(cin,choice1);
        if(atoi(choice1.c_str())==99)
        {
            break;
        }
        if(choice1.size()!=1)
        {
            method=0;
        }
        else
        {
            method=atoi(choice1.c_str());
        }
        if(method== 1 || method== 2||method==3)
        {
            break;
        }
        else
        {
            cout << "\nInvalid input,Try again!\n\n";
            system("PAUSE");
            system("cls");
        }
    }
    system("cls");
    switch (method)
    {
    case 1:

        while(current!=NULL)
        {
            if(current->key_carinfo.carprice_otrp_l<100000)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    case 2:
        while(current!=NULL)
        {
            if(current->key_carinfo.carprice_otrp_l>=100000 && current->key_carinfo.carprice_otrp_l<150000)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    case 3:
        while(current!=NULL)
        {
            if(current->key_carinfo.carprice_otrp_l>=150000)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    }
    system("PAUSE");
}

void Ordered::summariseengine()
{
    system("cls");
    nodetype *current;
    int count1=0;
    int count2=0;
    int count3=0;
    string choice1;
    int method;

    current=first;
    while(current!=NULL)
    {
        if(current->key_carinfo.enginenumber_l<30000000)
        {
            count1++;
        }
        else if (current->key_carinfo.enginenumber_l>=30000000 && current->key_carinfo.enginenumber_l<=60000000)
        {
            count2++;
        }
        else if(current->key_carinfo.enginenumber_l>60000000)
        {
            count3++;
        }
        current=current->link;
    }
    while(true)
    {
        cout <<"Car Information" <<endl;
        cout<<"********************************************************************************";
        cout <<"Engine Number Between:  \t\t\t Number of Cars\n";
        cout <<"10000000-29999999       \t\t\t " <<count1 <<endl;
        cout <<"30000000-60000000       \t\t\t " <<count2 <<endl;
        cout <<"60000001-99999999       \t\t\t " <<count3 <<endl <<endl;
        cout<<"********************************************************************************";
        current=first;

        cout <<"\n\nDo you want to display it?(Enter 99 to exit)\n";
        cout <<"Engine Number Between:\n";
        cout <<"1. 10000000-29999999   "        <<endl;
        cout <<"2. 30000000-60000000 "     <<endl;
        cout <<"3. 60000001-99999999     "     <<endl <<endl <<"Choice:";
        getline(cin,choice1);
        if(atoi(choice1.c_str())==99)
        {
            break;
        }
        if(choice1.size()!=1)
        {
            method=0;
        }
        else
        {
            method=atoi(choice1.c_str());
        }
        if(method== 1 || method== 2||method==3)
        {
            break;
        }
        else
        {
            cout << "\nInvalid input,Try again!\n\n";
            system("PAUSE");
            system("cls");
        }
    }
    switch (method)
    {
    case 1:
        system("cls");
        while(current!=NULL)
        {
            if(current->key_carinfo.enginenumber_l<30000000)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    case 2:
        system("cls");
        while(current!=NULL)
        {
            if(current->key_carinfo.enginenumber_l>=30000000 && current->key_carinfo.enginenumber_l<=60000000)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    case 3:
        system("cls");
        while(current!=NULL)
        {
            if(current->key_carinfo.enginenumber_l>60000000)
            {
                printforsummarise(current);
            }
            current=current->link;
        }
        break;
    }
    system("PAUSE");

}

void Ordered::printforsummarise(nodetype *current) //print the details of cars that have the chosen requirement
{
    cout <<fixed <<setprecision(2) <<endl;
    cout <<"Engine Number: " <<current->key_carinfo.enginenumber_l <<endl;
    cout <<"Model Name: " <<current->key_carinfo.carname_l <<endl;
    cout <<"Colour: "<<current->key_carinfo.colour_l <<endl;
    cout <<"Displacement: " <<current->key_carinfo.displacement_l <<" CC"<<endl;
    cout <<"Selling Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_sp_l <<endl;
    cout <<"Retail Price without insurance Price(Inclusive 6% GST): "<<current->key_carinfo.carprice_rp_l <<endl;
    cout <<"On the Road Price with insurance(Inclusive 6% GST): "<<current->key_carinfo.carprice_otrp_l <<endl<<endl;
    cout<<"********************************************************************************";
}
