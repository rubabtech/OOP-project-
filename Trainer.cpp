#include "Trainer.h"

// ============================================================
//   GYM MANAGEMENT SYSTEM - Trainer.cpp
//   OOP: Inheritance, Polymorphism, Encapsulation
// ============================================================

// ---- Default Constructor ----
Trainer::Trainer() : Person() {
    specialization[0] = '\0';
    salaryPerMonth    = 0.0;
    experienceYears   = 0;
    memberCount       = 0;
    isAvailable       = true;
}

// ---- Parameterized Constructor ----
Trainer::Trainer(int i, char n[], int a, char ph[], char spec[], double sal, int exp)
    : Person(i, n, a, ph) {          // base class constructor call
    charCopy(specialization, spec);
    salaryPerMonth  = sal;
    experienceYears = exp;
    memberCount     = 0;
    isAvailable     = true;
}

// ---- Destructor ----
Trainer::~Trainer() {
    // cout << "Trainer " << name << " destroyed\n";
}

// ---- Getters ----
char*  Trainer::getSpec()         { return specialization; }
double Trainer::getSalary()       { return salaryPerMonth; }
int    Trainer::getExperience()   { return experienceYears; }
bool   Trainer::getAvailability() { return isAvailable; }

// ---- Setters ----
void Trainer::setSalary(double s)       { salaryPerMonth = s; }
void Trainer::setAvailability(bool b)   { isAvailable = b; }

// ---- calculateFee: Runtime Polymorphism (overrides Person) ----
double Trainer::calculateFee() {
    return salaryPerMonth;           // salary per month
}

// ---- assignMember: adds member ID to array ----
void Trainer::assignMember(int memberId) {
    if (memberCount >= 10) {
        cout << "[!] Trainer capacity full!\n"; return;
    }
    assignedMembers[memberCount++] = memberId;
    cout << "[+] Member " << memberId << " assigned to " << name << "\n";
}

// ---- removeMember: removes member ID using for loop ----
void Trainer::removeMember(int memberId) {
    bool found = false;
    for (int i = 0; i < memberCount; i++) {
        if (assignedMembers[i] == memberId) {
            // shift left
            for (int j = i; j < memberCount-1; j++)
                assignedMembers[j] = assignedMembers[j+1];
            memberCount--;
            found = true;
            cout << "[+] Member " << memberId << " removed.\n";
            break;
        }
    }
    if (!found) cout << "[!] Member not found.\n";
}

// ---- showAssignedMembers ----
void Trainer::showAssignedMembers() {
    cout << "  Assigned Members (" << memberCount << "): ";
    if (memberCount == 0) { cout << "None\n"; return; }
    for (int i = 0; i < memberCount; i++)
        cout << assignedMembers[i] << " ";
    cout << "\n";
}

// ---- giveRaise: increases salary by percentage ----
void Trainer::giveRaise(double percent) {
    double raise = salaryPerMonth * percent / 100.0;
    salaryPerMonth += raise;
    cout << "[+] Raise given! New salary: Rs " << salaryPerMonth << "\n";
}

// ---- displayInfo: overrides pure virtual (Polymorphism) ----
void Trainer::displayInfo() {
    cout << "\n  ---- TRAINER INFO ----\n";
    cout << "  ID           : " << id               << "\n";
    cout << "  Name         : " << name             << "\n";
    cout << "  Age          : " << age              << "\n";
    cout << "  Phone        : " << phone            << "\n";
    cout << "  Specialization: " << specialization  << "\n";
    cout << "  Salary/Month : Rs " << salaryPerMonth << "\n";
    cout << "  Experience   : " << experienceYears  << " years\n";
    cout << "  Availability : " << (isAvailable ? "Available" : "Busy") << "\n";
    showAssignedMembers();
}

// ---- saveToFile: overrides pure virtual (File Handling) ----
void Trainer::saveToFile(ofstream &file) {
    file << "TRAINER\n";
    file << id << "\n" << name << "\n" << age << "\n" << phone << "\n"
         << specialization << "\n" << salaryPerMonth << "\n"
         << experienceYears << "\n" << memberCount << "\n";
    for (int i = 0; i < memberCount; i++)
        file << assignedMembers[i] << "\n";
}

// ---- Function Overloading (Compile-time Polymorphism) ----
void Trainer::update(char newSpec[]) {
    charCopy(specialization, newSpec);
    cout << "[+] Specialization updated.\n";
}

void Trainer::update(char newSpec[], double newSalary) {
    charCopy(specialization, newSpec);
    salaryPerMonth = newSalary;
    cout << "[+] Specialization and salary updated.\n";
}
