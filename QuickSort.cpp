#include<random>
#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
void swap(float& x, float& y);
int partition(float a[], int low, int high);
void quicksort(float a[], int low, int high);
int Xuat(float a[], int n, string filename);
int Nhap(float a[], int n, string filename);
int main()
{
    int n = pow(10, 6);
    float* a = new float[n];
    string filename = "010_foat_Bang_Nhau.inp";
    Nhap(a, n, filename);
    quicksort(a, 0, n - 1);
    filename = "float_Tang010.inp";
    Xuat(a, n, filename);
	return 0;
}
void swap(float& x, float& y)
{
	float a = x;
	x = y;
	y = a;
}
void quicksort(float a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);
        quicksort(a, low, pivot - 1);
        quicksort(a, pivot + 1, high);
    }
}
int partition(float a[], int low, int  high)
{
    float pivot = a[high];
    int left = low;
    int right = high - 1;
    while (true) 
    {
        while (left <= right && a[left] < pivot) 
            left++; //neu phan tu ben trai be hon moc, giu  nguyen vi tri
        while (left<=right && a[right] > pivot) 
            right--; //phan tu ben phai lon hon moc, giu nguyen vi tri
        if (left >= right) 
            break; 
        swap(a[left],a[right]); 
        left++; // left hien tai da xet . nen ++
        right--; // right hien tai da xet nen --
    }
    swap(a[left],a[high]);
    return left; 
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