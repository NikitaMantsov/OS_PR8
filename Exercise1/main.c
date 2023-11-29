#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void HandleSigInt(int signum) {
    printf("Caught SIGINT signal. Process will continue.\n");
}

void HandleSigTerm(int signum) {
    printf("Caught SIGTERM signal. Process will continue.\n");
}

void HandleSigUsr1(int signum) {
    printf("Caught SIGUSR1 signal. Exiting...\n");
    exit(0);
}

void SetSignalHandlers() {
    signal(SIGINT, HandleSigInt);
    signal(SIGTERM, HandleSigTerm);
    signal(SIGUSR1, HandleSigUsr1);
    signal(SIGPROF, SIG_DFL);
    signal(SIGHUP, SIG_IGN);
}

int main() {
    SetSignalHandlers();

    while (1) {
        pause();
    }

    return 0;
}
