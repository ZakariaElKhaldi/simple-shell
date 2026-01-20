#include<stdio.h>
#include<stdlib.h>

#define init_size 1024

// a function that return the command
// a comand is a sequence of words and each word will be treated as a token
char* get_command();

// return a double pointer to a token buffer
char** split_command_to_tokens(char* command);

int dash_exit();

// check the tokens and execute the command
int dash_execute(char** tokens);

int main(){
    return 0;
}

char* get_command(){
    int buffer_size = init_size;
    int buffer_index = 0;
    char* buffer = malloc(sizeof(char) * buffer_size);
    char courent_charachter;

    if (!buffer) {
        printf("buffer allocation error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        courent_charachter= getchar();
        if (courent_charachter == EOF || courent_charachter == '\n') {
            buffer[buffer_index] = '\0';
            // exiting
            return buffer;
        }else {
            buffer[buffer_index] = courent_charachter;
        }
        buffer_index++;
        if (buffer_index >= buffer_size) {
            buffer_size += init_size;
            buffer = realloc(buffer, buffer_size);
            if (!buffer) {
                printf("buffer reallocation error");
                exit(EXIT_FAILURE);
            }
        }
    }
}
