#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define INIT_SIZE 1024
#define TOKENS_SEPERATORS " " 

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
    int buffer_size = INIT_SIZE;
    int courent_buffer_index = 0;
    char* buffer = malloc(sizeof(char) * buffer_size);
    char courent_charachter;

    if (!buffer) {
        printf("buffer allocation error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        courent_charachter= getchar();
        if (courent_charachter == EOF || courent_charachter == '\n') {
            buffer[courent_buffer_index] = '\0';
            // exiting
            return buffer;
        }else {
            buffer[courent_buffer_index] = courent_charachter;
        }
        courent_buffer_index++;
        if (courent_buffer_index >= buffer_size) {
            buffer_size += INIT_SIZE;
            buffer = realloc(buffer, buffer_size);
            if (!buffer) {
                printf("buffer reallocation error");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char** split_command_to_tokens(char* command){
    // we know that a comand is a sequence of words/tokens that is seperated by spaces
    int buffer_size = INIT_SIZE;
    int courent_buffer_index = 0;
    char** tokens_buffer = malloc(buffer_size * sizeof(char*));
    

    if(!tokens_buffer){
        printf("tokens buffer initialisation error");
        exit(EXIT_FAILURE);
    }

    char* courent_token = strtok(command, TOKENS_SEPERATORS);
    while (courent_token != NULL) {
        tokens_buffer[courent_buffer_index] = courent_token;
        courent_buffer_index++;

        if(courent_buffer_index >= buffer_size){
            buffer_size += INIT_SIZE;
            tokens_buffer = realloc(tokens_buffer, buffer_size);
        }

        if (!tokens_buffer) {
            printf("tokens buffer reallocation error");
            exit(EXIT_FAILURE);
        }

        courent_token = strtok(NULL, TOKENS_SEPERATORS);
    }

    tokens_buffer[courent_buffer_index] = NULL;

    return tokens_buffer;
}
