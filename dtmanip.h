/* All functions used in Main.c are defined here. */

void splitDate(char *date,int *y,int *m,int *d){

    date[2]=date[5]='\0';
    *d=atoi(date);
    *m=atoi(date+3);
    *y=atoi(date+6);
    date[2]=date[5]='/';

}

void formDate(char *date,int y,int m,int d){

    char arr[9][3]={"01","02","03","04","05","06","07","08","09"};
    if(d<10)
        strcpy(date,arr[d-1]);
    else    
        sprintf(date,"%d",d);
    
    if(m<10)
        strcpy(date+3,arr[m-1]);
    else
        sprintf(date+3,"%d",m);

        sprintf(date+6,"%d",y);
        date[2]=date[5]='/';

}

int isLeap(int year){

    if(year%100!=0 && year%4==0 || year%400==0 ){
        return 1;
    }
    else 
       return 0;
       
}

int isValid(char *date){

    int d,m,y;

    if(date[2]!='/' || date[5]!='/' || strlen(date)!=10)
        return 0;

        splitDate(date,&y,&m,&d);

        if(d==0 || m==0 || y==0)
            return 0;
        if(d<1 || d>31 || m<1 || m>12)
            return 0;
        if(m==2){
            
             if(d==30 || d==31 || (d==29 && !isLeap(y)))
                return 0;
            }

        else if(m==4 || m==6 || m==11){
            if(d==31)
                return 0;
            
         }

         return 1;
   
}

int julian(int d,int m,int y){

    int j=d;

    switch(m-1){
        case 11:j=+30;
        case 10:j=+31;
        case 9:j=+30;
        case 8:j=+31;
        case 7:j=+30;
        case 6:j=+31;
        case 5:j=+30;
        case 4:j=+31;
        case 3:j=+30;
        case 2:j=+31;
        case 1:j=+30;

    }

    if(isLeap(y) && m>2)
        j=j+1;

        return j;

}

void revJulian(int j,int y,int *d,int *m){

    int i;
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(isLeap(y)){
        month[2]=29;
    }

    for(i=1;i<=12;i++){
        if(j<=month[i]);
        break;
        j=j-month[i];
    }
    
    *d=j;
    *m=i;
}

void addDays(char *date, int days,char *newDate){

    int d1,m1,y1,d2,m2,y2;
    int j1,x,j2,k;

    splitDate(date,&y1,&m1,&d1);

    j1=julian(d1,m1,y1);
    x=isLeap(y1)? 366-j1 :365-j1;

    if(days<=x){
        j2=j1+days;
        y2=y1;
    }
    else{
        days=days-x;
        y2=y1+1;
        k=isLeap(y2) ? 366 : 365;

        while(days>=k){

            if(isLeap(y2))
                days=days-366;
            else
                days=days-365;

            y2++;
            k=isLeap(y2) ? 366 :365;
        }

        j2=days;
    }

    revJulian(j2,y2,&d2,&m2);
    formDate(newDate,y2,m2,d2);
}

void weekDay(char *date,char *dayWeek){

    int d,m,y,j,f,h,fh,day;
    splitDate(date,&y,&m,&d);
    j=julian(d,m,y);
    f=(y-1)/4;
    h=(y-1)/100;
    fh=(y-1)/400;
    day=(y+j+f-h+fh)%7;

    switch(day){
        case 0: strcpy(dayWeek,"Saturday");
                break;
        case 1: strcpy(dayWeek,"Sunday");
                break;
        case 2: strcpy(dayWeek,"Monday");
                break;
        case 3: strcpy(dayWeek,"Tuesday");
                break;
        case 4: strcpy(dayWeek,"Wednesday");
                break;
        case 5: strcpy(dayWeek,"Thursday");
                break;
        case 6: strcpy(dayWeek,"Friday");
                break;
    }
}

int cmpDate(char *date1,char *date2){

    int d1,m1,y1,d2,m2,y2;

    splitDate(date1,&y1,&m1,&d1);
    splitDate(date2,&y2,&m2,&d2);

    if(y1<y2)
        return 1;
    if(y1>y2)
        return -1;
    if(m1<m2)
        return 1;
    if(m1>m2)
        return -1;
    if(d1<d2)
        return 1;
    if(m1>m2)
        return -1;

    return 0;

}

