#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int i,j,n,ch,c;

int binary();
int print();
int linear();
int interpoloation();
int jump();

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
    printf("----------------------------------------------------------------------------\n");
    printf("-                                                                          -\n");
    printf("-                          DSA ASSIGNMENT                                  -\n");
    printf("-                                                                          -\n");
    printf("-       BINARY_SEARCH   LINEAR_SEARCH JUMP_SEARCH INTERPOLATION_SEARCH     -\n");
    printf("----------------------------------------------------------------------------\n");
    printf("\n");
    int cl = clock();
    double cll  = ((double)cl)/CLOCKS_PER_SEC;
    printf("Array Sorting time to Execute : %f Seconds\n",cll);
    printf("\n");
    printf("\n");
    while(1){
    
    printf("1.Binary Search\n");
    printf("2.Linear Search\n");
    printf("3.Interpolation Search\n");
    printf("4.Jump Search\n");
    printf("5.Print Array\n");
    printf("5.Exit\n\n");

    printf("Enter Choice....\n");
    scanf("%d",&ch);
    
        switch (ch){
        case 1: binary(arr);
                break;
        case 2: linear(arr);
                break;
        case 3: interpolation(arr);
                break;
        case 4: jump(arr);
                break;
        case 5: print(arr);
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
    printf("\n");
    int cl = clock();
    double cll  = ((double)cl)/CLOCKS_PER_SEC;
    printf("Binary search time : %f Seconds\n",cll);
    
}
int linear(int arr[]){
    int pos = 0;
    int num;
    printf("Enter to search Num:\n");
    scanf("%d",&num);
    for(i=0;i<100;i++){
        if (arr[i] == num){
            pos = i;
            printf("%d Found at %d.\n",num,pos);
            int cl = clock();
            double cll  = ((double)cl)/CLOCKS_PER_SEC;
            printf("Linear search time : %f Seconds\n",cll);
        }
        
    }
}
int interpolation(int arr[]){
    int l = 0 , h = 100 - 1, middle,num;
    printf("Enter number to search :\n");
    scanf("%d",&num);
    while(arr[h] != arr[l] && num >= arr[l] && num <= arr[h] ){
        middle = l +((num - arr[l]) * (h - l) / (arr[h] - arr[l]) );

        if ( num == arr[middle]){
            printf("Element Found At %d\n",middle);
            printf("\n");
            int cl = clock();
            double cll  = ((double)cl)/CLOCKS_PER_SEC;
            printf("Interpolation search time : %f Seconds\n",cll);
            break;
        }
        else if(num  < arr[middle]){
            h = middle - 1;
        }
        else{
             l  = middle +1;
        }
    }
}
int jump(int arr[]){
    int i,num,s,e,jump;
    printf("Enter number to search :\n");
    scanf("%d",&num);

    jump = sqrt(100);
    s = 0;
    e = s + jump;

    while(e < 100 && arr[e] <= num){
        s = e;
        e += jump;
        if(e > 100 -1){
            e = 100;
        }
    }
    for(i = s ; i < e ; i++ ){
        if (arr[i] == num){
            printf("Found At %d\n",i);
            printf("\n");
            int cl = clock();
            double cll  = ((double)cl)/CLOCKS_PER_SEC;
            printf("Interpolation search time : %f Seconds\n",cll);
        }
        
    }
}
int print(int arr[]){
    for (i = 0; i < 100; i++){
        printf("Element - %d : %d \n",i,arr[i]);

    }
}
