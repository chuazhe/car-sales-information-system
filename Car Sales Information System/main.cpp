#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Unordered.h"
#include "Ordered.h"
#include "linkedlisttype.h"

using namespace std;

void displayMenu();
void insertFunction(Unordered&,Ordered&);
void deleteFunction(Unordered&,Ordered&);
void readfile(ifstream&,Unordered&,Ordered&);
void searchFunction(Ordered&);
void displayFunction(Ordered&);
void summarisemenu(Ordered&);


int main()
{
    system("color F0");
    Unordered ob1; //declare object of unordered linked list
    Ordered ob2;   //declare object of ordered linked list
    string choice;
    int integer;
    int count_for_sales;
    ifstream infile;
    ofstream outfile;
    readfile(infile,ob1,ob2); //Input the data from "CarData.txt"

    integer=0;
    while(integer!=7)
    {
        displayMenu();
        getline(cin,choice);
        if(choice.size()!=1)
        {
            integer=0;
        }
        else
        {
            integer=atoi(choice.c_str());
        }
        switch(integer)
        {
        case 1:
            ob2.print();
            cout <<"\n\n\nThe Total Sales of the Car sold is ";
            count_for_sales=ob2.getcount();
            cout  <<count_for_sales <<endl <<endl;
            system("PAUSE");
            break;
        case 2:
            displayFunction(ob2);
            break;
        case 3:
            summarisemenu(ob2);
            break;
        case 4:
            searchFunction(ob2);
            break;
        case 5:
            insertFunction(ob1,ob2);
            break;
        case 6:
            deleteFunction(ob1,ob2);
            break;
        case 7:
            system("cls");
            cout <<"Thanks you for using e-Car Sales Information!\n";
            system("PAUSE");
            break;
        default:
            system("cls");
            cout <<"Wrong Input! Please Try again!\n";
            system("PAUSE");
        }
    }
    ob1.overwritefile(outfile); //Update "CarData.txt"
    cout<<"\nData is successfully updated to the text file!" <<endl;
    return 0;
}


void displayMenu() //Menu
{
    system("cls");
    cout<<"********************************************************************************";
    cout<<"\n\t\t\te-Car Sales Information System  \n\n";
    cout<<"********************************************************************************";
    cout<<"What would you like to do? "<<endl;
    cout<<"\n1. Display all Car's sales information\n"<<endl;
    cout<<"2. Display the sales information based on On the Road Price\n"<<endl;
    cout<<"3. Summarise the sales information\n"<<endl;
    cout<<"4. Search and display specific Car's information\n"<<endl;
    cout<<"5. Add new Car information \n"<<endl;
    cout<<"6. Delete Function\n" <<endl;
    cout<<"7. Exit\n" <<endl;
    cout<<"Select your choice:";
}

