#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdarg>

class Log
{
public:
    enum Level{
        DEBUG = 0,
        INFO,
        WARN,
        ERROR,
        FATAL,
        OFF,
        LEVEL_COUNT
    };
    static Log* instance(); // 获取实例

    void open(std::string filename);

    void close();

    void log(Level level,const char* file,int line,const char* format,...);
private:
    Log();
    ~Log();

    std::ofstream fileStream;
    static const char* log_level[LEVEL_COUNT];
    std::string log_filename;
    static Log* m_instance;
};

#define debug(format,...) \
Log::instance()->log(Log::DEBUG,__FILE__,__LINE__,format,##__VA_ARGS__);

#define info(format,...) \
Log::instance()->log(Log::INFO,__FILE__,__LINE__,format,##__VA_ARGS__);

#define warn(format,...) \
Log::instance()->log(Log::WARN,__FILE__,__LINE__,format,##__VA_ARGS__);

#define error(format,...) \
Log::instance()->log(Log::ERROR,__FILE__,__LINE__,format,##__VA_ARGS__);

#define fatal(format,...) \
Log::instance()->log(Log::FATAL,__FILE__,__LINE__,format,##__VA_ARGS__);

#endif // LOG_H
