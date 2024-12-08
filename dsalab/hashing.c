#include <stdio.h>

int hashFunction(int x, int n)
{
    return x % n;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int linear_hash[n] = {0};
        int quadratic_hash[n] = {0};

        int linear_collisions = 0;
        for (int i = 0; i < n; i++)
        {
            int index = hashFunction(arr[i], 13);
            if (linear_hash[index] == 0)
            {
                linear_hash[index] = arr[i];
            }
            else
            {
                linear_collisions++;
                int j = 1;
                while (linear_hash[(index + j) % n] != 0 && j < n)
                {
                    linear_collisions++;
                    j++;
                }

                linear_hash[(index + j) % n] = arr[i];
            }
        }

        int quadratic_collisions = 0;
        bool isQuadraticPossible = true;
        for (int i = 0; i < n; i++)
        {
            int index = hashFunction(arr[i], 13);
            if (quadratic_hash[index] == 0)
            {
                quadratic_hash[index] = arr[i];
            }
            else
            {
                int j = 1;
                while (quadratic_hash[(index + j * j) % n] != 0 && j * j < n)
                {
                    j++;
                    quadratic_collisions++;
                    if (j * j >= n)
                    {
                        isQuadraticPossible = false;
                        break;
                    }
                }
                if (isQuadraticPossible)
                {
                    quadratic_hash[(index + j * j) % 13] = arr[i];
                }
                else
                {
                    for (int k = 0; k < n; k++)
                    {
                        quadratic_hash[k] = 0;
                    }
                    break;
                }
            }
        }

        // print linear hash table
        for (int i = 0; i < 13; i++)
        {
            printf("%d ", linear_hash[i]);
        }
        printf("\n");
        bool doQuadContainsZero = false;

        for (int i = 0; i < n; i++)
        {
            if (quadratic_hash[i] == 0)
            {
                doQuadContainsZero = true;
            }
        }
        if (doQuadContainsZero == true)
            printf("Not Possible");
        else
            for (int i = 0; i < 13; i++)
            {
                printf("%d ", quadratic_hash[i]);
            }
        printf("\n");

        printf("Linear Probing Collisions: %d ", linear_collisions);
        printf("Quadratic Probing Collisions: %d\n", quadratic_collisions);
    }
    return 0;
}
