#include "Person.h"

// ============================================================
//   GYM MANAGEMENT SYSTEM - Person.cpp
//   OOP: Base Class Definitions, Constructor, Destructor
// ============================================================

// ---- Utility: charCopy ----
void Person::charCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') { dest[i] = src[i]; i++; }
    dest[i] = '\0';
}

// ---- Utility: charLen ----
int Person::charLen(char arr[]) {
    int i = 0;
    while (arr[i] != '\0') i++;
    return i;
}

// ---- Default Constructor ----
Person::Person() {
    id  = 0;
    age = 0;
    name[0]  = '\0';
    phone[0] = '\0';
}

// ---- Parameterized Constructor ----
Person::Person(int i, char n[], int a, char ph[]) {
    id  = i;
    age = a;
    charCopy(name,  n);
    charCopy(phone, ph);
}

// ---- Destructor ----
Person::~Person() {
    // cleanup message (demonstrates destructor)
    // cout << "Person object destroyed\n";
}

// ---- Getters ----
int   Person::getId()    const { return id; }
int   Person::getAge()   const { return age; }
char* Person::getName()        { return name; }
char* Person::getPhone()       { return phone; }

// ---- Setters ----
void Person::setName(char n[])   { charCopy(name,  n); }
void Person::setPhone(char ph[]) { charCopy(phone, ph); }
