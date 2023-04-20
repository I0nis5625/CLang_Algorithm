#include <stdio.h>
#include <stdlib.h>

int binary_search(int a[], int n, int key){
    int first = 0; //검색하고자 하는 배열의 맨 처음 인덱스
    int last = n - 1; //검색하고자 하는 배열의 맨 마지막 인덱스
    do{
        int center = (first + last) / 2; //검색을 수행한 중앙값은 범위의 첫값과 마지막 값의 평균값이다.(소수점은 자동으로 버림 처리)
        if(a[center] == key) //만약 찾으려는 값이 배열의 중앙에 있는 경우
        return center; //그 중앙값을 반환한다.

        else if(a[center] < key) //찾으려는 값이 배열의 중앙보다 높은 값인 경우
        first = center + 1; //검색 범위를 처음 지정한 중앙 값보다 높게 지정하기 위해 중앙의 인덱스에서 +1한 값을 first 변수에 넣는다.

        else if(a[center] > key) //찾으려는 값이 배열의 중앙보다 낮은 값인경우
        last = center - 1; //검색 범위를 처음 지정한 중앙 값보다 낮게 지정하기 위해 중앙의 인덱스에서 -1 해준 값을 last 변수에 넣는다. 
    } while(first <= last); //last가 first보다 크거나 같은 경우까지 이를 계속 반복한다.

    return -1; //실패한 경우이므로 -1값을 반환한다.
}

int main(){
    int number, key; //배열 원소의 개수와 찾으려는 숫자를 입력한다.

    printf("Binary Search\n");
    printf("Number of elements : ");
    scanf("%d", &number);

    int *array = calloc(number, sizeof(int)); //숫자를 입력할 배열을 동적 할당을 이용해 지정해준다.

    printf("Enter the value in ascending order\n");

    for(int i = 0 ; i < number ; i++){ //배열의 처음부터 끝까지 값을 입력한다.
        printf("array[%d] : ", i);
        scanf("%d", &array[i]);

        if(i >= 1 && array[i] < array[i - 1]){ //처음의 i = 0인 경우 제대로 된 판별이 이루어지지 않으므로 제외하고 배열의 뒤 값이 더 큰 경우를 조건으로 지정한다.
            printf("Values are not in ascending order\n"); //배열의 뒤 값이 더 큰 경우 오름차순 정렬이 아니므로
            printf("Open the program and try again\n");
            exit(1); //현재 실행되고 있는 프로세스를 바로 종료한다(stdlib.h에 포함)
        }
    }

    printf("Value try to search : ");
    scanf("%d", &key);

    int result = binary_search(array, number, key); //현재 지정된 배열과 원소의 개수, 키값을 이진 검색 함수에 넘겨준다.

    if(result == -1)
    printf("Search Failed\n");

    else
    printf("%d is in array[%d]\n", key, result);

    free(array); //동적 할당해준 배열을 해제해준다.
}