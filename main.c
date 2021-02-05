#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

extern  int ft_strlen(char *);
extern char* ft_strcpy(char *, char *);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);
extern char *ft_strdup(const char *s1);


void error_chr(char *me, char *tr)
{
    if(strcmp(me, tr) != 0)
        printf("\033[0;31m KO :(\n");
    else if (strcmp(me, tr) == 0)
        printf("\033[0;32m OK :)\n");
}

void error_test(int me, int tr)
{
    if(me != tr)
        printf("\033[0;31m KO :(\n");
    else if (me == tr)
       printf("\033[0;32m OK :)\n");
}
void error_cmp(int g, int k)
{
    if((k > 0 && g > 0) || (k < 0 && g < 0) || (k == 0 && g == 0))
        printf("\033[0;32m OK :)\n");
    else
        printf("\033[0;31m KO :(\n");
}

int main()
{
    //black ==> \033[0;30m
    //red ==> \033[0;31m
    // green ==> \033[0;32m
    //yellow ==> \033[0;33m
    //purple \033[0;35m
    //\033 is Escape
    int me,tr;
    int g,k, z, r, trm, tro;
    char *x, *y, *wri, *hem, *lmee;
    me = ft_strlen("Null37");
    tr = strlen("Null37");
    
    /*############## ft_strlen ##################################*/
    printf("\033[0;33m ################|ft_strlen|#############\n");

    printf("\033[0;36m normal string ==>");
    error_test(me, tr);
    me = ft_strlen("");
    tr = strlen("");
    printf("\033[0;36m empty string ==>");
    error_test(me, tr);


    me = ft_strlen("   ajfjen njn eohfohqiofh oekfnkl lqkiooqhfohoq;ljkoq;fn;  hufhqjf nfo oqfonjn jonfjo nqofnnqbfu3 bqjfb j  qnjdnjo qn3djnj qnkbkb qjo oh 3koqh o3fon qonfjnqjlnfjl njijqjnfknqjknfj n jqnfon o3nofnpq3fjonn nfnqfjnqou3fn jqnfjnqj3 nofnqojn");
    tr = strlen("   ajfjen njn eohfohqiofh oekfnkl lqkiooqhfohoq;ljkoq;fn;  hufhqjf nfo oqfonjn jonfjo nqofnnqbfu3 bqjfb j  qnjdnjo qn3djnj qnkbkb qjo oh 3koqh o3fon qonfjnqjlnfjl njijqjnfknqjknfj n jqnfon o3nofnpq3fjonn nfnqfjnqou3fn jqnfjnqj3 nofnqojn");
    printf("\033[0;36m long string ==>");
    error_test(me, tr);
    /*################ ft_strcpy ##############################*/
    printf("\033[0;33m ################|ft_strcpy|#############\n");


    char dest[2000];
    char dest2[2000];
    x = ft_strcpy(dest, "Null37");
    y = strcpy(dest2, "Null37");
    printf("\033[0;36m normal string ==>");
    error_chr(dest, dest2);
  
    x = ft_strcpy(dest, "");
    y = strcpy(dest2, "");
    printf("\033[0;36m empty string ==>");
    error_chr(dest, dest2);
    printf("\033[0;36m long string ==>");
    x = ft_strcpy(dest,"    ajfjen njn eohfohqiofh oekfnkl lqkiooqhfohoq;ljkoq;fn;  hufhqjf nfo oqfonjn jonfjo nqofnnqbfu3 bqjfb j  qnjdnjo qn3djnj qnkbkb qjo oh 3koqh o3fon qonfjnqjlnfjl njijqjnfknqjknfj n jqnfon o3nofnpq3fjonn nfnqfjnqou3fn jqnfjnqj3 nofnqojn");
    y = strcpy(dest2,"    ajfjen njn eohfohqiofh oekfnkl lqkiooqhfohoq;ljkoq;fn;  hufhqjf nfo oqfonjn jonfjo nqofnnqbfu3 bqjfb j  qnjdnjo qn3djnj qnkbkb qjo oh 3koqh o3fon qonfjnqjlnfjl njijqjnfknqjknfj n jqnfon o3nofnpq3fjonn nfnqfjnqou3fn jqnfjnqj3 nofnqojn");
    error_chr(dest, dest2);

    /*######################### ft_strcmp ##########################*/
    printf("\033[0;33m ################|ft_strcmp|#############\n");
    g = ft_strcmp("", "");
    k = strcmp("", "");
    printf("\033[0;36m empty string ==> ");
    error_cmp(g, k);

    g = ft_strcmp(" ", "");
    k = strcmp(" ", "");
    printf("\033[0;36m one empty string first argument ==> ");
    error_cmp(g,k);

    g = ft_strcmp("", " ");
    k = strcmp("", " ");
    printf("\033[0;36m one empty string second argument ==> ");
    error_cmp(g,k);

    g = ft_strcmp("abc", "abc");
    k = strcmp("abc", "abc");
    printf("\033[0;36m equl string ==> ");
    error_cmp(g,k);

    g = ft_strcmp("abc", "edtg");
    k = strcmp("abc", "edtg");
    printf("\033[0;36m multiple string ==> ");
    error_cmp(g,k);

    g = ft_strcmp("abc", "abe");
    k = strcmp("abc", "abe");
    printf("\033[0;36m change last character ==> ");
    error_cmp(g,k);
    /*###########################| ft_write |#################################*/
    printf("\033[0;33m ################|ft_write|#############\n");
    wri = "Null37\n";
    printf("\033[0;36m output for my write ==>");
    z = ft_write(1, wri, sizeof(wri));
    r = write(1, wri, sizeof(wri));
    error_test(z, r);

    printf("\033[0;36m test wrong file ==> \n");
    int fd = open("test.txt", O_RDWR);
    z = ft_write(fd, wri, 2);
    r = write(fd, wri, 2);
    printf("%d\n", z);
    printf("%d", r);
    error_test(z, r);

    printf("\033[0;36m test open  file  \n");
    int fd2 = open("write_test.txt", O_CREAT | O_RDWR, 777);
    z = ft_write(fd2, "NULL37\n", 8);
    r = write(fd2, "NULL37\n", 8);
    printf("%d\n", z);
    printf("%d", r);
    error_test(z, r);

    /*###########################| ft_read |#################################*/
    printf("\033[0;33m ################|ft_read|#############\n");
    printf("\033[0;35m test stdin \n");
    char *buff;
    trm = ft_read(0, &buff, 10);
    tro = read(0, &buff, 10);
    error_test(trm, tro);
    
    printf("\033[0;35m test read open file \n");
    int fd3 = open("main.c", O_RDONLY);
    trm = ft_read(fd3, &buff, 10);
    tro = read(fd3, &buff, 10);
    error_test(trm, tro);

    printf("\033[0;35m test read  wrong file \n");
    fd3 = open("main.abc", O_RDONLY);
    trm = ft_read(fd3, &buff, sizeof(buff));
    tro = read(fd3, &buff, sizeof(buff));
    error_test(trm, tro);

    /*###########################| ft_strdup |#################################*/
    printf("\033[0;33m ################| ft_strdup|#############\n");
    hem = strdup("Null37");
    lmee = ft_strdup("Null37");
    printf("\033[0;35m |%s|\n", hem);
    printf("\033[0;35m |%s|", lmee);
    printf("\033[0;36m \ntest strdup equl string ==> ");
    error_chr(lmee, hem);

    hem = strdup("");
    lmee = ft_strdup("");
    printf("\033[0;36m \ntest strdup empty string ==> ");
    error_chr(lmee, hem);

    hem = strdup("    ajfjen njn eohfohqiofh oekfnkl lqkiooqhfohoq;ljkoq;fn;  hufhqjf nfo oqfonjn jonfjo nqofnnqbfu3 bqjfb j  qnjdnjo qn3djnj qnkbkb qjo oh 3koqh o3fon qonfjnqjlnfjl njijqjnfknqjknfj n jqnfon o3nofnpq3fjonn nfnqfjnqou3fn jqnfjnqj3 nofnqojn");
    lmee = ft_strdup("    ajfjen njn eohfohqiofh oekfnkl lqkiooqhfohoq;ljkoq;fn;  hufhqjf nfo oqfonjn jonfjo nqofnnqbfu3 bqjfb j  qnjdnjo qn3djnj qnkbkb qjo oh 3koqh o3fon qonfjnqjlnfjl njijqjnfknqjknfj n jqnfon o3nofnpq3fjonn nfnqfjnqou3fn jqnfjnqj3 nofnqojn");
    printf("\033[0;36m \ntest strdup very long string string ==> ");
    error_chr(lmee, hem);
}