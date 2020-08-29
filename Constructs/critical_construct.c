#include <stdio.h>

int main()
{
    int stack[] = {1, 2, 3, 4, 5};
    int top = 5;
    int pop;
    int i;

    printf("\nStack Initial Declaration:\n");
    for (i = 0; i < top; i++){
        printf("%d ", stack[i]);
    }

    #pragma omp parallel shared(stack, top) private(pop)
    {
        #pragma omp critical
        //Pop Stack
        pop = stack[top];
        top = top - 1;
    }

    printf("\nStack after construct: \n");
    for (i = 0; i < top; i++){
        printf("%d ", stack[i]);
    }
    return 0;
}
