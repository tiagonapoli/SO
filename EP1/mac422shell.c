#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

const char *commands[4] = {
  "protegepracaramba",
  "liberageral",
  "rodeveja",
  "rode"
};

typedef struct string { 
  char str[500];
  int sz;
} string;

void push_back(string* this, char c) {
  this->str[this->sz++] = c;
  this->str[this->sz] = '\0';
}

void get_line(string* this) {
  scanf("%[^\n]%*c", this->str);
  this->sz = strlen(this->str);
}

void get_word(string* this) {
  scanf("%s", this->str);
  this->sz = strlen(this->str);
}

void print(string this) {
  printf("[%d] [%s]\n", this.sz, this.str);
}

string* first_word(string s, string* x) {
  int i;
  x->sz = 0;
  x->str[0] = '\0';
  for(i=0;i<s.sz && s.str[i] != ' ';i++) {
    push_back(x,s.str[i]);
  }
}

string* except_first_word(string s, string* x) {
  int i;
  x->sz = 0;
  x->str[0] = '\0';
  for(i=0;i<s.sz && s.str[i] != ' '; i++) {}
  i++;
  while(i < s.sz) {
    push_back(x, s.str[i]);
    i++;
  }
}

int max(int a, int b) {
  if(a > b) return a;
  return b;
}

int check_command(char *c, int id) {
  return strcmp(c, commands[id]) == 0;
}


int main(void) {

  string input, command, args;
  char* argv[2];
  char* const envp[] = {NULL};
  int pid;
  int status;

  argv[0] = malloc(500 * sizeof(char));
  argv[1] = NULL;


  while(1) {
    
    printf("~ ");

    get_line(&input); 
    first_word(input, &command);
    except_first_word(input, &args);

    /*print(input);
    print(command);
    print(args);
    */
    if(check_command(command.str, 0)) {
      if(chmod(args.str, 0) < 0) {
        printf("%d %s\n", errno, strerror(errno)); 
      }
    } else if(check_command(command.str, 1)) {
      if(chmod(args.str, 511) < 0) {
        printf("%d %s\n", errno, strerror(errno)); 
      } 
    } else if(check_command(command.str, 2)) {
      pid = fork();
      if(pid == 0) {
        strcpy(argv[0], args.str);
        execve(args.str, argv, envp);
        printf("=> erro ao executar o programa %s\n", args.str);
        exit(127);
      } else {
        waitpid(pid, &status, 0);
        printf("=> programa %s retornou com codigo %d\n", args.str, WEXITSTATUS(status));
      }
    } else if(check_command(command.str, 3)) {
      pid = fork();
      if(pid == 0) {
        execve(args.str, argv, envp);
        printf("=> erro ao executar o programa %s\n", args.str);
        exit(127);
      }
    }
  }



  return 0;

}
