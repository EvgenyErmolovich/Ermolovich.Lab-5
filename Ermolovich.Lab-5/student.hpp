//
//  student.hpp
//  Ermolovich.Lab-5
//
//  Created by Evgeny on 28.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#ifndef student_h
#define student_h

const int N = 20;
const int M = 5;

struct Student
{
    Student();
    ~Student();
    void SetFirstName(char*);
    void SetSecondName(char*);
    void SetFuculty(char*);
    void SetMarks(int*);
    void SetStudent(char*, char*, char*, int*);
    double GetMiddleMark();
    char* GetFirstName();
    char* GetSecondName();
    char* GetFuculty();
    void DisplayStudent();
    bool operator == (const Student& );
private:
    char firstName[N], secondName[N], fuculty[N];
    int marks[M];
    double middleMark;
    void SetMiddleMark();
};

#endif