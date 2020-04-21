
#ifndef DTS_DateTime_H
#define DTS_DateTime_H
#include <sys/timeb.h>
#include <time.h>
#include <ostream>
#include<tuple>

namespace DateTime {
		class _Time {
		private :
			int m_Sec, m_Minute, m_Hour;

		public:
			_Time(int Sec, int Minute, int Hour);
			~_Time();
			int get_Hour();
			int get_Minute();
			int get_Second();
	};

		class _Date {
		private:
			int m_Day, m_Month, m_Year;

		public:
			_Date(int Day, int Month, int Year);
			~_Date();
			int get_Year();
			int get_Month();
			int get_Day();

	};

	class  _DateTime:public _Time, public _Date{

	public:
		_DateTime(int day, int month, int year, int sec, int min, int hour);
		~_DateTime();

		std::tuple<int, int, int> get_Time();
		std::tuple<int, int, int> get_Date();
	};
}
#endif // !DTS_DateTime_H
