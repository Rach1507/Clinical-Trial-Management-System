#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include<stdio.h>
#include<ctype.h>
#include <algorithm>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
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
        return 0;
    }
    while (!file2.fail())
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
    return I ;
}

void write_details(char filename[])
{

    fstream file2;
    file2.open(filename, ios::in);
    if (!file2)
    {
        cout<<"error in write details file";
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
    if(dashboardFlag==0)
    cout << "\t" << stdrec[0].field1 << "\t" << stdrec[0].field2 << "\t" << stdrec[0].field3 << "\t" << stdrec[0].field4 << "\t" << stdrec[0].field5 << "\n";
    else
    cout << "\t" << stdrec[0].field2 << "\t" << stdrec[0].field3 << "\t" << stdrec[0].field4 << "\t" << stdrec[0].field5 << "\n";
    file2.close();
}

string convertToString(char* a)
{
    string s(a);
  
    return s;
}
bool validation(string toBeChecked,int level ){

if(level==1){
for(int i=0;i<toBeChecked.length();i++){
    if(isdigit(toBeChecked[i])){

    }else{
        return false;
    }
}
return true;
}
if(level==2||level==3||level==6){
    for(int i=0;i<toBeChecked.length();i++){
    if(isdigit(toBeChecked[i])){
       

    }else{
         return false;
    }
}
return true;
}

if(level==5||level==8||level==9){
    for(int i=0;i<toBeChecked.length();i++){
    if(isdigit(toBeChecked[i])){
       

    }else{
         return true;
    }
}
return false;
  
}

if(level==4){
    if(toBeChecked=="Active"||toBeChecked=="Inactive"||toBeChecked=="active"||toBeChecked=="inactive"){
        return false;
    }else{
        return true;
    }
}
if(level==7){  //to check phone number
    for(int i=0;i<toBeChecked.length();i++){
    if(toBeChecked.length()!=10||isalpha(toBeChecked[i])){
        return true;

    }else{
        
    }
}
return false;
}
return true;
}
void add_record(string filename,string indFilename)
{

    int n = indFilename.length();
    int n0 = filename.length();

    char index[n + 1];
    char record_file[n0 + 1];

    strcpy(index, indFilename.c_str());
    strcpy(record_file, filename.c_str());

    char buf1[100], buf2[20],idx_drugName[10],idx_no[5],header;
    fstream file1, file2,file3;
    int I=0, cnt=0;
    ctm s;

    bool field1=true,field2=true,field3=true,field4=true,field5=true,field6=true,field7=true,field8=true,field9=true;

    cnt = get_num_records(record_file);
    file1.open(index, ios::out | ios::app);
    file3.open(index,ios::in);
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
        file2<<"ind|HSI|HSN|Phone|Age|Trial-Stage\n";
    }
    int no;
    cout << "\nEnter the details :\n";
    int j=0;
    I=cnt;

    //for (I = cnt,j=1; I <(cnt + 1); I++)
//    {
        if(dashboardFlag==0){

            

            while(field1){
                cout<<"\nEnter Drug name:\n";
                cin >> s.field1;
               string s1=convertToString(s.field1);
               field1= validation(s1,1);
               if(field1){
                   cout<<"please enter the valid drug name\n";
               }
            }
        

        if(!file3)
	{
		cout<<"\nError !\n";
		exit(0);
    }
    int flag=0;
	while(!file3.eof())
	{
		file3.getline(idx_drugName,10,'|');     
		file3.getline(idx_no,5,'\n');       
		if(strcmp(s.field1,idx_drugName)==0)
		{
			 
			flag=1;
			break;
		}
	}

        if(flag==0){
            

         while(field2){
                cout<<"Enter drug type\n";
                cin >> s.field2;
               string s1=convertToString(s.field2);
               field2= validation(s1,2);
               if(field2){
                   cout<<"please enter the valid drug type\n";
               }
            }

        

        while(field3){
                cout<<"Enter the department\n";
        cin >> s.field3;
               string s1=convertToString(s.field3);
               field3= validation(s1,3);
               if(field3){
                   cout<<"please enter the valid department\n";
               }
            }

        

        while(field4){
              cout<<"Enter the stage\n";
        cin >> s.field4;
               string s1=convertToString(s.field4);
               field4= validation(s1,4);
               if(field4){
                   cout<<"please enter the valid stage\n";
               }
            }

     

        while(field5){
            cout<<"Enter Trial-stage\n";
        cin >> s.field5;
               string s1=convertToString(s.field5);
               field5= validation(s1,5);
               if(field5){
                   cout<<"please enter the valid Tial-stage\n";
               }
            }


        }else{
            cout<<"drug already present\n";
            if(no>1)
            cout<<"Please enter new drugs\n";
        }
        }else{
            

        while(field6){
             cout<<"Enter human subject name\n";
        cin >> s.field2;
               string s1=convertToString(s.field2);
               field6= validation(s1,6);
               if(field6){
                   cout<<"please enter the valid human subject name\n";
               }
            }

        

         while(field7){
             cout<<"Enter the phone number\n";
        cin >> s.field3;
               string s1=convertToString(s.field3);
               field7= validation(s1,7);
               if(field7){
                   cout<<"please enter the valid phone number\n";
               }
            }

        

        while(field8){
             cout<<"Enter the age\n";
        cin >> s.field4;
               string s1=convertToString(s.field4);
               field8= validation(s1,8);
               if(field8){
                   cout<<"please enter the valid age\n";
               }
            }

        while(field9){
             cout<<"Enter the Trial-stage\n";
        cin >> s.field5;
               string s1=convertToString(s.field5);
               field9= validation(s1,9);
               if(field9){
                   cout<<"please enter the valid Trial-stage\n";
               }
            }


        }

        if(cnt==0&&dashboardFlag==0){
        sprintf(buf2, "%s|%d\n", s.field1, I);
        file1 << buf2;
        sprintf(buf1, "%d|%s|%s|%s|%s|%s\n", I, s.field1, s.field2, s.field3, s.field4, s.field5);
        file2 << buf1;
        }else if(cnt==0){
            sprintf(buf2, "%d|%d\n", I, I);
        file1 << buf2;
        sprintf(buf1, "%d|%d|%s|%s|%s|%s\n", I,I, s.field2, s.field3, s.field4, s.field5);
        file2<<buf1;
        }else{

            if(dashboardFlag==0){
                sprintf(buf2, "%s|%d\n", s.field1, I-1);
                file1 << buf2;
                sprintf(buf1, "%d|%s|%s|%s|%s|%s\n", I-1,s.field1, s.field2, s.field3, s.field4, s.field5);
                file2<<buf1;
            }else{
                sprintf(buf2, "%d|%d\n", I-1, I-1);
                file1 << buf2;
                sprintf(buf1, "%d|%d|%s|%s|%s|%s\n", I-1,I-1, s.field2, s.field3, s.field4, s.field5);
                file2<<buf1;
            }
        }
  //  }
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
                 << "Details :\n";

           if(dashboardFlag==0){
               cout<<"Drug name: "<<stdrec[i].field1<<"\n";
               cout<<"Drug type: "<<stdrec[i].field2<<"\n";
               cout<<"Department: "<<stdrec[i].field3<<"\n";
               cout<<"Stage: "<<stdrec[i].field4<<"\n";
               cout<<"Trial-stage: "<<stdrec[i].field5<<"\n";
               break;

           }else{
               cout<<"Human subject id: "<<stdrec[i].field1<<"\n";
               cout<<"Humman subject name: "<<stdrec[i].field2<<"\n";
               cout<<"Phone number: "<<stdrec[i].field3<<"\n";
               cout<<"Last dose: "<<stdrec[i].field4<<"\n";
               cout<<"Trial-stage: "<<stdrec[i].field5<<"\n";
               break;

           }

        }
    }
}

