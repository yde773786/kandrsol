#define NUMBER '0'
#define VAR_USED '('
#define VAR_ASSIGN ')'
#define MAXVAL 100

int getop(char a[]);
int getopstr(char a[] , char b[]); 
void push(double);
double pop(void);
void print(void);
int getloc(void);
int method(int input , char s[] , char block[]);
void swap(void);
void clear(void);
void ungets(char s[]);
int getlin(char s[] , int lim);
int getch(void);
void ungetch(int);

