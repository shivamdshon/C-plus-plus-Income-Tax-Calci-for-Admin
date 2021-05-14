#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>

using namespace std;


fstream record, temp;


/**********************************************BASE CLASS:TaxPayerInfo(taxpayer basic info):BELOW**********************************************************/


class TaxPayerInfo                           /*base class containg basic information for all derived classes*/
{   
    int id, age;                               /*id stores unique id of a person and age stores age of that person*/

    string sex, occupation;

    char name[30];              /*name stores name of the person, sex stores sex of the person and occupation stores occupation of that person*/

  public:

    void getdata();                            /*getdata() function gets the data from the user and stores it*/
    void showdata();                           /*showdata() function shows the data of the user in the screen*/
};

void TaxPayerInfo :: getdata()               /*definition of getdata() function*/
{   
    record.open("record.txt", ios::app|ios::out);

    cout<<"\nEnter your unique ID: ";
    cin>>id;
    record<<id<<"\n";

    char buf[1];                            /*to store the newline character from the buffer*/
    cin.getline(buf,1);

	cout<<"\nEnter your NAME: ";
	cin.getline(name,30);
    record<<name<<"\n";

	cout<<"\nEnter your AGE: ";
	cin>>age;
    record<<age<<"\n";

	cout<<"\nEnter your SEX: ";
	cin>>sex;
    record<<sex<<"\n";

	cout<<"\nEnter your OCCUPATION: ";
	cin>>occupation;
    record<<occupation<<"\n";
    
    record.close();
}

void TaxPayerInfo :: showdata()              /*definition of showdata() function*/
{   
    cout<<"\nID: "<<id;
    cout<<"\nNAME: "<<name;
    cout<<"\nAGE: "<<age;
    cout<<"\nSEX: "<<sex;
    cout<<"\nOCCUPATION: "<<occupation;
}


/**********************************************BASE CLASS(taxpayer basic info):ABOVE**********************************************************/



/**********************************************DERIVED CLASS:Citizen(tax calculation for citizen of age less than 60):BELOW**********************************************************/


class Citizen : public TaxPayerInfo
{
    int salary, tax;

  public:

    void getcitizen(int sal)
         {
         	salary=sal;

         }

    int taxcal();

    void showcitizen()
         {  
            record.open("record.txt", ios::app|ios::out);
            record<<salary<<"\n";
            record<<tax<<"\n";
            record.close();

         	if(tax==0)
         		cout<<"\nYOU DO NOT NEED TO PAY INCOME TAX\n";
    
            cout<<"\nYour Salary: "<<salary;
            cout<<"\nYour Payable Income Tax: "<<tax;
            cout<<"\nYour Net Income: "<<salary-tax;
         }
};

int Citizen :: taxcal()
{
	if(salary<=250000)
		tax = 0;

	if(salary>250000 && salary<=500000)
		tax = (salary-250000)*0.05;

	if(salary>500000 && salary<=1000000)
		tax = 12500 + (salary-500000)*0.2;

	if(salary>1000000)
		{  
			tax = 112500 + (salary-1000000)*0.3;

			if(salary>5000000 && salary<=10000000)
				tax = tax + (salary-1000000)*0.03;

			if(salary>10000000)
				tax = tax + (salary-1000000)*0.045;
        }
    return tax;
}



/**********************************************DERIVED CLASS:Citizen(tax calculation for citizen of age less than 60):ABOVE**********************************************************/



/**********************************************DERIVED CLASS:SenCitizen(tax calculation for senior citizen of age between 60 to 80):BELOW**********************************************************/


class SenCitizen : public TaxPayerInfo
{
    int salary, tax;

  public:

    void getcitizen(int sal)
         {
         	salary=sal;
         }

    int taxcal();

    void showcitizen()
         {  
            record.open("record.txt", ios::app|ios::out);
            record<<salary<<"\n";
            record<<tax<<"\n";
            record.close();

         	if(tax==0)
         		cout<<"\nYOU DO NOT NEED TO PAY INCOME TAX\n";

         	cout<<"\nYour Salary: "<<salary;
            cout<<"\nYour Payable Income Tax: "<<tax;
            cout<<"\nYour Net Income: "<<salary-tax;
         }
};

int SenCitizen :: taxcal()
{
	if(salary<=300000)
		tax = 0;

	if(salary>300000 && salary<=500000)
		tax = (salary-250000)*0.1;

	if(salary>500000 && salary<=1000000)
		tax = 20000 + (salary-500000)*0.2;

	if(salary>1000000)
		{  
			tax = 120000 + (salary-1000000)*0.3;

			if(salary>5000000 && salary<=10000000)
				tax = tax + (salary-1000000)*0.03;

			if(salary>10000000)
				tax = tax + (salary-1000000)*0.045;
        }
    return tax;
}



