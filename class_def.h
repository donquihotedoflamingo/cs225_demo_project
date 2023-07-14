#ifndef CLASS_DEF_H
#define CLASS_DEF_H

#include <iostream>
#include <string>
using namespace std;

// KHAI BÁO CLASS 
class BK_corp
{
    private:
        string family_name;
        string name;
        string unit;
        string role;
        string dob;
        string home_town;
        string address;
        string email;
        string phone_num;
        string start_work;
        string end_work;

    public:
        BK_corp();
        BK_corp(string,string,string,string,string,string,string,string,string,string,string);

        string get_family_name();
        string get_name();
        string get_unit();
        string get_role();
        string get_dob();
        string get_home_town();
        string get_address();
        string get_email();
        string get_phone_num();
        string get_start_work();
        string get_end_work();

};

#endif
