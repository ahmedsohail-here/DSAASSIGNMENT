#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void printArray(int arr2[], int size)
{

    for (int i = 0; i < size; ++i)
    {

        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Declaration
    ifstream in;
    string size, list1, element;
    const int time = 6;

    // FileRead
    in.open("TestCases/Question_03/TestCases/TestCase_01.txt");

    // ErrorChecking
    if (!in.is_open())
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    getline(in, element);
    getline(in, size);
    getline(in, list1);

    // CloseFile
    in.close();

    // TypeConversion
    int arraySize = stoi(size);
    int elementfind = stoi(element);
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
        
        if (ss.peek() == ',')
            ss.ignore();
    }

    printArray(arr, arraySize);

    cout << "Array Size: " << arraySize << endl;

    cout << "Element to find: " << elementfind << endl;

    bool found = false; // A flag to keep track if the element is found

    for (int i = 0; i < arraySize; i++)
    {
        if (elementfind == arr[i])
        {
            cout << "Element found at index: " << i << endl;
            found = true;
            break; // Once the element is found, exit the loop
        }
    }

    if (!found)
    {
        cout << "Element not found." << endl;
        return -1;
    }

    return 0;
}
