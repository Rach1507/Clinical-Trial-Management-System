#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
class ctm
{
public:
public:
    char ind[5], field1[20], field2[15], field3[15], field4[10], field5[15];
} stdrec[20];

int get_num_records(char filename[])
{
    int I = 1;
    fstream file2;
    file2.open(filename, ios::in);
    if (!file2)
    {
        cout << "Error in opening file";
        return 0;
    }
    while (!file2.fail()) //Unpacking record data
    {
        file2.getline(stdrec[I].ind, 5, '|');
        file2.getline(stdrec[I].field1, 20, '|');
        file2.getline(stdrec[I].field2, 15, '|');
        file2.getline(stdrec[I].field3, 15, '|');
        file2.getline(stdrec[I].field4, 10, '|');
        file2.getline(stdrec[I].field5, 15, '\n');
        I++;
    }
    I--;
    file2.close();
    return I - 2;
}

void write_details(char filename[])
{

    fstream file2;
    file2.open(filename, ios::in);
    if (!file2)
    {
        return;
    }
    if (!file2.fail()) //Unpacking record data
    {
        file2.getline(stdrec[0].ind, 5, '|');
        file2.getline(stdrec[0].field1, 20, '|');
        file2.getline(stdrec[0].field2, 15, '|');
        file2.getline(stdrec[0].field3, 15, '|');
        file2.getline(stdrec[0].field4, 10, '|');
        file2.getline(stdrec[0].field5, 15, '\n');
    }

    cout << "\t" << stdrec[0].field1 << "\t" << stdrec[0].field2 << "\t" << stdrec[0].field3 << "\t" << stdrec[0].field4 << "\t" << stdrec[0].field5 << "\n";

    file2.close();
}

void add_record(string filename)
{
    string index_str = filename + "-idx.txt";

    filename = filename + ".txt";

    int n = index_str.length();
    int n0 = filename.length();

    char index[n + 1];
    char record_file[n0 + 1];

    strcpy(index, index_str.c_str());
    strcpy(record_file, filename.c_str());

    char buf1[100], buf2[20];
    fstream file1, file2;
    int I, cnt;
    ctm s;

    cnt = get_num_records(record_file);
    // cout<<"No of recordings in file "<<cnt;
    file1.open(index, ios::out | ios::app);
    if (!file1)
    {
        cout << "\nError !\n";
        exit(0);
    }

    file2.open(record_file, ios::out | ios::app);
    if (!file2)
    {
        cout << "\nError !\n";
        exit(0);
    }
    int no;
    cout << "\nEnter the no. of records to be added : ";
    cin >> no;
    cout << "\nEnter the details :\n";

    write_details(record_file);

    for (I = cnt; I < (cnt + no); I++)
    {
        cin >> s.field1;
        cin >> s.field2;
        cin >> s.field3;
        cin >> s.field4;
        cin >> s.field5;

        sprintf(buf2, "%s|%d\n", s.field1, I);
        file1 << buf2;

        sprintf(buf1, "%d|%s|%s|%s|%s|%s\n", I, s.field1, s.field2, s.field3, s.field4, s.field5);
        file2 << buf1;
    }
    file1.close();
    file2.close();
}

void retrieve_details(char index_no[], char file_name[])
{

    int no = get_num_records(file_name);

    for (int i = 0; i < no; i++)
    {

        if (strcmp(stdrec[i].ind, index_no) == 0)
        {
            cout << "\n\n"
                 << "Details : ";
            write_details(file_name);
            cout << "\t" << stdrec[i].field1 << "\t" << stdrec[i].field2 << "\t" << stdrec[i].field3 << "\t" << stdrec[i].field4 << "\t" << stdrec[i].field5 << "\n";
            break;
        }
    }
}

void search_record(string filename)
{
    string index_str = filename + "-idx.txt";

    filename = filename + ".txt";

    int n = index_str.length();
    int n0 = filename.length();
    // declaring character array
    char index[n + 1];
    char record_file[n0 + 1];
    // copying the contents of the
    // string to char array
    strcpy(index, index_str.c_str());
    strcpy(record_file, filename.c_str());

    int I, flag1;
    char st_no[5], name[20], required_name[20];
    fstream file1;

    // cout<<index;

    cout << "\nPlease enter the Name of the drug";
    cout << " whose record is to be displayed\n";
    cin >> required_name;

    file1.open(index, ios::in);
    if (!file1)
    {
        cout << "\nError !\n";
        exit(0);
    }

    flag1 = 0;
    while (!file1.eof())
    {
        file1.getline(name, 20, '|');
        file1.getline(st_no, 5, '\n');

        if (strcmp(name, required_name) == 0)
        {
            // cout <<filename;
            retrieve_details(st_no, record_file);
            flag1 = 1;
            break;
        }
    }
    if (!flag1)
        cout << "\nRecord search failed !!\n";
    file1.close();
}
void delete_record()
{
}

void display_records()
{
}

int login_page()
{
    char username[20], password[20];
    char user[20] = "admin", pass[20] = "pass";
    cout << endl
         << endl;
    cout.width(25);
    cout << "--------------------------------------------------"
         << "Enter USERNAME and PASSWORD for login to th system"
         << "--------------------------------------------------\n";
    cout << endl
         << "\t\t\t\t\t\t\t\t\t    USERNAME: ";
    cin >> username;
    cout << "\t\t\t\t\t\t\t\t\t    PASSWORD: ";
    cin >> password;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    fstream file1, file2, file4;
    std::cout << "\n\t\t\t \t  _______________________________________________________________________________________________________ ";
    std::cout << "\n\t\t\t \t |                                                                                                       | ";
    std::cout << "\n\t\t\t \t |                                    CLINICAL TRIAL MANAGEMENT SYSTEM                                   | ";
    std::cout << "\n\t\t\t \t |_______________________________________________________________________________________________________| \n";

    int check;
    check = login_page();
    if (check == 1)
    {
        cout << "---------------------------------------------------------\n"
             << "\t Welcome to the System \t"
             << "\n--------------------------------------------------------";

        int choice;
        std::cout << "\n1: DRUG TRIAL DASHBOARD \n";
        std::cout << "\n2: HUMAN SUBJECTS DASHBOARD \n";
        for (;;)
        {
            std::cout << "PLEASE ENTER YOUR CHOICE:\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                for (;;)
                {
                    cout << "\nPlease choose :\n 0:Exit\n 1:Add Drug Record\n";
                    cout << "2:Search Drug Record\n 3:Delete Drug Record\n";
                    cout << "4:Display Drug Records\n";
                    cin >> choice;
                    switch (choice)
                    {
                    case 0:
                    {
                        exit(0);
                        break;
                    }
                    case 1:
                    {

                        string fileName = "drug";
                        cout << "\nEnter the details :\n";
                        add_record(fileName);
                        break;
                    }
                    case 2:
                    {
                        string fileName = "drug";
                        search_record(fileName);
                        break;
                    }
                    case 3:
                    {

                        delete_record();
                        break;
                    }
                    case 4:
                    {

                        display_records();
                        break;
                    }
                    default:
                    {
                        cout << "\nInvalid choice !\n";
                        break;
                    }
                    }
                }
                break;

            case 2:
                cout << "\nHUMAN SUBJECTS DASHBOARD\n";

                break;

            default:
                cout << "\nInvalid choice !\n";
                exit(0);
            }
        }
    }

    else
    {
        cout << "Invalid Credentials";
    }
}