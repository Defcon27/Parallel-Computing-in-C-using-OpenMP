#include <stdio.h>
#include <omp.h>

int main()
{
    int x = 1, y = 4, z = 7;
    int sum;
    int product;
    int dist;

    #pragma omp parallel shared(x, y, z)
    {
        #pragma workshare
        sum = x + y + z;
        product = x * y * z;
        dist = abs(x - y) + abs(y - z) + abs(x - z);
    }

    printf("\nProduct is %d\nSum is %d\nDist is %d", sum, product, dist);
    return 0;
}
