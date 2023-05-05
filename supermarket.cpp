#include<iostream>
#include<fstream>

using namespace std;

class shopping 
{
	
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void adminstrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
			
};

void shopping::menu()
{
	m:
	int choice;
	string email;
	string email1;
	string password1;
	string password;
	int login;
	
	cout<<"\t\t\t___________________________\n";
	cout<<"\t\t\t                           \n";
	cout<<"\t\t\t--WELCOME TO MAIN MENU-----\n";
	cout<<"\t\t\t___________________________\n";
	cout<<"\t\t 1: Adminstrator\n";
	cout<<"\t\t 2: Buyer        \n";
	cout<<"\t\t 1: Exit         \n";
	
//	cout<< "pls select: 1) for sign in and 2) for sign up";
//	cin>>login;
//	if (login==1){
//		cout<<"Enter your email\n";
//		cin>>email;
//		cout << "Enter your password\n";
//		cin>>password;
//	}
	
			cout<< "pls select: 1) for sign in and 2) for sign up";
        	cin>>login;
        	if(login==2){
        		cout<<"Enter your email";
        		cin>>email1;
        		cout<<"Enter your password\n";
        		cin>>password1;
        		cout<<"Now choose 1. for sign in \n";
        		cin>>login;
			}
	
	if (login==1){
		cout<<"Enter your email\n";
		cin>>email;
		cout << "Enter your password\n";
		cin>>password;
	}
	
	cout<<"\t\t Please select!";
	cin>> choice;
	
	switch(choice)
	{
		case 1:
			{
			
//			cout<<"Please login\n";
//			cout<<"Enter email\n";
//			cin>>email;
//			cout<<"Enter Password\n";
//			cin>>password;
			
			if(email==email1 && password== password1)
			{
				adminstrator();
			}
			else{
				cout<<"invalid Email or password\n";
			}
			break;
		}
			case 2:
				{
					buyer();
				}
			
			case 3:
			{
				exit(0);
				}	
			
			default	:
				{
					cout<< "select from given choices\n";
				}
	}
	goto m;
	
}

void shopping :: adminstrator()
{
	m:
	int choices;
	cout<<"Administrator menu\n";
	
	cout<<"\n\n 1. Add the product\n\n";
	cout<<"\n\n 2. Modify the prodduct\n\n";
	cout<<"\n\n 3. Delete the prodduct\n\n";
	cout<<"\n\n 4. Back to main menu\n\n";
	
	cout<<"\n Enter your choice\n\n";
	cin>>choices;
	
	switch(choices)
	{
		case 1:
			
				add();
				break;
				
		case 2:
			edit();
			break;
		
		case 3:
			rem();
			break;
			
		default :
			cout<<"\nInter valid option\n";
	}
	goto m;
}


void shopping::buyer()
{
	m:
	 int choice;
	 cout<<" BUYER\n\n\n";
	 
	 cout<< "1. Buy Product\n";
	 cout <<"2. Go Back\n";
	 cout <<"Enter your choise\n";
	 cin>>choice;
	 
	 switch(choice)
	 {
	 	case 1:
	 	receipt();
	 	break;
	 	
	 	case 2:
	 		menu();
	 		
	 	default :
		 cout<<"Enter correct choice\n";	
	 }
	 goto m;
}

void shopping :: add()
{
	m:
	fstream data;
	int c;
	int choicel;
	float p;
	float d;
	int token=0;
	string n;
	
	cout<<"Add new product\n\n";
	cout << "Product code of Product";
	cin>>pcode;
	cout<<"PRoduct name\n";
	cin>>pname;
	cout<<"Price of the project\n";
	cin>>price;
	cout<<"Discount on product\n";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<dis<<"\n";
		data.close();
		
		
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if( c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
	
	if(token==1)
	goto m;
	else{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<dis<<"\n";
		data.close();
		
	}
	
	cout<<"Record inserted\n";
}

void shopping ::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\nModify the record\n";
	cout<<"\nProduct Code:";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		cout<< "File does not exist\n";
	}
	else{
		
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"Product new code\n";
				cin>>c;
				cout<<"Name of the product\n";
				cin>>n;
				cout<<"Price\n";
				cin>>p;
				cout<<"Discount\n";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"REcord edited\n";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n Record not foundd sorry!\n";
		}
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\nDelete Product\n";
	cout<<"\n Product code\n";
	cin>>pkey;
	data.open("database.txt",ios_base()::in);
	
	if(!data)
	{
		cout<<"file does not exist";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			
			if(pcode==pkey)
			{
				cout<<"\n Product deleted successfully\n";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("databse.txt");
		rename("database.txt","database.txt");
		
		if(token==0)
		{
			cout<<"Record can't be found\n";
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"ProNO.\t\tName\t\tPrice\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping::receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"Reciept\n";
	data.open("database.txt",ios::in);
	
	if(!data){
		cout<<"\n\n Empty database\n";
	}
	else{
		data.close();
		
		list();
		cout<<"\n______________________________\n";
		cout<<"\nPlease place the order        \n";
		cout<<"\n______________________________\n";
		
		do{
			m:
			cout<<"ENter the PRoduct code\n";
			cin>>arrc[c];
			cout<<"\nEnter the product quantity\n";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate Product code... Please try again \n";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes then press 'y' elsw 'no' \n";
			cin>>choice;
		}while(choice=="y");
		
		cout<<"\t\t\t______________RECIEPT______________\n";
		cout<<"\nProduct No.\t\t Product Name\t\t Prodduct quantity\tPrice\tAmount\tMount with discount\n";
		
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<"\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
					
				}
				data>>pcode>>pname>>price>>dis;
			}
		}
		data.close();
		
		
	}	
	cout<<"\n Total AMount:"<<total;
}

int main()
{
	shopping s;
	s.menu();
}
