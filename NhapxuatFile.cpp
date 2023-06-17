// NhapxuatFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

void docfile(const char fname[], int a[], int& n);
//can khai bao thu vien fstream
void docfile1(int a[], int& n);

int main()
{
    int a[100];
    int n;
    //docfile("D:\\docfile.txt", a, n);
    docfile1(a,n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

void docfile1(int a[], int& n)
{
    ifstream input("D:\\docfile.txt");

    if (input.fail())
    {
        cout << "Cant open file!";
        return;
    }
    else {
        input >> n;
        for (int i = 0; i < n; i++) {
            input >> a[i];
        }
    }

    input.close();
}

void docfile(const char fname[], int a[], int& n)
{
    //Buoc 1: Khai bao con tro FILE
    FILE* fp;
    //Buoc 2: Mo file
    fopen_s(&fp, fname, "rt");
    //Buoc 3: Kiem tra xem da mo file len duoc chua
    if (fp == NULL)
    {
        cout << "Cant open file!";
        return;
    }
    else {
        fscanf_s(fp, "%d", &n);
        for (int i = 0; i < n; i++) {
            fscanf_s(fp, "%d", &a[i]);
        }
    }

    fclose(fp);
}
