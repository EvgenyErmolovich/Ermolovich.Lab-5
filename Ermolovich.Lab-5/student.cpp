//
//  student.cpp
//  Ermolovich.Lab-5
//
//  Created by Evgeny on 28.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include "student.hpp"
#include <iostream>
#include <string.h>

using namespace std;

Student::Student(){}

Student::~Student(){}

void Student::SetFirstName(char* s)
{
    strcpy(firstName,s);
}

void Student::SetSecondName(char* s)
{
    strcpy(secondName,s);
}

void Student::SetFuculty(char* s)
{
    strcpy(fuculty,s);
}

void Student::SetMarks(int* A)
{
    for(int i = 0; i < M; i++)
        marks[i] = A[i];
}

char* Student::GetFirstName()
{
    return firstName;
}

char* Student::GetSecondName()
{
    return secondName;
}

char* Student::GetFuculty()
{
    return fuculty;
}

double Student::GetMiddleMark()
{
    return middleMark;
}

void Student::SetMiddleMark()
{
    middleMark = 0;
    for(int i = 0; i < M; i++)
        middleMark += marks[i];
    middleMark = middleMark / M;
}

void Student::SetStudent(char* s1, char* s2, char* s3, int* a)
{
    SetFirstName(s1);
    SetSecondName(s2);
    SetFuculty(s3);
    SetMarks(a);
    SetMiddleMark();
}

void Student::DisplayStudent()
{
    cout << endl << firstName << " " << secondName << ", \t";
    cout.precision(3);
    cout << middleMark << "  , \t" <<  fuculty << ".";
    cout << "\tMarks: ";
    for(int i = 0; i < M; i++)
        cout << marks[i] << "  ";
}
bool Student::operator == (const Student& other)
{
    if (strcmp(firstName, other.firstName) == 0 && strcmp(secondName, other.secondName) == 0)
        return true;
    return false;
}