#include <stdio.h>
int arr[50],n,l,r,mid,key,massage = 100;

int Key_Checker(){

    if(l > r){
       massage = -1;
       return massage;
    }

    if(arr[mid] == key){
        massage = 0;
        return massage;
    }
    else if(arr[mid] > key){
        massage = 1;
        return massage;
    }
    else if(arr[mid] < key){
        massage = 2;
        return massage;
    }
}

int Array_Devision_Function(){

    while(1){
        if(massage == 0){
            return massage;
        }
        else if(massage == -1){
            return massage;
        }
        else if(massage == 1){
            r = mid -1;
            mid = (l+r)/2;
            Key_Checker(mid);
        }
        else if(massage == 2){
            l = mid+1;
            mid = (l+r)/2;
            Key_Checker(mid);
        }

        mid = (l+r)/2;
        Key_Checker(mid);
    }
}




int main(void){

    printf("How many elements do you want?: ");
    scanf("%d",&n);
    if(n>50)
    printf("Not possible for element number greater than 50 !!!!!");
    printf("--------------Enter sorted array--------------\n");

    for(int i = 0; i<n; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d",&key);
    l = 0;
    r = n-1;
    Array_Devision_Function();

    if(massage == 0){
    printf("Element found successfully, present at index %d",mid);
    }
    else if (massage == -1)
    {
        /* code */
        printf("Element not present in the array");
    }


    return 0;
}