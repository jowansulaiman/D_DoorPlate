
#ifndef D_DateTime
#define D_DateTime
#include <sys/timeb.h>
#include <time.h>
#include <ostream>
namespace DateTime {
		class _Time {
		private :
			int m_Sec;
			int m_Minute;
			int m_Uhr;

		protected:
			std::pair<std::string, std::string> check_Time();
			
		public:
			_Time( int,  int,  int);
			~_Time();
			std::string get_Time();
		//friend std::ostream& operator << (std::ostream& _OS, const  _Time& T);
	};

		class _Date {
		private:
			int m_Tag, m_Monat, m_Jahr;
		
		protected:
			std::pair<std::string, std::string> check_Date();

		public:
			_Date( int,  int,  int);
			~_Date();
			std::string get_date();
	};

	class  ZeitStempel /*:public _Time, public _Date*/{
	private:
		_Time m_start_Time;
		_Time m_end_Time;

		_Date m_start_Date;
		_Date m_end_Date;

	public:
		ZeitStempel();
		void check_DateTime();
		std::pair<std::string, std::string>get_Start_End_DateTime();
		~ZeitStempel();
	
	};
}
#endif // !D_DateTime
