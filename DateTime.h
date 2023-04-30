#ifndef DATETIME_H
#define DATETIME_H
#include <bits/stdc++.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int foo(int dd, int mm, int yy)
{
    int year=0;
        year=yy-1900;
        mm=mm-1;
        dd=dd-1;
        int day=0;
    for (int i=1900; i<yy; i++)
        {
        if((i % 4 == 0 && i % 100) || i % 400 == 0)
          {
              day+=366;
          }else
            {
                day+=365;
            }
        }
    for(int i=0; i<=mm; i++)
    {
    if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
        day+=31;

    if (i==4 || i==6 || i==9 || i==11)
        day+=30;

    if (i==2)
        {
      if((yy % 4 == 0 && yy % 100) || yy % 400 == 0)
          day+=29;
    else
       day+=28;
        }
    }
    day=day+dd;
    return day;
}


class XDate
{
private:
    int xDate;
public:
    int dd,mm,yy;
XDate()
{
        xDate = 0;
    }

XDate(char *p)
{
         dd=0, mm=0,yy=0;

        while (*p!='.')
        {
            dd=(*p-'0')+10*dd;
            p++;
        }
        p++;

        while (*p!='.')
        {
            mm=(*p-'0')+10*mm;
            p++;
        }
        p++;

        while (*p!='\0')
        {
            yy=(*p-'0')+10*yy;
            p++;
        }
        p++;

    xDate=foo(dd,mm,yy);
}
int getDay()
{
    return xDate;
}
void setDate(int a)
{
    xDate=a;
}

XDate encodeDate(int dd, int mm, int yy)
{

    int a=foo(dd,mm,yy);
    xDate=a;
}

XDate CurrenDate()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int dd,mm,yy;
    dd=st.wDay;
    mm=st.wMonth;
    yy=st.wYear;
    xDate=foo(dd,mm,yy);
}

int StrToDate(char *p)
{
    int  dd=0, mm=0,yy=0;
        while (*p!='.')
        {
            dd=(*p-'0')+10*dd;
            p++;
        }
        p++;

        while (*p!='.')
        {
            mm=(*p-'0')+10*mm;
            p++;
        }
        p++;

        while (*p!='\0')
        {
            yy=(*p-'0')+10*yy;
            p++;
        }
        p++;
    xDate=foo(dd,mm,yy);
    cout<<((dd>=1 && dd<=9)?"0":"")<<dd<<"/"<<((mm>=1 && mm<=9)?"0":"")<<mm<<"/"<<yy;
}


int operator+(XDate a)
{

    int res=0;
    res=a.getDay()+this->getDay();
    return res ;
}
int operator-(XDate a)
{

    int res=0;
    res=this->getDay()-a.getDay();
    return res ;
}



};


class Time
{
private:
    int hh,mm,ss;

public:
    double sec=this->hh*3600+this->mm*60+ss;

    Time()
    {
        hh=0;    mm=0;        ss=0;

    };

    Time(int a)
    {
        hh=a;
    };
    Time(int a,int b)
    {
        hh=a;        mm=b;
    };

    Time(int a,int b,int c)
    {
        hh=a;        mm=b;        ss=c;
    };
    Time(char *a)
    {
        hh = 0, mm = 0, ss = 0;
        while (*a != ':')
        {
            hh = (*a - '0')+10 * hh  ;
            a++;
        }
        a++;
        while (*a != ':')
        {
            mm =  (*a - '0')+10 * mm ;
            a++;
        }
        a++;
        while (*a != '\0')
        {
            ss =  (*a - '0')+10 * ss ;
            a++;
        }
    }
    void setH(int a)
    {
        hh=a;
    }
    void setM(int a)
    {
        mm=a;
    }
    void setS(int a)
    {
        ss=a;
    }
    int getH()
    {
        return hh;
    }
    int getM()
    {
        return mm;
    }

    int getS()
    {
        return ss;
    }
    Time operator+(Time b)
    {
        Time s;
        s.hh=hh+b.hh;
        s.mm=mm+b.mm;
        s.ss=ss+b.ss;
        if (s.ss>=60)
        {
            s.mm+=1;
            s.ss-=60;
        }
        if (s.mm>=60)
        {
            s.hh+=1;
            s.mm-=60;
        }
        return s;
    }
    Time operator-(Time a)
    {
        Time w;
        if (this->ss < a.ss)
        {
            w.ss=ss-a.ss+60;
            mm-=1;

        }else {
            w.ss=ss-a.ss;
        }
        if (this->mm < a.mm)
        {
            w.mm=mm-a.mm+60;
            hh-=1;

        }else {
            w.mm=mm-a.mm;
        }
        if (this->hh < a.hh)
        {
            w.hh=hh-a.hh+24;

        }else {
            w.hh=hh-a.hh;
        }
        return w;
    }


};
string TimeToString(Time s)
    {
        stringstream ss;
        ss.str("");
        ss<<setw(2)<<setfill('0')<<fixed<<s.getH()<<":"<<setw(2)<<setfill('0')<<fixed<<s.getM()<<":"<<setw(2)<<setfill('0')<<fixed<<s.getS();
        return ss.str();
    }

string DateToString(int l)
{
    int day = l, j = 0, k = 0;
        int month1 = 1, year = 1900;
        while(day > 365)
        {
            if((year % 4 == 3 && (year+1)%100 != 0) || (year+1) % 400 == 0)
            {
                year++;
                day -= 366;
            }
            else
            {
                year++;
                day -= 365;
            }
        }
        while((day > 28 && (year%4==0 && year%100) || year%400 == 0) || (day > 29 && (year%4!=0 && year%100!=0)))
        {
            month1++;
            day -= month[j];
            j++;
            k = j;
        }
        day+=1;
        if(day == 0){
            day = month[k];
            month1--;
        }
        if(month == 0){
            month1 = 12;
            year--;
        }
        stringstream ss;
        ss.str("");
        ss<<setw(2)<<setfill('0')<<fixed<<day<<"."<<setw(2)<<setfill('0')<<fixed<<month1<<"."<<setw(4)<<setfill('0')<<fixed<<year;
        return ss.str();
}


#endif // DATETIME_H
