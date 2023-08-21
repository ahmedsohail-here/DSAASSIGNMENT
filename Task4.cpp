#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr2[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

void Insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void SelectingTheMedian(int arr3[], int arraySize)
{
    int mid_value, mid_value_even;

    float median; // Change int to float or double

    if (arraySize % 2 == 0)
    {
        mid_value = (arraySize) / 2;
        mid_value_even = mid_value + 1;
        median = static_cast<float>(arr3[mid_value_even - 1] + arr3[mid_value - 1]) / 2.0;
        cout << "The median of array is: " << median << endl;
    }
    else
    {
        median = static_cast<float>(arr3[(arraySize + 1) / 2 - 1]); // Cast to float here as well
        cout << "The median of array is: " << median << endl;
    }
}

int main()
{
    // Declaration
    ifstream in;
    string size, list1, element;

    // FileRead
    in.open("TestCases/Question_04/TestCases/TestCase_01.txt");

    // ErrorChecking
    if (!in.is_open())
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    getline(in, size);
    getline(in, list1);

    // CloseFile
    in.close();

    // TypeConversion
    int arraySize = stoi(size);

    // Declaration
    const int ARRAY_SIZE = arraySize;
    int arr[ARRAY_SIZE];

    // Initialization
    stringstream ss(list1);
    int num;

    // ReadingIntegersAndStoringThem
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        ss >> num;
        arr[i] = num;
        // Check if the next character is a comma, and if so, ignore it
        if (ss.peek() == ',')
            ss.ignore();
    }

    cout << "Array Size: " << arraySize << endl;
    cout << "Elements before sorting:";

    printArray(arr, ARRAY_SIZE);

    Insertion_sort(arr, ARRAY_SIZE);

    cout << "Element after sorting:";

    printArray(arr, ARRAY_SIZE);

    SelectingTheMedian(arr, ARRAY_SIZE);

    return 0;
}
