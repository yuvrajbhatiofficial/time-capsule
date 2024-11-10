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
    cout << "Time capsule Created!\n";
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
            cout << "time Capsule Delivered:" << capsule.message << "\n";
            delivered = true;
        }
        else
        {
            // if the time of capsule is not reached yet
            cout << "Time Capsule scheduled for Later.\n";
        }
    }
    if (!delivered)
    {
        //if no message to deliverd , notify the user 
        cout<<"No capsule to deliver at this time.\n";
    }
    file.close();
}

//------------------------------------------------------------------------------------------------------------
//main return function

int main()
{
    int choice;
    cout << "welcome to Time capsule program " << endl;
    cout << "1: create a capsule (push message)" << endl;
    cout << "2: check for message " << endl;
    cout << " Enter your Choice (1 or 2): " << endl;
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        TimeCapsule capsule;
        cout << "Enter your message: ";
        getline(cin, capsule.message);
        cout << "Enter the delivery year: ";
        cin >> capsule.year;
        cout << "Enter the delivery month (1-12): ";
        cin >> capsule.month;
        cout << "Enter the delivery day(1-31): ";
        cin >> capsule.day;
        cout << "Enter the delivery hour: ";
        cin >> capsule.hour;
        cout << "Enter the delivery min: ";
        cin >> capsule.min;

        saveTimeCapsule(capsule);
    }
    else if (choice == 2)
    {
        checkTimeCapsules();
    }
    else{
        cout<<"Invalid Choice.\n";
    }

    return 0;
}
//------------------------------------------------------------------------------------------------------------