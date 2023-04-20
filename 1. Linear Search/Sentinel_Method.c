#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key)
{
    int i = 0;
    int a[n] = key;

    while(1){
        if(a[i] == key)
        break;;

        i++;
        
        return i = n ? -1 : i ;
    }
}

int main(){
    int number;
    int key;

    printf("Linear Search\n");
    printf("Number of Elements : ");

    scanf("%d", &number);

    int *array = calloc(number + 1, sizeof(int));

    for(int i = 0 ; i < number ; i++){
        printf("array[%d] : ", i);
        scanf("%d", &array[i]);
    }

    printf("Key : ");
    scanf("%d", &key);

    int result = search(array, number, key);
    if(result == -1)
    printf("Search Failed\n");

    else
    printf("%d is in : array[%d]", key, result);

    free(array);
}