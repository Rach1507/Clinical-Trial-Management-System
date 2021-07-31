#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
static int dashboardFlag;
class ctm
{
public:
public:
    char ind[5], field1[20], field2[15], field3[15], field4[10], field5[15];
} stdrec[20];

int get_num_records(char filename[])
{
    int I = 0;
    fstream file2;
    file2.open(filename, ios::in);
    if (!file2)
    {
        cout << "Error in get num recs";
        return 0;
    }
    while (!file2.fail())
    {
         //cout << "Error in get num recs in while";
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
    return I ;
}

void write_details(char filename[])
{

    fstream file2;
    file2.open(filename, ios::in);
    if (!file2)
    {
        cout<<"erroe in write details file";
        return;
    }
    if (!file2.fail()) 
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

void add_record(string filename,string indFilename)
{
   // string index_str = filename + "-idx.txt";

    //filename = filename + ".txt";

    int n = indFilename.length();
    int n0 = filename.length();

    char index[n + 1];
    char record_file[n0 + 1];

    strcpy(index, indFilename.c_str());
    strcpy(record_file, filename.c_str());

    char buf1[100], buf2[20],header;
    fstream file1, file2;
    int I, cnt;
    ctm s;

    cnt = get_num_records(record_file);
     cout<<"No of recordings in file "<<cnt;
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
     if(cnt==0&&filename.compare("drug.txt")==0){
        file2<<"ind|Drug name|Drug type|Department|Stage|Trial-Stage\n";
    }else if(cnt==0){
        file2<<"ind|HSI|HSN|Phone|LD|Trial-Stage\n";
    }
    int no;
    cout << "\nEnter the no. of records to be added : ";
    cin >> no;
    cout << "\nEnter the details :\n";

    write_details(record_file);
    int j=0;

    for (I = cnt,j=1; I < (cnt + no); I++)
    {
        cout<<"Enter the details of drug "<<j++;
        write_details(record_file);
        cin >> s.field1;
        cin >> s.field2;
        cin >> s.field3;
        cin >> s.field4;
        cin >> s.field5;

        if(cnt==0){
        sprintf(buf2, "%s|%d\n", s.field1, I);
        file1 << buf2;
        sprintf(buf1, "%d|%s|%s|%s|%s|%s\n", I, s.field1, s.field2, s.field3, s.field4, s.field5);
        file2 << buf1;
        }else{
        sprintf(buf2, "%s|%d\n", s.field1, I-1);
        file1 << buf2;
        sprintf(buf1, "%d|%s|%s|%s|%s|%s\n", I-1, s.field1, s.field2, s.field3, s.field4, s.field5);
        file2 << buf1;
        }
    }
    file1.close();
    file2.close();
}

void retrieve_details(char index_no[], char file_name[])
{

    int no = get_num_records(file_name);
    cout<<no<<" numbers";

    for (int i = 0; i < no; i++)
    {
        if (strcmp(stdrec[i].ind, index_no) == 0)
        {
            cout << "\n\n"
                 << "Details :\n";
            write_details(file_name);
            cout << "\t" << stdrec[i].field1 << "\t\t" << stdrec[i].field2 << "\t\t" << stdrec[i].field3 << "\t\t" << stdrec[i].field4 << "\t\t" << stdrec[i].field5 << "\n";
            break;
        }
    }
}

void search_record(string filename,string indFilename)
{
   // string index_str = filename + "-idx.txt";

    //filename = filename + ".txt";

    int n = indFilename.length();
    int n0 = filename.length();
    // declaring character array
    char index[n + 1];
    char record_file[n0 + 1];
    // copying the contents of the
    // string to char array
    strcpy(index, indFilename.c_str());
    strcpy(record_file, filename.c_str());

    int I, flag1;
    char st_no[5], name[20], required_name[20];
    fstream file1;

    // cout<<index;
    if(dashboardFlag==0){
    cout << "\nEnter the Name of the drug";
    cout << " whose record is to be searched\n";
    }else{
        cout<<"\nEnter the Human Subject Id which isto be searched";
    }
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
            cout<<"hello";
            break;
        }
    }
    if (!flag1)
        cout << "\nRecord search failed !!\n";
    file1.close();
}

