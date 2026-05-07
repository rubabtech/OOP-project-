#include "Member.h"
#include "Trainer.h"

// ============================================================
//   GYM MANAGEMENT SYSTEM - main.cpp
//   OOP Project | Classes, Inheritance, Polymorphism
// ============================================================

const int MAX = 10;

// ---- Global arrays of objects ----
Member  members[MAX];
Trainer trainers[MAX];
int totalMembers  = 0;
int totalTrainers = 0;
int nextMemberId  = 101;
int nextTrainerId = 201;

// ---- Utility: print line ----
void printLine(char ch, int n) {
    for (int i = 0; i < n; i++) cout << ch;
    cout << "\n";
}

// ---- Find member by ID ----
int findMember(int id) {
    for (int i = 0; i < totalMembers; i++)
        if (members[i].getId() == id) return i;
    return -1;
}

// ---- Find trainer by ID ----
int findTrainer(int id) {
    for (int i = 0; i < totalTrainers; i++)
        if (trainers[i].getId() == id) return i;
    return -1;
}

// ---- Add New Member ----
void addMember() {
    if (totalMembers >= MAX) { cout << "[!] Member limit reached!\n"; return; }

    char name[40], phone[15], pkg[15], date[15];
    int  age;

    cout << "\n--- Add New Member ---\n";
    cout << "Name  : "; cin.ignore(); cin.getline(name, 40);
    cout << "Age   : "; cin >> age;
    cout << "Phone : "; cin >> phone;
    cout << "Package (basic/standard/premium): "; cin >> pkg;
    cout << "Join Date (DD-MM-YYYY): "; cin >> date;

    members[totalMembers] = Member(nextMemberId, name, age, phone, pkg, date);
    cout << "\n[+] Member added! ID: " << nextMemberId << "\n";
    nextMemberId++;
    totalMembers++;
}

// ---- Add New Trainer ----
void addTrainer() {
    if (totalTrainers >= MAX) { cout << "[!] Trainer limit reached!\n"; return; }

    char   name[40], phone[15], spec[30];
    int    age, exp;
    double salary;

    cout << "\n--- Add New Trainer ---\n";
    cout << "Name           : "; cin.ignore(); cin.getline(name, 40);
    cout << "Age            : "; cin >> age;
    cout << "Phone          : "; cin >> phone;
    cout << "Specialization : "; cin.ignore(); cin.getline(spec, 30);
    cout << "Salary/Month   : "; cin >> salary;
    cout << "Experience (yrs): "; cin >> exp;

    trainers[totalTrainers] = Trainer(nextTrainerId, name, age, phone, spec, salary, exp);
    cout << "\n[+] Trainer added! ID: " << nextTrainerId << "\n";
    nextTrainerId++;
    totalTrainers++;
}

// ---- Display All Members (Runtime Polymorphism via virtual) ----
void displayAllMembers() {
    if (totalMembers == 0) { cout << "[!] No members found!\n"; return; }
    printLine('=', 50);
    cout << "         ALL GYM MEMBERS\n";
    printLine('=', 50);
    Person *ptr;                          // Base class pointer (Polymorphism)
    for (int i = 0; i < totalMembers; i++) {
        ptr = &members[i];                // points to Member object
        ptr->displayInfo();               // calls Member::displayInfo()
        printLine('-', 50);
    }
}

// ---- Display All Trainers (Runtime Polymorphism) ----
void displayAllTrainers() {
    if (totalTrainers == 0) { cout << "[!] No trainers found!\n"; return; }
    printLine('=', 50);
    cout << "         ALL GYM TRAINERS\n";
    printLine('=', 50);
    Person *ptr;                          // Base class pointer (Polymorphism)
    for (int i = 0; i < totalTrainers; i++) {
        ptr = &trainers[i];               // points to Trainer object
        ptr->displayInfo();               // calls Trainer::displayInfo()
        printLine('-', 50);
    }
}

// ---- Pay Fee ----
void payFee() {
    int id, months;
    cout << "\n--- Pay Membership Fee ---\n";
    cout << "Enter Member ID: "; cin >> id;
    int idx = findMember(id);
    if (idx == -1) { cout << "[!] Member not found!\n"; return; }
    cout << "Months to pay : "; cin >> months;
    members[idx].payFee(months);
}

// ---- Log Workout ----
void logWorkout() {
    int id; char workout[40];
    cout << "\n--- Log Workout ---\n";
    cout << "Enter Member ID: "; cin >> id;
    int idx = findMember(id);
    if (idx == -1) { cout << "[!] Member not found!\n"; return; }
    cout << "Workout (e.g. Chest+Triceps): "; cin.ignore(); cin.getline(workout, 40);
    members[idx].addWorkout(workout);
}

