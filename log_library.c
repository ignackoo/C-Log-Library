#include <stdio.h>
#include <time.h>

#include "log_library.h"


#define TYPE_TRACE      1
#define TYPE_DEBUG      2
#define TYPE_INFO       4
#define TYPE_WARNING    8
#define TYPE_ERROR      16
#define TYPE_CRITICAL   32


void Log_Message(FILE *pfile, int messagetype, int eventid, char* pmessage)
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

    /* message */
    fprintf(pfile, "%s", pmessage);

    /* cr lf */
    fprintf(pfile, "%s", "\n\r");

    return;
}

void LogTrace(int x, FILE* pfile, int eventid, char* pmessage)
{
    if (x) Log_Message(pfile, TYPE_TRACE, eventid, pmessage);
    return;
}

void LogDebug(int x, FILE* pfile, int eventid, char* pmessage)
{
    if (x) Log_Message(pfile, TYPE_DEBUG, eventid, pmessage);
    return;
}

void LogInfo(int x, FILE* pfile, int eventid, char* pmessage)
{
    if (x) Log_Message(pfile, TYPE_INFO, eventid, pmessage);
    return;
}

void LogWarning(int x, FILE* pfile, int eventid, char* pmessage)
{
    if (x) Log_Message(pfile, TYPE_WARNING, eventid, pmessage);
    return;
}

void LogError(int x, FILE* pfile, int eventid, char* pmessage)
{
    if (x) Log_Message(pfile, TYPE_ERROR, eventid, pmessage);
    return;
}

void LogCritical(int x, FILE* pfile, int eventid, char* pmessage)
{
    if (x) Log_Message(pfile, TYPE_CRITICAL, eventid, pmessage);
    return;
}
