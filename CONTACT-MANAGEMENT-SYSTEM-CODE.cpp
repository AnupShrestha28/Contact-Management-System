//Contact Management System
#include<fstream>
#include<windows.h>
#include<string.h>
#include<iostream>
#include<conio.h>

using namespace std;


//START OF CLASS

class contact
{
	private:
		unsigned long long int pno;
    	char name[30],lname[10],email[20],address[50];
	public:
		//FUNCTION FOR CREATING A CONTACT
    	void create_contact()    
		{
			fstream fp;
			fp.open("contacts.txt");
			contact c1;
			cout<<"First Name: "; 
			cin.ignore();
			cin>>name;
			cout<<"Last Name: ";
			cin.ignore();
			cin>>lname;
			strcat(name," ");
			strcat(name,lname);
			strupr(name);
			phone:
			cout<<"Phone: ";
			cin.ignore();
			cin>>pno;
			if(pno<=9800000000 || pno>=9899999999)
            	{
            		cout<<"\n<Phone number should start from '98' and must have 10 digit>\nEnter again ";
            		goto phone;
            	}
      		
	        while(fp.read((char*)&c1,sizeof(c1)))
			{
				while(c1.getPhone()==pno)
				{	
					cout<<"\n\t<Already registered!>\nEnter another num: ";
					cin>>pno;
				}
				
			}
			cout<<"Address: ";
			cin.ignore();
			cin>>address;
			strupr(address);
			cout<<"Email address: ";
			cin.ignore();
			cin>>email;
			strupr(email);
			cout<<"\n";
			
			//END OF CREATING FUNCTION
			
	}
	
	void setName()
	{
		cout<<"First Name: "; 
			cin.ignore();
			cin>>name;
			cout<<"Last Name: ";
			cin.ignore();
			cin>>lname;
			strcat(name," ");
			strcat(name,lname);
			strupr(name);
	}
	
	void setAddress()
	{
			cout<<"Address: ";
			cin.ignore();
			cin>>address;
			strupr(address);
	}
	
	void setEmail()
	{
			cout<<"Email address: ";
			cin.ignore();
			cin>>email;
			strupr(email);
		
	}
	
	void setNumber()
	{
			fstream fp;
			fp.open("contacts.txt");
			contact c1;
			phone:
			cout<<"Phone: ";
			cin.ignore();
			cin>>pno;
			if(pno<=9800000000 || pno>=9899999999)
            	{
            		cout<<"\n<Phone number should start from '98' and must have 10 digit>\nEnter again ";
            		goto phone;
            	}
      		
	        while(fp.read((char*)&c1,sizeof(c1)))
			{
				while(c1.getPhone()==pno)
				{	
					cout<<"\n\t<Already registered!>\nEnter another num: ";
					cin>>pno;
				}
				
			}
			fp.close();
	}
	
	void show_contact() 
	{
		cout<<endl<<"Name: "<<name; 
		cout<<endl<<"Phone : "<<pno;
		cout<<endl<<"Address: "<<address;
		cout<<endl<<"Email Address : "<<email;
	}
	unsigned long long int getPhone()
	{
		return pno;
	}

	char* getName()
	{
		return name;
	}


	char* getAddress()
	{
		return address;
	}

	char* getEmail()
	{
		return email;
	}
};
contact c1,c;
fstream fp;

//FUNCTION FOR ADDING A CONTACT
void addcontact() 
{
	system("cls");
	int choice=0;
	cout<<"\n\t\t==============================\n\t\t\tAdding Contacts\n\t\t==============================\n"; 
	cout<<"\n================================================================="<<endl;
	fp.open("contacts.txt",ios::out|ios::app);
	c1.create_contact();
	fp.write((char*)&c1,sizeof(c1));
	
	fp.close();
    cout<<"Contact Saved Successfully"<<endl;
    flag1:
        cout<<"\nAdd another? \n";
        cout<<"[1]Yes \t[2]No:  ";
        cin>>choice;
        cout<<"\n";
		if(choice!=1 && choice!=2)
        {
            cout<<"\n<<<Invalid input>>>";
		}
		else if(choice==1)
		{
			addcontact();
		}
		else
		{
			return;
		}
    
    //END OF ADDING FUNCTION

}

//FUNCTION FOR DIAPLAYING ALL SAVING CONTACTS
void allcontacts()
{
	bool found = false;
    system("cls");
    cout<<"\n\t\t==============================\n\t\t\tAvailable Contacts\n\t\t==============================\n"; 
	cout<<"\n=================================================================\n"<<endl;
    fp.open("contacts.txt",ios::in);
    while(fp.read((char*)&c1,sizeof(c1)))
	{
		found= true;
		c1.show_contact();
		cout<<endl<<"=================================================\n"<<endl;
	}
	if(found==false)
	cout<<"\n<NO contacts found...>"<<endl;
	fp.close();
	
	//END OF DISPLAY FUNCTION
}

