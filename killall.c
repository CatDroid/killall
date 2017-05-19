/*
 * Encode	: utf-8 NO BOM
 * Editor	: hanloong ho 
 * Data		: 2017.05.19
 * Title	: Android killall 
 * Url		: https://github.com/CatDroid/killall.git
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <android/log.h>


#define LOGI(fmt, ...) __android_log_print(ANDROID_LOG_VERBOSE, "killall", fmt ,  ##__VA_ARGS__)


int find_pid_by_name(char *ProcName, int *foundpid) {
    DIR *dir;
    struct dirent *d;
    int pid, i;
    char *s;
    int pnlen;

    i = 0;
    foundpid[0] = 0;
    pnlen = strlen(ProcName);

    /* Open the /proc directory. */
    dir = opendir("/proc");
    if (!dir) {
        printf("cannot open /proc");
        return -1;
    }

    /* Walk through the directory. */
    while ((d = readdir(dir)) != NULL) {

        char exe[PATH_MAX + 1];
        char path[PATH_MAX + 1];
        int len;
        int namelen;

        /* See if this is a process */
        if ((pid = atoi(d->d_name)) == 0) continue;

        snprintf(exe, sizeof(exe), "/proc/%s/exe", d->d_name);
        LOGI("find_pid_by_name  exe = %s.\n", exe);
        if ((len = readlink(exe, path, PATH_MAX)) < 0)
            continue;
        path[len] = '\0';

        /* Find ProcName */
        s = strrchr(path, '/');
        if (s == NULL) continue;
        s++;

        /* we don't need small name len */
        namelen = strlen(s);
        LOGI("s = %s\n", s);
        if (namelen < pnlen) continue;

        if (!strncmp(ProcName, s, pnlen)) {
            /* to avoid subname like search proc tao but proc taolinke matched */
            if (s[pnlen] == ' ' || s[pnlen] == '\0') {
                foundpid[i] = pid;
                i++;
            }
        }
    }

    foundpid[i] = 0;
    closedir(dir);

    return 0;

}


int main(int argc, char *argv[]) {
    int i, rv, pid_t[128];
    int status = 0;

    if (argc != 2) {
        LOGI("Usage %s procname\n", argv[0]);
        return 0;
    }

    rv = find_pid_by_name(argv[1], pid_t);
    LOGI("rv = %d.\n", rv);

    for (i = 0; pid_t[i] != 0; i++) {
        char process_pid[20];
        int pid = 0;
        memset(&process_pid, 0x0, 10);
        sprintf(process_pid, " %d", pid_t[i]);
        LOGI("process_pid = %s.\n", process_pid);
        pid = vfork();
        if (pid < 0) {
            LOGI("(out)vfork error");
            continue;
        }
        if (0 == pid) {
            execl("/system/bin/kill", "/system/bin/kill", process_pid, (char *) 0);
			//execl("/system/bin/kill", "/system/bin/kill", "-s 9", process_pid, (char *) 0);
        } else {
            while (waitpid(pid, &status, 0) < 0) {
                printf("waitpid error pid:%d \n", pid);
                break;
            }
        }
    }
    return 0;
}