void search_record(string filename,string indFilename)
{

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
            retrieve_details(st_no, record_file);
            flag1 = 1;
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
fstream file1,file2,file3,file4;
char filenamechr[10],idxfilenamechr[10],dummy[20];

 strcpy(idxfilenamechr,indxFilename.c_str());
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
		cout<<"\nError!\n";
		return;
	}
	if(flag==(cnt-1))          
	{
		cnt--;
		cout<<"\nDeleted !\n";
		
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


      file2.open(filenamechr,ios::out); 

	 file1.open(indxFilename,ios::out);

    if(file2.fail()){
        cerr<<"Error:"<<strerror(errno);
    }

for(I=0;I<cnt;I++)                   
	{             
        if(I==0&&fileName.compare("drug.txt")==0){
            file2<<"ind|Drug name|Drug type|Department|Stage|Trial-Stage\n";
        }else if(I==0){
             file2<<"ind|HSI|HSN|phone|LD|Trial-Stage\n";
        }  else if(dashboardFlag==0){
            file1<<stdrec[I].field1<<"|"<<I-1<<"\n";
		file2<<I-1<<"|"<<stdrec[I].field1 <<"|"<<stdrec[I].field2<<"|"<<stdrec[I].field3<<"|"<<stdrec[I].field4<<"|"<<stdrec[I].field5<<"\n";
     
        }else{
            file1<<I-1<<"|"<<I-1<<"\n";
		file2<<I-1<<"|"<<I-1 <<"|"<<stdrec[I].field2<<"|"<<stdrec[I].field3<<"|"<<stdrec[I].field4<<"|"<<stdrec[I].field5<<"\n";
        }                   
		
	}
	file1.close();
	file2.close();
	return;
}


