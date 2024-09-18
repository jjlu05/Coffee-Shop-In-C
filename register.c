#include <stdio.h>
#include <stdlib.h>
#include "register.h"
#include <math.h>
void print_item(int rows, int cols, int data[][cols], char* nameList[]){
    int userInput=0;//initializes the userInput variable to later take in input
    puts("Which item?");
    scanf("%d",&userInput);
    float numFiles = rows/50;
    for(int r=0; r<rows; r++){//for every row
        if(data[r][0]==userInput){//check condition if the item code is the same as userInput requested code
            
            printf("%s\t%d\n", nameList[(int)floor(r/50)],data[r][1]);//if so, print the file name the data is in, and the sales data itself
        }
    }
}
void total_sales(int rows, int cols, int data[][cols]){
    printf("Item\tSales\n");
    int testArray[50];//instantiate an array of size 50 which stores sales data for every item code
    for(int r=0; r<rows; r++){//for every row
        testArray[data[r][0]]+=data[r][1];//each item code 0-49 corresponds to an index within testArray, and the sales data for each item code gets incremented
    
    }
    for(int i=0;i<50;i++){
        printf("%02d\t%4d\n",i, testArray[i]);//print every item code and its corresponding sales data
    }
    
}
void top_overall(int rows, int cols, int data[][cols]){
    int totalSales[50]={0};//same as above except every index's value is set to zero. Don't know why but when testing this is what worked

    for (int r = 0; r < rows; r++) {
        totalSales[data[r][0]] += data[r][1];
    }

    int max = totalSales[0];//two variables which store max value and index of that max value
    int maxIndex = 0;
    for (int i = 1; i < 50; i++) {//for every item code
        if (totalSales[i] > max) {//if item code i's data is larger than the largest value so far, make that new value the max value and store the index of it
            max = totalSales[i];
            maxIndex = i;
        }
    }

    // Print the most popular item
    printf("The most popular item is item %d.\n", maxIndex);//prints the item code of the most popular item in data
}
    
