#include <stdio.h>

int search(int *arr, int key, int n)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    int key = 5;
    int index = search(arr, key, sizeof(arr)/sizeof(arr[0]));
    printf("%d\n", index);
    return 0;
}