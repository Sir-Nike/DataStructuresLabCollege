#include <stdio.h>

int ToH(int rings)
{
    if (rings == 1) return 1;
    return 2*(ToH(rings-1)) + 1;
}

int main()
{
    int rings;
    printf("Enter number of rings: ");
    scanf("%d",&rings);
    printf("Number of steps to complete ToH: %d\n", ToH(rings));
}
