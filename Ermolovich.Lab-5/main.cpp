//
//  main.cpp
//  Ermolovich.Lab-5
//
//  Created by Evgeny on 28.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include <iostream>
#include "student.hpp"

using namespace std;

Student InitStudent();
Student* InitArray(int);
void DisplayArray(Student*, int);
void EnterArray(int*, int);
void DisplayChoise(Student*, int, char*, double, double);
void Swap(Student&, Student&);
typedef int(*Comparer)(Student , Student );
int ByFirstName(Student , Student );
int BySecondName(Student, Student );
int ByFuculty(Student, Student );
int ByMiddleMarkIncrease(Student , Student );
int ByMiddleMarkDecrease(Student , Student );
void QuickSort(Student* , int , int, Comparer);
void BubbleSort(Student* , int, Comparer);
void ChoiceSort(Student* , int, Comparer);
void ShakerSort(Student* , int, Comparer);
void QuickSort(Student* , int, Comparer);
int StudentSearch(Student* a, int size, Student x);

int main()
{
    int n;
    cout << "\nEnter the number of Students:";
    cin >> n;
    Student* students = InitArray(n);
    if (!students)
    {
        cout << "\nDynamic array doesn't exist!\n";
        return 0;
    }
    cout << "\nThe list of Students:\n";
    DisplayArray(students, n);
    char fucultyTag[N];
    cout << "\nEnter the Fuculty-tag:";
    cin >> fucultyTag;
    double lowMiddleMark, upperMiddleMark;
    cout << "\nEnter the low boundary of MiddleMark:";
    cin >> lowMiddleMark;
    cout << "\nEnter the upper boundary of MiddleMark:";
    cin >> upperMiddleMark;
    cout << "\n\nThe list of choise-Students:\n";
    DisplayChoise(students, n, fucultyTag, lowMiddleMark, upperMiddleMark);
    cout << "\n\nThe sorting list of Students: \n";
    BubbleSort(students, n, ByFirstName);
    DisplayArray(students, n);
    delete[] students;
    return 0;
}

Student InitStudent()
{
    char firstName[N] = "", secondName[N] = "", fuculty[N] = "";
    cout << "\nEnter first name:";
    cin.ignore();
    cin.get(firstName, N, '\n');
    cout << "Enter second name:";
    cin.ignore();
    cin.get(secondName, N, '\n');
    cout << "Enter Fuculty:";
    cin.ignore();
    cin.get(fuculty, N, '\n');
    cout << "Enter array of marks:";
    int A[M];
    EnterArray(A, M);
    Student man;
    man.SetStudent(firstName, secondName, fuculty, A);
    return man;
}

Student* InitArray(int n)
{
    Student* array = new Student[n];
    if (!array)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the information about " << (i + 1) << " Student\n";
        array[i] = InitStudent();
    }
    return array;
}

void EnterArray(int* array, int n)
{
    for (int i = 0; i < M; i++)
    {
        cout << "enter A[" << (i + 1) << "] = ";
        cin >> array[i];
    }
}


void DisplayArray(Student* array, int n)
{
    for (int i = 0; i < n; i++)
        array[i].DisplayStudent();
    cout << endl;
}

void DisplayChoise(Student* array, int Dimension, char* fucultyTag, double lowMark, double upperMark)
{
    for (int i = 0; i < Dimension; i++)
        if (!strcmp(array[i].GetFuculty(), fucultyTag) && array[i].GetMiddleMark()
            <= upperMark  &&  array[i].GetMiddleMark() >= lowMark)
            array[i].DisplayStudent();
}

int ByFirstName(Student a, Student b)
{
    return strcmp(a.GetFirstName(), b.GetFirstName());
}

int BySecondName(Student a, Student b)
{
    return strcmp(a.GetSecondName(), b.GetSecondName());
}

int ByFuculty(Student a, Student b)
{
    return strcmp(a.GetFuculty(), b.GetFuculty());
}

int ByMiddleMarkIncrease(Student a, Student b)
{
    return a.GetMiddleMark()-b.GetMiddleMark();
}

int ByMiddleMarkDecrease(Student a, Student b)
{
    return b.GetMiddleMark()-a.GetMiddleMark();
}

void Swap(Student &a, Student &b)
{
    Student help = a;
    a = b;
    b = help;
}

void BubbleSort(Student* a, int size, Comparer comparer)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = size - 1; j >= i; j--)
        {
            if (comparer(a[j], a[j - 1]) < 0)
            {
                Swap(a[j], a[j - 1]);
            }
        }
    }
}

void ChoiceSort(Student* a, int size, Comparer comparer)
{
    for (int i = 1; i <= size - 1; i++)
    {
        int max = i - 1;
        for (int j = i - 1; j <= size - 1 ; j++)
            if (comparer(a[j],a[max]) < 0)
                max = j;
        Swap(a[i - 1], a[max]);
    }
}

void ShakerSort(Student* a, int size, Comparer comparer)
{
    int previous = 1;
    int next = size - 1;
    while (previous <= next)
    {
        for (int i = next; i >= previous; i--)
            if (comparer(a[i - 1],a[i]) > 0) Swap(a[i], a[i-1]);
        previous++;
        for (int i = previous; i <= next; i++)
            if (comparer(a[i - 1],a[i]) > 0) Swap(a[i], a[i - 1]);
        next--;
    }
}

void QuickSort(Student* a, int left, int right, Comparer comparer)
{
    int i = left, j = right;
    Student middle = a[(left + right) / 2];
    while (i <= j)
    {
        while (comparer(a[i], middle) < 0)
            i++;
        while (comparer(a[j], middle) > 0)
            j--;
        if (i <= j)
        {
            Swap (a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(a, left, j, comparer);
    if (i < right)
        QuickSort(a, i, right, comparer);
}

void QuickSort(Student* a, int size, Comparer comparer)
{
    QuickSort (0, size - 1, comparer);
}

int StudentSearch(Student* a, int size, Student x)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == x) return i;
    }
    return -1;
}
