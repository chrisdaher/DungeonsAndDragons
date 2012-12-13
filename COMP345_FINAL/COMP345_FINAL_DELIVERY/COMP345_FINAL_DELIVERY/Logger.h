#ifndef LOGGER_H
#define LOGGER_H
static ref class Logger{
public:
	static System::String^ currentLogInfo;
	static void LogInfo(System::String^ theInfo){
		currentLogInfo += theInfo + "\n";
	}
};
#endif