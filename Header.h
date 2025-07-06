#pragma once
//**************************** <- AirLine System -> ****************************//
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include<windows.h>
#include <conio.h>
using namespace std;
class Airport;
void DisplayPattern(string a)
{
    Sleep(3000);
    system("CLS");
    int ascii = 219;
    char ch = ascii;
    for (int i = 1;i <= 26;i++) cout << ch;
    cout << " " << a << " ";
    for (int i = 1;i <= 26;i++)
        cout << ch;
    cout << endl << endl << endl;
}
class Person
{
    string Name;
    int Age;
    string phoneNumber;
    string email;
    string Username;
    string Password;
    string CNIC;
public:
    Person() { Name = Username = Password = phoneNumber = email = CNIC = ""; Age = 0; }
    Person(string Name, int Age, string phoneNumber, string email, string Username, string Password, string CNIC)
    {
        this->Age = Age;
        this->Name = Name;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->Username = Username;
        this->Password = Password;
        this->CNIC = CNIC;
    }
    //getters for person class
    string GetName() { return Name; }
    int GetAge() { return Age; }
    string GetPassword() { return Password; }
    string GetPhoneNumber() { return phoneNumber; }
    string GetEmail() { return email; }
    string GetCNIC() { return CNIC; }


    //setters for person class
    void setName(string Name) { this->Name = Name; }
    void setUserName(string Username) { this->Username = Username; }
    void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
    void setEmail(string email) { this->email = email; }
    void setCNIC(string CNIC) { this->CNIC = CNIC; }
    void setAge(int a) { Age = a; }

    //Members Functions  
    void DisplayDetails()
    {
        cout << "Name        : " << Name << endl;
        cout << "PhoneNumber : " << phoneNumber << endl;
        cout << "Age         : " << Age << endl;
        cout << "CNIC        : " << CNIC << endl << endl;
    }
    bool addUserAndPasswordToFile(const string& username, const string& password)
    {
        ifstream infile("User_Name_Password.txt");
        string line;

        while (getline(infile, line)) {
            string n, passInFile;
            bool colonInLine = false;
            for (char colon : line) {
                if (colon == ':') {
                    colonInLine = true;
                }
                else if (colonInLine) {
                    passInFile += colon;
                }
                else {
                    n += colon;
                }
            }
            if (n == username) {
                return false; // username already exists in file
            }
        }

        // username not found in file, add to file
        ofstream outfile("User_Name_Password.txt", ios::app);
        if (outfile.is_open()) {
            outfile << username << ":" << password << endl;
            outfile.close();
            return true; // username added to file successfully
        }
        else {
            cout << "Error opening file." << endl;
            return false;
        }
    }
    bool check_Password(string P)      //Checking the password
    {
        if (P.length() != 8) { return false; } //for checking length
        bool UppperCase = false;
        bool LowerCase = false;
        bool SpecialCharacter = false, Digit = false;
        char* PasswordC = new char[8]; //dynamic array is made
        for (int i = 0; i < 8; i++) { PasswordC[i] = P[i]; }
        for (int i = 0; i < 8; i++)
        {
            char c = PasswordC[i];
            if (c >= 'A' && c <= 'Z') { UppperCase = true; }
            else if (c >= 'a' && c <= 'z') { LowerCase = true; }
            else if ((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '}')) { SpecialCharacter = true; }
            if (c >= '0' && c <= '9') { Digit = true; }
        }
        delete[] PasswordC;
        if (!UppperCase || !LowerCase || !SpecialCharacter || !Digit) { return false; }
        return true; //if the password is right
    }
    void setPassword(string& P)
    {
        try
        {
            string Password;
            int a;

            cout << "Enter Password: " << endl;

            while ((a = getch()) != 13)
            { // read each character until Enter is pressed
                if (a == 8)
                { // handle backspace
                    if (Password.length() > 0)
                    {
                        Password.erase(Password.length() - 1);
                        cout << "\b \b";
                    }
                }
                else
                {
                    Password.push_back(a);
                    cout << "*";
                }
            }

            cout << endl;
            if (!check_Password(Password))
            {
                string a = "Password Must Contain 1.Lower Case Wrong, 1.UpperCase , 1.Special Character, 1.Number and 8 character long";
                throw a;
            }
            if (addUserAndPasswordToFile(Username, Password))
                cout << "User Registered successfully" << endl << endl;
            else
            {
                cout << "User Already Exists" << endl;
                return;
            }

            DisplayDetails();
            Sleep(5);

        }
        catch (string& a)
        {
            //cout<<"Unhandled exception caught"<<endl;   
            cout << a << endl;
            setPassword(a);
        }

    }
    void check_Cnic(string& a)
    {
        string b;
        string c = "CNIC should be 13 digits";
        try {
            if (a.length() > 13) { throw a; }
        }
        catch (string c)
        {
            cout << c;
            cout << endl << "Enter valid CNIC :" << endl;
            cin >> b;
            check_Cnic(b);
        }
        return;
    }
    void RegisteryPerson()
    {
        DisplayPattern("  Registration Form  ");
        cout << "1. Enter Name: " << endl;
        cin >> Name;
        while (true)
        {
            try
            {
                cout << "2. Enter Age: " << endl;
                cin >> Age;
                if (Age < 18) { cout << "Age should be greater than 18 to register :" << endl; continue; }
                if (cin.fail()) { cin.clear();cin.ignore(); throw runtime_error("Invalid input. Please enter a number."); }
                break;
            }

            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore();
            }
        }
        cout << "3. Enter phone number: " << endl;
        cin >> phoneNumber;
        while (true)
        {
            try
            {
                cout << "4. Enter CNIC: " << endl;
                cin >> CNIC;
                if (CNIC.length() != 13) { throw runtime_error("Invalid input. Please enter a number."); }
                break;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore();
            }
        }


