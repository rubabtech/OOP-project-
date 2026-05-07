#ifndef TRAINER_H
#define TRAINER_H

#include "Person.h"

// ============================================================
//   GYM MANAGEMENT SYSTEM - Trainer.h
//   OOP Concept: Inheritance (Trainer inherits from Person)
//               Polymorphism (overrides displayInfo, calculateFee)
// ============================================================

class Trainer : public Person {       // Inheritance from Person
private:                              // Encapsulation
    char   specialization[30];        // e.g. cardio, weights, yoga
    double salaryPerMonth;
    int    experienceYears;
    int    assignedMembers[10];       // array of member IDs
    int    memberCount;
    bool   isAvailable;

public:
    // Constructors
    Trainer();
    Trainer(int id, char n[], int age, char ph[], char spec[], double salary, int exp);

    // Destructor
    ~Trainer();

    // Getters
    char*  getSpec();
    double getSalary();
    int    getExperience();
    bool   getAvailability();

    // Setters
    void setSalary(double s);
    void setAvailability(bool status);

    // Core Functions
    void assignMember(int memberId);
    void removeMember(int memberId);
    void showAssignedMembers();
    void giveRaise(double percent);

    // Overridden virtual functions (Runtime Polymorphism)
    void   displayInfo();
    void   saveToFile(ofstream &file);
    double calculateFee();            // returns salary (different from Member)

    // Function Overloading
    void update(char newSpec[]);
    void update(char newSpec[], double newSalary);
};

#endif
