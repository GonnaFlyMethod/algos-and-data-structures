#include <iostream>


using namespace std;


void bubble_sort(int *arr, int length_of_arr)
{
    for(int i=0; i < (length_of_arr - 1); i++)
    {
        for(int j=0;j < ((length_of_arr - i) - 1); j++)
        {
            if(arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void print_array_of_ints(int *arr, int length_of_arr)
{
    cout << "<Array> {";

    for(int i=0;i < length_of_arr;i++)
    {
        cout << arr[i] << " ";
    }

    cout << "}";
}


int main()
{
    int test_arr[] = {5, 4, 10, 2, 1, 3, 7, 6, 9, 8};
    int length_of_arr = sizeof(test_arr) / sizeof(test_arr[0]);
    bubble_sort(test_arr, length_of_arr);
    print_array_of_ints(test_arr, length_of_arr);
    return 0;
}