        cout << "5. Enter User Name: " << endl;
        cin >> Username;
        setPassword(Password);
    }


    bool checkPasswordFile(const string& username, const string& password)
    {
        ifstream infile("User_Name_Password.txt");
        string line;

        while (getline(infile, line))
        {
            string n, passInFile;
            bool colonInLine = false;
            for (char colon : line)
            {
                if (colon == ':')
                {
                    colonInLine = true;
                }
                else if (colonInLine)
                {
                    passInFile += colon;
                }
                else
                {
                    n += colon;
                }
            }
            if (n == username && passInFile == password)
            {
                return true;
            }
        }

        return false;
    }
    bool Login()
    {
        string user, pass;
        DisplayPattern(" Login Form ");
        cout << "Enter the username :" << endl;
        cin >> user;
        cout << "Enter the password :" << endl;
        cin >> pass;
        if (!checkPasswordFile(user, pass))
        {
            cout << "User does't exist!" << endl;
            return 0;
        }
        return 1;
    }
    int reset_password(const string& user, const string& password, const string& newPassword)
    {
        ifstream infile("passwords.txt");
        string line;
        string newLine;
        bool foundUser = false;

        while (getline(infile, line))
        {
            string name, securitycode;
            bool found_colon = false;
            for (char c : line) {
                if (c == ':') {
                    found_colon = true;
                }
                else if (found_colon) {
                    securitycode += c;
                }
                else {
                    name += c;
                }
            }
            if (name == user && securitycode == password)
            {
                // Found the user and password, change the password to newPassword
                newLine += name + ":" + newPassword + "\n";
                cout << "Password reset successful!\n";
                foundUser = true;
            }
            else
            {
                // This is not the user and password, add it to the new file unchanged
                newLine += line + '\n';
            }
        }

        infile.close();

        if (!foundUser) {
            cout << "User not found  password incorrect\n";
            return 0;
        }

        ofstream outfile("passwords.txt");
        outfile << newLine;
        outfile.close();

        return 1;
    }


};


class Passenger :public Person
{
    int Passport;

public:
    Passenger() {}
    Passenger(string Name, int Age, string phoneNumber, string email, string Username, string Password, string CNIC, int passpor) :Person(Name, Age, phoneNumber, email, Username, Password, CNIC)
    {
        Passport = passpor;
    }
    void registerPassenger(string Name, int Age, string phoneNumber, string email, string Username, string Password, string CNIC)
    {
        RegisteryPerson();
    }



};
class Admin :public Person
{
public:
    Admin() {}
    Admin(string Name, int Age, string phoneNumber, string email, string Username, string Password, string CNIC) :Person(Name, Age, phoneNumber, email, Username, Password, CNIC) {}

    int reset_password(const string& user, const string& password, const string& newPassword)
    {
        ifstream infile("passwords.txt");
        string line;
        string newLine;
        bool foundUser = false;

        while (getline(infile, line))
        {
            string name, securitycode;
            bool found_colon = false;
            for (char c : line) {
                if (c == ':') {
                    found_colon = true;
                }
                else if (found_colon) {
                    securitycode += c;
                }
                else {
                    name += c;
                }
            }
            if (name == user && securitycode == password)
            {
                // Found the user and password, change the password to newPassword
                newLine += name + ":" + newPassword + "\n";
                cout << "Password reset successful!\n";
                foundUser = true;
            }
            else
            {
                // This is not the user and password, add it to the new file unchanged
                newLine += line + '\n';
            }
        }

        infile.close();

        if (!foundUser) {
            cout << "User not found  password incorrect\n";
            return 0;
        }

        ofstream outfile("passwords.txt");
        outfile << newLine;
        outfile.close();

        return 1;
    }
};







class Seat {
public:
    int row;
    int col;
    bool is_reserved;
    bool not_available_corona;
    Seat() {}
    Seat(int ro, int co, bool isreserved, bool corona)
    {
        row = ro;
        col = co;
        is_reserved = isreserved;
        not_available_corona = corona;
    }

    void setReservation(bool flag)
    {
        is_reserved = flag;
    }
    bool getReservation() { return is_reserved; }
};

//*************************************AEROPLANE*****************************************************
class Aeroplane
{
private:
    string Aeroplane_N0;
    Seat** seats;
    bool corona_condition;

public:
    const int num_rows = 12;
    const int seats_per_row = 5;
    void setCorona(bool c) { corona_condition = c; }
    Aeroplane() {}
    Aeroplane(string Aeroplane_n0, bool corona_condition_)
    {
        Aeroplane_N0 = Aeroplane_n0;
        seats = new Seat * [num_rows];
        for (int i = 0; i < num_rows; i++)
        {
            seats[i] = new Seat[seats_per_row];
            for (int j = 0; j < seats_per_row; j++)
            {
                seats[i][j].row = i + 1;
                seats[i][j].col = j + 1;
                seats[i][j].is_reserved = false;
                seats[i][j].not_available_corona = 0;
            }
        }
        corona_condition = corona_condition_;

    }
    //copy constructor
    Aeroplane(const Aeroplane& other)
    {
        this->Aeroplane_N0 = other.Aeroplane_N0;
        this->seats = new Seat * [num_rows];
        for (int i = 0; i < num_rows; i++)
        {
            this->seats[i] = new Seat[seats_per_row];
            for (int j = 0; j < seats_per_row; j++)
            {
                this->seats[i][j] = other.seats[i][j];
            }
        }
        this->corona_condition = other.corona_condition;
    }


    string getAirplaneNumber()
    {
        return Aeroplane_N0;
    }

