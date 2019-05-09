#include<iostream>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<fstream>
#include <string>

using namespace std;
int total_no_slots = 48;
int per_hr_fare = 5;
float total_fare = 0;
int customers;
int plates = {};
int no_plates = {};
string
command, //to choose what to do each time
name, password, //the ones that are found in the file
inName, inPassword, //the ones you are going to input from keyboard
registerName, registerPassword; //also what you're going to input
int add_parking;
int hr_rate;

struct First {
	string user;
	struct {
		char username[10];
		char password[10];
	}signup;
	struct {
		char username2[10];
		char password2[10];
	}login;
	
};
	void add_opt() {
		ofstream g("registration_opt.txt"); //ofstream is the one for getting data from the file, 
			//and the file does not even have to exist. If it's ofstream, it'll take care of it for you.
			//but be warned that if there is a file called "registration.txt" in the name folder as the
			//.exe file, the contents will be deleted
		if (!g.is_open()) //if it's not open, then there is no such file with the given name inside
		//the folder (that is, in the folder where the .exe file is going to be)
		{
			cout << "could not open file\n"; //just so that you know why it won't work if it doesn't
			
		}
		cout << "\n\n\n" //3 newlines
			<< "New Username: ";
		getline(cin, registerName); //input from keyboard will go into registerName
		cout << "New Password: ";
		getline(cin, registerPassword); //input from keyboard will go into registerPassword
		g << registerName; //this basically says "put whatever's to the right (registerName) into
		//g ("registration.txt")".
		g << '\n'; //and now there will be a new line
		g << registerPassword; //and now the password
		//all placed safely in the file that g opened
		g.close(); //always make sure you close the file, or else you might end up with some nasty
		//stuff in the memory
		
	};
	bool login_opt()
	{
		bool check = false;
		
		
		ifstream f("registration_opt.txt"); //ifstream is the one for getting data from the file, and
			//let us assume you've already created a file called "registration.txt"
		if (!f.is_open()) //if it's not open, then there is no such file with the given name inside
		//the folder (that is, in the folder where the .exe file is going to be)
		{
			cout << "could not open file\n"; 
			//just so that you know why it won't work if it doesn't
			return 0;
		}
		getline(f, name, '\n'); //reads the user name from file f (which is using "registration.txt")
		getline(f, password, '\n'); //reads the password from file f (which is using "registration.txt")
		//also, if you tell the file to get you that text up until '\n', that's when you know it reads
		//the whole line at most, and won't go any further
		//and that is done by the 3rd parameter
		f.close(); //you don't need it open now, since you have the name and password from the file
		cout << "\n\n\n\n\n"; //give it 5 newlines
		//login
		while (1)
		{
			//you are going to input the name and password here
			cout << "\n\n\n"
				<< "Enter Username: ";
			getline(cin, inName);
			cout << "Enter Password: ";
			getline(cin, inPassword);
			//or this, if you are working with C strings (second version of declaration)
			//cin.get(inName, 31);
			//cin.get();
			//cin.get(inPassword, 31);
			//cin.get();
			//and the "cin.get()" after each input line is necessary, or else[...]
			//no idea what's happening inside istream, but it's mandatory if you don't want your
			//input to get stuck or worse
			if (inName == name && inPassword == password)
			{
				cout << "Login Successful\n" //the '\n' is a character, so that's why I can add it 
				//and it will automatically output a newline in console, alongside the string
					<< "Welcome, "
					<< inName;
				check = true;
				break; //just exit the while loop if you've entered the valid account
			}
			cout << "incorrect name or password\n"; //if you haven't entered the valid account,
			//then the while loop is not done yet. So that's why this output is without condition
		}
		return check;	//now do something about the account
	};
	
	
		
	
	void add_park()
	{
		int lot;
		float hr_rate;
		cout << "Total No of Parking Slots avaialble " << total_no_slots << endl;
		cout << "Press 1 to add 1 lot" << endl;
		cin >> lot;
		cout << "Enter it's hourly rate";
		cin >> hr_rate;
		total_no_slots++;
		cout << "For Slot" << total_no_slots - 1 << "Fare is" << hr_rate << endl;
		add_parking++;
	};
	void del_park()
	{
		int no;
		cout << "Enter PArking lot which you want to delete";
		cin >> no;
		if (no < total_no_slots)
		{
			total_no_slots = total_no_slots - 1;
			cout << "Total No of Slots are" << total_no_slots << endl;
		}
		else
		{
			cout << "Error Doesn't exist";
		}
	};
	void del_opt()
	{
		char n;
		system("CLS");
		cout << "\n\n\t\tEnter the operator username you want to get delete : ";
		cin >> n;
		ifstream inFile;
		inFile.open("registration_opt.txt", ios::binary);
		ofstream outFile;
		outFile.open("temp.dat", ios::out | ios::binary);
		
		cout << "\n\n\t\t Parking Record Deleted";

		inFile.close();
		outFile.close();

		remove("parking3.dat");
		rename("temp.dat", "registration_opt.txt");
	};
