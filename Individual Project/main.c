//
//  main.c
//  Individual Project
//
//  Created by Immanuel on 29/11/2020.
//  Copyright © 2020 Immanuel Antwi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <pthread.h>

#define NTHREADS 10
#define MAX_ARGS 10

//creating a global array to keep track of the commands that are being provided by the user
char *commands;
char *parameters[900];
char *directories[900];
int num_of_commands = 0;
int num_elements_command = 0;


char error_message[30] = "An error has occurred\n";
//the commandstruct structure is meant to contain the number of commands and the array of commands
typedef struct __mycommands{
    char * cmd;
    char *redirect;
    int argc;    //number of args for the cmd
    char *argv[MAX_ARGS];
    char cmd_suffix;
    } __mycommands;


//concat() function is meant to concatenate 2 strings(i.e path and filename) into 1 string.
char *concat(char *s1,char *s2){
   return 0;
    }


//path() provides different paths that a file can be located in and executed.
void path(){
    
    }
    
    
    
//cd() changes the currennt directory of the wish bash shell
void cd(char *d){
    
    }
int runCommand(__mycommands * command1) {
    char cmd[100];
    printf("Command: %s\n", command1->cmd);
    strcpy(cmd, "/bin/");
    strcat(cmd,command1->cmd);
    execv(cmd,command1->argv);
    //execvp(command1->cmd, command1->argv);
        //printf("%s\n%s\n%s\n", command1->argv[0], command1->argv[1], command1->argv[2]);
    return 1;

    }
    
//strremove() takes out all of the newline characters from the inputs given by the user
char *strremove(char *str, const char *sub) {
    return 0;
    }



//execute_file() is used to execute the commands provided by the user
int execute_file(){
    return 0;
    }

//the execute_command() function is responsble for executing the command and the parameters passed into the function.
void *execute_command(__mycommands *command1){
    //char *env[] = { (char *) "PATH=/bin",0};
    
    pid_t  pid;
    int    status;

    if ((pid = fork()) < 0) {     /* fork a child process           */
         printf("*** ERROR: forking child process failed\n");
         exit(1);
    }
    else if (pid == 0) {          /* for the child process:         */
        runCommand(command1);
         return(0);
    }
    else {                                  /* for the parent:      */
         while (wait(&status) != pid)       /* wait for completion  */
              ;
    }
//    pid_t childstatus;
//    childstatus = fork();
//    if (childstatus != 0) { //if parent process is running
//        wait(NULL);
//    } else {
//        /* This area is child process */
//        runCommand(command1);
//        return(0);
//    }

  
    return 0;
    }

//check_file() function checks to see if a file can be found in any of the directories and if it is executable
int check_file(char *c){
    return 0;
    }

//parallel_check_file() is responsible for checking whether a file provided through parallel commands is executable.
int parallel_check_file(char *c){
    return 0;
    }



//stringInput() function splits the input provided by the user into tokens and places them in an array
int split_input(char *s){
    return 0;
    }

//the check_redirect() function checks to see whether the commands that the user provides contains '>'
int check_redirect(){
    
    return 0;
    }

//the redirect() function performs the redirects the output of the commands provided into the given file
void redirection(){
        
    }

//the check_parallel() function is responsible to checkking if the command provided by the user involves the execution of parallel commands
int check_parallel(){
    return 0;
    }
    


    
//the parallel_commands() function is responsible for performing the parallel commands provided by the user
int parallel_commands(){
    return 0;
    }

void wishMessage(){
    write(STDOUT_FILENO, "wish> ", strlen("wish> "));
}

void *getCommands(char *arg[]){
   
    char *splittedCharacters;
    char space[100];
    int cmdlen;
    __mycommands *command1 = (__mycommands*) malloc(sizeof(__mycommands));
    command1->argc = 0;
    strcpy(space," ");
     command1->cmd = *arg;
     command1->argv[0] = command1->cmd;
    while((splittedCharacters = strtok_r(*arg," ",arg))){
            
        if (sizeof(splittedCharacters)==0){
           break;
        }
        cmdlen = strlen(splittedCharacters);
        if (splittedCharacters[cmdlen-1] == '\n') {    //
            splittedCharacters[cmdlen-1] = '\0';    //
        }
        
        if (strcmp(splittedCharacters, "exit") == 0){
            exit(1);
        }
        command1->argv[command1->argc] = splittedCharacters;    //put arg into arg array
        command1->argc = command1->argc+1;
        
        
           }
    execute_command(command1);
    
     
return 0;
}

//Runs interative mode
void interactiveMode(){
    
    while (1){
        wishMessage();
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        read = getline(&line,&len,stdin);
        
        getCommands(&line);
    }
}

//Runs Bash mode
void bashMode(char *filename){
    FILE *in_file = fopen(filename,"r");
    if (in_file == NULL)
        exit(EXIT_FAILURE);
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *splittedCharacters;
    while ((read = getline(&line, &len, in_file)) != -1) {
        while((splittedCharacters = strtok_r(line," ",&line))){
            printf("%s\n", splittedCharacters);
        }
      
    }
    
}



//the main function of the wish command is going to simulate a shell program.
int main(int argc,char *argv[]){
    if (argc==1){
        printf("Executing in Interactive mode..... \n");
        interactiveMode();
    }
    
    if (argc ==2){
        char * fileName = argv[1];
        printf("Executing in Bash \n");
        bashMode(fileName);
        
    }
    if (argc>2){
        write(STDOUT_FILENO, "wish> ", strlen("wish> "));
        exit(1);
    }
    
    return 0;
    
    }