void insertFunction(Unordered& ob1,Ordered& ob2) //Add New Car Data
{
    int enginenumber;
    string carname;
    string colour;
    string stringtemp;
    int displacement;
    double carprice_sp;
    double carprice_rp;
    double carprice_otrp;
    int location;
    system("cls");
    while(true)
    {
        cout<<"********************************************************************************";
        cout<<"\n\t\t\tInsert New Car Information  \n\n";
        cout<<"********************************************************************************";

        cout <<"\nPlease enter the Engine Number(8 Digits,Unique and between 10000000-99999999)\n(Enter 99 to exit)\n\nEngine Number:";
        getline(cin,stringtemp);
        if(atoi(stringtemp.c_str())==99) //For exit
        {
            return;
        }
        if(atoi(stringtemp.c_str())<10000000) //Engine number should start from 10000000
        {
            cout<<"\nInvalid input,Try again!\n";
            system("PAUSE");
            system("cls");
            continue;
        }
        if(stringtemp.find_first_not_of("1234567890") != string::npos||stringtemp.size()!=8) //Input Validation
        {
            cout<<"\nInvalid input,Try again!\n";
            system("PAUSE");
            system("cls");
            continue;
        }
        enginenumber=atoi(stringtemp.c_str());
        if(ob2.checkunique(enginenumber)) //check for uniqueness of engine number
        {
            cout <<"\nThis engine number is not unique!Try again!\n" <<endl;
            system("PAUSE");
            system("cls");
        }
        else
        {
            break;
        }
    }

    cout<<"\n********************************************************************************";
    while(true)
    {
        cout <<"\n\nPlease enter Car Model Name(Only alphabet,number,dot and hyphen is allowed)\n\nCar Model name:" ;
        getline(cin,carname);
        if(carname.find_first_of(":;|/_\`~,@?!#$%^&*()[]{}+*''""") != string::npos) //Input Validation
        {
            cout << "Invalid input,Try again!";
        }
        else
        {
            break;
        }
    }
    cout<<"\n********************************************************************************";
    while(true)
    {
        cout <<"\n\nPlease enter the Car's Colour\n\nColour:" ;
        getline(cin,colour);
        if(colour.find_first_of(":;|/_\`~,@.?!#$%^&*()1234567890[]{}+-*''""") != string::npos) //Input Validation
        {
            cout << "Invalid input,Try again!";
        }
        else
        {
            break;
        }
    }
    cout<<"\n********************************************************************************";
    while(true)
    {
        cout <<"\nPlease enter the Displacement(4 digits)\n\nDisplacement:";
        getline(cin,stringtemp);
        if(stringtemp.find_first_not_of("1234567890") != string::npos||stringtemp.size()!=4 ) //Input Validation
        {
            cout<<"\nInvalid input,Try again!\n";
        }
        else
        {
            break;
        }
    }
    displacement=atoi(stringtemp.c_str());
    cout<<"\n********************************************************************************";

    while(true)
    {
        cout <<"\nPlease enter the Selling Price(digits only)\n\nSelling Price:";
        getline(cin,stringtemp);
        if(stringtemp.find_first_not_of("1234567890.") != string::npos) //Input Validation
        {
            cout<<"\nInvalid input,Try again!\n";
        }
        else
        {
            break;
        }
    }
    carprice_sp=atof(stringtemp.c_str());
    cout<<"\n********************************************************************************";
    while(true)
    {
        cout <<"\nPlease enter the Retails Price without insurance inclusive 6% GST(digits only)\n\nRetails Price:";
        getline(cin,stringtemp);
        if(stringtemp.find_first_not_of("1234567890.") != string::npos) //Input Validation
        {
            cout<<"\nInvalid input,Try again!\n";
            continue;
        }
        carprice_rp=atof(stringtemp.c_str());
        if(carprice_sp>=carprice_rp) //Check for retail price because retail price should be higher than selling price in logical way
        {
            cout <<"\nRetail Price Must be higher than Selling Price!\n" <<endl;


        }
        else
        {
            break;
        }

    }

    cout<<"\n********************************************************************************";
    while(true)
    {
        cout <<"\nPlease enter the On the Road Price with insurance inclusive 6% GST(digits only)\n\nOn the Road Price:";
        getline(cin,stringtemp);
        if(stringtemp.find_first_not_of("1234567890.") != string::npos) //Input Validation
        {
            cout<<"\nInvalid input,Try again!\n";
            continue;
        }

        carprice_otrp=atof(stringtemp.c_str());
        if(carprice_rp>=carprice_otrp) //Check for On the Road Price because On the Road Price should be higher than Retail Price in logical way
        {
            cout <<"\nOn the Road Price Must be higher than Retail Price!\n" <<endl;

        }
        else
        {
            break;
        }
    }
    cout<<"\n********************************************************************************";
    while(true)
    {
        cout <<"\nPlease enter the Location for the unordered list\n\n1. Insert at the Beginning \n2. Insert at the End \nChoice:";
        getline(cin,stringtemp);
        if(stringtemp.size()!=1)
        {
            location=0;
        }
        else
        {
            location=atoi(stringtemp.c_str());
        }
        if(location== 1 || location== 2)
        {
            break;
        }
        else
        {
            cout << "\nInvalid input,Try again!\n";
        }
    }
    switch(location)
    {
    case 1:
        ob1.insertFirst(enginenumber, carname, colour,displacement, carprice_sp, carprice_rp, carprice_otrp);
        break;
    case 2:
        ob1.insertLast(enginenumber, carname, colour,displacement, carprice_sp, carprice_rp, carprice_otrp);
        break;
    }
    ob2.insertNode(enginenumber, carname, colour,displacement, carprice_sp, carprice_rp, carprice_otrp);
    cout <<"\nThe Data is successfully created!\n" <<endl;
    system("PAUSE");
}

void deleteFunction(Unordered& ob1,Ordered &ob2) //Delete data
{
    system("cls");
    string stringtemp;
    int choice;
    int enginefordelete;


    while(true)
    {
        cout <<"\nPlease enter the desired Delete function(Enter 99 to exit)\n\n1. Delete particular car sales information using car engine number \n2. Delete all Data \nChoice:";
        getline(cin,stringtemp);
        if(atoi(stringtemp.c_str())==99)
        {
            return;
        }
        if(stringtemp.size()!=1)
        {
            choice=0;
        }
        else
        {
            choice=atoi(stringtemp.c_str());
        }
        if(choice== 1 || choice== 2)
        {
            break;
        }
        else
        {
            cout << "\nInvalid input,Try again!\n";
            system("PAUSE");
            system("cls");
        }
    }
    switch(choice)
    {
    case 1:
        while(true)
        {
            cout <<"\nPlease enter the Engine Number(8 Digits)\n\nEngine Number:";
            getline(cin,stringtemp);
            if(stringtemp.find_first_not_of("1234567890") != string::npos||stringtemp.size()!=8)
            {
                cout<<"\nInvalid input,Try again!\n";
            }
            else
            {
                break;
            }
        }
        enginefordelete=atoi(stringtemp.c_str());
        ob2.deleteNode_O(enginefordelete); //delete unordered
        ob1.deleteNode_u(enginefordelete); //delete ordered

        system("PAUSE");

        break;
    case 2:
        ob1.destroylist();
        ob2.destroylist();
        cout<<"Data is successfully deleted!" <<endl;
        system("PAUSE");
        break;
    }
}

