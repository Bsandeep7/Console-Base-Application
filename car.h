#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>

struct user
{
    char userid[30];
    char name[30];
    char pwd[30];
};
struct car
{

    int car_id;
    char car_name[50];
    int capacity;
    int car_count;
    int price;

};
struct Customer_Car_Details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd;
    struct tm ed;
};


typedef struct user user;
typedef struct car car;
typedef struct Customer_Car_Details Customer_Car_Details ;

void addAdmin();
user * getinput();
int checkUserExist(user, char*);
int addMenu();
void addEmployee();
void addCar();
void viewEmployee();
void viewCar();
int deleteEmp();
int deleteCar();
int empMenu();
int rentCar();
int selectCarmodel();
int isValidDate(struct tm );
void updateCarCount(int);
void bookedCarDetails();
char *getCarName(int);
void availableViewcar();
int compareDate(struct tm,struct tm);
int returnCardetails();
void updateCarcountplus(int);
int validationReturncardetails(Customer_Car_Details);
#endif // CAR_H_INCLUDED


