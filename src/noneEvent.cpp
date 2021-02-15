#include <signal.h>
#include "profiler.h"
#include "noneEvent.h"

void NoneEvent::signalHandler(int signo, siginfo_t* siginfo, void* ucontext) {
    if (!Profiler::_instance.isEventWriterThread()) {
        Profiler::_instance.recordSample(ucontext, 1, 0, NULL);
    }
}

Error NoneEvent::start(Arguments& args) {
    OS::installSignalHandler(SIGPROF, signalHandler);
    return Error::OK;
}

void NoneEvent::stop() {
    OS::installSignalHandler(SIGPROF, NULL, SIG_IGN);
}
