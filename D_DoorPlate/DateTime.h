
#ifndef DTS_DateTime_H
#define DTS_DateTime_H
#include <sys/timeb.h>
#include <time.h>
#include <ostream>
#include <boost/date_time.hpp>
#include <chrono>
namespace DateTime {

		class _Time {
		private :
			long int  m_Minute, m_Hour;

		public:
			_Time(long int Minute, long int Hour);
			~_Time();

			long int get_Hour();
			long int get_Minute();
		
			std::string get_Time();
			bool compare_local_Time(std::shared_ptr<_Time> _DT);
			bool compare_Time(std::shared_ptr<_Time> _DT);

		public:
			_Time operator -(const _Time& _T);
			_Time operator +(const _Time& _T);
			bool operator <(_Time& _T);
			bool operator >(_Time& _T);
			bool operator ==(_Time& _T);
			bool operator !=(_Time& _T);
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
			bool compare_local_Date(std::shared_ptr<_Date> _DT);
			bool compare_Date(std::shared_ptr<_Date> _DT);

		public:
			_Date operator -(const _Date& _T);
			_Date operator +(const _Date& _T);
			bool operator <(_Date& _T);
			bool operator >(_Date& _T);
			bool operator ==(_Date& _T);
			bool operator !=(_Date& _T);
	};

	class  _DateTime:public _Time, public _Date{

	public:
		_DateTime(long int day, long int month, long int year, long int min, long int hour);
		~_DateTime();
		bool compare_local_DateTime(std::shared_ptr<_DateTime> _DT);

	public:
		_DateTime operator -( _DateTime _T);
		_DateTime operator +( _DateTime _T);
		bool operator <(_DateTime& _T);
		bool operator >(_DateTime& _T);
		bool operator ==(_DateTime& _T);
		bool operator !=(_DateTime& _T);
	};
}
#endif // !DTS_DateTime_H