    void show_seating_arrangement()
    {
        int no = 0, e = 0, b = 0;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < seats_per_row; j++)
            {
                Seat& s = seats[i][j];
                if (!corona_condition) {
                    if (s.is_reserved)
                    {
                        cout << "|X| ";
                    }
                    else {
                        if (i < 2)
                        {
                            cout << "|B| ";
                            b++;
                        }
                        else
                        {
                            cout << "|E| ";
                            e++;
                        }
                    }
                }
                else
                {
                    if (no % 2 == 0) {
                        cout << "|.| ";
                    }
                    else if (no % 2 == 1) {
                        if (s.is_reserved) {
                            cout << "|X| ";
                        }
                        else {
                            if (i < 2) {
                                cout << "|B| ";
                                b++;
                            }
                            else {
                                cout << "|E| ";
                                e++;
                            }
                        }
                    }
                    no++;
                }
            }
            cout << endl;
        }
        cout << "Economy seats available: " << e << endl;
        cout << "Business seats available: " << b << endl;
    }

    void reserve_seat(int row, int col)
    {
        // Find the seat with the given row and column numbers
        Seat& seat = seats[row - 1][col - 1];

        // If the seat is not available, print an error message and return
        if (seat.is_reserved)
        {
            cout << "Seat (" << row << ", " << col << ") is already reserved." << endl;
            return;
        }

        // Reserve the seat
        if (corona_condition)
        {
            if (((row % 2) != 0 && (col % 2) != 0) || ((row % 2 == 0) && (col % 2 == 0)))
            {
                cout << "CORONA SOPS SEAT CAN'T BE RESERVED" << endl;
                return;
            }
        }
        seat.setReservation(true);
        show_seating_arrangement();
        cout << "Seat (" << row << ", " << col << ") reserved." << endl;
        cout << "Congragulation " << endl;
    }

    void RESERVESYSTEM()
    {
        int r, c;
        cout << endl;
        cout << " Plane has seating Arrangments as : " << endl;
        show_seating_arrangement();
        cout << endl << endl;
        cout << "Enter row no : " << endl;
        cin >> r;
        cout << "Enter column no : " << endl;
        cin >> c;
        reserve_seat(r, c);
        cout << endl;
    }
};



//*************************************AIRPORT*****************************************************
class Airport
{
private:
    Aeroplane* airplanes[5]; // Array of pointers to airplanes at the airport
    int numAirplanes; // Current number of airplanes at the airport
    string AirportName;
public:
    const int maxAirplanes = 5;
    // Parameterized constructor
    Airport(Aeroplane* A1, Aeroplane* A2, Aeroplane* A3, Aeroplane* A4, Aeroplane* A5, bool C)
    {
        numAirplanes = 0;
        addAirplane(A1);
        addAirplane(A2);
        addAirplane(A3);
        addAirplane(A4);
        addAirplane(A5);
        for (int i = 0; i < numAirplanes; i++)
        {
            airplanes[i]->setCorona(C);
        }
        numAirplanes = 5;
        AirportName = "";
    }

    Airport(string a) { AirportName = a; }
    void setAirportName(string a) { AirportName = a; }
    string getAirportName() { return AirportName; }
    void DisplayAirplanes()
    {
        for (int i = 0;i < numAirplanes;i++)
        {
            cout << "Aeroplane No :" << i + 1 << " " << airplanes[i]->getAirplaneNumber() << endl;
        }
    }
    Airport(string names[], bool C)
    {
        numAirplanes = 5;
        for (int i = 0; i < maxAirplanes; i++)
        {
            airplanes[i] = new Aeroplane(names[i], C);
        }
    }

    void setAirplaneNumber(int a)
    {
        if ((numAirplanes + a) >= 5) { cout << "Maximum Capacity reached " << endl; return; }
        numAirplanes += a;
    }
    // Getter methods for attributes


    int getMaxAirplanes() { return maxAirplanes; }

    // Method to add an airplane to the airport
    void addAirplane(Aeroplane* airplane)
    {
        if (numAirplanes < maxAirplanes)
        {
            airplanes[numAirplanes] = airplane;
            // airplane->setCurrentAirport(this);
            numAirplanes++;
        }
        else
        {
            cout << "Cannot add airplane, maximum capacity reached";
        }
    }

    // Method to remove an airplane from the airport
    void removeAirplane(Aeroplane* airplane)
    {
        bool found = false;
        int index = -1;
        for (int i = 0; i < numAirplanes; i++)
        {
            if (airplanes[i] == airplane)
            {
                found = true;
                index = i;
                break;
            }
        }
        if (found)
        {
            for (int i = index; i < numAirplanes - 1; i++)
            {
                airplanes[i] = airplanes[i + 1];
            }
            airplanes[numAirplanes - 1] = nullptr;
            //airplane->setCurrentAirport(nullptr);
            numAirplanes--;
        }
        else {
            cout << "Airplane not found at this airport";
        }
    }

    // Method to find an airplane at the airport by its airplane number
    Aeroplane* findAirplane(string airplaneNumber)
    {

        for (int i = 0; i < numAirplanes; i++) {
            if (airplanes[i]->getAirplaneNumber() == airplaneNumber) {
                return airplanes[i];
            }
        }
        return nullptr;
    }

    // Method to check if an airplane is at the airport
    bool hasAirplane(Aeroplane* airplane)
    {
        for (int i = 0; i < numAirplanes; i++)
        {
            if (airplanes[i] == airplane)
            {
                return true;
            }
        }
        return false;
    }
};



class City
{
    string name;
    Airport* NorthAirport;
    Airport* SouthAirport;
public:
    City() {}
    City(string n) { name = n; }

