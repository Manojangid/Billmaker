#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<dirent.h>
#include<dos.h>
#include<conio.h>
 COORD coord={0,0};
void welcome();

struct Items
{
    char product[20];
    int quantity;
    float price;
}del[5];

int main()
{
     welcome();

     int ch,size = 0;
     FILE *fptr;
     FILE *sf;
     FILE *renme;
     FILE *data;
    char con,home,bill_name[20],search_bill[20],shop_name[50];
    int Choice,i,no_products;
    float sum=0;


      menu :  system("cls");
     gotoxy(25,5); printf("\t\tWELCOME\n");
     gotoxy(25,6);  printf("------------------------------------------\n");
     gotoxy(25,7);   printf("\t\bBILL MAKER SOFTWARE\n");
     gotoxy(25,8);  printf("------------------------------------------\n");
     gotoxy(25,9); printf(" Choose Option : \n");
     gotoxy(25,10);  printf(" 1. Make new bill\n");                                                 //Display Part
     gotoxy(25,11);  printf(" 2. View exiting bills\n");
     gotoxy(25,12);  printf(" 3. Open/Search bills\n");
     gotoxy(25,13);  printf(" 4. Advance\n");
     gotoxy(25,14);  printf(" 5. Settings\n");
     gotoxy(25,15);  printf(" 6. About us\n");
     gotoxy(25,16);  printf(" 7. Exit\n");
     gotoxy(25,17);  printf("------------------------------------------\n");
     gotoxy(25,18);  printf("Enter your option : ");
     gotoxy(45,18);  scanf("%d",&Choice);

    switch(Choice)  //1st switch case
    {
    case 1:
        {
             system("cls");
              printf("Note : Spaces and Special characters(!,@,#,$,%,^,&,*) are not allowed!\n");
              printf("_______________________________________________________________\n");

             printf("Enter name of Bill (e.g. xyzabc) : ");
             scanf("%s",bill_name);
               if((fptr = fopen(bill_name,"w+"))==NULL)
               {
                    printf("Error in making bill\nFor more information goto Help tab\n");
                    exit(1);
               }                                              //case 1
            system("cls");
            printf("Bill name : %s\tLocation of file : %s\n",bill_name,__FILE__);
            printf("Tips : Use Tab button(Double) for separate(Items, Quantity, Price)\n");
             printf("_______________________________________________________________\n");
            printf("Enter number of Products/Items : ");
            scanf("%d",&no_products);
            printf("Items\t\tQuantity\tPrice\n");

               for(i=0;i<no_products;i++){
                    scanf("%s\t%d\t%f",del[i].product,&del[i].quantity,&del[i].price);
                         }
             data = fopen("Data","r");
             fscanf(data,"%s",shop_name);
             fclose(data);
            fprintf(fptr,"\t\t%s\n\n",shop_name);
            fprintf(fptr,"\t\tRECEIPT\n");
            fprintf(fptr,"TIME : %s\t\tDATE : %s\n",__TIME__,__DATE__);
            fprintf(fptr,"---------------------------------------------------------------------\n");
            fprintf(fptr," Items\t\tQuantity\t\tPrice\n");
            fprintf(fptr,"---------------------------------------------------------------------\n");
               for(i=0;i<no_products;i++){
            fprintf(fptr,"%d. %s\t\t%d\t\t%.2f INR.\n",i+1,del[i].product,del[i].quantity,del[i].price);
                sum = sum + del[i].price;
                  }
            fprintf(fptr,"-----------------------------------------------------------------------\n");
            fprintf(fptr,"\t\t\tTotal : %.2f\n",sum);
            fprintf(fptr,"-----------------------------------------------------------------------\n");
            fprintf(fptr,"\t Thanks for shopping\n");
            fclose(fptr);
            printf("\nAdd Successfully!\n");
            printf("Please wait for 3 seconds...\n");
          Sleep(4000);
          goto menu;
}
        break;
    case 2:
        {
              system("cls");
              printf("Available Bills\n");
              printf("_______________________________________________________________\n");
               DIR *d;
               struct dirent *dir;
               d = opendir(".");
               if(d)
               {
                         while((dir = readdir(d))!=NULL)
                         {
                              printf("%s\n",dir->d_name);
                         }
                         closedir(d);
               }
               printf("\n\nBack to Homepage, press 1\n");
               scanf("%d",&home);
               if(home == 1)

                    goto menu;
               else{
                         printf("You Entered invalid key!\n");
                              printf("Please wait for 3 seconds...\n");
                              Sleep(4000);
                              goto menu;
               }
               getch();
        }
                    break;
    case 3:
         {
              system("cls");
             printf("Note : Spaces and Special characters(!,@,#,$,%,^,&,*) are not allowed!\n");
              printf("_______________________________________________________________\n");
              printf("Enter name of Bill/file (e.g xyzabc) : ");
              scanf("%s",search_bill);

              sf = fopen(search_bill,"r");
              if((sf = fopen(search_bill,"r"))==NULL)
              {
                printf("Bill/File not found!\n");

                getch();
              }
              else{
                  sf = fopen(search_bill,"r");
                    system("cls");                                                        //case 3
              printf("Bill name : %s\n",search_bill);
              printf("_______________________________________________________________\n");

               while(ch!=EOF)
               {
               ch=fgetc(sf);
               printf("%c",ch);

               }
               fseek(sf, 0, 2);
               size = ftell(sf);
               printf("\nSize of bill : %d bytes\n",size);
               printf("Location of File : %s\n",__FILE__);
               fclose(sf);

                getch();

              }

         }
     break;
      case 4: //advance option
         {
              sos:
              system("cls");

               gotoxy(25,5); printf("\t\tWELCOME\n");
               gotoxy(25,6);  printf("------------------------------------------\n");
               gotoxy(25,7);   printf("\t\bBILL MAKER SOFTWARE\n");
               gotoxy(25,8);  printf("------------------------------------------\n");
               gotoxy(25,9); printf(" Choose Option : \n");
               gotoxy(25,10);  printf(" 1. Edit bill\n");
               gotoxy(25,11);  printf(" 2. Rename\n");
               gotoxy(25,12);  printf(" 3. Delete\n");
               gotoxy(25,13);  printf(" 4. Back\n");
               gotoxy(25,16);  printf("------------------------------------------\n");
               gotoxy(25,17);  printf("Enter your option : ");
               gotoxy(45,17);  scanf("%d",&Choice);
                                                                                   //Advance

                switch(Choice)     //2nd switch case
                {
                case 1:
                    {
                         system("cls");
                         printf("Currently not available \n");
                         //edit bill
                         printf("Please wait for 3 seconds...\n");
                         Sleep(4000);
                         goto menu;
                         break;
                    }
               case 2:
                    {
                         char old_bill[20],new_bill[20];
                         //Rename of bill
                         system("cls");
                         printf("Enter exiting bill name : ");
                         scanf("%s",old_bill);
                         if( (renme = fopen(old_bill,"r"))==NULL)
                         {
                              perror("Error : ");
                              printf("Please wait for 3 seconds...\n");
                              Sleep(4000);
                              goto menu;
                         }
                         else{
                         printf("Enter new name : ");
                         scanf("%s",new_bill);
                         rename(old_bill,new_bill);
                         printf("\nName is changed\n");
                         printf("Please wait for 3 seconds...\n");
                         Sleep(4000);
                         goto menu;
                         }
                         break;
                    }
                    case 3:
                    {
                         //Delete bill
                         char remove_bill[20];
                         system("cls");
                          printf("Note : Please enter in this format e.g xyz (Space not allowed)\n");
                         printf("_______________________________________________________________\n");
                          printf("Enter name of bill for delete : ");
                          scanf("%s",remove_bill);
                          if(remove(remove_bill)==0)
                          {
                               printf("\nDeleted successfully\n");
                               printf("Please wait for 3 seconds...\n");
                              Sleep(4000);
                              goto menu;
                          }
                          else{
                              printf("Unable to delete bill\nThis is because %s is not exist\n",remove_bill);

                               printf("Please wait for 5 seconds...\n");
                              Sleep(5000);
                              goto menu;
                          }
                         break;
                    }
                    case 4:
                    {
                         //back
                         goto menu;
                         break;
                    }
                    default:
                         {
                              printf("\nInvalid Option!\n");
                              printf("Please wait for 3 seconds and try again...");
                              Sleep(4000);
                             goto sos;
                         }
                }
         }break;
     case 5:
     {
          //Settings
          system("cls");

               gotoxy(25,5); printf("\t\tWELCOME\n");
               gotoxy(25,6);  printf("------------------------------------------\n");
               gotoxy(25,7);   printf("\t\bBILL MAKER SOFTWARE\n");
               gotoxy(25,8);  printf("------------------------------------------\n");
               gotoxy(25,9); printf(" Choose Option : \n");
               gotoxy(25,10);  printf(" 1. Edit Shop name on bill\n");                                                 //Display Part
               gotoxy(25,11);  printf(" 2. Edit Phone number\n");
               gotoxy(25,12);  printf(" 3. Change title\n");
               gotoxy(25,13);  printf(" 4. Back\n");
               gotoxy(25,16);  printf("------------------------------------------\n");
               gotoxy(25,17);  printf("Enter your option : ");
               gotoxy(45,17);  scanf("%d",&Choice);

                    switch(Choice)
                    {
                  case 1:
                    {

                         system("cls");

                          data = fopen("Data","w");
                         printf("Enter your shop name : ");
                         scanf("%s",shop_name);
                         fprintf(data,"%s",shop_name);
                           fclose(data);
                         printf("\nYour shop name is change\n");
                         break;
                    }
                  case 2:
                    {
                        system("cls");
                         printf("This feature currently not available \n");
                         printf("Please wait for 3 seconds...\n");
                         Sleep(4000);
                         goto menu; //Edit number
                         break;
                    }
                    case 3:
                    {
                         //Edit title
                         system("cls");
                         printf("This feature currently not available \n");
                         printf("Please wait for 3 seconds...\n");
                         Sleep(4000);
                         goto menu;
                         break;
                    }
                    case 4:
                    {
                         goto menu;
                         break;
                    }
                    }

          break;
     }
     case 6:  //About Us
     {
     system("cls");
      break;
     }
    case 7:
         {
               exit(1);
               break;
         }

     default:
          {

                    printf("Invalid Option!\n");
                    printf("Please wait for 3 seconds and try again...");
                    Sleep(4000);
                    goto menu;
          }
    }
return 0;
}
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 welcome()
 {
      int a = 176,b= 177,c=178,d,e;

      system("cls");

for(d=1;d<=8;d++)
{
    gotoxy(26,4); printf("Welcome\n");
   gotoxy(28,6);  printf("\n\t\t\tPlease wait");
    gotoxy(28,7);printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
    gotoxy(28,6); printf("\n\t\t\tPlease wait");
    gotoxy(28,7);printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",c,a,a,a,a,a,a,a,a,a,a);
   gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
    gotoxy(28,6); printf("\n\t\t\tPlease wait.");
     gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",b,c,a,a,a,a,a,a,a,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
    gotoxy(28,6); printf("\n\t\t\tPlease wait..");
     gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",b,b,c,a,a,a,a,a,a,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
   gotoxy(28,6); printf("\n\t\t\tPlease wait...");
    gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,c,a,a,a,a,a,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
   gotoxy(28,6); printf("\n\t\t\tPlease wait");
    gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,a,b,b,c,a,a,a,a,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
    gotoxy(28,6); printf("\n\t\t\tPlease wait..");
    gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,b,b,c,a,a,a,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
   gotoxy(28,6); printf("\n\t\t\tPlease wait...");
    gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,b,b,c,a,a,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
   gotoxy(28,6); printf("\n\t\t\tPlease wait");
    gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,b,b,c,a,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
   gotoxy(28,6); printf("\n\t\t\tPlease wait.");
    gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,b,b,c,a,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
   gotoxy(28,6); printf("\n\t\t\tPlease wait.");
   gotoxy(28,7); printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,b,b,c,a);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    gotoxy(26,4); printf("Welcome\n");
   gotoxy(28,6); printf("\n\t\t\tPlease wait..");
    gotoxy(28,7);printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,b,b,c);
    gotoxy(15,12); printf("(C) Copyright 2018. All Rights Reserved.\n");
    Sleep(100);
    system("cls");


    }
 }


