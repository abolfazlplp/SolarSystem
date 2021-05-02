// RSKGDTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

using namespace std;

struct Indexes {
    int i=0;
    int j=0;
};

void ArrayReverse(int a[], int size) {
    if (size <= 1) {
        return;
    }
    else {
        int temp;
        int i = 0;
        temp = a[i];
        a[i] = a[size - 1];
        a[size - 1] = temp;
        ArrayReverse(&a[1], size - 2);
    }
}

Indexes FindCorrespondingIndexes(int a[][3], int b[], int index) {

    int bindex = b[index];
    int rows = sizeof(**a) / sizeof(a[0]);
    int cols = sizeof(a[0]) / sizeof(int);

    Indexes CorrespondingIndexes;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] == bindex) {
                CorrespondingIndexes.i = i;
                CorrespondingIndexes.j = j;
                break;
            }
        }
    }

    return CorrespondingIndexes;
}

int main()
{
    /*int arr[6] = { 45,56,21,87,73,63 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    ArrayReverse(arr, arrSize);

    for(int i=0; i< arrSize;i++)
    cout << arr[i];*/

    int x[2][3] = { {1,2,3},{4,5,6} };
    int y[6] = { 1,2,3,4,5,6 };

    Indexes CorIndexes =FindCorrespondingIndexes(x, y, 2);

    cout << CorIndexes.i << "," << CorIndexes.j;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
