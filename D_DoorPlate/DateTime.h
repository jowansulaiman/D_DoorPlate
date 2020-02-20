
#ifndef D_DateTime
#define D_DateTime
#include <sys/timeb.h>
#include <time.h>
#include <memory>

namespace DautmUhrzeit {
	class UhrZeit {
	private :
		unsigned int m_Sec;
		unsigned int m_Minute;
		unsigned int m_Uhr;
	public:
		UhrZeit();
		UhrZeit(unsigned int, unsigned int, unsigned int);


	};
	class Datum {
	private:
		int m_Tag,
			m_Monat,
			m_Jahr;

		char tmpbuf[128], timebuf[26], ampm[4] = "AM";
		time_t ltime;
		struct _timeb tstruct;
		struct tm today, gmt, xmas = { 0, 0, 12, 25, 11, 93 };
		errno_t err;
	
	public:
		Datum();
		Datum(int, int, int);
		~Datum();

		bool chec_Time();
		int _time();
		void _date();
		void _day();
		void _month();
		void _year();
		friend class ZeitStempel;
	};

	class  ZeitStempel {
	private:
		Datum start;
		Datum end;


	public:
		ZeitStempel();
		ZeitStempel(int, int, int);
		~ZeitStempel();
	};
}
#endif // !D_DateTime
