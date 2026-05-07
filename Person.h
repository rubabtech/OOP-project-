#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
using namespace std;

// ============================================================
//   GYM MANAGEMENT SYSTEM - Person.h
//   OOP Concept: Base Class (Abstraction + Encapsulation)
// ============================================================

class Person {
protected:                        // protected: accessible in derived classes
    int    id;
    char   name[40];
    int    age;
    char   phone[15];

public:
    // Constructor
    Person();
    Person(int id, char n[], int age, char ph[]);

    // Destructor
    virtual ~Person();

    // Getters (Encapsulation - private data via public functions)
    int  getId()   const;
    int  getAge()  const;
    char* getName();
    char* getPhone();

    // Setters
    void setName(char n[]);
    void setPhone(char ph[]);

    // Virtual function (Runtime Polymorphism)
    virtual void displayInfo() = 0;   // Pure virtual = Abstract class
    virtual void saveToFile(ofstream &file) = 0;
    virtual double calculateFee() = 0;

    // Utility
    void charCopy(char dest[], const char src[]);
    int  charLen(char arr[]);
};

#endif
