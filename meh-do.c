#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_SHELL "sh"

/*
 * Adds various sbin directories to the path so that executables in those
 * directories can be called by meh-do.
 *
 * Returns 0 on success, or any other integer on failure.
 */
int add_sbin_to_path() {
    char *sbin_str = "/sbin:/usr/sbin:/usr/local/sbin:";
    char *curr_path = getenv("PATH");
    if (curr_path == NULL) {
        return 1;
    }
    size_t path_len = strlen(curr_path) + strlen(sbin_str);
    char new_path[path_len];
    memset(new_path, 0, path_len);
    strncat(new_path, sbin_str, strlen(sbin_str));
    strncat(new_path, curr_path, strlen(curr_path));
    return setenv("PATH", new_path, 1);
}

int main (int argc, char **argv)
{
    add_sbin_to_path();

    /*
     * We should start looking at arguments after arg[0]
     */
    char **exec_args = (argv + 1);

    /* If the user didn't specify any arguments, open a login shell */
    if (exec_args[0] == NULL) {
        char *shell = getenv("SHELL");
        if (shell == NULL)
            shell = DEFAULT_SHELL;

        exec_args = (char*[]){ shell, "-l", NULL };
    }

    /* Run the command provided */
    if (execvp(exec_args[0], exec_args) != 0) {
        fprintf(stderr, "Unable to execute %s\n", exec_args[0]);
        return 1;
    }
}

