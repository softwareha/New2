#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
//insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	printf("Sorted array:\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
//Quick sort
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high)
{
	int x = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1); 
}
void quicksort(int arr[], int low, int high)
{
	int temp[high - low + 1]; 
	int i = -1;
	temp[++i] = low; 
	temp[++i] = high;    
	while (i >= 0) {
		high = temp[i--];        
		low = temp[i--];
		int pi = partition(arr, low, high);
		if (pi - 1 > low) {
			temp[++i] = low;
			temp[++i] = pi - 1;
		}
		if (pi + 1 < high) { //;;p:1
			temp[++i] = pi + 1;
			temp[++i] = high;
		}
	}
}
//Selection sort
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}
//Merge sort
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],
			int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
void Clock()
{
            clock_t start_t, end_t;
           double total_t;
           int i;
           start_t = clock();
        for(i=0; i< 10000000; i++) {
           }
           end_t = clock();
           total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
           printf("Total time taken by CPU: %f\n", total_t );
  }
int main()
{
    int ans,ch,j;
    do
    {
        int range;
	printf("\nEnter range of your numbers to sort : ");
	scanf("%d",&range);
	int a[range];
    printf("\n1)Inserttion Sort \n2)Selection Sort \n3)Quick Sort\n4)Merge sort\n");
    int opt;
    printf("\nEnter your Choice : ");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1: 
         printf("Case?:\n");
         printf("1.Best case\n2.Average case\n3.Worst case\n4.Custom input\n");
         printf("Enter your choice: ");
         scanf("%d",&ch);
         switch(ch){
          case 1:
          for (int i = 0; i < range; i++) {
        a[i] = i;
      }
          insertionSort(a, range);
	  //printArray(a, range);
	    Clock();
	    break;
	   case 2:
	 for (int i = 0; i < range; i++)
          a[i]= rand();
	    insertionSort(a, range);
	    //printArray(a, range);
	    Clock();
	    break;
	    case 3:
	    j=range;
	    for (int i = 0; i < range; i++){
             a[i]= j;
             j--;
             }
	    insertionSort(a, range);
	    //printArray(a, range);
	    Clock();
	    break;
	     case 4:
	    printf("Enter array elements: \n");
	    for(int i=0;i<range;i++){
	      scanf("%d",&a[i]);
	      }
	    insertionSort(a,range);
	    printArray(a,range);
	    Clock();
	    break;
	   default:printf("No choice match");
	   }
	   break;
	case 2:  
	    printf("Case?:\n");
         printf("1.Best case\n2.Average case\n3.Worst case\n4.Custom input\n");
         printf("Enter your choice: ");
         scanf("%d",&ch);
         switch(ch){
          case 1:
          for (int i = 0; i < range; i++) {
        a[i] = i;
      }
         selectionSort(a, range);
	  //printArray(a, range);
	    Clock();
	    break;
	   case 2:
	 for (int i = 0; i < range; i++)
          a[i]= rand();
	    selectionSort(a, range);
	   // printArray(a, range);
	    Clock();
	    break;
	    case 3:
	 j=range;
	    for (int i = 0; i < range; i++){
             a[i]= j;
             j--;
             }
	   selectionSort(a, range);
	   // printArray(a, range);
	    Clock();
	    break;
	     case 4:
	    printf("Enter array elements: \n");
	    for(int i=0;i<range;i++){
	      scanf("%d",&a[i]);
	      }
	    selectionSort(a,range);
	    printArray(a,range);
	    Clock();
	    break;
	   default:printf("No choice match");
	   }
        break;
  case 3:
   printf("Case?:\n");
         printf("1.Best case\n2.Average case\n3.Worst case\n4:Custom input\n");
         printf("Enter your choice: ");
         scanf("%d",&ch);
         switch(ch){
          case 1:
          for (int i = 0; i < range; i++) {
        a[i] = i;
      }
         quicksort(a, 0, range - 1);
	 // printArray(a, range);
	    Clock();
	    break;
	   case 2:
	 for (int i = 0; i < range; i++)
          a[i]= rand();
	   quicksort(a, 0, range - 1);
	  //  printArray(a, range);
	    Clock();
	    break;
	    case 3:
	    j=range;
	    for (int i = 0; i < range; i++){
             a[i]= j;
             j--;
             }
	  quicksort(a, 0, range - 1);
	   //printArray(a, range);
	    Clock();
	    break;
	    case 4:
	    printf("Enter array elements: \n");
	    for(int i=0;i<range;i++){
	      scanf("%d",&a[i]);
	      }
	    quicksort(a,0,range-1);
	    printArray(a,range);
	    Clock();
	    break;
	    
	   default:printf("No choice match");
	   }
        break;
   case 4:
   printf("Case?:\n");
         printf("1.Best case\n2.Average case\n3.Worst case\n4:Custom input\n");
         printf("Enter your choice: ");
         scanf("%d",&ch);
         switch(ch){
          case 1:
          for (int i = 0; i < range; i++) {
        a[i] = i;
      }
        mergeSort(a, 0, range - 1);
	 // printArray(a, range);
	    Clock();
	    break;
	   case 2:
	 for (int i = 0; i < range; i++)
          a[i]= rand();
	   mergeSort(a, 0, range - 1);
	  //  printArray(a, range);
	    Clock();
	    break;
	    case 3:
	    j=range;
	    for (int i = 0; i < range; i++){
             a[i]= j;
             j--;
             }
	   mergeSort(a, 0, range - 1);
	   //printArray(a, range);
	    Clock();
	    break;
	    case 4:
	    printf("Enter array elements: \n");
	    for(int i=0;i<range;i++){
	      scanf("%d",&a[i]);
	      }
	 mergeSort(a, 0, range - 1);
	    printArray(a,range);
	    Clock();
	    break;
	    
	   default:printf("No choice match");
	   }
        break;
    default : printf("\nNo choice match");
    }
        printf("\nTo terminate the program press 0 otherwie you can enter any number : ");
        scanf("%d",&ans);
    } while(ans!=0);
	return 0;
}

