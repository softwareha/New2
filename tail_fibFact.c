#include <stdio.h>
#include <time.h>
int factorial(int n) 
{
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}
int factorial_tail(int n, int acc) {
    if (n == 0) {
        return acc;
    } else {
        return factorial_tail(n-1, n*acc);
    }
}
int fib(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return fib(num - 1) + fib(num - 2); 
    }
}
// Tail Recursive Fibonacci
int fibonacci_tail_Recusive(int n,int prev1,int prev2)
{
    
    if(n<0) return -1;
    if(n==1||n==0) return prev2;
    return fibonacci_tail_Recusive(n-1,prev2+prev1,prev1);
}
int fibonacci_tail_Recusive_wrapper(int n)
{
    return fibonacci_tail_Recusive(n,1,1);
}
int main() {
    int choice, num,ch;
    clock_t start, end;
    double time_taken;

    while (1) {
        printf("1.Factorial\n2.Fibbonacci series\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
               printf("1.Without tail recursion\n2.With tail recursion\n");
                 printf("\nEnter your choice: ");
                scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                  printf("Enter a number: ");
                  scanf("%d", &num);
                  start = clock();
                  printf("\n\nFactorial of %d is %d\n", num, factorial(num));
                  end = clock();
                  time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
                  printf("\n\nTime taken by without tail recursion: %f seconds\n", time_taken);
                  break;
               case 2:
                printf("\n\nEnter a number: ");
                scanf("%d", &num);
                start = clock();
                printf("\n\nFactorial of %d is %d\n", num, factorial_tail(num, 1));
                end = clock();
                time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("\n\nTime taken by with tail recursion: %f seconds\n", time_taken);
                break;
            default:
                printf("\n\nInvalid choice. Please try again.\n");
                }
        break;
         case 2:
               printf("1.Without tail recursion\n2.With tail recursion\n");
                 printf("\nEnter your choice: ");
                scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                  printf("Enter the number of elements to be in the series : ");
                  scanf("%d", &num); 
                start = clock();
                 printf("%d\n",fib(num));
                  end = clock();
                  time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
                  printf("\n\nTime taken by without tail recursion: %f seconds\n", time_taken);
                  break;
               case 2:
                printf("Enter the number of elements to be in the series : ");
                  scanf("%d", &num); 
                start = clock();
                 printf("%d\n", fibonacci_tail_Recusive_wrapper(num));
                end = clock();
                time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("\n\nTime taken by with tail recursion: %f seconds\n", time_taken);
                break;            
            default:
                printf("\n\nInvalid choice. Please try again.\n");
        }
        break;
         default:
                printf("\n\nInvalid choice. Please try again.\n");
    }
    }
    return 0;
}

