#ifndef D_DateTime
#define D_DateTime

class Date{
protected:
	int *min;
	int * hou;
	int *day, *month, *year;
	
public:
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
	void time();
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
