#include <iostream>
#include <ev.h>
#include <unistd.h>

static ev_io gStdinWatcher;
static ev_timer gTimeoutWatcher;
static ev_signal gSignalWatcher;

static void stdinWatcherCB(EV_P_ ev_io *aWatcher, int aReadEvents) {
    std::cout << "stdinWatcherCB called" << std::endl;
    ev_io_stop(EV_A_ aWatcher);
    ev_break(EV_A_ EVBREAK_ALL);
}
static void timeoutWatcherCB(EV_P_ ev_timer *aWatcher, int aReadEvents) {
    std::cout << "timeoutWatcherCB called" << std::endl;
    ev_break(EV_A_ EVBREAK_ONE);
}
static void signalWatcherCB(EV_P_ ev_signal *aWatcher, int aReadEvents) {
    std::cout << "signalWatcherCB called" << std::endl;
    ev_break(EV_A_ EVBREAK_ALL);
}


int main(int argC, char *argV[]) {
    std::cout << "starting..." << std::endl;

//loop create
    struct ev_loop *loop = EV_DEFAULT;

//io
    ev_io_init(&gStdinWatcher, stdinWatcherCB, STDIN_FILENO, EV_READ);
    ev_io_start(EV_A_ &gStdinWatcher);

//timer
    ev_timer_init(&gTimeoutWatcher, timeoutWatcherCB, 5.5, 0.0);
    ev_timer_start(EV_A_ &gTimeoutWatcher);

    std::cout << "started!" << std::endl;

//run loop
    ev_run(EV_A_ 0);

    std::cout << "stopped!" << std::endl;
    return 0;
}