#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include"car.h"
#include<time.h>

int main()
{
    int i,k,type,choice,result;
    user *usr;
    addAdmin();
    gotoxy(25,9);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(22,12);
    textcolor(GREEN);
    printf("*RENT A CAR AND GO WHEREVER YOU NEED* ");
    getch();
    clrscr();

   while(1)
   {
       clrscr();
       gotoxy(30,2);
       textcolor(RED);
       printf("CAR RENTAL SYSTEM");
       textcolor(YELLOW);
       gotoxy(1,6);
       for(i=0;i<80;i++)
         printf("*");
       textcolor(YELLOW);
       gotoxy(1,16);
       for(i=0;i<80;i++)
        printf("*");
       gotoxy(30,8);
       textcolor(GREEN);
       printf("1. ADMIN");
       gotoxy(30,10);
       printf("2. EMPLOYEE");
       gotoxy(30,12);
       printf("3. EXIT");
       gotoxy(30,14);
       textcolor(WHITE);
       printf("SELECT YOUR ROLE :");
         scanf("%d",&type);
          k=0;
       if(type==1)
       {
          do
          {
              usr=getinput();
              if(usr!=NULL)
               k=checkUserExist(*usr,"admin");
              else
                break;
          }while(k==0);
          if(k==-1)
            break;
          if(k==1)
         {
            gotoxy(30,20);
            textcolor(RED);
            printf("Press any key to continue");
            getch();

            while(1)
           {
             clrscr();
             choice=addMenu();
             if(choice==7)
             break;
            switch(choice)
            {
              case 1:
                clrscr();
                addEmployee();
                break;
              case 2:
                clrscr();
                addCar();
                break;
              case 3:
                clrscr();
                viewEmployee();
                break;
              case 4:
                clrscr();
                viewCar();
                break;
              case 5:
                clrscr();
                result=deleteEmp();
                gotoxy(25,13);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry! No emp found for given emp id");
                }
                else if(result==1)
                {

                    textcolor(LIGHTGREEN);
                    printf("Record deleted successfully!");
                }
                else if(result==2)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry! Error in deletion. Try again!");
                }
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to the main screen!");
                    getch();
                break;
               case 6:
                clrscr();
                result=deleteCar();
                gotoxy(25,13);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry! No car record found for given car id");
                }
                else if(result==1)
                {

                    textcolor(LIGHTGREEN);
                    printf("Car Record deleted successfully!");
                }
                else if(result==2)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry! Error in deletion. Try again!");
                }
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to the main screen!");
                    getch();
                break;
              default:
                printf("Incorrect choice");
                getch();
             }
          }

        }
       }


       else if(type==2)
        {
          do
          {
              usr=getinput();
              if(usr!=NULL)
               k=checkUserExist(*usr,"emp");
              else
                break;
          }while(k==0);
          if(k==-1)
            break;
          if(k==1)
         {
            gotoxy(30,20);
            textcolor(RED);
            printf("Press any key to continue");
            getch();
            while(1)
            {
               clrscr();
               choice=empMenu();
               if(choice==6)
                break;
               switch(choice)
               {
             case 1:
                clrscr();
                int rentresp;
                rentresp=rentCar();
                if(rentresp==-2)
                 {
                    gotoxy(35,9);
                    textcolor(LIGHTRED);
                    printf("Sorry! All cars booked. Try later");
                    getch();
                 }
                else if(rentresp==0)
                 {
                    gotoxy(27,18);
                    textcolor(LIGHTRED);
                    printf("You did not choose any car");
                    getch();
                  }

                break;
             case 2:
                clrscr();
                bookedCarDetails();
                break;
             case 3:
                clrscr();
                availableViewcar();
                break;
             case 4:
                clrscr();
                viewCar();
                break;
            case 5:
                clrscr();
                result=returnCardetails();
                gotoxy(25,19);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry! No car record found for given car details");
                }
                else if(result==1)
                {

                    textcolor(LIGHTGREEN);
                    printf("Bookoing Return Car Record deleted successfully!");
                }
                else if(result==2)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry! Error in deletion. Try again!");
                }
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to the main screen!");
                    getch();
                break;
             default :
                printf("Incorrect Choice");
                getch();
               }
            }
         }
        }
       else if(type==3)
        {
            clrscr();
            gotoxy(30,10);
            textcolor(LIGHTCYAN);
            printf("Thank for Using App:");
            getch();
            exit(0);
        }
        else
        {
            textcolor(LIGHTRED);
            gotoxy(30,20);
            printf("Invalid User Type");
           _getch();
            gotoxy(30,20);
            printf("\t\t\t\t\t");
            gotoxy(48,14);
            printf("\t\t\t");
            gotoxy(48,14);
            textcolor(WHITE);
         }
       //}while(1);
   }
}
