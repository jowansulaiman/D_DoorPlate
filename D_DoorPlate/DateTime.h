#ifndef D_DateTime
#define D_DateTime

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>


class Date{
protected:
	int *min;
	int * hou;
	int *day, *month, *year;

	char tmpbuf[128], timebuf[26], ampm[4] = "AM";
	time_t ltime;
	struct _timeb tstruct;
	struct tm today, gmt, xmas = { 0, 0, 12, 25, 11, 93 };
	errno_t err;
public:
	Date() {  };
	Date(int m, int h, int d, int mo, int y) {
		 min, hou, day, month, year = new int;

		*min = m;
		*hou = h;   *day = d;
		*month = mo; *year = y;
	};
	~Date() {
		delete min, hou, day, month, year;
	}

	bool chec_Time();
	void _time();
	void _date();
	void _day();
	void _month();
	void _year();
	void _hour();
	void _min();
	friend class DateTime;
};

 class  DateTime {
private:
	Date start;
	Date end;
 

public:
	DateTime(int s, int m, int h, int d, int mo, int y,
	       	 int e_s, int e_m, int e_h, int e_d, int e_mo, int e_y):start(m,  h,  d,  mo,  y), end(e_m,  e_h,  e_d,  e_mo,  e_y) {	}

	~DateTime() {
	}
	void str() {
	
	}



};
#endif // !D_DateTime
