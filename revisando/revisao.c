#include <stdio.h>

int main(){
    int i, a, b;
    void troca(int *x, int*y);
    scanf("%d %d", &a, &b);
    printf("i = %d, a = %d, b = %d\n", i, a, b);
    troca(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    printf("Hello, world!\n");

    for(i=0;i<10;i++){
        printf("%d\n", i);
    }
    return 0;
}

void troca(int *x, int*y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}