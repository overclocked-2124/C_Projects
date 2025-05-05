//This is the program to perform bubble sort on a array

#include<stdio.h>
main(){
	int a[10],n,i,j,temp;
	printf("\n Enter the size of n:\n" );
	scanf("%d",&n);
	printf("\n Enter the array elements: \n");
	for(i=0;i<n-1;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n-1;i++) {
		for(j=0;j<n-i-1;j++){ 
			if(a[j]>=a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}	
}
