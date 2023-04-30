#include <iostream>
#include <bits/stdc++.h>
#include "DateTime.h"
using namespace std;


void pr()
{
    cout<<"1)operator +(int)\n2)operator -(int)\n3)operator +(DateTime)\n4)operator -(DateTime)\n5)operator +(char *p)\n6)operator -(char *p)\n";
}
class DateTime
{
public:
    double dat;
    int dd=0,mm=0,yy=0,ss=0,mn=0,hh=0;
    DateTime()
    {
        dat=0;
    }

    void Date(char *p)
    {
        dd=0;mm=0;yy=0;
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
        dat=foo(dd,mm,yy);
        double sec2=this->hh*3600+this->mn*60+this->ss;
        sec2=sec2/86400;
        this->dat+=sec2;
    }

    void Time(char *p)
    {

        while (*p!=':')
        {
            hh=(*p-'0')+10*hh;
            p++;
        }
        p++;

        while (*p!=':')
        {
            mn=(*p-'0')+10*mn;
            p++;
        }
        p++;

        while (*p!='\0')
        {

            ss=(*p-'0')+10*ss;
            p++;
        }
        dat=foo(dd,mm,yy);
        double sec2=this->hh*3600+this->mn*60+this->ss;
        sec2=1.*sec2/86400;
        this->dat+=sec2;
    }

    void Date_time(char *p)
    {

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

        while (*p!=' ')
        {

            yy=(*p-'0')+10*yy;
            p++;
        }
        p++;
         while (*p!=':')
        {
            hh=(*p-'0')+10*hh;
            p++;
        }
        p++;

        while (*p!=':')
        {
            mn=(*p-'0')+10*mn;
            p++;
        }
        p++;

        while (*p!='\0')
        {

            ss=(*p-'0')+10*ss;
            p++;
        }
        dat=foo(dd,mm,yy);
        double sec2=this->hh*3600+this->mn*60+this->ss;
        sec2=sec2/86400;
        this->dat+=sec2;
}

    string ShowDateTime()
    {
        stringstream ss;
        ss.str("");
        ss<<setw(2)<<setfill('0')<<fixed<<this->dd<<":"<<setw(2)<<setfill('0')<<fixed<<this->mm<<":"<<setw(2)<<setfill('0')<<fixed<<this->yy<<" "<<setw(2)<<setfill('0')<<fixed<<this->hh<<":"<<setw(2)<<setfill('0')<<fixed<<this->mn<<":"<<setw(2)<<setfill('0')<<fixed<<this->ss;
        return ss.str();
    }

    string ShowDate()
    {
        stringstream ss;
        ss.str("");
        ss<<setw(2)<<setfill('0')<<fixed<<this->dd<<":"<<setw(2)<<setfill('0')<<fixed<<this->mm<<":"<<setw(2)<<setfill('0')<<fixed<<this->yy;return ss.str();
    }

    string ShowTime()
    {
        stringstream ss;
        ss.str("");
        ss<<setw(2)<<setfill('0')<<fixed<<this->hh<<":"<<setw(2)<<setfill('0')<<fixed<<this->mn<<":"<<setw(2)<<setfill('0')<<fixed<<this->ss;
        return ss.str();
    }

    void setDateWrk(int a, int b, int c)
    {
        //dd=0; mm=0; yy=0;
        dd=a; mm=b; yy=c;
    }

    void setTimeWrk(int a, int b, int c)
    {
        //hh=0; mn=0; ss=0;
        hh=a; mn=b; ss=c;

    }
    void DateToWrk()
    {
          dat=foo(dd,mm,yy);
    }
    void WrkToDate()
    {
        string a;
        a=DateToString(dat);
        this->Date(&a[0]);

    }
    void TimeToWrk()
    {
        double sec2=this->hh*3600+this->mn*60+this->ss;
        int day;
        day=sec2/86400;
        sec2=sec2-day*86400;
        this->dat+=day;
        sec2=sec2/86400;
        this->dat+=sec2;
    }

    void WrkToTime()
    {
        dd+=(int)dat;
        double task=dat-(int)dat;
        ss=round(task*86400);
        mn=ss/60;
        ss=ss-mn*60;
        hh=mn/60;
        mn=mn-hh*60;

    }

    DateTime operator+(double a)
    {
        this->dat+=(a/86400);
        DateTime s;
        s.dat=this->dat;
        return s;

    }
    DateTime operator-(double a)
    {
        this->dat-=(a/86400);
        DateTime s;
        s.dat=this->dat;
        return s;

    }
    DateTime operator+(DateTime a)
    {
        DateTime s;
        s.dat=this->dat+a.dat;
        return s;
    }
    DateTime operator-(DateTime a)
    {
        DateTime s;
        s.dat=this->dat-a.dat;
        return s;
    }
    DateTime operator+(string p)
    {
        DateTime s;
        s.Date_time(&p[0]);
        s.dat=this->dat+s.dat;
        s.WrkToTime();
        s.WrkToDate();
        return s;
    }
    DateTime operator-(string p)
    {
        DateTime s;
        s.Date_time(&p[0]);
        s.dat=this->dat-s.dat;
        s.WrkToTime();
        s.WrkToDate();
        return s;
    }

};

int main()
{
        string a="13.12.2022 13:45:10",b="12.01.1900 05:12:20",d; double c;DateTime first,sec,res;
         first.Date_time(&a[0]); sec.Date_time(&b[0]);
        cout<<"First Date:"<<a;
        cout<<"\nSecond Date:"<<b;
        cout<<"\nEnter amount of second which need to add: ";cin>>c;
        pr(); cout<<"Your choice...";
        cin>>d;
        if (d=="1")
        {
            res=first+c;
            cout<<"Res:"<<res.dat;
        }else if(d=="2")
        {
            res=first-c;
            cout<<"Res:"<<res.dat;
        }else if(d=="3")
        {
            res=first+sec;
            cout<<"Res:"<<res.dat;
        }else if(d=="4")
        {
            res=first-sec;
            cout<<"Res:"<<res.dat;
        }else if (d=="5")
        {
            res=first+b;
            cout<<res.ShowDateTime();
        }else if (d=="6")
        {
            res=first-b;
            cout<<res.ShowDateTime();
        }
}

