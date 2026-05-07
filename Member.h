#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"

// ============================================================
//   GYM MANAGEMENT SYSTEM - Member.h
//   OOP Concept: Inheritance (Member inherits from Person)
//               Encapsulation (private data, public methods)
// ============================================================

class Member : public Person {        // Inheritance: public base class
private:                              // Encapsulation: private data
    char   packageType[15];           // basic / standard / premium
    int    monthsPaid;
    double feePerMonth;
    bool   isActive;
    char   joinDate[15];
    char   workoutHistory[5][40];     // 2D array: last 5 workouts
    int    workoutCount;

public:
    // Constructors
    Member();
    Member(int id, char n[], int age, char ph[], char pkg[], char date[]);

    // Destructor
    ~Member();

    // Getters
    char*  getPackage();
    double getFeePerMonth();
    bool   getIsActive();
    int    getMonthsPaid();

    // Setters
    void setPackage(char pkg[]);
    void setActive(bool status);

    // Core Functions
    void   payFee(int months);
    void   addWorkout(char workout[]);
    void   showWorkoutHistory();
    void   renewMembership(int months);

    // Overridden virtual functions (Runtime Polymorphism)
    void   displayInfo();
    void   saveToFile(ofstream &file);
    double calculateFee();            // overridden: different for Member

    // Function Overloading (Compile-time Polymorphism)
    void   update(char newName[]);
    void   update(char newName[], char newPhone[]);
    void   update(char newName[], char newPhone[], char newPkg[]);
};

#endif
