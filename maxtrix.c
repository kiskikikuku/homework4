#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int** create_maxtrix(int row, int col);
void print_matrix(int** print_matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix_a, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main(){

    printf("[----- [Park Taehyun]  [2018068040] -----]\n");

    char command; // 명령 입력받는 문자
    int row, col; // 행렬수 저장할 변수
    srand(time(NULL)); // 랜덤 인자

    printf("Input row and col : ");
    scanf("%d %d", &row, &col); // 행렬 값 입력받기
    int **matrix_a = create_maxtrix(row, col); // 행렬 a 생성
    int **matrix_b = create_maxtrix(row, col); // 행렬 b 생성
    int **matrix_a_t = create_maxtrix(row, col); // 행렬 a_t 생성


    printf("Matrix Created.\n");

    if(matrix_a == NULL || matrix_b == NULL) {
        return -1;
    }
    
    do
    {
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");
        
        printf("Command = ");
        scanf(" %c", &command);

        switch (command)
        {
        case 'z': case 'Z' : 
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;

        case 'p' : case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n"); 
            print_matrix(matrix_b, row, col);
            break;

        case 'a': case 'A' : 
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;

        case 's' : case 'S' :
            printf("Subtract two matrices\n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't' : case 'T': 
            printf("Transpose matrix\n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        
        case 'm' : case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;

        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }
            
    } while (command != 'q' && command !='Q');
    
    return 1;
}

int** create_maxtrix(int row, int col){
    
    int** x = (int**) malloc(row*sizeof(int**));
    
    for (int i = 0; i < col; i++)
    {
        *(x+i) = (int*) malloc(col*sizeof(int*));
    }
    
    return x;
}

void print_matrix(int** print_matrix, int row, int col){

    for (int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            printf("%d ", *(*(print_matrix+i)+j));
        }
        printf("\n");
    }
}

int free_matrix(int** matrix, int row, int col){
    
    for (int i = 0; i < col; i++)
    {
        free(*(matrix+i));
    }

    free(matrix);
}

int fill_data(int** matrix, int row, int col){

    for (int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
           *(*(matrix+i)+j) = rand()%10;
        }
    }

}

int addition_matrix(int** matrix_a, int** matrix_b, int row, int col){
    for (int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
        }
        printf("\n");
    }

}

int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col){


}

int transpose_matrix(int** matrix_a, int** matrix_t, int row, int col){


}

int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col){



}