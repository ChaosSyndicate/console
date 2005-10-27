#pragma once

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

class ConsoleHandler {

	public:
		ConsoleHandler();
		~ConsoleHandler();

	public:

		DWORD StartMonitorThread();
		void StopMonitorThread();

	private:

		bool OpenSharedMemory();

		void ReadConsoleBuffer();

		void ResizeConsoleWindow(HANDLE hStdOut);

	private:

		static DWORD WINAPI MonitorThreadStatic(LPVOID lpParameter);
		DWORD MonitorThread();

	private:

		shared_ptr<void>			m_hParentProcess;

		SharedMemory<ConsoleStartupParams>			m_startupParams;
		SharedMemory<CONSOLE_SCREEN_BUFFER_INFO>	m_consoleInfo;
		SharedMemory<CHAR_INFO>		m_consoleBuffer;

		shared_ptr<void>			m_hMonitorThread;
		shared_ptr<void>			m_hMonitorThreadExit;

		DWORD						m_dwScreenBufferSize;
};

//////////////////////////////////////////////////////////////////////////////


