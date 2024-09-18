#include <stdio.h>
#include <stdlib.h>
#include "register.h"
int main(int argc, char* argv[]){
    if(atoi(argv[argc-1])!=1&&atoi(argv[argc-1])!=2&&atoi(argv[argc-1])!=3){//checks to see if the final command is not 1, 2, or 3
        printf("Run the program with a list of input file, followed by the\ncalculation to perform\n./register file_name.txt ... option\nwhere file_name.txt ... is a list of files to process\nand option is one of the following:\n1: Output the monthly sales of an item.\n2: Calculate the total sales for each item and save to sales.txt\n 3: Find the most popular item");
    }
    
    int numFiles = argc-2;
    FILE *allFiles[numFiles];//array of all files
    char* nameFiles[numFiles];
    int data[50*numFiles][2];//2D array with 2 columns and 50*numFiles rows, since there are 50 rows per file
    for(int i=0;i<numFiles;i++){//for each file in the command line

     allFiles[i] = fopen(argv[i+1],"r");//start reading from the first file
     nameFiles[i] = argv[i+1];
         
    for (int j = 0; j < 50; j++)//for each row in the file
    {
        int rowIndex = i * 50 + j;//code pulled from the video lecture to properly assign data to a 2D array
        (fscanf(allFiles[i], "%d %*s %d", &data[rowIndex][0], &data[rowIndex][1]));//skips over the middle column in the data files. Gives the proper values to the correct rows and columns in the data 2d array.
    }
    fclose(allFiles[i]);//closes this specific file and prepares to open the next one
    }
        
    

   if(atoi(argv[argc-1])==1){//if final user input was one
    print_item(50*numFiles, 2, data, nameFiles);//call print_item
   }
   else if(atoi(argv[argc-1])==2){//was two
    total_sales(50*numFiles, 2, data);//call
   }
   else{//was three
    top_overall(50*numFiles, 2, data);//call
   }

}