    City(string n, Airport* N, Airport* S)
    {
        name = n;
        NorthAirport = N; SouthAirport = S;
    }
    string getCityName() { return name; }
    void DisplayAirport()
    {
        cout << "North Airport " << endl;
        NorthAirport->DisplayAirplanes();
        cout << endl;
        cout << "South Airport " << endl;
        SouthAirport->DisplayAirplanes();
        cout << endl;
    }
};

class Country
{
    City* C[5];
public:
    Country() {}
    Country(City* C1, City* C2, City* C3, City* C4, City* C5)
    {
        C[0] = C1;
        C[1] = C2;
        C[2] = C3;
        C[3] = C4;
        C[4] = C5;
    }
    void DisplayCity()
    {
        DisplayPattern(" Pakistan ");
        for (int i = 0;i < 5;i++)
        {
            cout << "City : " << C[i]->getCityName() << endl << endl;
            C[i]->DisplayAirport();
        }
    }

};
class Flight
{
protected:
    Airport* departureAirport;
    Airport* arrivalAirport;
    Aeroplane* airplane;
    int journeyDuration;
    int distance;
    double ticketPrice;
    int departureTime;
    int landingTime;
    bool reservedflight = 0;
    string departurew;
    string arrive;

public:
    Flight(Airport* departure, Airport* arrival, Aeroplane* plane, int duration, int dist, string d, string ar)
    {
        departureAirport = departure;
        arrivalAirport = arrival;
        airplane = plane;
        journeyDuration = duration;
        distance = dist;
        ticketPrice = 0;
        departureTime = 0;
        landingTime = 0;
        departurew = d;
        arrive = ar;
    }
    string getarrivalTime() { return arrive; }
    string getdepartureTime() { return departurew; }
    virtual void setreservedflight(bool a) { a = reservedflight; }
    virtual bool getreservedflight() { return reservedflight; }
    virtual Airport* getDepartureAirport() { return departureAirport; }
    virtual Airport* getArrivalAirport() { return arrivalAirport; }
    Aeroplane* getAeroplane() { return airplane; }
    virtual int getJourneyDuration() { return journeyDuration; }
    virtual int getDistance() { return distance; }
    virtual double getTicketPrice() { return ticketPrice; }
    virtual int getDepartureTime() { return departureTime; }
    virtual int getLandingTime() { return landingTime; }
    virtual void setDepartureTime(int time) { departureTime = time; }
    virtual void setLandingTime(int time) { landingTime = time; }
    virtual void fly() = 0;  // Pure virtual function

    virtual void deductPenality()
    {
        cout << "25% money is deducted from your account : " << endl;
        reservedflight = 0;

    }
    virtual void changeAirplaneLocation()
    {
        departureAirport->removeAirplane(airplane);
        arrivalAirport->addAirplane(airplane);
    }
};

class LocalFlight : public Flight
{
public:
    LocalFlight(Airport* departure, Airport* arrival, Aeroplane* plane, double duration, int dist, string DepartureTime, string arrivalTime) : Flight(departure, arrival, plane, duration, dist, DepartureTime, arrivalTime)
    {
        ticketPrice = 10000 * duration;
    }
    Aeroplane* getAeroplane() { return airplane; }
    string DepartureAirportName() { return departureAirport->getAirportName(); }
    string ArrivalAirportName() { return arrivalAirport->getAirportName(); }
    virtual void fly() override
    {
        // Perform actions specific to a local flight
    }

    virtual void setreservedflight(bool a) { a = reservedflight; }
    virtual bool getreservedflight() { return reservedflight; }
    virtual double calculateFare()
    {
        ticketPrice = 10000 * journeyDuration;
        return ticketPrice;
    }
    virtual double getTax()
    {
        return static_cast<double>(calculateFare()) * (5.0 / 100);
    }
    virtual double deductTax()
    {
        double tax = static_cast<double>(calculateFare()) * (5.0 / 100);
        ticketPrice -= tax;
        return tax;
    }
    virtual void deductPenality()
    {
        cout << "25% money is deducted from your account : " << endl;
        reservedflight = 0;

    }

};

class InternationalFlight : public Flight
{
public:
    InternationalFlight(Airport* departure, Airport* arrival, Aeroplane* plane, double duration, int dist, string DepartureTime, string arrivalTime) : Flight(departure, arrival, plane, duration, dist, DepartureTime, arrivalTime)
    {
        ticketPrice = 20000 * duration;
    }
    Aeroplane* getAeroplane() { return airplane; }
    string DepartureAirportName() { return departureAirport->getAirportName(); }
    string ArrivalAirportName() { return arrivalAirport->getAirportName(); }
    virtual void fly() override {}

    virtual void setreservedflight(bool a) { a = reservedflight; }
    virtual bool getreservedflight() { return reservedflight; }

    virtual double calculateFare()
    {
        ticketPrice = 20000 * journeyDuration;
        return ticketPrice;
    }
    virtual double getTax()
    {
        return static_cast<double>(calculateFare()) * (10.0 / 100);
    }

    virtual double deductTax()
    {
        ticketPrice = 20000 * journeyDuration;
        double tax = static_cast<double>(calculateFare()) * (10.0 / 100);
        ticketPrice -= tax;
        return tax;
    }
    virtual void deductPenality()
    {
        cout << "25% money is deducted from your account : " << endl;
        reservedflight = 0;

    }
};

class DisplayFlights
{

public:
    friend class Admin;
    LocalFlight* localFlights[100];
    InternationalFlight* intlFlights[50];
    int localCount;
    int intlCount;
    Country* C;

