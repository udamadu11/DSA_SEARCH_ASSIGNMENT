#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i,j,n,ch;

int binary();
int print();
int linear();
int main(){
    int arr[100];
    int temp;
    
    for(i=0;i < 100;i++){
        arr[i] = rand() % 100 + 1;
    }

    for(i = 0 ; i < 100 ; i++){
        for (j = i+1; j < 100; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }
    printf("\n");
    int cl = clock();
    double cll  = ((double)cl)/CLOCKS_PER_SEC;
    printf("Sorting time to Execute : %f Seconds\n",cll);

    while(1){
    
    printf("1.Binary Search\n");
    printf("2.Linear Search\n");
    printf("3.Jump Search\n");
    printf("4.Binary Search\n");
    printf("5.Print Array\n");
    printf("5.Exit\n\n");

    printf("Enter Choice....\n");
    scanf("%d",&ch);
    
        switch (ch){
        case 1: binary(arr);
                break;
        case 2: linear(arr);
                break;
        case 3: print(arr);
                break;
        default: printf("Invalid Choice !!!\n");  
        }
    }
}
int binary(int arr[]){
    int first = 0,last ,middle,num;
    last = 100 -1;
    middle = (first + last)/2;

    printf("Enter Number To search...\n");
    scanf("%d",&num);

    while (first <= last){
        if (arr[middle] < num){
            first = middle + 1;
        }
        else if(arr[middle] == num){
            printf("%d Found at %d\n",num,middle);
        break;
        }
        else{
            last = middle - 1;
        }
        middle = (first + last)/2;
    }
    if (first > last){
            printf("Not Found\n");
        }
    
}
int linear(int arr[]){

}
int print(int arr[]){
    for (i = 0; i < 100; i++){
        printf("Element - %d : %d \n",i,arr[i]);
    }
}