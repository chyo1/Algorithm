#include <stdio.h>

int main() {
	char c, code[510];
	int i = -1;

	while (1) {
		code[++i] = getchar();

		if (code[i] == '\n') {
			if (code[0] == 'E'&&code[1] == 'N'&&code[2] == 'D') break;

			while (i-- > 0) printf("%c", code[i]);
			printf("\n");
		}
	}

	return 0;
}