void delete_record(string fileName,string indxFileName)
{

    int I,flag;
char idx_no[20],drg_name[20],idx_drugName[20],indFileNameChr[20];
fstream file1;


     if(dashboardFlag==0){
	cout<<"\nEnter the name of the drug which is to be deleted\n";
     }
    else
    cout<<"\nEnter the Human Subject Id, whose record is to be deleted\n";

	cin>>drg_name;

  /*  if(dashboardFlag==0){
        string s=convertToString(drg_name);
        string remove1=s+".txt";
        string remove2=s+"-idx.txt";
        char rem1[20],rem2[20];
        strcpy(rem1,remove1.c_str());
        strcpy(rem2,remove1.c_str());
       int r1= remove(rem1);
        int r2=remove(rem2);
        cout<<"rem1name="<<rem1<<"rem1="<<r1<<"\n";
        cout<<"rem2name="<<rem2<<" rem2="<<r2<<"\n";
    }*/
    strcpy(indFileNameChr, indxFileName.c_str());
	file1.open(indFileNameChr,ios::in);
	if(!file1)
	{
		cout<<"\nError in opening file!\n";
		exit(0);
	}
	flag=0;

	while(!file1.eof())
	{
		file1.getline(idx_drugName,20,'|');     
		file1.getline(idx_no,20,'\n');       

		if(strcmp(drg_name,idx_drugName)==0)
		{
            string idx=convertToString(idx_no);
            string drgname=convertToString(drg_name);
			delete_drugRec(fileName,indxFileName,idx,drgname); 
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

bool f1=true,f2=true,f3=true,f4=true,f5=true,f6=true,f7=true,f8=true;

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
I++;
 }

I--;
char drugNameChr[20];
strcpy(drugNameChr,drugName.c_str());
for(j=0;j<I;j++)
{
if(strcmp(drugNameChr,recsObj[j].field1)==0)
{
   cout<<"The old values are\n";
   if(dashboardFlag==0){
    
 cout<<"Drug name: "<<recsObj[j].field1<<"\n";
 cout<<"Drug type: "<<recsObj[j].field2<<"\n";
 cout<<"Department: "<<recsObj[j].field3<<"\n";
 cout<<"Stage: "<<recsObj[j].field4<<"\n";
 cout<<"Trial-stage: "<<recsObj[j].field5<<"\n";
 }else{
    
 cout<<"Human subject id: "<<recsObj[j].field1<<"\n";
 cout<<"Human subject name: "<<recsObj[j].field2<<"\n";
 cout<<"Phone number: "<<recsObj[j].field3<<"\n";
 cout<<"Last dose: "<<recsObj[j].field4<<"\n";
 cout<<"Trial-stage: "<<recsObj[j].field5<<"\n";

 }
   cout<<"\n";
cout<<"\nEnter the new values \n";
  //cin>>recsObj[j].field1;     //field1 cannot be modified as it is either the drug name or the human subject id
 //cin>>recsObj[j].field2;
if(dashboardFlag==0){
 while(f2){
                cout<<"Enter drug type\n";
                cin>>recsObj[j].field2;
               string s1=convertToString(recsObj[j].field2);
               f2= validation(s1,2);
               if(f2){
                   cout<<"please enter the valid drug type\n";
               }
            }
while(f3){
                cout<<"Enter drug department\n";
                cin>>recsObj[j].field3;
               string s1=convertToString(recsObj[j].field2);
               f3= validation(s1,2);
               if(f2){
                   cout<<"please enter the valid drug department\n";
               }
            }

            while(f4){
              cout<<"Enter the stage\n";
        cin >> recsObj[j].field4;
               string s1=convertToString(recsObj[j].field4);
               f4= validation(s1,4);
               if(f4){
                   cout<<"please enter the valid stage\n";
               }
            }

     

        while(f5){
            cout<<"Enter Trial-stage\n";
        cin >> recsObj[j].field5;
               string s1=convertToString(recsObj[j].field5);
               f5= validation(s1,5);
               if(f5){
                   cout<<"please enter the valid Tial-stage\n";
               }
            }

}else{
while(f6){
             cout<<"Enter human subject name\n";
        cin >>recsObj[j].field2;
               string s1=convertToString(recsObj[j].field2);
               f6= validation(s1,6);
               if(f6){
                   cout<<"please enter the valid human subject name\n";
               }
            }

        

         while(f7){
             cout<<"Enter the phone number\n";
        cin >> recsObj[j].field3;
               string s1=convertToString(recsObj[j].field3);
               f7= validation(s1,7);
               if(f7){
                   cout<<"please enter the valid phone number\n";
               }
            }

        

        while(f8){
             cout<<"Enter the age\n";
        cin >> recsObj[j].field4;
               string s1=convertToString(recsObj[j].field4);
               f8= validation(s1,8);
               if(f8){
                   cout<<"please enter the valid age\n";
               }
            }

        while(f1){
             cout<<"Enter the Trial-stage\n";
        cin >>recsObj[j].field5;
               string s1=convertToString(recsObj[j].field5);
               f1= validation(s1,9);
               if(f1){
                   cout<<"please enter the valid Trial-stage\n";
               }
            }


}

 if(dashboardFlag==0){
     cout<<"new values are as follows:\n";
 cout<<"Drug name: "<<recsObj[j].field1<<"\n";
 cout<<"Drug type: "<<recsObj[j].field2<<"\n";
 cout<<"Department: "<<recsObj[j].field3<<"\n";
 cout<<"Stage: "<<recsObj[j].field4<<"\n";
 cout<<"Trial-stage: "<<recsObj[j].field5<<"\n";
 }else{
     cout<<"new values are as follows:\n";
 cout<<"Human subject id: "<<recsObj[j].field1<<"\n";
 cout<<"Human subject name: "<<recsObj[j].field2<<"\n";
 cout<<"Phone number: "<<recsObj[j].field3<<"\n";
 cout<<"Last dose: "<<recsObj[j].field4<<"\n";
 cout<<"Trial-stage: "<<recsObj[j].field5<<"\n";

 }
 
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
cout<<ctmObj.field1<<"\t\t"<<ctmObj.field2<<"\t\t"<<ctmObj.field3<<"\t\t"<<ctmObj.field4<<"\t\t"<<ctmObj.field5<<"\n";
	 	
 	}
	file2.close();
}





int login_page()
{
    char username[20], password[20];
    /*char user1[20] = "rachitha", pass1[20] = "pass";
    char user2[20] = "tarun", pass2[20] = "pass";
    char user3[20] = "phani", pass3[20] = "pass";
    char user4[20] = "atharva", pass4[20] = "pass";
    char user5[20] = "aarabhi", pass5[20] = "pass";*/
    char user1[20] = "dr.rachBR", pass1[20] = "passRach";
    char user2[20] = "dr.ahuja", pass2[20] = "passAhuja";
    char user3[20] = "dr.rahia", pass3[20] = "passRahia";
    char user4[20] = "dr.kashyap", pass4[20] = "passKash";
    char user5[20] = "dr.aarabhi", pass5[20] = "passAara";
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
    if ((strcmp(username, user1) == 0 && strcmp(password, pass1) == 0)||(strcmp(username, user2) == 0 && strcmp(password, pass2) == 0)||(strcmp(username, user3) == 0 && strcmp(password, pass3) == 0)||(strcmp(username, user4) == 0 && strcmp(password, pass4) == 0)||(strcmp(username, user5) == 0 && strcmp(password, pass5) == 0))
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
    check = login_page();
    if (check == 1)
    {
        cout << "---------------------------------------------------------\n"
             << "\t Welcome to the System \t"
             << "\n--------------------------------------------------------";

        int choice;
       
        for (;;)
        {
        std::cout << "\n1: DRUG TRIAL DASHBOARD \n";
        std::cout << "\n2: HUMAN SUBJECTS DASHBOARD \n";
        std::cout << "\n3: Exit \n";
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
                int backToUpperLevel2=0;
                for (;;)
                {
                    cout << "\nPlease choose :\n\n1:Add Drug Record\n\n";
                    cout << "2:Search Drug Record\n\n";
                    cout << "3:Delete drug\n\n"<<"4:Display Drug Records\n\n""5.Modify Records\n\n0:Back to main menu\n";
                    cin >> choice;
                    switch (choice)
                    {
                    case 0:
                    {
                        backToUpperLevel2=1;
                        //exit(0);
                        break;
                    }
                    case 1:
                    {

                        string fileName = "drug.txt";
                        string indxFilename="drug-idx.txt";
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
                    if(backToUpperLevel2==1)
                    break;
                }
                break;
            }

            case 2:
            {
               

                for(;;){
                     cout << "\nHUMAN SUBJECTS DASHBOARD\n";
                    cout<<"Enter the drug name  (q=go to main menu)\n";
                    cin>>drugFileName;
                    if(drugFileName=="q"){
                        break;
                    }
                    fstream drugcheck;
                    drugcheck.open("drug-idx.txt",ios::in);
                    if(!drugcheck)
                    {
                        cout<<"\nError !\n";
                        exit(0);
                    }
                	int flag=0;
                    char idx_drugName[10],idx_no[5],drugFileNameChr[10];
                    strcpy(drugFileNameChr,drugFileName.c_str());

                    while(!drugcheck.eof())
                    {
                        drugcheck.getline(idx_drugName,10,'|');     
                        drugcheck.getline(idx_no,5,'\n');
                        if(strcmp(drugFileNameChr,idx_drugName)==0){
                            flag=1;
                            break;
                        }
                    }
                if(flag==1){
                    cout<<"\n";
                    cout<<"Here you can find the data of the above entered drug \n";
                    drugIdxFile+=drugFileName+"-idx.txt";
                    drugFileName+=".txt";
                    int backToUpperLevel1=0;
                    for(;;){

                    cout << "\nPlease choose :\n1:Add Human subject Record\n\n";
                    cout << "2:Search Human subject Record\n\n3:Delete Human subject Record\n\n";
                    cout << "4:Display Human subject Records\n\n""5.Modify Records\n\n0:Go back to human subject dashboard\n";
                    cin >> choice;
                    switch (choice)
                    {
                    case 0:
                    {
                       // exit(0);
                       backToUpperLevel1=1;
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
                    if(backToUpperLevel1==1)
                    break;
                }

                }else{
                    cout<<"Sorry, te drug name you've entered is not yet added in the database\n";
                }
                
           
                }
         break;
            } 
            case 3:
            exit(0);
            break;
        }//end of switch main
     } //end of for loop main
    } // end of if
    else
    {
        cout << "Invalid Credentials !";
    }
}