/**********************************************DERIVED CLASS:SenCitizen(tax calculation for senior citizen of age between 60 to 80):ABOVE**********************************************************/



/**********************************************DERIVED CLASS:SupSenCitizen(tax calculation for super senior citizen of age of 80 years  and above):BELOW**********************************************************/


class SupSenCitizen : public TaxPayerInfo
{
    int salary, tax;

  public:

    void getcitizen(int sal)
         {
         	salary=sal;
         }

    int taxcal();

    void showcitizen()
         {  
            record.open("record.txt", ios::app|ios::out);
            record<<salary<<"\n";
            record<<tax<<"\n";
            record.close();

         	if(tax==0)
         		cout<<"\nYOU DO NOT NEED TO PAY INCOME TAX\n";

         	cout<<"\nYour Salary: "<<salary;
            cout<<"\nYour Payable Income Tax: "<<tax;
            cout<<"\nYour Net Income: "<<salary-tax;
         }
};

int SupSenCitizen :: taxcal()
{
	if(salary<=250000)
		tax = 0;

	if(salary>250000 && salary<=500000)
		tax = (salary-250000)*0.05;

	if(salary>500000 && salary<=1000000)
		tax = 12500 + (salary-500000)*0.2;

	if(salary>1000000)
		{  
			tax = 112500 + (salary-1000000)*0.3;

			if(salary>5000000 && salary<=10000000)
				tax = tax + (salary-1000000)*0.03;

			if(salary>10000000)
				tax = tax + (salary-1000000)*0.045;
        }
    return tax;
}



/**********************************************DERIVED CLASS:SupSenCitizen(tax calculation for  super senior citizen of age of 80 years and above):ABOVE**********************************************************/





/******************************************************************MAIN FUNCTION************************************************************************/


