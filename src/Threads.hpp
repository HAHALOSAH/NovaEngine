#ifndef __THREADS_HPP
#define __THREADS_HPP

#if defined(__linux__) || defined(__APPLE__) // Use pthread on linux and mac
#include <pthread.h>
#elif defined(_WIN32) || defined(_WIN64) // Use windows threads on windows
#include <windows.h>
#endif // __linux__ || __APPLE__

namespace nova {
    #if defined(__linux__) || defined(__APPLE__) // Use pthread on linux and mac
    pthread_t createThread(void *(*start_routine) (void *), void *arg) {
        pthread_t thread;
        pthread_create(&thread, NULL, start_routine, arg);
        return thread;
    }
    void joinThread(pthread_t thread) {
        pthread_join(thread, NULL);
    }
    #elif defined(_WIN32) || defined(_WIN64) // Use windows threads on windows
    HANDLE createThread(void *(*start_routine) (void *), void *arg) {
        HANDLE thread;
        thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)start_routine, arg, 0, NULL);
        return thread;
    }
    void joinThread(HANDLE thread) {
        WaitForSingleObject(thread, INFINITE);
    }
    #endif // __linux__ || __APPLE__
}

#endif