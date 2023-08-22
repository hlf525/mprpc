#pragma once
#include "lockqueue.h"
#include <stdio.h>

//定义宏    LOG_INFO("xxx %d %s", 20, "xxxxx")
#define LOG_INFO(logmsgformat, ...) \
    do \
    {  \
        Logger &logger = Logger::GetInstance();\
        logger.SetLogLevel(INFO);\
        char c[1024] = {0};\
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__);\
        logger.Log(c);\
    } while (0)


//定义宏 
#define LOG_ERROR(logmsgformat, ...) \
    do \
    {  \
        Logger &logger = Logger::GetInstance();\
        logger.SetLogLevel(ERROR);\
        char c[1024] = {0};\
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__);\
        logger.Log(c);\
    } while (0)


enum LogLevel
{
    INFO,//普通信息
    ERROR,//错误信息
};

//MPRPC框架提供的日志系统   任何系统都可以使用该日志模块
class Logger
{
public:
    //获取日志的单例
    static Logger& GetInstance();

    //设置日志级别
    void SetLogLevel(LogLevel level);
    
    //写日志
    void Log(std::string msg);

private:
    int m_loglevel;//记录日志级别
    LockQueue<std::string> m_lockqueue;//日志缓冲队列

    //防止通过拷贝构造创建新对象
    Logger();
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
};


