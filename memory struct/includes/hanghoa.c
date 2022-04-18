#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include<windows.h> 
#include <stdlib.h>
#include<conio.h>
#include "hanghoa.h"

void enter_order(goods *input)
{
   printf("Enter commodity codes: ");
   gets(input->commodity_codes);
   printf("Enter Shirt: ");
   gets(input->shirt);
   printf("Enter style: ");
   gets(input->style);
   printf("Enter size: ");
   gets(input->size);
   printf("Enter number: ");
   scanf("%d",&input->number);
}
bool search(goods hh[], int n, char x[])
{
   for (int i = 0 ; i < n;i++)
      if ( strcmp(hh[i].commodity_codes, x) == 0)
         return true;
   return false;
}
void enter_list_order(goods hh[], int n)
{
   enter_order(&hh[0]);
   while(getchar() != '\n');
   for (int i = 1 ; i < n;i++)
   {
      do
      {
         printf("Enter commodity codes: ");
         gets(hh[i].commodity_codes);
         if ( search(hh, i , hh[i].commodity_codes) == true)
               printf("Ban da nhap trung ma hang hoa vui long nhap lai !\n");
      } while( search(hh,  i ,hh[i].commodity_codes) == true);
      printf("Enter Shirt: ");
      gets(hh[i].shirt);
      printf("Enter style: ");
      gets(hh[i].style);
      printf("Enter size: ");
      gets(hh[i].size);
      printf("Enter number: ");
      scanf("%d",&hh[i].number);
      while(getchar() != '\n');
   }
}
void setTable(goods *st, bool *check,  bool *check2, int i)
{
   char row = 205, col = 186, cornerL = 204, cornerR = 185, midd = 206;
   char cornerRR = 185, cornerLL = 204, middleSingle = 206;
   if ( *check == true )
   {
      for (int f = 0; f <= 98; f++)
      {
         if (f == 0) putchar(cornerLL);
         else if (f == 16) putchar(middleSingle);
         else if (f == 37) putchar(middleSingle);
         else if (f == 49) putchar(middleSingle);
         else if (f == 62) putchar(middleSingle); 
         else if (f == 82) putchar(middleSingle); 
         else if (f == 98) putchar(cornerRR); 
         else putchar(row);
      }
      *check = false;
   }
      printf("\n%c%-15d%c%-20s%c%-11s%c%-12s%c%-19s%c%-15d%c\n",col,i,col,st->commodity_codes,col,st->shirt,col,st->style,col,st->size,col,st->number,col);
      printf("%-16c%-21c%-12c%-13c%-20c%-16c%-16c\n",col,col,col,col,col,col,col);
      if ( *check2 == true)
      {
         for (int rd = 0; rd <= 98; rd++)
         {
            switch (rd)
            {
                  case 0:  putchar(cornerL);   continue;
                  case 16: putchar(midd);      continue;
                  case 37: putchar(midd);      continue;
                  case 49: putchar(midd);      continue;
                  case 62: putchar(midd);      continue;
                  case 82: putchar(midd);      continue;
                  case 98: putchar(cornerR);   continue;
                  default: putchar(row);
            }
         }
      }
      else
      {
         cornerL = 200; midd = 202; cornerR = 188;
         for (int rd = 0; rd <= 98; rd++)
         {
            switch (rd)
            {
                  case 0: putchar(cornerL);  continue;
                  case 16:putchar(midd);     continue;
                  case 37:putchar(midd);;    continue;
                  case 49:putchar(midd);     continue;
                  case 62:putchar(midd);     continue;
                  case 82:putchar(midd);     continue;
                  case 98:putchar(cornerR);  continue;
                  default:putchar(row); 
            }
         }
      }
}
void out_list_goods(list *gd)
{
   bool check = true, check2 = true;
   char cornerRR = 187, cornerLL = 201, middleSingle = 203, row = 205,col = 186;
   for (int f = 0; f <= 98; f++)
   {
      switch (f)
      {
            case 0:  putchar(cornerLL);           continue;
            case 16: putchar(middleSingle);       continue;
            case 37: putchar(middleSingle);       continue;
            case 49: putchar(middleSingle);       continue;
            case 62: putchar(middleSingle);       continue;
            case 82: putchar(middleSingle);       continue;
            case 98: putchar(cornerRR);           continue;
            default: putchar(row); 
      }
   }
   printf("\n%c%-15s%c%-20s%c%-11s%c%-12s%c%-19s%c%-15s%c\n",col,"STT",col,"Ma hang hoa ",col, "Ten ao ",col,"Kieu ao",col,"Size ao",col,"So luong",col);
   for (int i = 0 ; i < gd->n;i++)
   {
      if ( i == gd->n - 1 )
         check2 = false;
      setTable(gd->hh[i],&check,&check2,i + 1);
   }
}
void run_word(char str[][50], int idx)
{
   for (int i = idx ; i <= idx;i++)
   {
      for (int j = 0 ; j < strlen(str[i]);j++)
      {
         Sleep(30);
         printf("%c",str[i][j]);
      }
   }
}
void table()
{
   char cornerRR = 187, cornerLL = 201, row = 205,col = 186;
   char  cornerL = 200, cornerR = 188;
   int m = 1;
   char str[][50] = {
   "QUAN LY HANG HOA","0. Ket thuc", "1. Nhap so luong don hang",
   "2. Them thong tin don hang","3. In danh sach don hang",
   "4. Thong ke so luong hang hoa co trong danh sach",
   "5. Tim ma co trong danh sach","6. Sap xep danh sach theo ma",
   "7. In danh sach co so luong nhieu nhat",
   "8. Thong ke kieu x va size z"
   };
   printf("\t\t");
   yellow();
   for (int rd = 0; rd <= 50; rd++)
   {
      switch (rd)
      {
            case 0:  
            Sleep(20);
            putchar(cornerLL);   
            continue;
            case 50: 
            Sleep(20);
            putchar(cornerRR);   
            continue;
            default: 
            Sleep(20);
            putchar(row);
      }
   }
   reset();
   for (int i = 1; i <= 10;i++)
   {
      switch(i)
      {
         case 1: 
            yellow();
            printf("\n\t\t%c\t\t",col);
            red();
            run_word(str,0);
            Sleep(50);
            yellow();
            printf("%19c",col);
         continue;
         case 2:  
            printf("\n\t\t%c ",col); 
            green();
            run_word(str,1);
            yellow();
            printf("%38c",col); 
         continue;
         case 3:  
            printf("\n\t\t%c ",col); 
            green();
            run_word(str,2);
            yellow();
            printf("%24c",col);
         continue;
         case 4: 
            printf("\n\t\t%c ",col);
            green();
            run_word(str,3);
            yellow();
            printf("%23c",col);
            continue;
         case 5:  
            printf("\n\t\t%c ",col);
            green();
            run_word(str,4);
            yellow();
            printf("%25c",col);
            continue;
         case 6:  
            printf("\n\t\t%c ",col);
            green();
            run_word(str,5);
            yellow();  
            printf("%c",col);
            continue;
         case 7:   
            printf("\n\t\t%c ",col); 
            green();
            run_word(str,6);
            yellow();  
            printf("%21c",col);
            continue;
         case 8:   
            printf("\n\t\t%c ",col); 
            green();
            run_word(str,7);
            yellow();  
            printf("%21c",col); 
            continue;
         case 9:  
            printf("\n\t\t%c ",col); 
            green();
            run_word(str,8);
            yellow();
            printf("%11c",col);
            continue;
         case 10: 
            printf("\n\t\t%c ",col);  
            green();
            run_word(str,9);
            yellow();
            printf("%21c",col); 
            continue;
         default:
            Sleep(20);
            printf("\n\t\t%-50c%c",col,col);
      }
   }
   printf("\n\t\t");
   for (int rd = 0; rd <= 50; rd++)
   {
      switch (rd)
      {
            case 0: putchar(cornerL); Sleep(20); continue;
            case 50:putchar(cornerR); Sleep(20); continue;
            default: Sleep(20);  putchar(row); 
      }
   }
   reset();
   printf("\n");
}
void red () 
{
   printf("\033[1;31m");
}
void yellow ()
{
   printf("\033[1;33m");
}
void reset () 
{
   printf("\033[0m");
}
void green()
{
   printf("\033[0;32m");
}
void menu(list *st)
{
   int option;
   while(true)
   {
      system("cls");
      table();
      green();
      printf("\t\tInput option: ");
      scanf("%d",&option);
      reset();
      switch(option)
      {
         case 2: 
         {
            goods *as = (goods *)realloc(NULL,st->n);
            while(getchar() != '\n');
            enter_order(as);
            while(getchar() != '\n');
            st->hh[st->n] = as;
            st->n++;
         }
         break;
         case 3:
         {
            out_list_goods(st);
            printf("\n");
         }
         break;           
      }
      
   }
}