// ---- Assign Trainer to Member ----
void assignTrainer() {
    int tid, mid;
    cout << "\n--- Assign Trainer to Member ---\n";
    cout << "Trainer ID: "; cin >> tid;
    cout << "Member  ID: "; cin >> mid;
    int ti = findTrainer(tid);
    int mi = findMember(mid);
    if (ti == -1) { cout << "[!] Trainer not found!\n"; return; }
    if (mi == -1) { cout << "[!] Member not found!\n";  return; }
    trainers[ti].assignMember(mid);
}

// ---- Give Trainer Raise ----
void giveRaise() {
    int id; double percent;
    cout << "\n--- Give Trainer Raise ---\n";
    cout << "Trainer ID     : "; cin >> id;
    cout << "Raise percent  : "; cin >> percent;
    int idx = findTrainer(id);
    if (idx == -1) { cout << "[!] Trainer not found!\n"; return; }
    trainers[idx].giveRaise(percent);
}

// ---- Calculate Total Revenue (Polymorphism demo) ----
void totalRevenue() {
    double revenue = 0, expense = 0;
    Person *ptr;

    // Member fees
    for (int i = 0; i < totalMembers; i++) {
        ptr = &members[i];
        revenue += ptr->calculateFee();   // virtual function call
    }
    // Trainer salaries
    for (int i = 0; i < totalTrainers; i++) {
        ptr = &trainers[i];
        expense += ptr->calculateFee();   // virtual function call
    }

    printLine('=', 40);
    cout << "  Total Member Revenue : Rs " << revenue << "\n";
    cout << "  Total Trainer Expense: Rs " << expense << "\n";
    cout << "  Net Balance          : Rs " << revenue - expense << "\n";
    printLine('=', 40);
}

// ---- Save All to File ----
void saveAll() {
    ofstream file("gym_data.txt");
    if (!file) { cout << "[!] File error!\n"; return; }
    file << totalMembers << "\n";
    for (int i = 0; i < totalMembers; i++)
        members[i].saveToFile(file);
    file << totalTrainers << "\n";
    for (int i = 0; i < totalTrainers; i++)
        trainers[i].saveToFile(file);
    file.close();
    cout << "[+] Data saved to gym_data.txt\n";
}

// ---- Menus ----
void memberMenu() {
    int ch;
    do {
        printLine('=', 45);
        cout << "         MEMBER MANAGEMENT\n";
        printLine('=', 45);
        cout << " 1. Add New Member\n";
        cout << " 2. Display All Members\n";
        cout << " 3. Pay Fee\n";
        cout << " 4. Log Workout\n";
        cout << " 0. Back\n";
        printLine('=', 45);
        cout << "Choice: "; cin >> ch;
        switch(ch) {
            case 1: addMember();         break;
            case 2: displayAllMembers(); break;
            case 3: payFee();            break;
            case 4: logWorkout();        break;
            case 0: break;
            default: cout << "[!] Invalid!\n";
        }
    } while (ch != 0);
}

void trainerMenu() {
    int ch;
    do {
        printLine('=', 45);
        cout << "         TRAINER MANAGEMENT\n";
        printLine('=', 45);
        cout << " 1. Add New Trainer\n";
        cout << " 2. Display All Trainers\n";
        cout << " 3. Assign Trainer to Member\n";
        cout << " 4. Give Raise\n";
        cout << " 0. Back\n";
        printLine('=', 45);
        cout << "Choice: "; cin >> ch;
        switch(ch) {
            case 1: addTrainer();        break;
            case 2: displayAllTrainers(); break;
            case 3: assignTrainer();     break;
            case 4: giveRaise();         break;
            case 0: break;
            default: cout << "[!] Invalid!\n";
        }
    } while (ch != 0);
}

// ---- MAIN ----
int main() {
    int choice;

    printLine('*', 50);
    cout << "     UNIVERSITY GYM MANAGEMENT SYSTEM\n";
    cout << "     OOP Project | C++ | Multiple Files\n";
    printLine('*', 50);

    do {
        printLine('=', 45);
        cout << "            MAIN MENU\n";
        printLine('=', 45);
        cout << " 1. Member Management\n";
        cout << " 2. Trainer Management\n";
        cout << " 3. Total Revenue & Expense\n";
        cout << " 4. Save All Data to File\n";
        cout << " 0. Exit\n";
        printLine('=', 45);
        cout << "Choice: "; cin >> choice;

        switch(choice) {
            case 1: memberMenu();    break;
            case 2: trainerMenu();   break;
            case 3: totalRevenue();  break;
            case 4: saveAll();       break;
            case 0:
                cout << "\nSaving before exit...\n";
                saveAll();
                cout << "Thank you! Goodbye!\n";
                break;
            default: cout << "[!] Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
