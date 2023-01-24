#include <stdio.h>
#include <limits.h>

int inputInt(int maxVal, int minVal){
    long long tempNum; 
    do{
        if (scanf("%12lld", &tempNum) && (getchar() == '\n')){
                if (tempNum < maxVal && tempNum > minVal){
                    printf("skaicius nuskaitytas\n");
                    return tempNum;
                } else{
                    printf("skaicius netelpa i rezius\n");
                }
            } else{
                printf("iveskite skaiciu!!\n");
                scanf("%*[^\n]");
            }

    }while (1);
}

void seeMatrix(int *matrix, int n){
    printf("\n");

    for(int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            printf("%5d ", matrix[i*n + j]);
        printf("\n");
    }
            
    printf("\n");
}

int isBiggest(int arr[], int targetNum, int arrLength, int place){

    for (int i=0; i < arrLength; i++){
        if (targetNum < arr[i]){
            return 0;
        }
    }

    return 1;
}

int isSmallest(int arr[], int targetNum, int arrLength, int place){
    
    for (int i=0; i < arrLength; i++){
        if (targetNum > arr[i]){
            return 0;
        }
    }

    return 1;
}

int isBalnoPoint(int row, int column, int *matrix, int arrSize){

    int localMatrix[arrSize][arrSize];
    int tempArr[arrSize];

    for (int i=0; i < arrSize; i++)
        for (int j=0; j < arrSize; j++)
            localMatrix[i][j] = matrix[i*arrSize + j];
    
    // printf("\ndirbu su elementu %d, %d - %d\n", row, column, localMatrix[row][column]);

    // tikrinimas ar didziausias eiluteje ir maziausias stulpelyje
    
    for (int i=0; i < arrSize; ++i){
        tempArr[i] = localMatrix[row][i];
        // printf("%d ", tempArr[i]);
    }
    // printf("\n");
    
    if (isBiggest(tempArr, localMatrix[row][column], arrSize, row)){
        for (int i=0; i < arrSize; i++)
            tempArr[i] = localMatrix[i][column];
        
        if (isSmallest(tempArr, localMatrix[row][column], arrSize, column)){
            return 1;
        }
    }

    //tikrinimas ar maziausias eiluteje ir didziausias stulpelyje
    for (int i=0; i < arrSize; ++i)
        tempArr[i] = localMatrix[row][i];

    if (isSmallest(tempArr, localMatrix[row][column], arrSize, row)){
        for (int i=0; i < arrSize; i++)
            tempArr[i] = localMatrix[i][column];
        
        if (isBiggest(tempArr, localMatrix[row][column], arrSize, column)){
            return 1;
        }
    }
    return 0;
}



int main(){

    int n;

    printf("Iveskite N (N>0): ");
    n = inputInt(INT_MAX, 0);

    int matrix[n][n];

    printf("po viena iveskite %d elementu(-s) sudaryti matricai:\n", n * n);

    for(int i=0; i < n; i++){ 
        for(int j=0; j < n; j++){
            printf("eilute %d stulpelis %d: ", i+1, j+1);
            matrix[i][j] = inputInt(INT_MAX, INT_MIN);
        }
    }

    // seeMatrix((int *)matrix, n);


    printf("balno tasku koordinates:\n");

    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            if (isBalnoPoint(i, j, (int *)matrix, n))
                printf("(%d, %d) ", j, i);


            // printf("%d %s balno taskas\n", matrix[i][j], isBalnoPoint(i, j, (int *)matrix, n) ? "yra" : "nera");

}