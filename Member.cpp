#include "Member.h"

// ============================================================
//   GYM MANAGEMENT SYSTEM - Member.cpp
//   OOP: Inheritance, Encapsulation, Polymorphism
// ============================================================

// ---- Default Constructor ----
Member::Member() : Person() {
    packageType[0] = '\0';
    joinDate[0]    = '\0';
    monthsPaid     = 0;
    feePerMonth    = 0.0;
    isActive       = false;
    workoutCount   = 0;
}

// ---- Parameterized Constructor ----
Member::Member(int i, char n[], int a, char ph[], char pkg[], char date[])
    : Person(i, n, a, ph) {          // calling base class constructor
    charCopy(packageType, pkg);
    charCopy(joinDate, date);
    monthsPaid   = 0;
    isActive     = true;
    workoutCount = 0;

    // Set fee based on package type (encapsulated logic)
    if (packageType[0] == 'b')      feePerMonth = 2000.0;  // basic
    else if (packageType[0] == 's') feePerMonth = 3500.0;  // standard
    else                             feePerMonth = 5500.0;  // premium
}

// ---- Destructor ----
Member::~Member() {
    // cout << "Member " << name << " destroyed\n";
}

// ---- Getters ----
char*  Member::getPackage()      { return packageType; }
double Member::getFeePerMonth()  { return feePerMonth; }
bool   Member::getIsActive()     { return isActive; }
int    Member::getMonthsPaid()   { return monthsPaid; }

// ---- Setters ----
void Member::setPackage(char pkg[]) {
    charCopy(packageType, pkg);
    if (pkg[0] == 'b')      feePerMonth = 2000.0;
    else if (pkg[0] == 's') feePerMonth = 3500.0;
    else                     feePerMonth = 5500.0;
}
void Member::setActive(bool status) { isActive = status; }

// ---- calculateFee: Runtime Polymorphism (overrides Person) ----
// Return type: double
double Member::calculateFee() {
    return feePerMonth * monthsPaid;
}

// ---- payFee: pays for given months ----
void Member::payFee(int months) {
    monthsPaid += months;
    isActive    = true;
    cout << "[+] Fee paid for " << months << " months.\n";
    cout << "    Total Paid: Rs " << calculateFee() << "\n";
}

// ---- renewMembership ----
void Member::renewMembership(int months) {
    monthsPaid += months;
    isActive    = true;
    cout << "[+] Membership renewed for " << months << " months!\n";
}

// ---- addWorkout: adds to 2D char array ----
void Member::addWorkout(char workout[]) {
    if (workoutCount < 5) {
        charCopy(workoutHistory[workoutCount], workout);
        workoutCount++;
    } else {
        // shift up using for loop
        for (int i = 0; i < 4; i++)
            charCopy(workoutHistory[i], workoutHistory[i+1]);
        charCopy(workoutHistory[4], workout);
    }
    cout << "[+] Workout logged: " << workout << "\n";
}

// ---- showWorkoutHistory: displays 2D array ----
void Member::showWorkoutHistory() {
    cout << "\n  --- Workout History ---\n";
    if (workoutCount == 0) { cout << "  No workouts logged yet.\n"; return; }
    for (int i = 0; i < workoutCount; i++)
        cout << "  " << i+1 << ". " << workoutHistory[i] << "\n";
}

// ---- displayInfo: overrides pure virtual (Polymorphism) ----
void Member::displayInfo() {
    cout << "\n  ---- MEMBER INFO ----\n";
    cout << "  ID       : " << id            << "\n";
    cout << "  Name     : " << name          << "\n";
    cout << "  Age      : " << age           << "\n";
    cout << "  Phone    : " << phone         << "\n";
    cout << "  Package  : " << packageType   << "\n";
    cout << "  Fee/Month: Rs " << feePerMonth << "\n";
    cout << "  Joined   : " << joinDate      << "\n";
    cout << "  Status   : " << (isActive ? "Active" : "Inactive") << "\n";
    showWorkoutHistory();
}

// ---- saveToFile: overrides pure virtual (File Handling) ----
void Member::saveToFile(ofstream &file) {
    file << "MEMBER\n";
    file << id           << "\n" << name        << "\n"
         << age          << "\n" << phone        << "\n"
         << packageType  << "\n" << joinDate     << "\n"
         << monthsPaid   << "\n" << feePerMonth  << "\n"
         << isActive     << "\n" << workoutCount << "\n";
    for (int i = 0; i < workoutCount; i++)
        file << workoutHistory[i] << "\n";
}

// ---- Function Overloading (Compile-time Polymorphism) ----
// update() with 1 param
void Member::update(char newName[]) {
    charCopy(name, newName);
    cout << "[+] Name updated.\n";
}

// update() with 2 params
void Member::update(char newName[], char newPhone[]) {
    charCopy(name,  newName);
    charCopy(phone, newPhone);
    cout << "[+] Name and phone updated.\n";
}

// update() with 3 params
void Member::update(char newName[], char newPhone[], char newPkg[]) {
    charCopy(name,  newName);
    charCopy(phone, newPhone);
    setPackage(newPkg);
    cout << "[+] Name, phone, and package updated.\n";
}
