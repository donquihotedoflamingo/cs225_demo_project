#include <iostream>
#include <string>
#include "class_def.h"

// File này khởi tạo các object và methods

BK_corp::BK_corp()
{}

// Constructor có tham số - Khởi tạo các object
BK_corp::BK_corp(string family_name_x, string name_x, string unit_x, string role_x, string dob_x, string home_town_x, string address_x, string email_x, string phone_num_x, string start_work_x, string end_work_x)
{
    family_name = family_name_x;
    name = name_x ;
    unit = unit_x ;
    role = role_x ;
    dob = dob_x ;
    home_town = home_town_x ;
    address = address_x ;
    email = email_x ;
    phone_num = phone_num_x ;
    start_work = start_work_x ;
    end_work = end_work_x;
}

string BK_corp::get_family_name()
{
    return family_name;
}

string BK_corp::get_name()
{
    return name;
}

string BK_corp::get_unit()
{
    return unit;
}

string BK_corp::get_role()
{
    return role;
}

string BK_corp::get_dob()
{
    return dob;
}

string BK_corp::get_home_town()
{
    return home_town;
}

string BK_corp::get_address()
{
    return address;
}

string BK_corp::get_email()
{
    return email;
}

string BK_corp::get_phone_num()
{
    return phone_num;
}

string BK_corp::get_start_work()
{
    return start_work;
}

string BK_corp::get_end_work()
{
    return end_work;
}

