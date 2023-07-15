#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "class_def.h"
#include <iomanip>

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

// Hiển thị dữ liệu
void display_data(vector<BK_corp>&display)
{
    for(auto item : display)
    {
        cout << left << setw(11) << item.get_family_name() << " | "
            << left << setw(2) << item.get_name() << " | "
            << left << setw(15) << item.get_unit() << " | "
            << left << setw(9) << item.get_role() << " | "
            << left << setw(11) << item.get_dob() << " | "
            << left << setw(9) << item.get_home_town() << " | "
            << left << setw(9) << item.get_address() << " | "
            << left << setw(11) << item.get_email() << " | "
            << left << setw(11) << item.get_phone_num() << " | "
            << left << setw(11) << item.get_start_work() << " | "
            << left << setw(11) << item.get_end_work() << endl;
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
    cout << endl;

    for(auto item : search)
    {
        if(item.get_family_name() == fam_name && item.get_name() == name)
        {

            cout << "DATA AVAILABLE\n";
            cout << "Here is the result:\n";

            cout << left << setw(9) << item.get_family_name() << " | "
            << left << setw(2) << item.get_name() << " | "
            << left << setw(11) << item.get_unit() << " | "
            << left << setw(9) << item.get_role() << " | "
            << left << setw(11) << item.get_dob() << " | "
            << left << setw(9) << item.get_home_town() << " | "
            << left << setw(9) << item.get_address() << " | "
            << left << setw(11) << item.get_email() << " | "
            << left << setw(11) << item.get_phone_num() << " | "
            << left << setw(11) << item.get_start_work() << " | "
            << left << setw(11) << item.get_end_work() << endl;
        }
    }

}

// Thêm nhân viên mới (gồm 2 hàm: nhập và lưu về file txt)
void save_data(string family_name_x, string name_x, string unit_x, string role_x, string dob_x, string home_town_x, string address_x, string email_x, string phone_num_x, string start_work_x, string end_work_x)
{
    fstream output("data.txt", ios::app);
    output << "\n";
    output << family_name_x << endl;
    output << name_x << endl;
    output << unit_x << endl;
    output << role_x << endl;
    output << dob_x << endl;
    output << home_town_x << endl;
    output << address_x << endl;
    output << email_x << endl;
    output << phone_num_x << endl;
    output << start_work_x << endl;
    output << end_work_x << endl;

    output.close();
}

void add_data(vector<BK_corp>&add)
{
    cout << "ADD NEW EMPLOYEE:\n";

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

    cout << "1. Input family name: ";
    cin.ignore();
    getline(cin, family_name);

    cout << "2. Input name: ";
    getline(cin, name);

    cout << "3. Input department: ";
    getline(cin, unit);

    cout << "4. Input position: ";
    getline(cin, role);

    cout << "5. Input date of birth: ";
    getline(cin, dob);

    cout << "6. Input home town: ";
    getline(cin, home_town);

    cout << "7. Input address: ";
    getline(cin, address);

    cout << "8. Input email: ";
    getline(cin, email);

    cout << "9. Input phone number: ";
    getline(cin, phone_num);

    cout << "10. Input start work: ";
    getline(cin, start_work);

    cout << "11. Input end work: ";
    getline(cin, end_work);

    BK_corp tmp(family_name, name, unit, role, dob, home_town, address, email, phone_num, start_work, end_work);
    add.push_back(tmp);
    save_data(family_name, name, unit, role, dob, home_town, address, email, phone_num, start_work, end_work);
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
        else if(option == "5")
        {
            add_data(person);
        }
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