//FUNCTION FOR SEARCHING A CONTACT
void searchcontact() 
{
	system("cls");
    int counter=0,choice=0,key;
	do{
		cout<<"\n\t\t==============================\n\t\t\tSearching Contact\n\t\t==============================\n"; 
		cout<<"\n================================================================="<<endl;
    	char user[30],user1[10],addr[20];
    	fp.open("contacts.txt",ios::in);
		cout<<"[1] Search by Name"<<endl;
		cout<<"[2] Search by Address"<<endl;
		cout<<"Choose: ";
		cin>>key;
		switch(key)
		{
			case 1:
				 cout<<"Enter Full Name :";
				cin>>user>>user1;
				strcat(user," ");
				strcat(user,user1);
				strupr(user);
				while(fp.read((char*)&c1,sizeof(c1)))
				{
					if(strcmp(c1.getName(),user)==0)
					{
						c1.show_contact();
						counter++;
					}
				}
				key=3;
				break;
				
			case 2:
				cout<<"Enter the address to be searched :";
				cin>>addr;
				strupr(addr);
				while(fp.read((char*)&c1,sizeof(c1)))
				{
					if(strcmp(c1.getAddress(),addr)==0)
					{
						c1.show_contact();
						counter++;
					}
				}
				key=3;
				break;
				
			default:
				break;
		}
	}while(key!=3);
	fp.close();
	if(counter==0)
      	cout<<" Contact Not Found "<<endl;
   	else
       	cout<<"\nContact Found Successfully"<<endl;
    	fp.close();
    	flag2:
            cout<<"\n\n..::Try again?\n[1] Yes\t\t[2] No:  ";
            cin>>choice;
			if(choice!=1 && choice!=2)
            {
            	cout<<"\n<<<Invalid input>>>";
			}
			else if(choice==1)
			{
				searchcontact();
			}
			else
			{
				return;
			}
  
    
    //END OF SEARCHING FUNCTION
}

void chooseUpdate(contact& c2)
{
	system("cls");
	int choice;
	again:
	c1.show_contact();
	cout<<endl<<"What do you want to update?"<<endl;
	cout<<"[1] Name"<<endl;
	cout<<"[2] Email"<<endl;
	cout<<"[3] Address"<<endl;
	cout<<"[4] Phone number"<<endl;
	cout<<"[5] All"<<endl;
	cout<<"Enter your choice:"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
				c2.setName();
				break;
			
		case 2:
				c2.setEmail();
				break;
		
		case 3:
				c2.setAddress();
				break;
			
		case 4:
				c2.setNumber();
				break;
			
		case 5:
				c2.create_contact();
				break;
			
		default:
				goto again;
	}
	
}


//FUNCTION FOR UPDATING CONTACT
void updatecontact()  
{
	system("cls");
	int choice=0;
    bool found = false;
     unsigned long long int phn;
    cout<<"\n\t\t==============================\n\t\t\tEdit Contact\n\t\t==============================\n"; 
	cout<<"\n================================================================="<<endl;
    cout<<"..::Enter the number of contact to edit: "; 
	cin.ignore();
	cin>>phn;
    fp.open("contacts.txt",ios::in|ios::out);
	while(fp.read((char*)&c1,sizeof(c1)))
    {
        if(c1.getPhone()==phn)
        {
            
			chooseUpdate(c1);
            int pos=(-1)*sizeof(c1);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&c1,sizeof(c1));
			found = true;
			cout<<"\n<Contact sucessfully updated>"<<endl;
			break;
        }
    }
    if(found==false)
	cout<<"\nContact Not Found..."<<endl;
    fp.close();
    flag3:
            cout<<"\n\n..::Try again?\n[1] Yes\t\t[2] No:  ";
            cin>>choice;
			if(choice!=1 && choice!=2)
            {
            	cout<<"\n<<<Invalid input>>>";
			}
			else if(choice==1)
			{
				updatecontact();
			}
			else
			{
				return;
			}
    
    //END OF UPDATING FUNCTION
}


	
	

