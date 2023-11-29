#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void HandleAlarm(int sig) {
    // Пуста функція, оскільки нам не потрібно робити щось конкретне при отриманні сигналу
}

void SetupAlarm(int duration, const char *text) {
    signal(SIGALRM, HandleAlarm);
    alarm(duration);
    pause();
    printf("Alarm triggered: %s\n", text);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <duration in seconds> <message>\n", argv[0]);
        return 1;
    }

    int duration = atoi(argv[1]);
    const char *message = argv[2];

    pid_t childPID = fork();

    if (childPID < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (childPID == 0) {
        SetupAlarm(duration, message);
        exit(0);
    } else {
        printf("Alarm set for %d seconds. Child process PID: %d\n", duration, childPID);
        exit(0);
    }

    return 0;
}