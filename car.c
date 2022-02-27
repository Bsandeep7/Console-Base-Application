#include<stdio.h>
#include"conio2.h"
#include"car.h"
#include<string.h>
#include<stdlib.h>
#include<time.h>
void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        FILE *fp=fopen("admin.bin","wb");
        user u[2]={{"admin","anil","abcd"},{"admin","sachin","abc"}};
        fwrite(u,sizeof(u),1,fp);
        printf("saved!");
        fclose(fp);
    }
    fclose(fp);

}

user *getinput()
{
    clrscr();
    int i;
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM \n");
    for(i=0;i<80;i++)
      printf("%c",247);
    gotoxy(32,5);
    printf("*LOGIN PANNEL*");
    textcolor(LIGHTCYAN);
    gotoxy(1,7);
     for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(1,16);
     for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(60,8);
    textcolor(RED);
    printf("Press 0 to exit");
    gotoxy(25,9);
    textcolor(LIGHTCYAN);
    printf("Enter user id:");
    fflush(stdin);
    static user usr;
    fgets(usr.userid,20,stdin);
    char *pos;
    pos=strchr(usr.userid,'\n');
    if(pos!=NULL)
    {
        *pos='\0';
    }
    if(strcmp(usr.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(32,19);
        printf("Login Cancelled");
        getch();
        return NULL;

    }
    gotoxy(25,10);
    textcolor(LIGHTCYAN);
    printf("Enter password:");
    fflush(stdin);
    i=0;
    textcolor(WHITE);
    for(;;)
    {
        usr.pwd[i]=_getch();
        if(usr.pwd[i]==13)
        {
            break;
        }
        printf("*");
        i++;
    }
    usr.pwd[i]='\0';
    if(strcmp(usr.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(32,20);
        printf("Login Cancelled");
        getch();
        return NULL;
    }
    return &usr;
    getch();
}
int checkUserExist(user u,char *usertype)
{
    if(strlen(u.userid)==0 || strlen(u.pwd)==0)
    {
      gotoxy(25,19);
      textcolor(RED);
      printf("Both field are mandtory. Try again:");
      getch();
      gotoxy(30,19);
       printf("\t\t\t");
      return 0;
    }
     FILE *fp;
    if(strcmp(usertype,"admin")==0)
    {
       fp=fopen("admin.bin","rb");
    }
    else
    {
        fp=fopen("emp.bin","rb");
    }
    if(fp==NULL)
    {
        gotoxy(30,19);
        textcolor(RED);
        printf("Sorry! Cannot open the file:");
        getch();
        gotoxy(30,19);
        printf("\t\t\t\t");
        return -1;
    }
    int found=0;
    user user;
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0)
        {
            found=1;
            break;
        }
    }
        if(found==0)
        {
            gotoxy(30,19);
            textcolor(RED);
            printf("Invalid user id or password!");
            getch();
            gotoxy(30,19);
            printf("\t\t\t");


        }
        else
        {
            gotoxy(30,19);
            textcolor(RED);
            printf("Login sucessfull!");
            getch();
            gotoxy(30,19);
            printf("\t\t\t");
        }
        fclose(fp);
        return found;


}
int addMenu()
{
    int i,choice;
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(35,5);
    textcolor(LIGHTGREEN);
    printf("ADMIN MENU \n");
    for(i=0;i<80;i++)
        printf("*");
    textcolor(YELLOW);
    gotoxy(32,7);
    printf("1.AddEmployee");
     gotoxy(32,8);
    printf("2.AddCarDetails");
     gotoxy(32,9);
    printf("3.ShowEmployee");
     gotoxy(32,10);
    printf("4.ShowCardetails");
     gotoxy(32,11);
    printf("5.DeleteEmployee");
     gotoxy(32,12);
    printf("6.DeleteCardtails");
     gotoxy(32,13);
    printf("7.Exit");
    gotoxy(32,15);
    printf("Enter Choice:");
    scanf("%d",&choice);

    return choice;

}
void addEmployee()
{
     char empid[10]="EMP-";
     char temp[10];
      char uchoice;
      char *pos;
     FILE *fp=fopen("emp.bin","ab+");
     fseek(fp,0,SEEK_END);
     long total_rec=ftell(fp)/sizeof(user);
     if(total_rec!=0)
     {
        fseek(fp,-90,SEEK_END);
        fread(temp,sizeof(temp),1,fp);
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);

     }
     total_rec++;
     sprintf(temp,"%ld",total_rec);
     strcat(empid,temp);

     user u;
     strcpy(u.userid,empid);
     do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for( i=0; i<80; i++)
        {
            printf("~");
        }
        textcolor(WHITE);
        gotoxy(25,5);
        printf("***** ADD EMPLOYEE DETAILS *****");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);

        pos=strchr(u.name,'\n');
        *pos='\0';
        textcolor(YELLOW);
        printf("Enter Employee Pwd:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        *pos='\0';
        textcolor(YELLOW);
        fseek(fp,0,SEEK_END);
        fwrite(&u,sizeof(user),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCCESSFULLY");
        printf("\n EMPLOYEE ID IS: %s",u.userid);
        _getch();
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do YOU WANT TO ADD MORE EMPLOYEE(Y/N) :");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&uchoice);
        total_rec++;
        strcpy(empid,"EMP-");
        sprintf(temp,"%ld",total_rec);
        strcat(empid,temp);
        strcpy(u.userid,empid);


    }
    while(uchoice=='Y'||uchoice=='y');
    fclose(fp);
}
void addCar()
{
    car c;
    int s;
    char uchoice;
    FILE *fp=fopen("car.bin","ab+");
    fseek(fp,0,SEEK_END);
    int total_car=ftell(fp)/sizeof(car);
    if(total_car!=0)
     {
        fseek(fp,-68,SEEK_END);
        fread(&s,sizeof(s),1,fp);
        total_car=s;

     }
    total_car++;
    c.car_id=total_car;
    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        int i;
        gotoxy(1,3);
        textcolor(GREEN);
        for( i=0; i<80; i++)
        {
            printf("~");
        }
        gotoxy(28,5);
        textcolor(WHITE);
        printf("***ADD CAR DETAILS***");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Car Model:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(c.car_name,50,stdin);
        char *pos;
        pos=strchr(c.car_name,'\n');
        *pos='\0';
        gotoxy(1,9);
        textcolor(YELLOW);
        printf("Enter Car Capicity:");
        fflush(stdin);
        scanf("%d",&c.capacity);
        gotoxy(1,10);
        textcolor(YELLOW);
        printf("Enter Car Count:");
        fflush(stdin);
        scanf("%d",&c.car_count);
        gotoxy(1,11);
        textcolor(YELLOW);
        printf("Enter Car Price For Per Day:");
        fflush(stdin);
        scanf("%d",&c.price);
        fseek(fp,0,SEEK_END);
        fwrite(&c,sizeof(car),1,fp);
        gotoxy(30,14);
        textcolor(GREEN);
        printf("CAR ADDDED SUCESSFULLY");
        gotoxy(1,15);
        printf("CAR ID IS:: %d",c.car_id);
        getch();
        gotoxy(1,18);
        textcolor(LIGHTRED);
        printf("DO YOU WANT TO ADD MORE CAR(Y/N)");
        fflush(stdin);
        scanf("%c",&uchoice);
        total_car++;
        c.car_id=total_car;


    }while(uchoice=='Y'||uchoice=='y');
    fclose(fp);
}
void viewEmployee()
{
    FILE *fp=fopen("emp.bin","rb");
    user u;
    gotoxy(34,1);
    textcolor(YELLOW);
    printf("CAR RENTAL APP");
    int i;
    gotoxy(1,2);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(32,5);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(GREEN);
     for(i=0;i<80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(28,9);
        textcolor(RED);
        printf("Sorry File Cannot open!");
        getch();
        return;
    }

    gotoxy(2,8);
    printf("Emplyoee ID \t\t\t Name \t\t\t Password") ;
    gotoxy(1,9);
    for(i=0;i<80;i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);
    while(fread(&u,sizeof(u),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%s",u.userid);
        gotoxy(34,x);
        printf("%s",u.name);
        gotoxy(58,x);
        printf("%s",u.pwd);
        x++;
    }
    fclose(fp);
    getch();
}
void viewCar()
{
    FILE *fp=fopen("car.bin","rb");
    car c;
    gotoxy(30,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM");
    int i;
    gotoxy(1,2);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(30,5);
    printf("*ALL CAR DETAILS*");
    gotoxy(1,7);
    textcolor(GREEN);
     for(i=0;i<80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(27,9);
        textcolor(LIGHTRED);
        printf("Sorrry File Cannot Be Open!");
        getch();
        return;
    }
     gotoxy(2,8);
    printf("CarID   Model\t\t Capacity \t  Available \t Price/day") ;
    gotoxy(1,9);
    for(i=0;i<80;i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%d",c.car_id);
        gotoxy(10,x);
        printf("%s",c.car_name);
        gotoxy(26,x);
        printf("%d",c.capacity);
        gotoxy(43,x);
        printf("%d",c.car_count);
        gotoxy(59,x);
        printf("%d",c.price);
        x++;

    }
    fclose(fp);
    getch();
}
int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    int i,result;
    char empid[10];
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(30,5);
    printf("*DELETE EMPLOYEE RECORDS*");
    gotoxy(1,7);
    textcolor(GREEN);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(1,11);
    textcolor(GREEN);
    for(i=0;i<80;i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        gotoxy(28,9);
        textcolor(LIGHTRED);
        printf(" NO EMPLOYEE NOT ADDED YET!");
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Employee ID to Delete the Record:");
    textcolor(WHITE);
    scanf("%s",empid);
    user u;
    int found=0;
    while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(strcmp(u.userid,empid)!=0)
        {
            fwrite(&u,sizeof(u),1,fp2);
        }
        else
        {
            found=1;
        }

    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("temp.bin");

    }
    else
    {
        result=remove("emp.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","emp.bin");
        if(result!=0)
            return 2;
    }
    return found;
}

int deleteCar()
{
    FILE *fp1=fopen("car.bin","rb");
    int i,carid,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(30,5);
    printf("*DELETE CAFR RECORDS*");
    gotoxy(1,7);
    textcolor(GREEN);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(1,11);
    textcolor(GREEN);
    for(i=0;i<80;i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        gotoxy(30,9);
        textcolor(LIGHTRED);
        printf("NO CAR ADDED YET!");
        getch();
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(20,9);
    textcolor(YELLOW);
    printf("Enter Car ID Model TO Delete:");
    textcolor(WHITE);
    scanf("%d",&carid);
    car c;
    int found=0;
    while(fread(&c,sizeof(c),1,fp1)==1)
    {
        if(carid==c.car_id)
        {
            found=1;
        }
        else
        {
            fwrite(&c,sizeof(c),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
        remove("temp.bin");
    else
    {
        result=remove("car.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","car.bin");
        if(result!=0)
            return 2;
    }
    return found;
}
int empMenu()
{
    int choice;
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL APP");
    gotoxy(35,7);
    textcolor(GREEN);
    printf("EMPLOYEE MENU");
    int i;
    gotoxy(1,8);
    for(i=0;i<80;i++)
        printf("*");
    gotoxy(32,9);
    textcolor(YELLOW);
    printf("1.Rent A Car");
    gotoxy(32,10);
    printf("2.Booking Car Details");
    gotoxy(32,11);
    printf("3.Available Car Details");
    gotoxy(32,12);
    printf("4.Show All Car Details");
    gotoxy(32,13);
    printf("5.Return Car");
    gotoxy(32,14);
    printf("6.Exit");
    gotoxy(32,16);
    printf("Enter a choice:");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;

}


int selectCarmodel()
{
    FILE *fp=fopen("car.bin","rb");
    car C;
    int flag,choice;
    int count=0;
    int x=8;
    textcolor(YELLOW);
    gotoxy(33,x);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            printf("%d . %s",C.car_id,C.car_name);
            gotoxy(33,++x);
            count++;
        }
    }
    if(count==0)
    {
        fclose(fp);
        return -2;
    }
    gotoxy(27,x+2);
    printf("Enter A Choice(0 for Quit):");
    while(1)
    {
        flag=0;
        scanf("%d",&choice);
        if(choice==0)
        {
            fclose(fp);
            return 0;
        }
        rewind(fp);
        while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(C.car_id==choice&&C.car_count>0)
            {
                flag=1;
                break;
            }

        }
        if(flag==1)
        {
            return choice;
            fclose(fp);

        }
        else
        {
            gotoxy(37,x+4);
            textcolor(LIGHTRED);
            printf("Wrong Input");
            _getch();
            gotoxy(35,x+4);
            printf("\t\t");
            gotoxy(48,x+2);
            printf("\t\t");
            gotoxy(48,x+2);
            textcolor(WHITE);

        }

    }
}
int isValidDate(struct tm dt)
{
    time_t obj=time(0);
    struct tm *p=localtime(&obj);

    if(dt.tm_year>=1900+p->tm_year ) //&& dt.tm_year<=1900+p->tm_year)
    {
        if(dt.tm_mon>=p->tm_mon+1 || dt.tm_year>=1901+p->tm_year) //&& dt.tm_mon<=1+p->tm_mon)
        {
            if(((dt.tm_mday>=p->tm_mday && dt.tm_mday<=31) || ((dt.tm_mon>=p->tm_mon+2 || dt.tm_year>=1901+p->tm_year) && dt.tm_mday<=31))&& (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
                return 1;
            else if(((dt.tm_mday>=p->tm_mday && dt.tm_mday<=30) || ((dt.tm_mon>=p->tm_mon+2 || dt.tm_year>=1901+p->tm_year) && dt.tm_mday<=31)) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
                return 1;
            else if(((dt.tm_mday>=p->tm_mday && dt.tm_mday<=28 ) || (dt.tm_year>=1901+p->tm_year && dt.tm_mday<=28)) && (dt.tm_mon==2))
                return 1;
            else if ((dt.tm_mday>=29 && dt.tm_mon<=2) && (dt.tm_year%400==0 || (dt.tm_year%4==0 && dt.tm_year%100==0)))
                return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
/*int isValidDate(struct tm dt)

    time_t obj=time(0);
    struct tm *p=localtime(&obj);
{
    if(dt.tm_year>=1900+p->tm_year)
    {
        if(dt.tm_mon>=1 && dt.tm_mon<=12)
        {
            if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
                return 1;
            else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 ||(dt.tm_year%4==0 && dt.tm_year%100!=0)))
               return 1;
            else
               return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}*/

void updateCarCount(int c_id)
{
    FILE *fp=fopen("car.bin","rb+");
    car c;

   while(fread(&c,sizeof(car),1,fp)==1)
   {
       if(c.car_id==c_id)
       {
          int x=c.car_count;
          x--;
          fseek(fp,-8,SEEK_CUR);
          fwrite(&x,sizeof(int),1,fp);
          break;
       }
   }
   fclose(fp);
}
void bookedCarDetails()
{
    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    int i;
    Customer_Car_Details CC;
    gotoxy(33,1);
    textcolor(YELLOW);
    printf("CAR RENTAL APP");
    gotoxy(1,2);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(31,5);
    printf("*BOOKED CAR DETAILS*");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf("Model \t Cust Name \t Pick Up \tDrop \t   S_date \t  E_date");
    int x=10;
    textcolor(YELLOW);
    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,x);
        printf("%s",getCarName(CC.car_id));
        gotoxy(10,x);
        printf("%s",CC.cust_name);
        gotoxy(26,x);
        printf("%s",CC.pick);
        gotoxy(40,x);
        printf("%s",CC.drop);
        gotoxy(52,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(68,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;


    }
    fclose(fp);
    _getch();

}
char *getCarName(int c_id)
{
    FILE *fp=fopen("car.bin","rb");
     static car c;
    while(fread(&c,sizeof(car),1,fp)==1)
    {
        if(c.car_id==c_id)

            break;
    }
    fclose(fp);
    return c.car_name;
}
int rentCar()
{
    FILE *fp=fopen("customer.bin","ab");
    Customer_Car_Details CC;
    int c;
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(34,5);
    textcolor(GREEN);
    printf("EMPLOYEE MENU");
    int i;
    gotoxy(1,6);
    for(i=0;i<80;i++)
        printf("*");
    c=selectCarmodel();
    if(c==0||c==-2)
        return c;

    CC.car_id=c;
    clrscr();
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(34,5);
    textcolor(GREEN);
    printf("EMPLOYEE MENU");
    gotoxy(1,7);
    for(i=0;i<80;i++)
        printf("*");
    gotoxy(1,17);
    for(i=0;i<80;i++)
        printf("*");
    gotoxy(27,9);
    textcolor(YELLOW);
    printf("Enter Customer Name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.cust_name,30,stdin);
    char *pos;
    pos=strchr(CC.cust_name,'\n');
    *pos='\0';
    gotoxy(27,10);
    textcolor(YELLOW);
    printf("Enter Pickup Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.pick,30,stdin);
    pos=strchr(CC.pick,'\n');
    *pos='\0';
    gotoxy(27,11);
    textcolor(YELLOW);
    printf("Enter Drop Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.drop,30,stdin);
    pos=strchr(CC.drop,'\n');
    *pos='\0';
    gotoxy(27,12);
    textcolor(YELLOW);
    printf("Enter Start Date (dd/mm/year):");
    fflush(stdin);
    textcolor(WHITE);
    do
    {
       scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
        //scanf("%d",&CC.sd.tm_mday);
        //scanf("%d",&CC.sd.tm_mon);
        //scanf("%d",&CC.sd.tm_year);
       int datevalid=isValidDate(CC.sd);
       if(datevalid==1)
       {
           break;
       }
           gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date");
            _getch();
            gotoxy(27,18);
            printf("\t\t");
            gotoxy(57,12);
            printf("\t\t\t");
            gotoxy(57,12);
            textcolor(WHITE);

       }while(1);
    gotoxy(27,13);
    textcolor(YELLOW);
    printf("Enter End Date (dd/mm/year):");
    textcolor(WHITE);
    do
    {
       scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
       int datevalid=isValidDate(CC.ed);
       if(datevalid==0)
       {
           gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date");
            _getch();
            gotoxy(27,18);
            printf("\t\t");
            gotoxy(55,13);
            printf("\t\t\t");
            gotoxy(55,13);
            textcolor(WHITE);
        }
        else
        {
              int compare=compareDate(CC.sd,CC.ed);
              if(compare==1)
              {
               break;
               }
              else
              {
               gotoxy(27,18);
               textcolor(LIGHTRED);
               printf("Enter A Valid Date!");
               _getch();
               gotoxy(27,18);
               printf("\t\t\t\t");
              gotoxy(55,13);
              printf("\t\t\t\t");
              gotoxy(55,13);
              textcolor(WHITE);
              }
         }

    }while(1);

    if(fp==NULL)
    {
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("Sorry ! File cannot be opened");
        getch();
        gotoxy(27,18);
        printf("\t\t");
        return -1;
    }
    fwrite(&CC,sizeof(Customer_Car_Details),1,fp);
    printf("Booking Done:%d",CC.car_id);
    printf("\nPress any key to continue...");
    _getch();

    fclose(fp);
    updateCarCount(c);
    bookedCarDetails();
    return 1;
    getch();
}
void availableViewcar()
{
    FILE *fp=fopen("car.bin","rb");
    car c;
    gotoxy(30,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM");
    int i;
    gotoxy(1,2);
    for(i=0;i<80;i++)
        printf("%c",247);
    gotoxy(30,5);
    printf("*ALL CAR DETAILS*");
    gotoxy(1,7);
    textcolor(GREEN);
     for(i=0;i<80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(27,9);
        textcolor(LIGHTRED);
        printf("Sorrry File Cannot Be Open!");
        getch();
        return;
    }
     gotoxy(2,8);
    printf("CarID   Model\t\t Capacity \t  Available \t Price/day") ;
    gotoxy(1,9);
    for(i=0;i<80;i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(c.car_count>0)
        {
        gotoxy(2,x);
        printf("%d",c.car_id);
        gotoxy(10,x);
        printf("%s",c.car_name);
        gotoxy(26,x);
        printf("%d",c.capacity);
        gotoxy(43,x);
        printf("%d",c.car_count);
        gotoxy(59,x);
        printf("%d",c.price);
        x++;
        }
    }
    fclose(fp);
    getch();
}
int compareDate(struct tm sd,struct tm ed)
{
    if(sd.tm_year<=ed.tm_year)
    {
        if((sd.tm_mon<=ed.tm_mon && sd.tm_year==ed.tm_year) || sd.tm_year<ed.tm_year )
        {
            if((sd.tm_mday<ed.tm_mday && sd.tm_mon<=ed.tm_mon) || sd.tm_year<ed.tm_year)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}
int returnCardetails()
{
    int i;
    Customer_Car_Details CC;
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(34,5);
    textcolor(GREEN);
    printf("EMPLOYEE MENU");
    gotoxy(1,7);
    for(i=0;i<80;i++)
        printf("*");

    gotoxy(1,17);
    for(i=0;i<80;i++)
        printf("*");
    gotoxy(27,9);
    textcolor(YELLOW);
    printf("Enter Customer Name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.cust_name,30,stdin);
    char *pos;
    pos=strchr(CC.cust_name,'\n');
    *pos='\0';
    gotoxy(27,10);
    textcolor(YELLOW);
    printf("Enter Pickup Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.pick,30,stdin);
    pos=strchr(CC.pick,'\n');
    *pos='\0';
    gotoxy(27,11);
    textcolor(YELLOW);
    printf("Enter Drop Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.drop,30,stdin);
    pos=strchr(CC.drop,'\n');
    *pos='\0';
    gotoxy(27,12);
    textcolor(YELLOW);
    printf("Enter Start Date (dd/mm/year):");
    fflush(stdin);
    textcolor(WHITE);
    scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
    gotoxy(27,13);
    textcolor(YELLOW);
    printf("Enter End Date (dd/mm/year):");
    fflush(stdin);
    textcolor(WHITE);
    scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
    int b;
    b=validationReturncardetails(CC);
    if(b==0)
    {
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Car Details Not Match");
            _getch();
            return -1;
     }
    FILE *fp1=fopen("customer.bin","rb");
    FILE *fp2=fopen("temp.bin","wb");
    int found=0;
    int result;
    while(fread(&CC,sizeof(CC),1,fp1)==1)
     {
       if(b==CC.car_id)
        {
         found=1;
        }
      else
        {
           fwrite(&CC,sizeof(CC),1,fp2);
        }
     }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    remove("temp.bin");
    else
    {
    result=remove("customer.bin");
    if(result!=0)
        return 2;
    result=rename("temp.bin","customer.bin");
    if(result!=0)
        return 2;
    }
    updateCarcountplus(b);
    return found;


}
int validationReturncardetails(Customer_Car_Details CC)
{
    static Customer_Car_Details SS;
    FILE *fp=fopen("customer.bin","rb");
    int found=0;
    while(fread(&SS,sizeof(SS),1,fp)==1)
    {
        if((strcmp(SS.cust_name,CC.cust_name)==0 && strcmp(SS.pick,CC.pick)==0 && strcmp(SS.drop,CC.drop)==0 &&(SS.sd.tm_mday==CC.sd.tm_mday&&SS.sd.tm_mon==CC.sd.tm_mon&&SS.sd.tm_year==CC.sd.tm_year) && (SS.ed.tm_mday==CC.ed.tm_mday&&SS.ed.tm_mon==CC.ed.tm_mon&&SS.ed.tm_year==CC.ed.tm_year))==1)
         found=1;
          break;

    }
    fclose(fp);
    if(found==1)
    return SS.car_id;
    else
        return 0;

}
void updateCarcountplus(int c_id)
{
    FILE *fp=fopen("car.bin","rb+");
    car c;

   while(fread(&c,sizeof(car),1,fp)==1)
   {
       if(c.car_id==c_id)
       {
          int x=c.car_count;
          x++;
          fseek(fp,-8,SEEK_CUR);
          fwrite(&x,sizeof(int),1,fp);
          break;
       }
   }
   fclose(fp);
}
