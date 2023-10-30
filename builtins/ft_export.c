#include <stdio.h>  // Including the standard input-output header file for functions like printf.
#include <stdlib.h> // Including the standard library header for functions like exit.
 
/**
 * Executes the "export" command in the shell.
 *
 * @param variable: The name of the environment variable to export.
 * @param value: The value to assign to the environment variable.
 * @return: 0 if the export was successful, -1 otherwise.
 */
int exportVariable(const char* variable, const char* value) {
    // Constructing the command string to export the variable.
    char command[100];
    snprintf(command, sizeof(command), "export %s=%s", variable, value);
 
    // Executing the command using the system function.
    int result = system(command);
 
    if (result == -1) {  // Checking if the command execution failed.
        printf("Export failed.\n");
        return -1;
    }
 
    return 0;  // Returning 0 to indicate successful export.
}
 
// Usage example for exportVariable
 
int main() {
    const char* variable = "MY_VARIABLE";
    const char* value = "my_value";
 
    printf("Exporting variable: %s=%s\n", variable, value);
    int exportResult = exportVariable(variable, value);
 
    if (exportResult == 0) {
        printf("Export successful.\n");
    } else {
        printf("Export failed.\n");
    }
 
    return 0;
}