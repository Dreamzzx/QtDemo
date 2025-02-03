#include "log.h"

const char* Log::log_level[LEVEL_COUNT]={
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL",
    "OFF",
};
Log* Log::m_instance = NULL;

Log* Log::instance()
{
    if(m_instance == nullptr)
    {
        m_instance = new Log();
    }
    return m_instance;
}

void Log::open(std::string filename)
{
    log_filename = filename;

    fileStream.open(filename,std::ios::app|std::ios::out);
}

void Log::close()
{
    if(fileStream.is_open())
    {
        fileStream.close();
        delete m_instance;
        m_instance = nullptr;
    }
}

void Log::log(Level level, const char *file, int line, const char *format,...)
{
    if(fileStream.is_open())
    {
        time_t ticks = time(NULL);
        struct tm* tm = std::localtime(&ticks);
        char timestamp[32];
        std::memset(timestamp,0,sizeof(timestamp));
        std::strftime(timestamp,sizeof(timestamp),"%Y-%m-%d %H-%M-%S",tm);

        // 打印time
        const char* fmt ="%s %s %s:%d";
        int size = snprintf(NULL,0,fmt,timestamp,log_level[level],file,line);
        if(size > 0)
        {
            char * buffer = new char[size + 1];
            snprintf(buffer,size+1,fmt,timestamp,log_level[level],file,line);
            buffer[size] ='\0';
            fileStream<<buffer<<std::endl;
            delete[] buffer;
        }

        // 打印text
        va_list arg_ptr;
        va_start(arg_ptr,format);
        size = vsnprintf(NULL,0,fmt,arg_ptr);
        va_end(arg_ptr);
        if(size > 0)
        {
            char * buffer = new char[size + 1];
            va_start(arg_ptr,format);
            vsnprintf(buffer,size + 1,format,arg_ptr);
            fileStream<<buffer<<std::endl;
            va_end(arg_ptr);
            delete[] buffer;
        }
    }
}

Log::Log()
{

}

Log::~Log()
{

}