    void removelocalFlight(LocalFlight* F)
    {
        bool found = false;
        int index = -1;
        for (int i = 0; i < localCount; i++)
        {
            if (localFlights[i] == F)
            {
                found = true;
                index = i;
                break;
            }
        }
        if (found)
        {
            for (int i = index; i < localCount - 1; i++)
            {
                localFlights[i] = localFlights[i + 1];
            }
            localFlights[localCount - 1] = nullptr;

            localCount--;
            cout << "Flight has been removed :" << endl;
        }
        else
        {
            cout << "Flight has  not found :" << endl;
        }
    }
    DisplayFlights()
    {
        localCount = intlCount = 0;
    }
    void addLocalFlight(LocalFlight* flight)
    {
        if (localCount < 100)
        {
            localFlights[localCount] = flight;
            localCount++;
        }
        else
        {
            cout << "FLights slots are filled!" << endl;
        }

    }

    void addIntlFlight(InternationalFlight* flight)
    {
        if (intlCount < 50)
            intlFlights[intlCount] = flight;
        intlCount++;
    }
    void AddCountry(Country* c) { C = c; }
    void DisplaySpecificLocalFlight(int an)
    {
        an -= 1;
        cout << "Local Flight " << endl;
        cout << "Flight No " << an + 1 << endl;
        cout << localFlights[an]->DepartureAirportName() << " -> " << localFlights[an]->ArrivalAirportName() << endl;
        // cout<<"Departure Time : "<<localFlights[an]->getDepartureTime()<<"\t Arrival Time : "<<localFlights[an]->getLandingTime();
        cout << "Distance : " << localFlights[an]->getDistance() << endl;
        cout << "Departure Time : " << localFlights[an]->getdepartureTime() << endl;
        cout << "Arrival Time : " << localFlights[an]->getarrivalTime() << endl;
        cout << "Travel Expense : " << localFlights[an]->calculateFare() << endl;
        cout << "Tax deduction : " << localFlights[an]->deductTax() << " Rupees" << endl;


        Sleep(5000);
    }
    void DisplaySpecificInternationalFlight(int an)
    {
        an = an - 1;
        cout << " International Flight " << endl;
        cout << "Flight No " << an << endl;
        //cout<<intlFlights[an]->DepartureAirportName()<<" -> "<<intlFlights[an]->ArrivalAirportName()<<endl;
        //cout<<"Departure Time : "<<intlFlights[an]->getDepartureTime()<<"\t Arrival Time : "<<intlFlights[an]->getLandingTime();
        cout << "Distance : " << intlFlights[an]->getDistance() << endl;
        cout << "Time Departure : " << intlFlights[an]->getDepartureTime() << "Rupees" << endl;
        cout << "Arrival Time : " << intlFlights[an]->getarrivalTime() << endl;
        cout << "Travel Expense : " << intlFlights[an]->calculateFare() << endl;
        cout << "Tax deduction : " << intlFlights[an]->deductTax() << " Rupees" << endl;
        cout << "TICKET";
        Sleep(5000);
    }
    void displayLocalFlights()
    {
        cout << localCount << endl;
        for (int i = 0; i < localCount; i++)
        {
            cout << "Flight No " << i + 1 << endl << endl;
            cout << localFlights[i]->DepartureAirportName() << " -> " << localFlights[i]->ArrivalAirportName() << endl;
            cout << "Distance : " << localFlights[i]->getDistance() << " km" << endl;
            cout << "Departure Time : " << localFlights[i]->getdepartureTime() << endl;
            cout << "Arrival Time : " << localFlights[i]->getarrivalTime() << endl;;
            cout << "Travel Expense : " << localFlights[i]->calculateFare() << "Rupees" << endl;
            cout << "Tax deduction : " << localFlights[i]->deductTax() << " Rupees" << endl;


            cout << endl << endl << endl;

        }
    }

