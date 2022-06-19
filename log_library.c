#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#include "log_library.h"


#define TYPE_TRACE      1
#define TYPE_DEBUG      2
#define TYPE_INFO       4
#define TYPE_WARNING    8
#define TYPE_ERROR      16
#define TYPE_CRITICAL   32


void _Log_Header(FILE *pfile, int eventid, int messagetype)
{
    time_t t;
    struct tm stm;

    t = time(NULL);
#if defined _MSC_VER
    localtime_s(&stm, &t);
#else
    stm = *localtime(&t);
#endif

    /* date */
    fprintf(pfile, "%04d-%02d-%02d ", 1900 + stm.tm_year, 1 + stm.tm_mon, stm.tm_mday);

    /* time */
    fprintf(pfile, "%02d:%02d:%02d ", stm.tm_hour, stm.tm_min, stm.tm_sec);

    /* code */
    fprintf(pfile, "%8d ", eventid);

    /* type */
    if (messagetype == TYPE_TRACE)         fprintf(pfile, "   TRACE ");
    else if (messagetype == TYPE_DEBUG)    fprintf(pfile, "   DEBUG ");
    else if (messagetype == TYPE_INFO)     fprintf(pfile, "    INFO ");
    else if (messagetype == TYPE_WARNING)  fprintf(pfile, " WARNING ");
    else if (messagetype == TYPE_ERROR)    fprintf(pfile, "   ERROR ");
    else /* TYPE_CRITICAL */               fprintf(pfile, "CRITICAL ");

    return;
}

void LogTrace(int x, FILE* pfile, int eventid, const char* fmt, ...)
{
    va_list args;
    if (x)
    {
        va_start(args, fmt);
        _Log_Header(pfile, eventid, TYPE_TRACE);
        vfprintf(pfile, fmt, args);
        fprintf(pfile, "\n\r");
        va_end(args);
    }
    return;
}

void LogDebug(int x, FILE* pfile, int eventid, const char* fmt, ...)
{
    va_list args;
    if (x)
    {
        va_start(args, fmt);
        _Log_Header(pfile, eventid, TYPE_DEBUG);
        vfprintf(pfile, fmt, args);
        fprintf(pfile, "\n\r");
        va_end(args);
    }
    return;
}

void LogInfo(int x, FILE* pfile, int eventid, const char* fmt, ...)
{
    va_list args;
    if (x)
    {
        va_start(args, fmt);
        _Log_Header(pfile, eventid, TYPE_INFO);
        vfprintf(pfile, fmt, args);
        fprintf(pfile, "\n\r");
        va_end(args);
    }
    return;
}

void LogWarning(int x, FILE* pfile, int eventid, const char* fmt, ...)
{
    va_list args;
    if (x)
    {
        va_start(args, fmt);
        _Log_Header(pfile, eventid, TYPE_WARNING);
        vfprintf(pfile, fmt, args);
        fprintf(pfile, "\n\r");
        va_end(args);
    }
    return;
}

void LogError(int x, FILE* pfile, int eventid, const char* fmt, ...)
{
    va_list args;
    if (x)
    {
        va_start(args, fmt);
        _Log_Header(pfile, eventid, TYPE_ERROR);
        vfprintf(pfile, fmt, args);
        fprintf(pfile, "\n\r");
        va_end(args);
    }
    return;
}

void LogCritical(int x, FILE* pfile, int eventid, const char* fmt, ...)
{
    va_list args;
    if (x)
    {
        va_start(args, fmt);
        _Log_Header(pfile, eventid, TYPE_CRITICAL);
        vfprintf(pfile, fmt, args);
        fprintf(pfile, "\n\r");
        va_end(args);
    }
    return;
}