void delete_drugRec(string fileName,string indxFilename,string indx_no,string drugName)
{
int I=0;
fstream file1,file2;
char filenamechr[10],idxfilenamechr[10];
//string filename1="drug.txt";

// strcpy(idxfilenamechr,indxFilename.c_str());
  strcpy(filenamechr, fileName.c_str());

int	cnt = get_num_records(filenamechr);	
	int flag=-1;
	for(I=0;I<cnt;I++)     
	{
        string ind=stdrec[I].ind;
        if(ind.compare(indx_no)==0)
		{
			flag=I;
			break;
		}	

	}
	if(flag==-1)              
	{
		cout<<"\nError !\n";
		return;
	}
	if(flag==(cnt-1))          
	{
		cnt--;
		cout<<"\nDeleted if(flag==(cnt-1))!\n";
		
	}
	else
	{
		for(I=flag;I<cnt;I++)
		{
			stdrec[I] = stdrec[I+1];
		}
		cnt--;
		cout<<"\nDeleted !\n";
	}

    file1.open(indxFilename,ios::out);

	file2.open(filenamechr,ios::out);  
    if(file2.fail()){
        cerr<<"Error:"<<strerror(errno);
    }
        cout<<"Value of count 1 "<<cnt;  
    cout<<"Value of count 2"<<cnt;

for(I=0;I<cnt;I++)                   
	{             
        if(I==0&&fileName.compare("drug.txt")==0){
            file2<<"ind|Drug name|Drug type|Department|Stage|Trial-Stage\n";
        }else if(I==0){
             file2<<"ind|HSI|HSN|phone|LD|Trial-Stage\n";
        }  else{
            file1<<stdrec[I].field1<<"|"<<I-1<<"\n";
		file2<<I-1<<"|"<<stdrec[I].field1 <<"|"<<stdrec[I].field2<<"|"<<stdrec[I].field3<<"|"<<stdrec[I].field4<<"|"<<stdrec[I].field5<<"\n";
     
        }                   
		
	}

	file1.close();
	file2.close();
	return;
}


void delete_record(string fileName,string indxFileName)
{

    int I,flag;
char idx_no[5],drg_name[5],idx_drugName[5];
fstream file1;

     if(dashboardFlag==0)
	cout<<"\nEnter the name of the drug which is to be deleted\n";
    else
    cout<<"\nEnter the Human Subject Id, whose record is to be deleted\n";

	cin>>drg_name;
	file1.open(indxFileName,ios::in);
	if(!file1)
	{
		cout<<"\nError !\n";
		exit(0);
	}
	flag=0;

	while(!file1.eof())
	{
		file1.getline(idx_drugName,10,'|');     
		file1.getline(idx_no,5,'\n');       

		if(strcmp(drg_name,idx_drugName)==0)
		{
			delete_drugRec(fileName,indxFileName,idx_no,drg_name); 
			flag=1;
			break;
		}
	}
	if(!flag)
	cout<<"\nDeletion failed !\n"; 
	file1.close();
	
	
}

