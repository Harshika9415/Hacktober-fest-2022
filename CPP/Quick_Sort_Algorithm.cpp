#include <bits/stdc++.h>
using namespace std;
void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i == size - 1)
        {
            cout << " ";
        }
        else
        {
            cout << ",";
        }
    }
    cout << endl;
}

int partition(int Array[], int low, int high)
{
    int pivot = Array[low]; // taking the first element as the pivot element.
    int i = low + 1;        // Taking the element after the pivot element.
    int j = high;           // Taking the element which is at the end of  the array.
    int temp;               // used for the doing the swapping of the variables.
    do
    {
        while (Array[i] <= pivot) // we have to find  the element larger than pivot element .
        {
            i++;
        }
        while (Array[j] > pivot) // we have to find the element smaller than pivot element  .
        {
            j--;
        }
        if (i < j) // swapping of the element is done in when the i is less than j.
        {
            temp = Array[i];
            Array[i] = Array[j];
            Array[j] = temp;
        }

    } while (i < j);
    // Swap A[low] and A[j] for positioning the pivot element at the right place when sorting the array.
    temp = Array[low];
    Array[low] = Array[j];
    Array[j] = temp;
    return j;
}

void Quick_Sort(int Array[], int low, int high, int size)
{
    int partitionIndex; // Index of the pivot after partition.
    if (low < high)
    {
        partitionIndex = partition(Array, low, high);
        Quick_Sort(Array, low, partitionIndex - 1, size);  // sort left sub array.
        Quick_Sort(Array, partitionIndex + 1, high, size); // sort right sub array.
    }
}
int main()
{
    int size;
    cout << "Enter the Numbers of the elements in the array:- ";
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> array[i];
    }

    cout << "Unsorted Array:-" << endl;
    PrintArray(array, size);
    Quick_Sort(array, 0, size - 1, size);
    cout << "Sorted Array is:-" << endl;
    PrintArray(array, size);

    return 0;
}