void readfile(ifstream& infile,Unordered& ob1,Ordered& ob2) //read from "CarData" textfile
{
    char enginenumber[9];
    int enginenumber_i;
    string enginenumber_s;
    char carname[50];
    char colour[50];
    char displacement[5];
    string displacement_s;
    int displacement_i;
    char carprice_sp[25];
    string carprice_sp_s;
    double carprice_sp_d;
    char carprice_rp[25];
    string carprice_rp_s;
    double carprice_rp_d;
    char carprice_otrp[25];
    string carprice_otrp_s;
    double carprice_otrp_d;
    char ch; //go to next line
    infile.open("CarData.txt");
    if(infile.is_open())
    {
        while(infile)
        {
            infile.get(enginenumber,9);
            infile.get(ch);
            infile.get(carname,50);
            infile.get(ch);
            infile.get(colour,50);
            infile.get(ch);
            infile.get(displacement,5);
            infile.get(ch);
            infile.get(carprice_sp,25);
            infile.get(ch);
            infile.get(carprice_rp,25);
            infile.get(ch);
            infile.get(carprice_otrp,25);
            infile.get(ch);
            infile.get(ch);
            enginenumber_s=enginenumber;
            displacement_s=displacement;
            carprice_sp_s=carprice_sp;
            carprice_rp_s=carprice_rp;
            carprice_otrp_s=carprice_otrp;
            enginenumber_i=atoi(enginenumber_s.c_str());
            displacement_i=atoi(displacement_s.c_str());
            carprice_sp_d=atof(carprice_sp_s.c_str());
            carprice_rp_d=atof(carprice_rp_s.c_str());
            carprice_otrp_d=atof(carprice_otrp_s.c_str());
            ob1.insertLast(enginenumber_i, carname, colour,displacement_i, carprice_sp_d, carprice_rp_d, carprice_otrp_d);
            ob2.insertNode(enginenumber_i, carname, colour,displacement_i, carprice_sp_d, carprice_rp_d, carprice_otrp_d);
        }
        system("cls");
        cout<<"Data is successfully updated!" <<endl;
        system("PAUSE");
    }
    else
    {
        cout <<"Data does not exist" <<endl;
    }
    infile.close();
}

void searchFunction(Ordered& ob2) //Search Function
{
    system("cls");
    string stringtemp;
    int enginenumber;
    while(enginenumber!=0)
    {
        cout <<"\nPlease enter the Engine Number(8 Digits) or Enter 99 to exit\n\nEngine Number:";
        getline(cin,stringtemp);
        if(atoi(stringtemp.c_str())==99)
        {
            return;
        }
        if(stringtemp.find_first_not_of("1234567890") != string::npos||stringtemp.size()!=8)
        {
            cout<<"\nInvalid input,Try again!\n";
            system("PAUSE");
            system("cls");
        }
        else
        {
            break;

        }
    }
    enginenumber=atoi(stringtemp.c_str());
    ob2.search_display_O(enginenumber);
    system("PAUSE");
}

void displayFunction(Ordered& ob2) //Display Function
{
    system("cls");
    string choice1;
    int method;

    while(true)
    {
        cout <<"The preferred method(Enter 99 to exit)\n";
        cout <<"1. Lowest to Highest\n";
        cout <<"2. Highest to Lowest\nChoice:";
        getline(cin,choice1);
        if(atoi(choice1.c_str())==99)
        {
            return;
        }
        if(choice1.size()!=1)
        {
            method=0;
        }
        else
        {
            method=atoi(choice1.c_str());
        }
        if(method== 1 || method== 2)
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
    switch(method)
    {
    case 1:
        ob2.printlistreverse();
        system("PAUSE");
        break;
    case 2:
        ob2.print();
        system("PAUSE");
        break;
    }
}

void summarisemenu(Ordered& ob2) //Menu for summarise
{
    system("cls");
    string choice1;
    int method;
    while(true)
    {
        cout <<"The preferred method(Enter 99 to exit)\n";
        cout <<"1. Summarise based on Displacement\n";
        cout <<"2. Summarise based on On the Road Price\n";
        cout <<"3. Summarise based on Engine Number\nChoice:";
        getline(cin,choice1);
        if(atoi(choice1.c_str())==99)
        {
            return;
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
        ob2.summarise();
        break;
    case 2:
        ob2.summariseprice_otrp();
        break;
    case 3:
        ob2.summariseengine();
        break;
    }
}
