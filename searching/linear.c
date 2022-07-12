#include <stdio.h>

int search(int *arr, int key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
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
    int index = search(arr, key, sizeof(arr) / sizeof(arr[0]));
    printf("%d\n", index);
    return 0;
}