void modify(string filename)
{
fstream in;
char buffer[45];
string drugName,HumanSubId;
int I,j;
char filenameChr[15];
strcpy(filenameChr,filename.c_str());
int countOfRecs=get_num_records(filenameChr);
ctm recsObj[countOfRecs];

in.open(filenameChr,ios::in);

if(!in)
{
cout<<"\nCannot open the file";
return;
}
 if(dashboardFlag==0)
cout<<"\nEnter the Drug name\n";
else 
cout<<"\nEnter the Human Subject id\n";
cin>>drugName;

I=0;

while(!in.eof())
  {
in.getline(recsObj[I].ind,5,'|');
in.getline(recsObj[I].field1,20,'|');
in.getline(recsObj[I].field2,15,'|');
in.getline(recsObj[I].field3,15,'|');
in.getline(recsObj[I].field4,10,'|');
in.getline(recsObj[I].field5,15,'\n');
cout<<recsObj[I].field1<<" "<<recsObj[I].field2<<" "<<recsObj[I].field3<<" "<<recsObj[I].field4<<" "<<recsObj[I].field5<<"\n";
I++;
 }

I--;
char drugNameChr[20];
strcpy(drugNameChr,drugName.c_str());
cout<<"I count: "<<I;
for(j=0;j<I;j++)
{
if(strcmp(drugNameChr,recsObj[j].field1)==0)
{
cout<<"\nEnter the new values \n";
  //cin>>recsObj[j].field1;     //field1 cannot be modified as it is either the drug name or the human subject id
 cin>>recsObj[j].field2;
  cin>>recsObj[j].field3;
 cin>>recsObj[j].field4;
  cin>>recsObj[j].field5;
  cout<<"new vals "<<recsObj[j].field1<<" "<<recsObj[j].field2<<" "<<recsObj[j].field3<<" "<<recsObj[j].field4<<" "<<recsObj[j].field5<<"\n";
break;

  }
 }

if(j==I)
 {
cout<<"\nRecord not found.\n"; 
return;
 }

in.close();
fstream file;
file.open(filenameChr,ios::out);
if(!file)
 {
cout<<"\nUnable"; 
return;
 }

for(j=0;j<I;j++)
 {
strcpy(buffer,recsObj[j].ind);
strcat(buffer,"|");
strcat(buffer,recsObj[j].field1);
strcat(buffer,"|");
strcat(buffer,recsObj[j].field2);
strcat(buffer,"|");
strcat(buffer,recsObj[j].field3);
strcat(buffer,"|");
strcat(buffer,recsObj[j].field4);
strcat(buffer,"|");
strcat(buffer,recsObj[j].field5);
strcat(buffer,"\n");
file<<buffer;
 }
file.close();
}
void display_records(string filename)
{

    fstream file2;
     ctm ctmObj;

	
	file2.open(filename,ios::in);
    if(dashboardFlag==0)
cout<<"\n\n"<<"Drugs details : \n";
    else
    cout<<"\n\n"<<"Human Subject details : \n";
	while(!file2.fail())
 	{
		file2.getline(ctmObj.ind,5,'|');
		file2.getline(ctmObj.field1,20,'|');
		file2.getline(ctmObj.field2,15,'|');
		file2.getline(ctmObj.field3,15,'|');
		file2.getline(ctmObj.field4,10,'|');
		file2.getline(ctmObj.field5,15,'\n');
cout<<ctmObj.ind<<"\t\t"<<ctmObj.field1<<"\t\t"<<ctmObj.field2<<"\t\t"<<ctmObj.field3<<"\t\t"<<ctmObj.field4<<"\t\t"<<ctmObj.field5<<"\n";
	 	
 	}
	file2.close();
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
    string drugFileName;
    string drugIdxFile;
    fstream drugFileObj;
    fstream  indx;
    check = 1;//login_page();
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
            if(choice==1){
                dashboardFlag=0;
            }else{
                dashboardFlag=1;
            }
            switch (choice)
            {
            case 1:
            {
                for (;;)
                {
                    cout << "\nPlease choose :\n 0:Exit\n 1:Add Drug Record\n";
                    cout << "2:Search Drug Record\n 3:Delete Drug Record\n";
                    cout << "4:Display Drug Records\n" "5.Modify Records\n";
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

                        string fileName = "drug.txt";
                        string indxFilename="drug-idx.txt";
                        cout << "\nEnter the details :\n";
                        add_record(fileName,indxFilename);
                        break;
                    }
                    case 2:
                    {
                        string fileName = "drug.txt";
                        string indxFilename="drug-idx.txt";
                        search_record(fileName,indxFilename);
                        break;
                    }
                    case 3:
                    {
                         string fileName = "drug.txt";
                        string indxFilename="drug-idx.txt";
                        delete_record(fileName,indxFilename);
                        break;
                    }
                    case 4:
                    {
                        string fileName = "drug.txt";

                        display_records(fileName);
                        break;
                    }
                    case 5:
                    {
                        string fileName = "drug.txt";

                        modify(fileName);
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
            }

            case 2:
            {
                cout << "\nHUMAN SUBJECTS DASHBOARD\n";

                for(;;){
                    cout<<"Enter the drug name\n";
                    cin>>drugFileName;
                    drugIdxFile+=drugFileName+"-idx.txt";
                  //  drugIdxFile="drugFiles/"+drugIdxFile;
                    drugFileName+=".txt";
                   // drugFileName="drugFiles/"+drugFileName;
                    drugFileObj.open(drugFileName,ios::in|ios::app);
                    indx.open(drugIdxFile,ios::in|ios::app);
                    for(;;){

                    cout << "\nPlease choose :\n 0:Exit\n 1:Add patient Record\n";
                    cout << "2:Search Drug Record\n 3:Delete Drug Record\n";
                    cout << "4:Display Drug Records\n" "5.Modify Records\n";
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
                        add_record(drugFileName,drugIdxFile);
                        break;
                    }
                    case 2:
                    {
                       search_record(drugFileName,drugIdxFile);
                        break;
                    }
                    case 3:
                    {
                        delete_record(drugFileName,drugIdxFile);
                        break;
                    }
                    case 4:
                    {
                        display_records(drugFileName);
                        break;
                    }
                    case 5:
                    {
                        modify(drugFileName);
                        break;
                    }
                    default:{
                            cout << "\nInvalid choice !\n";
                            exit(0);
                            }
                    }
                }
           
                }
         break;
            } 
        }//end of switch main
     } //end of for loop main
    } // end of if
    else
    {
        cout << "Invalid Credentials";
    }
}

/*ind|HSI|HSN|Phone|LD|Trial-Stage
0|a|a|a|a|a
1|b|b|b|b|b
2|c|c|c|c|c

a|0
b|1
c|2
*/