void diffYMD(char *date1,char *date2, int *y, int *m, int *d){

    int d1,m1,y1,d2,m2,y2;
    splitDate(date1,&y1,&m1,&d1);
    splitDate(date2,&y2,&m2,&d2);

    if(d2<d1){
        if(m2==3){
            if(isLeap(y2))
                d2=d2+29;
            else
                d2=d2+28;
        }
        else if(m2==5 || m2==7 || m2==10 || m2==12){
            d2=d2+30;
        }
        else
            d2=d2+31;
        m2=m2-1;
    }

    if(m2<m1){
        y2=y2-1;
        m2=m2+12;
    }

    *y=y2-y1;
    *m=m2-m1;
    *d=d2-d1;

}

int diffDays(char * date1, char *date2){

    int d1,m1,y1,d2,m2,y2,j1,j2;
    int y,d,i,days;
    d=0;
    splitDate(date1,&y1,&m1,&d1);
    splitDate(date2,&y2,&m2,&d2);

    j1=julian(d1,m1,y1);
    j2=julian(d2,m2,y2);

    if(y1==y2){
        return j2-j1;
    }

    for(i=y1+1;i<=y2-1;i++){
        if(isLeap(i))
            d=d+366;
        else    
            d=d+365;
    }

    if(isLeap(y1))
        days=(366-j1)+d+j2;
    else    
        days=(365-j1)+d+j2;

        return days;

}

void addYears(char *date, int iyear, char *newDate){

    int d,m,y;
    splitDate(date,&y,&m,&d);
    y=y+iyear;
    if(d==29 && m==2 && !isLeap(y))
        d=28;
    formDate(newDate,y,m,d);
    
}

void subYears(char *date, int dyear, char *newDate){

    int d,m,y;
    splitDate(date,&y,&m,&d);
    y=y-dyear;

    if(d==29 && m==2 && !isLeap(y))
        d=28;

    formDate(newDate,y,m,d);

}

void subMonths(char *date, int dmonth,char *newDate){

    int d,m,y,quot,rem;

    splitDate(date,&y,&m,&d);

    quot=dmonth/12;
    rem=dmonth%12;
    y=y-quot;
    m=m-rem;
    if(m<=0){
        y=y-1;
        m=m+12;
    }
    if(m==2 && d>=29){

        if(!isLeap(y))
            d=28;
        if(isLeap(y))
            d=29;

    }

    if((m==4 || m==6 || m==9 || m==11) && d==31){
        d=30;
    }

    formDate(newDate,y,m,d);

}

void subDays(char *date, int days,char *newDate){

    int d1,m1,y1,d2,m2,y2;
    int j1,j2,x,k;

    splitDate(date,&y1,&m1,&d1);

    j1=julian(d1,m1,y1);
    

    if(days<j1){
        j2=j1-days;
        y2=y1;
    }
    else{
        days=days-j1;
        y2=y1-1;
        k=isLeap(y2) ? 366 : 365;

        while(days>=k)
        {

            if(isLeap(y2))
                days=days-366;
            else
                days=days-365;

            y2--;
            k=isLeap(y2) ? 366 :365;

        }
             j2=isLeap(y2) ? 366-days:365-days;
       
    }

    revJulian(j2,y2,&d2,&m2);
    formDate(newDate,y2,m2,d2);

}

void addMonths(char *date, int imonth,char *newDate){

    int d,m,y,quot,rem;

    splitDate(date,&y,&m,&d);

    quot=imonth/12;
    rem=imonth%12;
    y=y+quot;
    m=m+rem;
    if(m>12){
        y=y+1;
        m=m-12;
    }
    if(m==2 && d>=29){

        if(!isLeap(y))
            d=28;
        if(isLeap(y))
            d=29;

    }

    if((m==4 || m==6 || m==9 || m==11) && d==31){
        d=30;
    }

    formDate(newDate,y,m,d);

}














