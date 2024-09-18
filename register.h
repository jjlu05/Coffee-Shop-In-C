#ifndef REGISTER_H
#define REGISTER_H
#include <stdio.h>

/***************************************************
* void print_item(int rows, int cols, int data[][cols], char* nameList[])
* Prints the sales of an item of the user's choosing in the given months of the nameList
*
* Parameters:
* rows: the number of rows in data
* cols: the number of columns in the data
* data: A 2D array of the sales data
* nameList: the list of file name (subset of argv)
* Returns:
* Nothing
************************************************/
  void print_item(int rows, int cols, int data[][cols], char* nameList[]);
/***************************************************
* void total_sales(int rows, int cols, int data[][cols])
* Prints the total number of sales for every single item 0-49
*
* Parameters:
* rows: the number of rows in data
* cols: the number of columns in the data
* data: A 2D array of the sales data
* Returns:
* Nothing
************************************************/
    void total_sales(int rows, int cols, int data[][cols]);
/***************************************************
* void top_overall(int rows, int cols, int data[][cols])
* Prints the item with the most total sales across all months
*
* Parameters:
* rows: the number of rows in data
* cols: the number of columns in the data
* data: A 2D array of the sales data
* Returns:
* Nothing
************************************************/
    void top_overall(int rows, int cols, int data[][cols]);
   

#endif