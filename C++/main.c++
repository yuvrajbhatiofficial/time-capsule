#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>   // For timing functionalities if needed
#include <thread>

using namespace std;

//------------------------------------------------------------------------------------------------------------
// first we have to create one structure and three functions

// lets create struct to use our parameteres
struct TimeCapsule
{
    string message;
    int year, month, day, hour, min;
};

//------------------------------------------------------------------------------------------------------------


// now we create function to get current date and time so in future it compare with struct parameters
tm getCurrenDateTime()
{
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    return *ltm;
} // helper function is done now i am going to main function to create menu and main loop


//------------------------------------------------------------------------------------------------------------


// Function : save time capsule data to a file
void saveTimeCapsule(const TimeCapsule &capsule)
{
    ofstream file("time_capsule_data.txt", ios::app);
    file << capsule.year << " " << capsule.month << " " << capsule.day << " "; // store date of message
    file << capsule.hour << " " << capsule.min << " " << capsule.message << "\n";
    file.close();
    cout << "***********************"<<endl;
    cout << "* Time capsule Created! *"<<endl;
    cout << "***********************"<<endl;
}

//------------------------------------------------------------------------------------------------------------


// Function: load and check timew capsule for delivery
void checkTimeCapsules()
{
    ifstream file("time_capsule_data.txt");
    string line;
    TimeCapsule capsule;
    bool delivered = false; // flag

    while (getline(file, line))
    {

        // read each string from file
        istringstream iss(line);
        iss >> capsule.year >> capsule.month >> capsule.day >> capsule.hour >> capsule.min;
        getline(iss >> ws, capsule.message);

        // get current time and date
        tm now = getCurrenDateTime();

        // check conditions matches for delivery
        if ((capsule.year < (now.tm_year + 1900)) ||
            (capsule.year == (now.tm_year + 1900) && capsule.month < (now.tm_mon + 1)) ||
            (capsule.year == (now.tm_year + 1900) && capsule.month == (now.tm_mon + 1) && capsule.day < now.tm_mday) ||
            (capsule.year == (now.tm_year + 1900) && capsule.month == (now.tm_mon + 1) && capsule.day == now.tm_mday && capsule.hour < now.tm_hour) ||
            (capsule.year == (now.tm_year + 1900) && capsule.month == (now.tm_mon + 1) && capsule.day == now.tm_mday && capsule.hour == now.tm_hour && capsule.min <= now.tm_min))
        {
            cout << "time Capsule Delivered: ------>" << capsule.message << "\n";
            delivered = true;
        }
        else
        {
            // if the time of capsule is not reached yet
            cout << "-----------------------------------"<<endl;
            cout << "|Time Capsule scheduled for Later.|"<<endl;
            cout << "-----------------------------------"<<endl;
            
        }
    }
    if (!delivered)
    {
        //if no message to deliverd , notify the user 
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"|No capsule to deliver at this time.|"<<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
    file.close();
}

//------------------------------------------------------------------------------------------------------------
//main return function

int main()
{
    int choice;
    cout<<""<<endl;
    cout << "*----*----*----* WELCOME TO TIME CAPSULE PROGRAM *----*----*----* " << endl;

    do{
    cout << "*-----------------------------------*"<<endl;
    cout << "|               MENU                |"<<endl;
    cout << "|-----------------------------------|"<<endl;
    cout << "|1: create a capsule (push message) |" << endl;
    cout << "|-----------------------------------|"<<endl;
    cout << "|2: check for message               |" << endl;
    cout << "|-----------------------------------|"<<endl;
    cout << "|3: Exit                            |"<< endl;
    cout << "|___________________________________|"<<endl;

    cout << " Enter your Choice: " << endl;
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        TimeCapsule capsule;
        cout << "|---------------------|"<<endl;
        cout << "| Enter your message: |"<<endl;
        cout << "|---------------------|"<<endl;
        getline(cin, capsule.message);
        
        //year:->
        while(true){
            cout << "|--------------------------|"<<endl;
            cout << "| Enter the delivery year: | "<<endl;
            cout << "|--------------------------|"<<endl;
              cin >> capsule.year;
            if(capsule.year >= 0 && capsule.year <= 9999){
                break;
            }
            else{
                cout<<"Invalid Input Try Again !"<<endl;
            }
        }
        
        //month:->
        while(true){
            cout << "|----------------------------------|"<<endl;
            cout << "| Enter the delivery month (1-12): |"<<endl;
            cout << "|----------------------------------|"<<endl;
            cin >> capsule.month;
            if(capsule.month >= 1 && capsule.month <= 12){
                break;
            }
            else{
                cout<<"Invalid Input Try Again !"<<endl;
            }
        }

        //day:->

         while(true){
            cout << "|-------------------------------|"<<endl;
            cout << "| Enter the delivery day(1-31): |"<<endl;
            cout << "|-------------------------------|"<<endl;
             cin >> capsule.day;
            if(capsule.day >= 1 && capsule.day <= 31){
                break;
            }
            else{
                cout<<"Invalid Input Try Again !"<<endl;
            }
        }

        //Hour:->

         while(true){
            cout << "|--------------------------|"<<endl;
            cout << "| Enter the delivery hour: |"<<endl;
            cout << "|--------------------------|"<<endl;
             cin >> capsule.hour;
            if(capsule.hour >= 0 && capsule.hour <= 23){
                break;
            }
            else{
                cout<<"Invalid Input Try Again !"<<endl;
            }
        }
        
        //minute:->

         while(true){
            cout << "|-------------------------|"<<endl;
            cout << "| Enter the delivery min: |"<<endl;
            cout << "|-------------------------|"<<endl;
            cin >> capsule.min;
            if(capsule.min >= 0 && capsule.min <= 59){
                break;
            }
            else{
                cout<<"Invalid Input Try Again !"<<endl;
            }
        }
    
    
       
        
        

        saveTimeCapsule(capsule);
    }
    else if (choice == 2)
    {
        checkTimeCapsules();
    }
    else if (choice != 3){
         cout << "***********************"<<endl;
         cout << "*  Invalid Choice.  ⚠️  *"<<endl;
         cout << "***********************"<<endl;
    }

    }while (choice != 3);
    cout << "******************************"<<endl;
    cout << "* Exiting program. Goodbye!! *"<<endl;
    cout << "******************************"<<endl;

    return 0;
}
//------------------------------------------------------------------------------------------------------------