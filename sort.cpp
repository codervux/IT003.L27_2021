#include<algorithm>
#include<random>
#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
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
    sort(a, a + n);
    filename = "float_Tang010.inp";
    Xuat(a, n, filename);
    return 0;
}