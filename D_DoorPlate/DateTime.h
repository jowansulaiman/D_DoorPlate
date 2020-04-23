
#ifndef DTS_DateTime_H
#define DTS_DateTime_H
#include <sys/timeb.h>
#include <time.h>
#include <ostream>
#include<tuple>
#include <boost/date_time.hpp>
namespace DateTime {

		class _Time {
		private :
			long int m_Sec, m_Minute, m_Hour;

		public:
			_Time(long int Sec, long int Minute, long int Hour);
			~_Time();
			long int get_Hour();
			long int get_Minute();
			long int get_Second();
			std::string get_Time();
		
		public:
			_Time operator -(const _Time& _T);
			_Time operator +(const _Time& _T);
			bool operator <(_Time& _T);
			bool operator >(_Time& _T);
			bool operator ==(_Time& _T);
	};

		class _Date {
		private:
			long int m_Day, m_Month, m_Year;

		public:
			_Date(long int Day, long int Month, long int Year);
			~_Date();
			long int get_Year();
			long int get_Month();
			long int get_Day();
			std::string get_Date();

		public:
			_Date operator -(const _Date& _T);
			_Date operator +(const _Date& _T);
			bool operator <(_Date& _T);
			bool operator >(_Date& _T);
			bool operator ==(_Date& _T);
	};

	class  _DateTime:public _Time, public _Date{

	public:
		_DateTime(long int day, long int month, long int year, long int sec, long int min, long int hour);
		~_DateTime();


		_DateTime operator -( _DateTime _T);
		_DateTime operator +( _DateTime _T);
		bool operator <(_DateTime& _T);
		bool operator >(_DateTime& _T);
		bool operator ==(_DateTime& _T);
	};
}
#endif // !DTS_DateTime_H
