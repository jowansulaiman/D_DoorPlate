
#ifndef D_DateTime
#define D_DateTime
#include <sys/timeb.h>
#include <time.h>
#include <ostream>
#include<tuple>

namespace DateTime {
		class _Time {
		private :
			int m_Sec, m_Minute, m_Uhr;

		public:
			_Time( int,  int,  int);
			~_Time();
			std::tuple<int, int, int> get_Time();
	};

		class _Date {
		private:
			int m_Tag, m_Monat, m_Jahr;

		public:
			_Date( int,  int,  int);
			~_Date();
			std::tuple<int,int,int> get_Date();
	};

	class  _DateTimeController /*:public _Time, public _Date*/{
	private:
		std::shared_ptr<_Time> m_start_Time;
		std::shared_ptr<_Time> m_end_Time;

		std::shared_ptr<_Date> m_start_Date;
		std::shared_ptr<_Date> m_end_Date;

	public:
		_DateTimeController(int day, int month, int year, int sec, int min, int hour);
		void check_DateTime();
		std::pair<std::string, std::string>get_Start_End_DateTime();
		~_DateTimeController();
	
	};
}
#endif // !D_DateTime
