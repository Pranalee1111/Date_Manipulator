/* All date related manipulations are performed here */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dtmanip.h"

main(){

    int choice;
    char date[11],date1[11],date2[11];
    char dayWeek[10],newDate[11];
    int iyear,imonth,dyear,dmonth,days;
    int y,m,d;

    while(1){

        printf("\n1.Date Validation\n");
        printf("2.Compare Dates\n");
        printf("3.Difference of dates in days\n");
        printf("4.Difference of dates in years,months,days\n");
        printf("5.Day of Week\n");
        printf("6.Add years\n");
        printf("7.Add months\n");
        printf("8.Add days\n");
        printf("9.Subtract years\n");
        printf("10.subtract months\n");
        printf("11.subtract days\n");
        printf("12.Exit\n");

        printf("\nEnter Your Choices: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                    printf("Enter date(dd/mm/yyyy): ");
                    scanf("%s",date);

                    if(isValid(date))
                        printf("Valid Date\n\n");
                    else
                        printf("Not a Valid Date\n\n");

                    break;

            case 2:
                    printf("Enter first date(dd/mm/yyyy): ");
                    scanf("%s",date1);
                    printf("Enter second date(dd/mm/yyyy): ");
                    scanf("%s",date2);

                    if(!isValid(date1) || !isValid(date2))
                    {
                        printf("Enter only valid dates\n");
                        break;
                    }

                    if(cmpDate(date1,date2)==0){
                        printf("\n\nDate:%s and Date: %s are same\n",date1,date2);
                    }
                    else if(cmpDate(date1,date2)==1){
                        printf("\n\nDate:%s < Date:%s\n",date1,date2);
                    }
                    else{
                        printf("\n\nDate:%s > Date:%s",date1,date2);
                    }
                    break;

            case 3:
                    printf("Enter first date(dd/mm/yyyy): ");
                    scanf("%s",date1);
                    printf("Enter second date(dd/mm/yyyy): ");
                    scanf("%s",date2);

                    if(!isValid(date1) || !isValid(date2)){
                        printf("\nEnter only Valid Dates\n");
                        break;
                    }

                    if(cmpDate(date1,date2)==1)
                        days=diffDays(date1,date2);
                    else    
                        days=diffDays(date2,date1);

                    printf("\n\nDifference in days: %d\n\n",days);
                
                    break;

            case 4:
                    printf("Enter first date(dd/mm/yyyy): ");
                    scanf("%s",date1);
                    printf("Enter second date(dd/mm/yyyy): ");
                    scanf("%s",date2);

                    if(!isValid(date1) || !isValid(date2)){
                        printf("\nEnter only Valid Dates\n");
                        break;
                    }

                    if(cmpDate(date1,date2)==1)
                        diffYMD(date1,date2,&y,&m,&d);
                    else
                        diffYMD(date2,date1,&y,&m,&d);
                    
                    printf("\n\nDifference of two dates: ");
                    printf("%d years %d months %d days\n",y,m,d);

                    break;

            case 5:
                    printf("Enter date(dd/mm/yyyy): ");
                    scanf("%s",date);
                    weekDay(date,dayWeek);
                    printf("\nDay of Week is %s\n",dayWeek);
            
                    break;

            case 6:
                    printf("Enter date(dd/mm/yyyy): ");
                    scanf("%s",date);

                    if(!isValid(date)){
                        printf("Enter a valid date\n");
                        break;
                    }
                    printf("Enter a number of years to be added: ");
                    scanf("%d",&iyear);

                    addYears(date,iyear,newDate);
                    printf("\n\nNew date is %s\n",newDate);

                    break;

            case 7:
                    printf("Enter date(dd/mm/yyyy): ");
                    scanf("%s",date);

                      if(!isValid(date)){
                        printf("Enter a valid date\n");
                        break;
                    }
                    printf("Enter a number of months to be added: ");
                    scanf("%d",&imonth);

                    addMonths(date,imonth,newDate);
                    printf("\n\nNew date is %s\n",newDate);

                    break;

            case 8:
                    printf("Enter date(dd/mm/yyyy): ");
                    scanf("%s",date);

                      if(!isValid(date)){
                        printf("Enter a valid date\n");
                        break;
                    }
                    printf("Enter a number of days to be added: ");
                    scanf("%d",&days);

                    addDays(date,days,newDate);
                    printf("\n\nNew date is %s\n",newDate);
                
                    break;

            case 9: 
                    printf("Enter date(dd/mm/yyyy): ");
                    scanf("%s",date);

                      if(!isValid(date)){
                        printf("Enter a valid date\n");
                        break;
                    }
                    printf("Enter a number of years to be subtracted: ");
                    scanf("%d",&dyear);

                    subYears(date,dyear,newDate);
                    printf("\n\nNew date is %s\n",newDate);
                
                    break;

            case 10:
                    printf("Enter date(dd/mm/yyyy): ");
                    scanf("%s",date);

                      if(!isValid(date)){
                        printf("Enter a valid date\n");
                        break;
                    }
                    printf("Enter a number of months to be subtracted: ");
                    scanf("%d",&dmonth);

                    subMonths(date,dmonth,newDate);
                    printf("\n\nNew date is %s\n",newDate);
                
                    break;

            case 11:
                    printf("Enter date(dd/mm/yyyy): ");
                    scanf("%s",date);

                      if(!isValid(date)){
                        printf("Enter a valid date\n");
                        break;
                    }
                    printf("Enter a number of days to be subtracted: ");
                    scanf("%d",&days);

                    subDays(date,days,newDate);
                    printf("\n\nNew date is %s\n",newDate);
                    break;

            case 12:
                    exit(1);
                    break;

            default:
                    printf("\n\nWrong Choice");
 
        }
    }
      
}