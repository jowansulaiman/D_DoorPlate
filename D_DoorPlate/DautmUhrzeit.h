
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
		void getSEc(){}
	};
	class Datum {
	private:
		UhrZeit m_start;
		UhrZeit m_end;
		unsigned int m_Tag,
			m_Monat,
			m_Jahr;
	
	public:
		Datum();
		Datum(unsigned int, unsigned int, unsigned int);
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
		void test() {
		
		}
	};
}
#endif // !D_DateTime
