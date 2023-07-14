#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "class_def.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Tải dữ liệu có sẵn từ file txt lên
void init(vector<BK_corp>&loading_data)
{
    fstream upload("data.txt", ios::in);
    bool mark = true;

    while(mark == true)
    {
        begining:
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

            getline(upload, family_name);
            getline(upload, name);
            getline(upload, unit);
            getline(upload, role);
            getline(upload, dob);
            getline(upload, home_town);
            getline(upload, address);
            getline(upload, email);
            getline(upload, phone_num);
            getline(upload, start_work);
            getline(upload, end_work);

            BK_corp tmp(family_name, name, unit, role, dob, home_town, address, email, phone_num, start_work, end_work);
            loading_data.push_back(tmp);

            if(upload.eof()) mark = false;
            else goto begining;
    }
}

void display_data(vector<BK_corp>&display)
{
    for(auto item : display)
    {
        cout << "Family name: " << item.get_family_name() << endl;
        cout << "Last name: " << item.get_name() << endl;
        cout << "Appartment: " << item.get_unit() << endl;
        cout << "Position: " << item.get_role() << endl;
        cout << "Date of birth: " << item.get_dob() << endl;
        cout << "Home town" << item.get_home_town() << endl;
        cout << "Address: " << item.get_address() << endl;
        cout << "Email: " << item.get_email() << endl;
        cout << "Phone number: " << item.get_phone_num() << endl;
        cout << "Start work: " << item.get_start_work() << endl;
        cout << "End work:" << item.get_end_work() << endl;
    }
}

// Tìm kiếm
void search_data(vector<BK_corp>&search)
{
    string fam_name, name;
    cout << "Input family name you want to find: ";
    cin.ignore();
    getline(cin, fam_name);
    cout << "Input name you want to find: ";
    cin >> name;
    cout << fam_name << endl;
    cout << name << endl;

    for(auto item : search)
    {
        if(item.get_family_name() == fam_name && item.get_name() == name)
        {
            cout << "DATA AVAILABLE\n";
            cout << "Here is the result:\n";
            cout << "Family name: " << item.get_family_name() << endl;
            cout << "Last name: " << item.get_name() << endl;
            cout << "Appartment: " << item.get_unit() << endl;
            cout << "Position: " << item.get_role() << endl;
            cout << "Date of birth: " << item.get_dob() << endl;
            cout << "Home town: " << item.get_home_town() << endl;
            cout << "Address: " << item.get_address() << endl;
            cout << "Email: " << item.get_email() << endl;
            cout << "Phone number: " << item.get_phone_num() << endl;
            cout << "Start work: " << item.get_start_work() << endl;
            cout << "End work: " << item.get_end_work() << endl;
        }
    }

}

int main()
{
 
    // Khai báo vector person có kiểu "BK_corp", có nhiệm vụ lưu trữ và truy vấn thông tin
    vector<BK_corp>person;

    // Invoke hàm init
    init(person);

    // Hiển thị danh sách các chức năng - tùy chọn
    while (true)
    {
        string option;
        cout << "Choose action | Type 1 - 6 to choose option\n";
        // Action list
        cout << "1 - DISPLAY data of BKCorporation\n"; // Hiển thị thông tin TOÀN BỘ công ty
        cout << "2 - SEARCH employee data\n"; // Tìm kiếm thông tin nhân viên 
        cout << "3 - DISPLAY employee status\n"; // Hiển thị tình trạng nhân viên
        cout << "4 - DISPLAY data of subsidiaries\n"; // Hiển thị thông tin đơn vị (công ty con)
        cout << "5 - ADD new employee\n"; // Thêm nhân viên mới
        cout << "6 - UPDATE data\n"; // Thêm nhân viên mới
        cout << "7 - EXIT program\n"; // Thoát chương trình

        cout << "Choose option: ";
        cin >> option;

        if(option == "1")
        {
            display_data(person);
        }
        else if(option == "2")
        {
            search_data(person);
        }
        else if(option == "3"){cout << "Hello";}
        else if(option == "4"){cout << "Hello";}
        else if(option == "5"){cout << "Hello";}
        else if(option == "6"){cout << "Hello";}
        else if(option == "7")
        {
            cout << "Exiting.....\n";
            cout << "The program has ended.\n";
            break;
        }
        else
        {
            cout << "Type error...Please try again!\n";
        }

        cout << "Press any key to continue...\n";
        cin.ignore();
        getline(cin, option);
        system("cls"); // Xóa tất cả các thông tin hiển thị trên màn hình console và chạy lại vòng lặp while
    }

    return 0;
}