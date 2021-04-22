#include<random>
#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

void heapify(float a[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(float a[], int n)
{ 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int Xuat(float a[], int n, string filename)
{
    ofstream fo(filename);
    if (fo.fail() == true)
        return 0;
    for (int i = 0; i < n; i++)
        fo << setw(10) << a[i];
    return 1;
}
int Nhap(float a[], int n, string filename)
{
    ifstream fi(filename);
    if (fi.fail())
        return 0;
    for (int i = 0; i < n; i++)
        fi >> a[i];
    return 1;
}
int main()
{
    int n = pow(10, 6);
    float* a = new float[n];
    string filename = "010_foat_Bang_Nhau.inp";
    Nhap(a, n, filename);
    heapSort(a, n);
    filename = "Thuc_Tang010.inp";
    Xuat(a, n, filename);
    delete a;
    return 0;
}