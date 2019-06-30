#include "apue.h"
#include <crt_externs.h>
#define environ (*_NSGetEnviron())

static void	my_exit1(void);
static void	my_exit2(void);

int
main(void)
{
    //按照stack pop的顺序将成功register的exit handler在exit的时候全部call一遍
	if (atexit(my_exit2) != 0)
		err_sys("can't register my_exit2");

	if (atexit(my_exit1) != 0)
		err_sys("can't register my_exit1");
	if (atexit(my_exit1) != 0)
		err_sys("can't register my_exit1");

	printf("main is done\n");
    printf("environ %s", environ[0]);
	return(0);
}

static void
my_exit1(void)
{
	printf("first exit handler\n");
}

static void
my_exit2(void)
{
	printf("second exit handler\n");
}