    friend ostream& operator<<(ostream& os, const DisplayFlights& df)
    {
        for (int i = 0; i < df.intlCount; i++)
        {
            os << "Flight No " << i + 1 << endl;
            os << df.intlFlights[i]->DepartureAirportName() << " -> " << df.intlFlights[i]->ArrivalAirportName() << endl;
            os << "Time Departure : " << df.intlFlights[i]->getdepartureTime() << endl;
            os << "Time Departure : " << df.intlFlights[i]->getarrivalTime() << endl;
            os << "Travel Expense : " << df.intlFlights[i]->calculateFare() << "Rupees" << endl;
            os << "Tax deduction : " << df.intlFlights[i]->deductTax() << " Rupees" << endl;
            os << endl << endl << endl;
        }
        return os;
    }
};
bool VerifyFinancialDetail()
{
    string choice = "1";
    int s;
    cout << endl << endl;
    DisplayPattern(" Payment Method ");
    cout << endl << endl;
    do {
        cout << "\t\t" << "|\t\t" << "1)- Debit Card :" << "\t\t" << "|" << endl;
        cout << "\t\t" << "|\t\t" << "2)- Credit Card : " << "\t\t" << "|" << endl;
        cout << "\t\t" << "|\t\t" << "3)- Google Pay : " << "\t\t" << "|" << endl;
        cout << "\t\t" << "|\t\t" << "4)- Apple Pay : " << "\t\t" << "|" << endl;
        cout << "\t\t" << "|\t\t" << "5)- Exit : " << "\t\t\t" << "|" << endl;
        try {
            cin >> s;
            if (cin.fail()) {
                throw "Invalid input. Please enter a number.";
            }
            if (s < 1 || s > 5) {
                throw "Invalid choice. Please enter a number between 1 and 5.";
            }
        }
        catch (const char* error) {
            cin.clear();
            cin.ignore();
            cout << error << endl;
            continue;
        }
        if (s == 5) {
            return false;
        }
        cout << endl;
        cout << endl << endl;
        cout << "Enter key :" << endl;
        cin >> choice;
        if (choice.length() != 16) {
            cout << "Invalid key length. Please enter a 16-digit key." << endl << endl;
        }
    } while (choice.length() != 16);

    return true;
}
class Menu
{
    friend class Admin;
    DisplayFlights* D;
    int ascii = 219;
    char ch = ascii;
    int choice;
    int yu = 10;
    string passi = "", useri = "";
    string nam;
    double durationn;
    string departairportName;
    string destinationairportName;
    string departuretime;
    string arrivaltime, AeroplaneName;
    int distaance;
    Aeroplane* S;
    Airport* T;
    Airport* U;
    InternationalFlight* L;
    LocalFlight* l;
public:
    Menu() {}
    void AddAllFlights(DisplayFlights* flights)
    {
        D = flights;
    }
    void DisplayMainMenu()
    {


        do {
            try {
                Sleep(2000);
                system("CLS");

                for (int i = 1;i <= 26;i++) cout << ch;
                cout << " Welcome  To Nuces AirLine Flight System ";
                for (int i = 1;i <= 26;i++)
                    cout << ch;
                cout << endl << endl << endl;
                for (int i = 0;i < 72;i++) { (i > 16) == 1 ? cout << "-" : cout << " "; }
                cout << endl;
                cout << "\t\t" << "|\t\t" << "1)- Register as Passenger :" << "\t\t" << "|" << endl;
                cout << "\t\t" << "|\t\t" << "2)- Register as Admin : " << "\t\t" << "|" << endl;
                cout << "\t\t" << "|\t\t" << "3)- Login As a Passenger : " << "\t\t" << "|" << endl;
                cout << "\t\t" << "|\t\t" << "4)- Login as Admin : " << "\t\t\t" << "|" << endl;
                cout << "\t\t" << "|\t\t" << "5)- Flight Schedule : " << "\t\t\t" << "|" << endl;
                cout << "\t\t" << "|\t\t" << "6)- Exit : " << "\t\t" << "\t\t" << "|" << endl;
                for (int i = 0;i < 72;i++) { (i > 16) == 1 ? cout << "-" : cout << " "; }
                cout << endl << endl;
                cout << "\t" << "Enter Choice:   ";
                cin >> choice;
                if (cin.fail()) {
                    throw runtime_error("Invalid input. Please enter a number.");
                }

                switch (choice) {
                case 1:
                    {
                        Passenger* P;
                        P = new Passenger;
                        P->RegisteryPerson();
                        delete P;


                        break;
                    }
                    case 2: {
                        Admin* A;
                        A = new Admin;
                        A->RegisteryPerson();
                        delete A;
                        break;
                    }
                    case 3: {
                        // login as passenger
                        Passenger* P;
                        P = new Passenger;
                        bool reserve = 0;
                        if (P->Login() == 1)
                        {
                            do {
                                cout << "\t\t" << "|\t\t" << "1)- Reset Password :" << "\t\t" << "|" << endl;
                                cout << "\t\t" << "|\t\t" << "2)- Reserve a seat : " << "\t\t" << "|" << endl;
                                cout << "\t\t" << "|\t\t" << "3)- Cancel a seat : " << "\t\t" << "|" << endl;
                                cout << "\t\t" << "|\t\t" << "4)- See Flight Schedule : " << "\t" << "|" << endl;
                                cout << "\t\t" << "|\t\t" << "6)- Exit : " << "\t\t" << "\t" << "|" << endl;

                                cout << "Enter your choice: ";
                                try {
                                    cin >> choice;
                                    if (cin.fail()) { throw "Invalid input. Please enter a number."; }
                                }
                                catch (const char* error) {
                                    cin.clear();
                                    cin.ignore();
                                    cout << error << endl;
                                    continue;
                                }

                                switch (choice) {
                                case 1:
                                    cout << "Enter UserName :" << endl;
                                    cin >> useri;
                                    cout << "Enter New Password :" << endl;
                                    cin >> passi;
                                    P->addUserAndPasswordToFile(useri, passi);
                                    break;
                                case 2:
                                    //Reserve a seat
                                    do {
                                        VerifyFinancialDetail();
                                        cout << "\t\t" << "|\t\t" << "1)- Local Flight :" << "\t\t" << "|" << endl;
                                        cout << "\t\t" << "|\t\t" << "2)- International Flight : " << "\t\t" << "|" << endl;
                                        cout << "\t\t" << "|\t\t" << "3)- Exit : " << "\t\t" << "\t\t" << "|" << endl;

                                        cout << "Enter choice :" << endl;
                                        try {
                                            cin >> choice;
                                            if (cin.fail()) {
                                                throw "Invalid input. Please enter a number.";
                                            }
                                        }
                                        catch (const char* error)
                                        {
                                            cin.clear();
                                            cin.ignore();
                                            cout << error << endl;
                                            continue;
                                        }

                                        // Process user input
                                        switch (choice) {
                                        case 1:
                                            // Local flights
                                            D->displayLocalFlights();
                                            cout << endl << endl;
                                            cout << "Enter flight no :" << endl;
                                            cin >> choice;
                                            D->localFlights[choice - 1]->getAeroplane()->RESERVESYSTEM();
                                            DisplayPattern(" Ticket ");
                                            D->DisplaySpecificLocalFlight(choice);
                                            cout << endl << endl;
                                            Sleep(7000);
                                            break;
                                        case 2:
                                            // International flight selected
                                            cout << *D;
                                            cout << endl << endl;
                                            cout << "Enter flight no :" << endl;
                                            cin >> choice;
                                            D->intlFlights[choice - 1]->getAeroplane()->RESERVESYSTEM();
                                            DisplayPattern(" Ticket ");
                                            D->DisplaySpecificInternationalFlight(choice);
                                            Sleep(7000);
                                            break;
                                        case 3:
                                            cout << "Exiting flight schedule ! " << endl;
                                            break;
                                        default:
                                            cout << "Invalid choice. Please try again." << endl;
                                            break;
                                        }

                                    } while (choice != 3);

                                    break;
                                case 3:
                                    // Cancel a seat

                                    D->localFlights[yu]->deductPenality();
                                    break;
                                case 4:
                                    // See flight schedule
                                    do {
                                        DisplayPattern("Flights Schedule");
                                        cout << "\t\t" << "1)- Local Flights :" << endl;
                                        cout << "\t\t" << "2)- International Flights :" << endl;
                                        cout << "\t\t" << "3)- Exit :" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            throw runtime_error("Invalid input. Please enter a number.");
                                        }
                                        switch (choice) {
                                        case 1:
                                            D->displayLocalFlights();
                                            break;
                                        case 2:
                                            cout << *D;
                                            break;
                                        case 3:
                                            cout << "Exiting Flight Schedule..." << endl;
                                            break;
                                        default:
                                            cout << "Invalid choice. Please try again." << endl;
                                            break;
                                        }
                                    } while (choice != 3);
                                    break;
                                case 6:
                                    cout << "Exiting!" << endl;
                                    break;
                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                                    break;
                                }

                            } while (choice != 6);
                        }


                        delete P;
                        break;
                    }
                    case 4: {
                        // login as admin
                        Admin* A;
                        A = new Admin;
                        A->Login();
                        if (A->Login() == 1)
                        {
                            do {
                                try {
                                    DisplayPattern(" Admin Panel ");
                                    cout << "\t\t" << "|\t\t" << "1)- Add a Flight :" << "\t\t\t" << "|" << endl;
                                    cout << "\t\t" << "|\t\t" << "2)- Remove a Flight : " << "\t\t\t" << "|" << endl;
                                    cout << "\t\t" << "|\t\t" << "3)- See Flight Schedule : " << "\t\t" << "|" << endl;
                                    cout << "\t\t" << "|\t\t" << "4)- Reset Password : " << "\t\t\t" << "|" << endl;
                                    cout << "\t\t" << "|\t\t" << "5)- Display Whole System : " << "\t\t" << "|" << endl;
                                    cout << "\t\t" << "|\t\t" << "6)- Show Seating Arrangment of Plane : " << "\t" << "|" << endl;
                                    cout << "\t\t" << "|\t\t" << "7)- Exit : " << "\t\t" << "\t\t" << "|" << endl;
                                    cout << "Enter your choice: ";
                                    cin >> choice;
                                    switch (choice) {
                                    case 1:
                                        // Add a flight
                                        do {
                                            try {
                                                cout << "1)- Local Flight :" << endl;
                                                cout << "2)- International Flight :" << endl;
                                                cout << "3)- Exit" << endl;
                                                cout << "Enter your choice: ";
                                                cin >> choice;
                                                switch (choice) {
                                                case 1:
                                                    cout << "Local Flight option selected" << endl;
                                                    DisplayPattern(" Add Flight ");
                                                    cout << "Enter Name of the Flight " << endl;
                                                    cin >> nam;
                                                    cout << "Enter the Name of Departure Airport " << endl;
                                                    cin >> departairportName;
                                                    cout << "Enter the Name of Destination Airport" << endl;
                                                    cin >> destinationairportName;
                                                    cout << "Enter the name of the Plane" << endl;
                                                    cin >> AeroplaneName;
                                                    cout << "Enter the Distance of the flight " << endl;
                                                    cin >> distaance;
                                                    cout << "Enter the Departure time of the flight " << endl;
                                                    cin >> departuretime;
                                                    cout << "Enter the arrival time of the flight" << endl;
                                                    cin >> arrivaltime;
                                                    cout << "Enter the journey duration" << endl;
                                                    cin >> durationn;

                                                    S = new Aeroplane("departairportName", 0);
                                                    T = new Airport("departairportName");
                                                    U = new Airport("destinationairportName");

                                                    l = new LocalFlight(T, U, S, durationn, distaance, departuretime, arrivaltime);
                                                    D->addLocalFlight(l);

                                                    break;
                                                case 2:
                                                    DisplayPattern(" Add Flight ");
                                                    cout << "International Flight option selected" << endl;
                                                    cout << "Enter Name of the Flight " << endl;
                                                    cin >> nam;
                                                    cout << "Enter the Name of Departure Airport " << endl;
                                                    cin >> departairportName;
                                                    cout << "Enter the Name of Destination Airport" << endl;
                                                    cin >> destinationairportName;
                                                    cout << "Enter the name of the Plane" << endl;
                                                    cin >> AeroplaneName;
                                                    cout << "Enter the Distance of the flight " << endl;
                                                    cin >> distaance;
                                                    cout << "Enter the Departure time of the flight " << endl;
                                                    cin >> departuretime;
                                                    cout << "Enter the arrival time of the flight" << endl;
                                                    cin >> arrivaltime;
                                                    cout << "Enter the journey duration" << endl;
                                                    cin >> durationn;
                                                    S = new Aeroplane("departairportName", 0);
                                                    T = new Airport("departairportName");
                                                    U = new Airport("destinationairportName");

                                                    L = new InternationalFlight(T, U, S, durationn, distaance, departuretime, arrivaltime);
                                                    D->addIntlFlight(L);
                                                    break;
                                                case 3:
                                                    cout << "Exiting the program" << endl;
                                                    break;
                                                default:
                                                    throw "Invalid choice! Please enter a number between 1 and 3.";
                                                }
                                            }
                                            catch (const char* msg) {
                                                cout << "Error: " << msg << endl;
                                            }
                                        } while (choice != 3);

                                        break;
                                    case 2:

                                        do {
                                            cout << endl << endl;
                                            cout << "1)- Local Flight :" << endl;
                                            cout << "2)- International Flight :" << endl;
                                            cout << "3)- Exit" << endl;
                                            cout << "Enter your choice: ";
                                            try {
                                                cin >> choice;
                                                if (cin.fail()) {
                                                    throw "Invalid input. Please enter a number.";
                                                }
                                            }
                                            catch (const char* error) {
                                                cin.clear();
                                                cin.ignore();
                                                cout << error << endl;
                                                continue;
                                            }

                                            switch (choice)
                                            {
                                            case 1:
                                                D->displayLocalFlights();
                                                cout << endl << endl << "Enter flight no to remove it" << endl;
                                                cin >> choice;
                                                D->removelocalFlight(D->localFlights[choice - 1]);
                                                break;
                                            case 2:
                                                cout << *D;
                                                cout << endl << endl << "Enter flight no to remove it" << endl;
                                                cin >> choice;
                                                D->removelocalFlight(D->localFlights[choice - 1]);
                                                break;
                                            case 3:
                                                cout << "Exiting program..." << endl;
                                                break;
                                            default:
                                                cout << "Invalid choice. Please try again." << endl;
                                                break;
                                            }
                                        } while (choice != 3);
                                        break;
                                    case 3:
                                        DisplayPattern(" Local Flights ");
                                        D->displayLocalFlights();
                                        DisplayPattern(" International Flights ");
                                        cout << *D;           //overloaded stream operator
                                        Sleep(5000);
                                        break;
                                    case 4:
                                        DisplayPattern(" Reset Password ");
                                        cout << "Enter username " << endl;
                                        cin >> nam;
                                        cout << "Enter the password " << endl;
                                        cin >> departuretime;
                                        cout << "Enter new password " << endl;
                                        cin >> arrivaltime;
                                        A->reset_password(nam, departuretime, arrivaltime);

                                        break;
                                    case 5:
                                        D->C->DisplayCity();
                                        //D->C->DisplayCity();
                                        Sleep(1000);
                                        break;
                                    case 6:
                                        DisplayPattern(" Seating Arrangement ");
                                        D->localFlights[1]->getAeroplane()->show_seating_arrangement();
                                        Sleep(7000);
                                        D->localFlights[1]->getAeroplane()->setCorona(1);
                                        DisplayPattern(" Seating Arrangement In Corona ");
                                        D->localFlights[1]->getAeroplane()->show_seating_arrangement();
                                        Sleep(6000);
                                        break;
                                    case 7:
                                        break;
                                    default:
                                        throw "Invalid choice! Please enter a number between 1 and 7.";
                                    }
                                }
                                catch (const char* msg) {
                                    cout << "Error: " << msg << endl;
                                }
                            } while (choice != 7);
                        }
                        //delete A;
                        break;
                    }
                    case 5:
                    {

                        do {
                            DisplayPattern("Flights Schedule");
                            cout << "\t\t" << "1)- Local Flights :" << endl;
                            cout << "\t\t" << "2)- International Flights :" << endl;
                            cout << "\t\t" << "3)- Set Corona Condition :" << endl;
                            cout << "\t\t" << "4)- Exit :" << endl;
                            cin >> choice;
                            if (cin.fail()) {
                                throw runtime_error("Invalid input. Please enter a number.");
                            }
                            switch (choice)
                            {
                            case 1:
                                D->displayLocalFlights();
                                Sleep(1000);
                                break;
                            case 2:
                                cout << *D;
                                Sleep(1000);
                                break;
                            case 3:
                                //
                                do {
                                    cout << endl << endl;
                                    cout << "1)- Local Flight :" << endl;
                                    cout << "2)- International Flight :" << endl;
                                    cout << "3)- Exit" << endl;
                                    cout << "Enter your choice: ";
                                    try {
                                        cin >> choice;
                                        if (cin.fail()) {
                                            throw "Invalid input. Please enter a number.";
                                        }
                                    }
                                    catch (const char* error) {
                                        cin.clear();
                                        cin.ignore();
                                        cout << error << endl;
                                        continue;
                                    }

                                    switch (choice)
                                    {
                                    case 1:
                                        D->displayLocalFlights();
                                        cout << endl << endl << "Enter flight no to set the corona SOPs in it" << endl;
                                        cin >> choice;
                                        D->localFlights[choice - 1]->getAeroplane()->setCorona(1);
                                        cout << "SOPS are granted for the flight" << endl;
                                        break;
                                    case 2:
                                        cout << *D;
                                        cout << endl << endl << "Enter flight no to remove it" << endl;
                                        cin >> choice;
                                        D->intlFlights[choice - 1]->getAeroplane()->setCorona(1);
                                        cout << "SOPS are granted for the flight" << endl;
                                        break;
                                    case 3:
                                        cout << "Exiting program..." << endl;
                                        break;
                                    default:
                                        cout << "Invalid choice. Please try again." << endl;
                                        break;
                                    }
                                } while (choice != 3);
                                break;
                            case 4:
                                cout << "Exiting Flight Schedule..." << endl;
                                break;

                            default:
                                cout << "Invalid choice. Please try again." << endl;
                                break;
                            }
                        } while (choice != 4);
                    }
                    case 0: {
                        // exit the program
                        cout << "Goodbye!" << endl;
                        break;
                    }
                    default: {
                        // invalid choice
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                    }
                    }
                }
                catch (const exception& e)
                {
                    cin.clear();
                    cout << "Error: " << e.what() << ". Please try again." << endl;
                    cin.ignore();
                }

            } while (choice != 0);
            delete D;

        }
    };