//FUNCTION FOR DELETING A CONTACT
void deletecontact() 
{	
	system("cls");
	int counter=0,choice=0;
    unsigned long long int phn;
    cout<<"\n\t\t==============================\n\t\t\tDelete Contact\n\t\t==============================\n"; 
	cout<<"\n================================================================="<<endl;
	cout<<"..::Enter the number of contact to delete:";
	cin.ignore();
	cin>>phn;
    fp.open("contacts.txt",ios::in|ios::out);
	fstream ft;
    ft.open("temp.txt",ios::out);
	fp.seekg(0,ios::beg);
    while(fp.read((char*)&c1,sizeof(c1)))
	{
		if(c1.getPhone()==phn)
		{
			counter++;
		}
		else
		{
			ft.write((char*)&c1,sizeof(c1));
		}
	}
	ft.close();
	fp.close();
	remove("contacts.txt");
	rename("temp.txt","contacts.txt");
	if(counter==0)
	{
		cout<<"Contact not found...."<<endl;
	}
	
	else
	{
		cout<<"\n\tContact Deleted..."<<endl;
		
		//END OF DELETING FUNCTION
	}
	    flag4:
            cout<<"\n\n..::Try again?\n[1] Yes\t\t[2] No:  ";
            cin>>choice;
			if(choice!=1 && choice!=2)
            {
            	cout<<"\n<<<Invalid input>>>";
			}
			else if(choice==1)
			{
				deletecontact();
			}
			else
			{
				return;
			}
}

//FUNCTION FOR DISPLAYING MAINMENU
void mainmenu()
{
	int ch,i=0;
    
	system("cls"); //loading screen
    cout<<"\n\n\n\n\n\n\t\t\t\t\tSYSTEM LOADING \n\t\t\t\t\t";
	for(i=1;i<6;i++)
	{
		Sleep(500);
		cout<<"...";
	}
	cout<<"\n\n\t\t\t\t\t<System Sucessfully Loaded>\n\n";
	cout<<"\t\t\t\t\t<Enter any key to continue>";
	getch();
    system("cls");
    
	flag5:
	system("cls");
    //************Main menu *********************** 
    cout<<"\n\t============================================================\n\t\t\tWELCOME TO CONTACT MANAGEMENT SYSTEM\n\t============================================================\n";
    cout<<"\n\t\t\tMAIN MENU\n\t\t=======================\n\t\t";
	cout<<"[1] Add a new Contact\n\t\t";
	cout<<"[2] List all Contacts\n\t\t";
	cout<<"[3] Search for contact\n\t\t";
	cout<<"[4] Edit a Contact\n\t\t";
	cout<<"[5] Delete a Contact\n\t\t";
	cout<<"[0] Exit\n\t\t========================\n\t\t";
	
	cout<<"\n\n\t\tEnter Your Choice: ";
	cin>>ch;
	if(ch<0 && ch >5)
    {
    	cout<<"\n\n**Invalid input**";
	}
    switch(ch)
    {
    	case 0:
        	exit:
        	cout<<"\n\n\t\tEXit for sure ?\n\t\t[1]Yes [2]No: ";
        	cin>>ch;
        	if(ch==1)
        	{
        		cout<<"\n\n\n\t\t\t<<<<<<<<<< Thank you for using the system >>>>>>>>>>>>>>>\n\n\n\n";
        		cout<<"\n\n\n\n\n\n\t\t\t\t\tSystem Closing \n\t\t\t\t\t";
				for( i=1;i<6;i++)
				{
					Sleep(500);
					cout<<"...";
				}
				cout<<"\n\t\t\t\t\t<System Sucessfully closed>";
				getch();
				exit (0);
			}
			else if(ch ==2)
			{
				goto flag5;
			}
			else
			{
				cout<<"\n\t\t<Invalid data provided>";
				goto exit;
			}
		case 1:
			{
				addcontact();
                cout<<"Press enter key to continue...."<<endl;
                cin.get();
                cin.ignore();
               	break;
            }
        case 2:
        	{
        		allcontacts();
            	cout<<"Press enter key to continue...."<<endl;
            	cin.get();
            	cin.ignore();
            	break;
        	}
        case 3:
            {
               	searchcontact();
                cout<<"Press enter key to continue...."<<endl;
            	cin.get();
                cin.ignore();
                break;
            }
        case 4:
            {
                updatecontact();
                cout<<"Press any key to continue...."<<endl;
                cin.get();
                cin.ignore();
                break;
            }
        case 5:
            {
            	deletecontact();
                cout<<"Press any key to continue...."<<endl;
                cin.get();
                cin.ignore();
                break;
            }
        case 6:
			exit (0); 
			default:
                cout<<"\n\n\t\t\t\t\t<Enter valid option>"<<endl;
                cout<<"\n\n\t\t\t\t\tpress Enter key to continue";
				getchar();
                break;
        	}
        	flag6: 
    		cout<<"\n\n\n=============================================================";
    		cout<<"\n\t\t[1]Goto Menu\t [2]Exit :";
    		cin>>ch;
    		if(ch==1)
    		{
    			goto flag5;
			}
			else if(ch==2)
			{
				goto exit;
			}
			else
			{
				cout<<"\n\t\t<Invalid data provided>";
				goto exit;
			}
}
int main()
{
	mainmenu();
    return 0;
}


//END OF PROGRAM
