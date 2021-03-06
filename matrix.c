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

    char command; // 명령 입력 문자
    int row, col; // 행렬인자 저장할 변수
    srand(time(NULL)); // 랜덤 인자

    printf("Input row and col : ");
    scanf("%d %d", &row, &col); // 행렬 값 입력받기
    int **matrix_a = create_maxtrix(row, col); // 행렬 a 생성
    int **matrix_b = create_maxtrix(row, col); // 행렬 b 생성
    int **matrix_a_t = create_maxtrix(col, row); // 행렬 a_t 생성


    printf("Matrix Created.\n");

    if(matrix_a == NULL || matrix_b == NULL) {
        return -1;
    } // pre check - 행렬이 정상적으로 생성되었는지 확인
    
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
            fill_data(matrix_a, row, col); 
            fill_data(matrix_b, row, col); // 행렬 a, b에 값 채우기
            printf("Matrix Initialized\n"); 
            break;

        case 'p' : case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n"); 
            print_matrix(matrix_b, row, col); // 행렬 a, b 출력
            break;

        case 'a': case 'A' : 
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col); // 행렬 a+b 출력
            break;

        case 's' : case 'S' :
            printf("Subtract two matrices\n");
            subtraction_matrix(matrix_a, matrix_b, row, col); //행렬 a-b 출력
            break;
        case 't' : case 'T': 
            printf("Transpose matrix\n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row); // a의 전치행렬을 a_t에 대입 후 출력
            break;

        
        case 'm' : case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col); // a * a_t 의 값 출력
            break;
        
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col); // 행렬들에 할당했던 공간 해제
            break;

        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }
            
    } while (command != 'q' && command !='Q'); // q, Q가 들어오면 종료 (할당했던 공간 해제 후 종료된다.)
    
    return 1;
}

int** create_maxtrix(int row, int col){ 
    
   if (row <= 0 || col <= 0) {
      printf("Check the size of row and col!\n");
      return NULL;
   } // pre check
     
    int** x = (int**) malloc(row*sizeof(int*)); // 행에 대한 공간 할당
    
    for (int i = 0; i < row; i++)
    {
        x[i] = (int*) malloc(col*sizeof(int));
    } // 열에 대한 공간 할당

    
   if (x == NULL) {
      printf("Memory Allocation Failed.\n");
      return NULL;
   } // post check
    
    return x;
} // row행 col열의 정수형 행렬 공간을 할당, 1행의 주소를 반환한다.

void print_matrix(int** print_matrix, int row, int col){

    if(row<=0 || col <=0){
        printf("Please check the size of row and col before print matrix\n");
        return;
    } // pre check

    for (int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            printf("%d ", print_matrix[i][j]);
        }
        printf("\n");
    } // 중첩 for문으로 행렬 데이터 순차적으로 출력

    if(print_matrix == NULL){
        printf("Memory allocation failed\n");
        return;
    } // post check

    return;
} //행렬 시작주소와 행,열 갯수를 받아 출력하여준다.

int free_matrix(int** matrix, int row, int col){

    if(row<=0 || col <=0){
        printf("Please check the size of row and col before deallocation matrix\n");
        return -1;
    } // pre check
    
    for (int i = 0; i < row; i++)
    {
        free(*(matrix+i));
    } // 열에 대한 포인팅 해제

    free(matrix); // 행에 대한 포인팅 해제

    return 1;
} // 행렬에 할당했던 공간을 해제한다.

int fill_data(int** matrix, int row, int col){

   if (row <= 0 || col <= 0) {
      printf("Check the size of row and col before fill data\n");
      return -1;
   } // pre check

    for (int i = 0; i < row; i++)
        for(int j = 0; j< col; j++){
           matrix[i][j] = rand()%20;
    } // 0~19 사이의 값을 랜덤으로 채워넣기

     if (matrix == NULL) {
      printf("Memory Allocation Failed.\n");
      return -1;
   } // post check

   return 1;
} // 행렬의 시작주소, 행,열 갯수를 받아 무작위 한자리 정수로 채운다.

int addition_matrix(int** matrix_a, int** matrix_b, int row, int col){
    if (row <= 0 || col <= 0) {
      printf("Check the size of row and col before add data\n");
      return -1;
   } // pre check
    
    int** matrix_sum_temp = create_maxtrix(row, col); // 행렬 합을 저장할 임시 공간 할당
    
    for (int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            *(*(matrix_sum_temp+i)+j) = *(*(matrix_a+i)+j) + *(*(matrix_b+i)+j); 
        }
    } // (a+b)[i][j] = a[i][j] + b[i][j]

    
    if (matrix_a == NULL || matrix_b == NULL || matrix_sum_temp == NULL) {
      printf("Memory Allocation Failed.\n");
      return -1;
   } // post check

    print_matrix(matrix_sum_temp, row, col); // 결과 출력
    free_matrix(matrix_sum_temp, row, col); // 임시공간 할당 해제

    return 1;    
} // 두 행렬의 덧셈

int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col){
    int** matrix_sub_temp = create_maxtrix(row, col); // 행렬 차를 저장할 임시 공간 할당

    if(row<=0 || col <=0){
        printf("Please check the size of row and col before subtract matrix\n");
        return -1;
    } // pre check
    
    for (int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            *(*(matrix_sub_temp+i)+j) = *(*(matrix_a+i)+j) - *(*(matrix_b+i)+j); 
        }
    } // (a-b)[i][j] = a[i][j] - b[i][j]

    if (matrix_a == NULL || matrix_b == NULL || matrix_sub_temp == NULL) {
      printf("Memory Allocation Failed.\n");
      return -1;
   } // post check

    print_matrix(matrix_sub_temp, row, col);
    free_matrix(matrix_sub_temp, row, col);

    return 1;
} // 두 행렬의 뺄셈

int transpose_matrix(int** matrix_a, int** matrix_t, int row, int col){

    if(row<=0 || col <=0){
        printf("Please check the size of row and col before trans matrix\n");
        return -1;
    } // pre check

     for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            matrix_t[i][j] = matrix_a[j][i]; 
        }

    if (matrix_a == NULL || matrix_t == NULL) {
        printf("Memory Allocation Failed.\n");
        return -1;
         } // post check

    return 1;
} // 전치행렬 연산

int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col){ // a * a(t)

    if (row <= 0 || col <= 0) {
      printf("Check the size of row and col before multiply\n");
      return -1;
   } // pre check

    int** matrix_mul_temp = create_maxtrix(row, row);
    
    for (int row_a = 0; row_a < row; row_a++)
        for (int row_t = 0; row_t < row; row_t++){
            int temp_sum = 0;
            for (int i = 0; i < col; i++)
            {
                temp_sum += matrix_a[row_a][i]*matrix_t[i][row_t];
            }
            matrix_mul_temp[row_a][row_t] = temp_sum;
        } // 행렬 곱

    if (matrix_a == NULL || matrix_t == NULL || matrix_mul_temp == NULL) {
        printf("Memory Allocation Failed.\n");
        return -1;
         } // post check

    print_matrix(matrix_mul_temp, row, row);
    free_matrix(matrix_mul_temp, row, row);
    
    return 1;
} // 두 행렬의 곱셈