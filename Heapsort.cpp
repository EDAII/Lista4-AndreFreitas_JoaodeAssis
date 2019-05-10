#include <iostream>
#include <math.h>
#include <vector>
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
                cout << "   [" << arr[print] << "]  ";
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
    cout<<"Primeiramente, fazemos o build Heap max"<<endl; 
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        printaheap(arr, n);
        heapify(arr, n, i);
        printaheap(arr, n);
    }
    cout << "Aqui acaba o build heap max" << endl;
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
    vector<int> top;
    cout<<"Informe quantos numeros você quer colocar no heap"<<endl;
    int t;
    cin>>t;
    cout<<"Informe os numeros:"<<endl;
    while(t--){
        int y;
        cin>>y;
        top.push_back(y);
    }

    int arr[top.size()];
    for(int i=0;i<top.size();i++){
        arr[i]=top[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);
}
