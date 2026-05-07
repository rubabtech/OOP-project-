# Gym Management System

A complete Gym Management System built in C++ for OOP (Object Oriented Programming) course using multiple files.

## File Structure
- `Person.h / Person.cpp` — Abstract Base Class (pure virtual functions)
- `Member.h / Member.cpp` — Derived Class (inherits Person)
- `Trainer.h / Trainer.cpp` — Derived Class (inherits Person)
- `main.cpp` — Main entry point, menus, polymorphic calls

## Features
- Add Members (basic / standard / premium package)
- Add Trainers with specialization and salary
- Pay Membership Fee & log workouts
- Assign Trainer to Member
- Give Trainer salary raise
- Total Revenue & Expense report
- Save all data to file

## OOP Concepts Used
- **Encapsulation** — private data, public getters/setters
- **Abstraction** — Person is abstract class (pure virtual functions)
- **Inheritance** — Member and Trainer inherit from Person
- **Runtime Polymorphism** — virtual functions, base class pointer
- **Compile-time Polymorphism** — function overloading (update())
- **Constructor & Destructor** — in every class
- **Access Specifiers** — private, protected, public
- **File Handling** — ofstream saves all data
- **2D char array** — workout history in Member class
- **Pointers** — Person *ptr for polymorphic calls

## How to Run
Add all 7 files in one Dev-C++ project and press F11

## Compiler
g++ Person.cpp Member.cpp Trainer.cpp main.cpp -o gym
