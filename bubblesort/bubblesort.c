#include <stdio.h>
#include <time.h>

void printArray(int arr[20]){
	int i;
	printf("Array:[");
	for (i = 0; i < 20; i++){
	    printf("%d", arr[i]);
	    if (i!=19){
	    	printf(",");
	    }
	}
	printf("]\n");
}

int main(){
	int SortData[20];
	int copySortData[20];
	srand(0);
	int i;
	for (i = 0; i < 20; i++){
		int num = rand()%100;
	    SortData[i] = num;
	    copySortData[i] = num;
	}
	clock_t begin = clock();
	printArray(SortData);
	int comparisons = 0;
	int j;
	for (i=0; i<20;i++){
		for (j=0;j<19;j++){
			comparisons+=1;
			if (SortData[j] > SortData[j+1]){
				int temp = SortData[j+1];
				SortData[j+1] = SortData[j];
				SortData[j] = temp;
			}
		}
		printArray(SortData);
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Bubble sort 1: %d comparisons made, took %f seconds to run\n", comparisons, time_spent);

	clock_t begin2 = clock();
	printArray(copySortData);
	int sorted = 0;
	comparisons = 0;
	while(sorted==0){
		sorted = 1;
		for (i=0;i<19;i++){
			comparisons+=1;
			if (copySortData[i] > copySortData[i+1]){
				sorted = 0;
				int temp = copySortData[i+1];
				copySortData[i+1] = copySortData[i];
				copySortData[i] = temp;
			}
		}
		printArray(copySortData);
	}
	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("Bubble sort 2: %d comparisons made, took %f seconds to run", comparisons, time_spent2);

	printf("\nImprovement of %f seconds\n", time_spent-time_spent2);

	return 0;
}
