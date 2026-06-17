#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <utmp.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

#define LOG_FILE "/tmp/login_daemon.log"
#define MAX_SESSIONS 256

typedef struct {
    char user[32];
    char line[32];
} session_t;

session_t sessions[MAX_SESSIONS];
int session_count = 0;

/* ghi log file */
void log_message(const char *msg) {
    int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        return;
    }
    write(fd, msg, strlen(msg));
    close(fd);
}

/* tao daemon dung chuan UNIX */
void daemonize() {
    pid_t pid;

    /* fork lan 1 */
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    /* tao session moi */
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }

    /* fork lan 2 */
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    /* chuyen sang root dir */
    chdir("/");

    /* reset permission */
    umask(0);

    /* dong standard FD */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

/* tim session da ton tai chua */
int is_new_session(const char *user, const char *line) {
    for (int i = 0; i < session_count; i++) {
        if (strcmp(sessions[i].user, user) == 0 &&
            strcmp(sessions[i].line, line) == 0) {
            return 0;
        }
    }

    if (session_count < MAX_SESSIONS) {
        strncpy(sessions[session_count].user, user, 31);
        sessions[session_count].user[31] = '\0';

        strncpy(sessions[session_count].line, line, 31);
        sessions[session_count].line[31] = '\0';

        session_count++;
    }

    return 1;
}

/* doc utmp va detect login moi */
void check_logins() {
    struct utmp *entry;

    setutent();

    while ((entry = getutent()) != NULL) {

        if (entry->ut_type != USER_PROCESS) {
            continue;
        }

        if (entry->ut_user[0] == '\0') {
            continue;
        }

        if (is_new_session(entry->ut_user, entry->ut_line)) {

            time_t t = time(NULL);
            char *ts = ctime(&t);
            ts[strcspn(ts, "\n")] = 0;

            char buf[512];

            snprintf(buf, sizeof(buf),
                     "[%s] LOGIN user=%s tty=%s host=%s\n",
                     ts,
                     entry->ut_user,
                     entry->ut_line,
                     entry->ut_host ? entry->ut_host : "-");

            log_message(buf);
        }
    }

    endutent();
}

int main() {

    /* CHUYEN THANH DAEMON */
    daemonize();

    log_message("[daemon] login monitor started\n");

    while (1) {
        check_logins();
        sleep(5);
    }

    return 0;
}
