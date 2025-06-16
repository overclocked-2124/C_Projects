#include<stdio.h>

int Binary(int arr[],int low,int high,int target);



int main(){
    int arr[] ={1,2,3,4,5,6,7,8,9} , len,low,high,target;
    len=sizeof(arr)/sizeof(arr[0]);
    low=0;
    high=len-1;
    target = 5;
    printf("target is in posisition: %d",Binary(arr,low,high,target));
    return(0);
}



int Binary(int arr[],int low,int high,int target){
    if(low> high){
        return(-1);
    }
    int mid = (low+high)/2;

    if(arr[mid]==target){
        return(mid);
    }

    else if (arr[mid] > target){
        return Binary(arr, low, mid - 1, target);
    }
    else {
        return Binary(arr, mid + 1, high, target);
    }

}