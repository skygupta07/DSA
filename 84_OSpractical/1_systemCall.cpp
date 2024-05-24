#include <iostream>
#include <unistd.h> // for system calls
#include <sys/wait.h> // for wait system call

using namespace std;

int main() {
    pid_t childPid;

    // Get the process ID of the parent process
    pid_t parentPid = getpid();
    cout << "Parent process ID: " << parentPid << endl;

    // Create a child process
    childPid = fork();

    if (childPid == -1) {
        // Error occurred
        cerr << "Failed to fork." << endl;
        return 1;
    } else if (childPid == 0) {
        // Child process
        // Get the process ID of the child process
        pid_t childPid = getpid();
        cout << "Child process ID: " << childPid << endl;

        // Execute a new program in the child process using exec
        char *args[] = {"/bin/ls", "-l", NULL}; // Command to execute
        execvp(args[0], args); // Execute the command
        // If execvp returns, it means an error occurred
        cerr << "Failed to execute command." << endl;
        return 1;
    } else {
        // Parent process
        cout << "Parent process waiting for child to finish..." << endl;

        // Wait for the child process to terminate
        int status;
        waitpid(childPid, &status, 0);

        if (WIFEXITED(status)) {
            cout << "Child process terminated with status: " << WEXITSTATUS(status) << endl;
        } else {
            cerr << "Child process terminated abnormally." << endl;
        }
    }

    return 0;
}
