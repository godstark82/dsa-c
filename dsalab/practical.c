#include <stdio.h>
#include <stdlib.h>

//! CodeChef Qns
//! 1. Search in array [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/SEARCHINARR]
int searchInArray(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
        return -1;
    }
}

//! 2. Find Maximum in array [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/UWCOI20A]
int maxInArray(int arr[], int n)
{
    int maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return arr[maxIndex];
}

//! 3. Largest and Second Largest [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/LARGESECOND]
//? Printing the sum of largest and second largest in an array
//? We can also do it by sorting the array and get last two elements
int largestAndSecondLargestSum(int arr[], int n)
{
    int max = a[0];
    int maxIndex = 0;
    int secMax = -1;

    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != max && a[i] > secMax && i != maxIndex)
        {
            secMax = a[i];
        }
    }

    return (max + secMax);
}

//! 4. Cost of Groceries [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/KITCHENCOST]
int totalCostOfGrocery(int a[], int b[], int n)
{
    //? a -> Freshness, b[] -> Cost
    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= x)
        {
            cost = cost + b[i];
        }
    }

    return cost;
}

//! 5. Running Comparison [https://www.codechef.com/practice/course/arrays/ARRAYS/problems/RUNCOMPARE]
int runningComparison(int a[], int b[], int n)
{
    int bothHappyCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (b[i] > 2 * a[i] || a[i] > 2 * b[i])
        {
        }
        else
        {
            bothHappyCount++;
        }
    }

    return bothHappyCount;
}