int main()
{
	Citizen c;
	SenCitizen sc;
	SupSenCitizen ssc;
    int choice, salarymain, uid=0, flag=0;
    char ch;

    int id, age, salary, tax;          /*for reading from a file*/                       

    string sex, occupation;            /*for reading from a file*/

    char name[30];                     /*for reading from a file*/

	mainmenu: system("cls");

     cout<<"\t\t\t************************Income-Tax Calculator****************************\t\t\t\n\n\n";
	cout<<"\n1.Add New Record\n2.List All Tax Payers\n3.Search\n4.Edit\n5.Delete Record\n6.Want to know about IncomTax\n7.Exit Program\n\nEnter your choice (1,2,3,4,5 or 6) ... ";
	cin>>choice;

    switch(choice)
    {
     

        case 1: categorymenu:

                system("cls");
                cout<<"\nCategory you belongs to:\n\n1.Citizen(age<60)\n2.SenCitizen(60<=age && age<80)\n3.SupSenCitizen(age>=80)\n4.Return To Main Menu\n5.Exit Program\n\nEnter your choice (1,2,3,4 or 5) ... ";
                int cat;
                cin>>cat;

                switch(cat)
                {
                    case 1: 
                            system("cls");

                            c.getdata();
                            
                            cout<<"\nEnter your salary: ";
                            cin>>salarymain;

                            c.getcitizen(salarymain);
                            c.taxcal();

                             cout<<"\n Your data has been stored. Do you  want to see the data you have entered?\n Press (y/n) .. ";
                             cin>>ch;

                             if(ch=='y' || ch=='Y')
                             {
                                c.showdata();
                                c.showcitizen();
                                getch();
                                goto mainmenu;
                             }
                             else
                                goto mainmenu;
                             


                    case 2: 

                            system("cls");

                            sc.getdata();
                            
                            cout<<"\nEnter your salary: ";
                            cin>>salarymain;

                            sc.getcitizen(salarymain);
                            sc.taxcal();

                             cout<<"\nYour data has been stored. Do you  want to see the data you have entered?\n Press (y/n) .. ";
                             cin>>ch;

                             if(ch=='y' || ch=='Y')
                             {
                                sc.showdata();
                                sc.showcitizen();
                                getch();
                                goto mainmenu;
                             }
                             else
                                goto mainmenu;

                    case 3: 

                            system("cls");

                            ssc.getdata();
                            
                            cout<<"\nEnter your salary: ";
                            cin>>salarymain;

                            ssc.getcitizen(salarymain);
                            ssc.taxcal();

                             cout<<"\nYour data has been stored. Do you  want to see the data you have entered?\n Press (y/n) .. ";
                             cin>>ch;

                             if(ch=='y' || ch=='Y')
                             {
                                ssc.showdata();
                                ssc.showcitizen();
                                getch();
                                goto mainmenu;
                             }
                            else
                                goto mainmenu;

                    case 4: system("cls");
                            goto mainmenu;


                    case 5: system("cls");
                            cout<<"Thank you for your time. Program is exiting now.";
                            exit(0);


                    default: system("cls");
                             cout<<"Wrong choice! Please try again.";
                             goto categorymenu;
                                   



                }
                
                


        case 2: 

                system("cls");

                record.open("record.txt", ios::in);

                while(!record.eof())
                {
                    record>>id;
                    char buf[1];
                    record.getline(buf,1);
                    record.getline(name,30);
                    record>>age;
                    record>>sex;
                    record>>occupation;
                    record>>salary;
                    record>>tax;

                    cout<<"ID: "<<id;
                    cout<<"\nNAME: "<<name;
                    cout<<"\nAGE: "<<age;
                    cout<<"\nSEX: "<<sex;
                    cout<<"\nOCCUPATION: "<<occupation;
                    cout<<"\nSALARY: "<<salary;
                    cout<<"\nTAX: "<<tax;
                }

                record.close();

                cout<<"\n\n\nDo you want to return to the Main Menu(y/n)? ";
                cin>>ch;

                if(ch=='y' || ch=='Y')
                    goto mainmenu;
                else
                {
                    system("cls");
                    cout<<"Thank you for your time. Program is exiting now.";
                    exit(0);
                }

                

                
        case 3: system("cls");
                 
                cout<<"\nEnter your unique id: ";
                cin>>uid;

                record.open("record.txt", ios::in);

                while(!record.eof())
                {
                    record>>id;
                    char buf[1];
                    record.getline(buf,1);
                    record.getline(name,30);
                    record>>age;
                    record>>sex;
                    record>>occupation;
                    record>>salary;
                    record>>tax;

                    if(id==uid)
                    {   flag=1;
                        cout<<"\nRecord has been found!\n\n";

                        cout<<"ID: "<<id;
                        cout<<"\nNAME: "<<name;
                        cout<<"\nAGE: "<<age;
                        cout<<"\nSEX: "<<sex;
                        cout<<"\nOCCUPATION: "<<occupation;
                        cout<<"\nSALARY: "<<salary;
                        cout<<"\nTAX: "<<tax;

                        break;
                    }


                    
                }

                if(!flag)
                    cout<<"\nSorry! No data found.\n";

                flag=0;

                record.close();

                cout<<"\n\n\nDo you want to return to the Main Menu(y/n)? ";
                cin>>ch;

                if(ch=='y' || ch=='Y')
                    goto mainmenu;
                else
                {
                    system("cls");
                    cout<<"Thank you for your time. Program is exiting now.";
                    exit(0);
                }

                    


        case 4:  editmenu:

                 system("cls");
                 cout<<"Enter the unique id of the person whose record you want to edit: ";
                 cin>>uid;
                 
                 cout<<"What do you want to edit:\n\n\n1.Name\n2.Age\n3.Occupation\n4.Salary\n5.Return To Previous Menu\n6.Return To Mainmenu\n7.Exit Program\n\nEnter your choice: ";
                 int editchoice;
                 cin>>editchoice;

                 switch(editchoice)
                 {
                    case 1:{                          /*case 1 is for the editing of name*/
                           record.open("record.txt", ios::in); temp.open("temp.txt", ios::out);

                           char buf[1];
                           cin.getline(buf,1);

                           system("cls");

                           char newname[30];
                           cout<<"Enter the new name: ";
                           cin.getline(newname,30);
                 
                           while(!record.eof())
                           {
                               record>>id;
                               char buf[1];
                               record.getline(buf,1);
                               record.getline(name,30);
                               record>>age;
                               record>>sex;
                               record>>occupation;
                               record>>salary;
                               record>>tax;

                               if(id=uid)
                               {   
                                   temp<<id<<endl;
                                   temp<<newname<<endl;
                                   temp<<age<<endl;
                                   temp<<sex<<endl;
                                   temp<<occupation<<endl;
                                   temp<<salary<<endl;
                                   temp<<tax<<endl;
                               }
     
                               else
                               {   
                                   temp<<id<<endl;
                                   temp<<name<<endl;
                                   temp<<age<<endl;
                                   temp<<sex<<endl;
                                   temp<<occupation<<endl;
                                   temp<<salary<<endl;
                                   temp<<tax<<endl;
                               }
                           }

                            record.close();
                            temp.close();
                                
                            remove("record.txt");
                            rename("temp.txt","record.txt");

                            system("cls");

                            cout<<"Your new record has been successfully saved!\n\nDo you want to edit more records(y/n)? ";
                            cin>>ch;

                            if(ch=='y' || ch=='Y')
                            goto editmenu;
                            else
                            {
                                system("cls");
                                goto mainmenu;   
                            }
                        }


                    case 2:{system("cls");
                                  /*case 2 is for the editing of the age*/
                            record.open("record.txt", ios::in); temp.open("temp.txt", ios::out);

                           int newage;
                           cout<<"Enter the new age: ";
                           cin>>newage;
                 
                           while(!record.eof())
                           {
                               record>>id;
                               char buf[1];
                               record.getline(buf,1);
                               record.getline(name,30);
                               record>>age;
                               record>>sex;
                               record>>occupation;
                               record>>salary;
                               record>>tax;

                               if(id=uid)
                               {   
                                   temp<<id<<endl;
                                   temp<<name<<endl;
                                   temp<<newage<<endl;
                                   temp<<sex<<endl;
                                   temp<<occupation<<endl;
                                   temp<<salary<<endl;
                                   temp<<tax<<endl;
                               }
     
                               else
                               {   
                                   temp<<id<<endl;
                                   temp<<name<<endl;
                                   temp<<age<<endl;
                                   temp<<sex<<endl;
                                   temp<<occupation<<endl;
                                   temp<<salary<<endl;
                                   temp<<tax<<endl;
                               }
                           }

                            record.close();
                            temp.close();

                            remove("record.txt");
                            rename("temp.txt","record.txt");
                           
                            system("cls");

                           cout<<"Your new record has been successfully saved!\n\nDo you want to edit more records(y/n)? ";
                            cin>>ch;

                            if(ch=='y' || ch=='Y')
                            goto editmenu;
                            else
                            {
                                system("cls");
                                goto mainmenu;   
                            }

                           }


                    case 3:{system("cls");
                                          /*case 2 is for the editing of the age*/
                           record.open("record.txt", ios::in); temp.open("temp.txt", ios::out);

                           int newoccupation;
                           cout<<"Enter the new occupation: ";
                           cin>>newoccupation;
                 
                           while(!record.eof())
                           {
                               record>>id;
                               char buf[1];
                               record.getline(buf,1);
                               record.getline(name,30);
                               record>>age;
                               record>>sex;
                               record>>occupation;
                               record>>salary;
                               record>>tax;

                               if(id=uid)
                               {   
                                   temp<<id<<endl;
                                   temp<<name<<endl;
                                   temp<<age<<endl;
                                   temp<<sex<<endl;
                                   temp<<newoccupation<<endl;
                                   temp<<salary<<endl;
                                   temp<<tax<<endl;
                               }
     
                               else
                               {   
                                   temp<<id<<endl;
                                   temp<<name<<endl;
                                   temp<<age<<endl;
                                   temp<<sex<<endl;
                                   temp<<occupation<<endl;
                                   temp<<salary<<endl;
                                   temp<<tax<<endl;
                               }
                           }

                            record.close();
                            temp.close();

                           remove("record.txt");
                           rename("temp.txt","record.txt");
                           
                           system("cls");

                           cout<<"Your new record has been successfully saved!\n\nDo you want to edit more records(y/n)? ";
                            cin>>ch;

                            if(ch=='y' || ch=='Y')
                            goto editmenu;
                            else
                            {
                                system("cls");
                                goto mainmenu;   
                            }

                           }  


                    case 4:{system("cls");
                                        /*case 2 is for the editing of the age*/
                           record.open("record.txt", ios::in); temp.open("temp.txt", ios::out);

                           int newsalary;
                           cout<<"Enter the new salary: ";
                           cin>>newsalary;
                 
                           while(!record.eof())
                           {
                               record>>id;
                               char buf[1];
                               record.getline(buf,1);
                               record.getline(name,30);
                               record>>age;
                               record>>sex;
                               record>>occupation;
                               record>>salary;
                               record>>tax;

                               if(id=uid)
                               {   
                                   temp<<id<<endl;
                                   temp<<name<<endl;
                                   temp<<age<<endl;
                                   temp<<sex<<endl;
                                   temp<<occupation<<endl;
                                   temp<<newsalary<<endl;
                                   
                                   if(age<60)
                                   {
                                    c.getcitizen(newsalary);
                                    temp<<c.taxcal()<<endl;
                                   }
                                   else
                                    if(60<=age && age<80)
                                    {
                                        c.getcitizen(newsalary);
                                        temp<<c.taxcal()<<endl;
                                    }
                                    else
                                    {
                                        c.getcitizen(newsalary);
                                        temp<<c.taxcal()<<endl;
                                    }
                               }
     
                               else
                               {   
                                   temp<<id<<endl;
                                   temp<<name<<endl;
                                   temp<<age<<endl;
                                   temp<<sex<<endl;
                                   temp<<occupation<<endl;
                                   temp<<salary<<endl;
                                   temp<<tax<<endl;
                               }
                           }

                            record.close();
                            temp.close();

                            remove("record.txt");
                            rename("temp.txt","record.txt");
                           
                            system("cls");

                           cout<<"Your new record has been successfully saved!\n\nDo you want to edit more records(y/n)? ";
                            cin>>ch;

                            if(ch=='y' || ch=='Y')
                            goto editmenu;
                            else
                            {
                                system("cls");
                                goto mainmenu;   
                            }

                           }


                    case 5:  system("cls");
                             goto categorymenu;


                    case 6: system("cls");
                            goto mainmenu;


                    case 7: system("cls");
                            cout<<"Thank you for your time. Program is exiting now.";
                            exit(0);

                    default: system("cls");
                             cout<<"Wrong choice! Please try again.";
                             goto editmenu;                      
                
                 }
                 


        case 5: deletedata:

                 system("cls");

                 cout<<"Enter the unique id of the person whose record you want to delete: ";
                 cin>>uid;

                 record.open("record.txt", ios::in); temp.open("temp.txt", ios::out);
                 
                 while(!record.eof())
                {
                    record>>id;
                    char buf[1];
                    record.getline(buf,1);
                    record.getline(name,30);
                    record>>age;
                    record>>sex;
                    record>>occupation;
                    record>>salary;
                    record>>tax;

                    if(id!=uid)
                    {   
                        temp<<id<<endl;
                        temp<<name<<endl;
                        temp<<age<<endl;
                        temp<<sex<<endl;
                        temp<<occupation<<endl;
                        temp<<salary<<endl;
                        temp<<tax<<endl;
                    }
				}

                record.close();
                temp.close();

                remove("record.txt");
                rename("temp.txt","record.txt");

                system("cls");

                cout<<"\nRecord has been deleted!\n\nWant to delete more(y/n)? ";
                cin>>ch;
                 
                 if(ch=='y' || ch=='Y')
                    goto deletedata;
                 else
                    goto mainmenu;
                    
                
        case 6: system("cls");
        		int c;
        		cout<<"\nAn income tax is a tax imposed on individuals or entities (taxpayers) that varies with the"<<endl; 
					cout<<"income or profits (taxable income) of the taxpayer. Details vary widely by jurisdiction."<<endl; 
					cout<<"Many jurisdictions refer to income tax on business entities as companies tax or corporate tax."<<endl; 
					cout<<"Partnerships generally are not taxed; rather, the partners are taxed on their share of partnership items."<<endl;
					cout<<"Tax may be imposed by both a country and subdivisions. Most jurisdictions exempt locally organized "<<endl;
					cout<<"charitable organizations from tax."<<endl<<endl;
					p:
					cout<<"Want to know more ?\n"<<endl<<"(Y/N)"<<endl;
					c=getch();
					if(c == 'y')
					{
						ShellExecute(NULL, "open", "https://en.wikipedia.org/wiki/Income_tax",NULL, NULL, SW_SHOWNORMAL);
						return 0;
					}
					else
					goto mainmenu;

                
        case 7: system("cls");
                cout<<"Thank you for your time. Program is exiting now.";
                exit(0);


		        default: system("cls");
		                 cout<<"Wrong choice.\n\n\nWhat do you want to do?\n\n1.Try again\n2.Exit";
		                 int defaultchoice;
		                 cin>>defaultchoice;
		
		                 switch(defaultchoice)
		                 {
		                    case 1: system("cls");
		                            goto mainmenu;
		
		                    
		                    case 2: system("cls");
		                            cout<<"Thank you for your time. Program is exiting now.";
		                            exit(0);
		
		
		                    default: system("cls");
		                            cout<<"Wrong choice again!\n\nNumber of tries exceeded. Program is closing now.";
		                            exit(0); 
		                 }
	}
}
