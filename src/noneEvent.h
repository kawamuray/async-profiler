#ifndef _NONEVENT_H
#define _NONEVENT_H

#include <jvmti.h>
#include <signal.h>
#include "engine.h"

class NoneEvent : public Engine {
  private:
    static void signalHandler(int signo, siginfo_t* siginfo, void* ucontext);

  public:
    const char* name() {
        return EVENT_NONE;
    }

    const char* units() {
        return "N/A";
    }

    Error start(Arguments& args);
    void stop();
};

#endif // _NONEVENT_H
