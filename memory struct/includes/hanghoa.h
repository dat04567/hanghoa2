#pragma once
#include<stdbool.h>
typedef struct goods
{
   char commodity_codes[20], size[20], style[20], shirt[20];
   int number;
} goods;
typedef struct list
{
   goods *hh[100]; // khai báo mảng một chiều các con trỏ sinh viên 
   int n;
} list;
void enter_order(goods *a);
bool search(goods [], int , char []);
void enter_list_order(goods [], int );
void setTable(goods *, bool *,  bool *, int );
void sort_by_code(goods [], int );
void statistical_style_x_in_style_z(goods[], int);
void out_list_goods(list *);
int max_number(goods [], int);
void table();
void red();
void yellow ();
void reset ();
void green();
void run_word(char [][50], int );
void menu(list *);

