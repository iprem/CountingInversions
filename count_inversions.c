#include <stdio.h>
#include <stdlib.h>

void MergeSort(long *, long, long, long*);
void CountInversions(long*, long, long, long, long*);
void display(long*, long, long);

int main(int argc, char **argv){
	
	long set[100000], *set2, val;
	FILE *fp;
	set2 = set;
	long i = 0, count = 0;
	
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Cannot read the file\n");
		exit(1);
	}
	printf("Hi\n");	
	while(fscanf(fp, "%li\n", &set[i++]) != EOF);	

	//display(set, 0 , i-2);
	MergeSort(set, 0, i-2, &count);
	//display(set,0,i-2);
	printf("Total number of inversions in the set = %li\n", count);

	exit(0);

}

void MergeSort(long *set, long i, long j, long *count){
	
	int mid = (i+j)/2;
	//printf("\nInside MergeSort %d\t%d\n",i,j);
	if(j>i)	{
		//printf("\nSet1 %d\t%d\n",i,mid);
		//display(set, i, mid);
		MergeSort(set, i , mid, count);
		//printf("\nSet2 %d\t%d\n",mid+1,j);
		//display(set, mid+1 , j);
		MergeSort(set, mid+1, j, count);
		//printf("\nGoto CountInversion\n");
		CountInversions(set, i, j, mid, count);
		//display(set, i, j);
	}
}

void CountInversions(long *set, long i, long j, long mid,long *count){
	
	long l1 = mid-i+1, l2 = j-mid;
	long k=0, x; 
	long temp1[l1], temp2[l2];
	for(x = 0; x<l1 ; x++)
		temp1[x] = set[i+x];
	for(x = 0; x<l2; x++)
		temp2[x] = set[mid+1+x];
	int l = 0, m = 0; k = i;
	while(l<l1 && m<l2){
		if(temp1[l] > temp2[m]){
			
			set[k] = temp2[m];
			*count += (l1 -l);
			m++;
		}
		else{
			set[k] = temp1[l];
			l++;
		}
		k++;
	}
	while(l < l1){
		set[k] = temp1[l];
		k++;
		l++;	
	}
	while(m < l2){
		set[k] = temp2[m];
		k++;
		m++;	
	}
	//printf("Ouside Loop %d\n",*count);
}		

void display(long *set, long i, long j){
	
	while(i <= j)	printf("%li \t", set[i++]);
	printf("\n");
}
