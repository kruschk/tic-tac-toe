#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

struct winsize w;

int drawBorder(void);

int main(void) {
	drawBorder();
	sleep(5);
	return 0;
}

int drawBorder(void) {
	ioctl(0, TIOCGWINSZ, &w);
	for (size_t j = 0; j < w.ws_col; j++) {
		putchar('o');
	}
	for (int i = 0; i < (w.ws_row - 1); i++) {
		putchar('\n');
		putchar('o');
		for (int j = 0; j < (w.ws_col - 2); j++) {
			putchar(' ');
		}
		putchar('o');
	}
	for (size_t j = 0; j < w.ws_col; j++) {
		putchar('o');
	}
	//printf("lines %d\n", w.ws_row);
	//printf("columns %d\n", w.ws_col);
	return 0;
}
