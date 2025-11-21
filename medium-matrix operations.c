#include <stdio.h>
#include <conio.h>

// Function to read matrix
void readMatrix(int r, int c, int a[r][c]) {
    printf("Enter elements of the matrix:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to print matrix
void printMatrix(int r, int c, int a[r][c]) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int r, int c, int a[r][c], int b[r][c], int result[r][c]) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Matrix Multiplication
void multiplyMatrix(int r1, int c1, int a[r1][c1], int r2, int c2, int b[r2][c2], int result[r1][c2]) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Matrix Transpose
void transposeMatrix(int r, int c, int a[r][c], int result[c][r]) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[j][i] = a[i][j];
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    // ------------ Input for First Matrix ------------
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    int A[r1][c1];
    readMatrix(r1, c1, A);

    // ------------ Input for Second Matrix ------------
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    int B[r2][c2];
    readMatrix(r2, c2, B);

    // ------------ Menu ------------
    int choice;
    printf("\nChoose an operation:\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose of Matrix A\n");
    printf("4. Transpose of Matrix B\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\n");

    switch(choice) {
        case 1:
            if(r1 == r2 && c1 == c2) {
                int add[r1][c1];
                addMatrix(r1, c1, A, B, add);
                printf("Result of Matrix Addition:\n");
                printMatrix(r1, c1, add);
            } else {
                printf("Matrix Addition not possible! Dimensions must match.\n");
            }
            break;

        case 2:
            if(c1 == r2) {
                int mul[r1][c2];
                multiplyMatrix(r1, c1, A, r2, c2, B, mul);
                printf("Result of Matrix Multiplication:\n");
                printMatrix(r1, c2, mul);
            } else {
                printf("Matrix Multiplication not possible! c1 must equal r2.\n");
            }
            break;

        case 3: {
                int tA[c1][r1];
                transposeMatrix(r1, c1, A, tA);
                printf("Transpose of Matrix A:\n");
                printMatrix(c1, r1, tA);
            }
            break;

        case 4: {
                int tB[c2][r2];
                transposeMatrix(r2, c2, B, tB);
                printf("Transpose of Matrix B:\n");
                printMatrix(c2, r2, tB);
            }
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