void admin() {
	
	string opr="admin";
	int no;
	
	if (opr=="admin")
	{
		
			cout << "What you want to do?"<<endl;
			cout << "Press 1. Add operator?"<<endl;
			cout << "Press 2. Delete operator?"<<endl;
			cout << "Press 3. Add Parking slot?"<<endl;
			cout << "Press 4. Delete Parking Slot?"<<endl;
			cout << "Press 5. List all available opt"<<endl;
			cin >> no;
			switch (no)
			{
			case 1:
				add_opt();
			case 2:
				del_opt();
			case 3:
				add_park();
			case 4:
				del_park();
			case 5:
				cout << "Total No of parking slots " << total_no_slots << endl;
				cout << "Per hour rate " << per_hr_fare << endl;
				cout << "No of parking spaces " << total_no_slots - customers << endl;
			default:
				cout << "You have enterened incorrect command";

			}
	}
	else
	{
		cout << "You have enterend invlid name of admin";
	}
};
void revenue()
{
	cout << "Total fare is " << total_fare << endl;
};
char location_of_car(int plate) {
	const char* location;
	location = "Unknown";

	return *location;
};
void opt_con()
{
	bool result;
	int in;
	result = login_opt();
	if (result == true)
	{
		cout << "Press. 1 For Total No. of Parking slots"<<endl;
		cout << "Press. 2 For Revenue of Parking parking lot"<<endl;
		cout << "Enter plate No of car to know where it is located"<<endl;
		cin >> in;
		switch (in)
		{
		case 1:

			cout << "Tota no of Parking slots are";
			cout << total_no_slots;


		case 2:
			revenue();
		default:
			cout<<location_of_car(in);

		}

		
	}

};

void customer()
{
	bool result;

	
	int park, in[5];
	float hrs;
	cout << "Enter five digit unique car plate no.";
	for (int i = 0; i < 5; ++i)
	{
		std::cin >> in[i];
		result = true;
	}
	
	if (result == true)
	{
		int in;
		cout << "Press 1. if you want to park";
		cout << "Press 2. Drive away";
		cin >> in;
		if (in == 1)
		{
			cout << "These are avaialbel slots" << total_no_slots << "where you want to park";
			cin >> park;
			total_no_slots = total_no_slots - 1;
		}
		else if (in == 2)
		{
			int slot;
			cout << "Enter slot No";
			cin >> slot;
			if (slot<48 && add_parking == 0)
			{
				
				cout << "Enter no of hours you stayed in parking, i.e. Write 1.15 if it is 1 hr and 15 min";
				cin >> hrs;
				total_fare = per_hr_fare * hrs;
				cout << "Total fare is" << endl << total_fare;
			}
			else if(slot>48 && add_parking!=0) {
				cout << "For Slot" << total_no_slots << "Fare is" << hr_rate << endl;
				cout << "Enter no of hours you stayed in parking, i.e. Write 1.15 if it is 1 hr and 15 min";
				cin >> hrs;
				total_fare = per_hr_fare * hrs;
				cout << "Total fare is" << endl << total_fare;
			}

		}

		
	}
};

int main()
{
	int number;
	cout << "Three control menus are available"<<endl;
	cout << "Press 1. To enter in Admin"<<endl;
	cout << "Press 2. To enter in Opertor"<<endl;
	cout << "Press 3. To enter in Customer"<<endl;
	cin >> number;
	switch (number)
	{
	case 1:
		admin();
	case 2:
		opt_con();
	case 3:
		customer();
	default:
		cout << "You have pressed wrong no";
		break;
	}

}
//cpo
