#include <iostream>
#include <math.h>
using namespace std;

void printaheap(int arr[], int n)
{

    int en = n;
    int ct = 0;

    while (en > 0)
    {
        en = (int)(en / 2);
        ct++;
    }
    cout << endl
         << endl;
    int print = 0;
    for (int i = 0; i < ct; i++)
    {
        for (int z = 0; z < 2 * ((10 - i * 2)); z++)
        {
            cout << " ";
        }
        for (int j = 0; j < pow(2, i); j++)
        {
            if (print < n)
            {
                cout << "   " << arr[print] << "  ";
                print++;
            }
        }
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        printaheap(arr, n);
        heapify(arr, n, i);
        printaheap(arr, n);
    }
    cout << "Aqui acaba o build heap" << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        printaheap(arr, n);
        heapify(arr, i, 0);
        printaheap(arr, n);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int t = sizeof(arr);

    heapSort(arr, n);
}
