/******************************************************************************
**  Copyright(c) 2022 ignackoo. All rights reserved.
**
**  Licensed under the MIT license.
**  See LICENSE file in the project root for full license information.
**
**  This file is part of the C Log Libray.
**
*/
#ifndef __LOG_LIBRARY_H
#define __LOG_LIBRARY_H


#ifdef __cplusplus
extern "C" {
#endif
    void LogTrace(int x, FILE* pfile, int eventid, const char* fmt, ...);

    void LogDebug(int x, FILE* pfile, int eventid, const char* fmt, ...);

    void LogInfo(int x, FILE* pfile, int eventid, const char* fmt, ...);

    void LogWarning(int x, FILE* pfile, int eventid, const char* fmt, ...);

    void LogError(int x, FILE* pfile, int eventid, const char* fmt, ...);

    void LogCritical(int x, FILE* pfile, int eventid, const char* fmt, ...);
#ifdef __cplusplus
}
#endif


#endif /* __LOG_LIBRARY_H */
