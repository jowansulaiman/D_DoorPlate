#ifndef WiFi_h
#define WiFi_h

namespace WiFi {
	class WiFi_Connection {
	private:
		const char* m_Host;
		const char* m_Password;
	public:
		WiFi_Connection();
	};
}
#endif // !WiFi_h
