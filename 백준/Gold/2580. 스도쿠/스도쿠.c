#include <stdio.h>
#define MAX_STACK_SIZE 81
#define SUDOKU_SIZE 9

int sdk[SUDOKU_SIZE][SUDOKU_SIZE];
int top = -1, top_bk = -1;

typedef struct {
	int row, col;
	int num;
} element;
element stack[MAX_STACK_SIZE];

typedef struct {
	int row, col;
} point;
point binkan[MAX_STACK_SIZE];

void push(element item);
element pop();

void push_xy(point xy) {
	binkan[++top_bk] = xy;
}
point pop_xy() {
	return binkan[top_bk--];
}

int main() {
	int i, j, row, col, nine_row, nine_binkan, num_chk = 0, n_back = 0;
	int num[10] = { 0, };
	int error = 0;
	point bnk;
	element ans;
	for (i = 0; i < SUDOKU_SIZE; i++) {
		for (j = 0; j < SUDOKU_SIZE; j++) {
			scanf("%d", &sdk[i][j]);
			if (!sdk[i][j]) {
				bnk.row = i, bnk.col = j;
				push_xy(bnk);
			}
		}
	}
	while (top_bk != -1) {
		row = nine_row = binkan[top_bk].row;
		col = nine_binkan = binkan[top_bk].col;
		for (i = 0; i < 9; i++) {
			if (sdk[i][col]) num[sdk[i][col]] = 1;
			if (sdk[row][i]) num[sdk[row][i]] = 1;
		}
		nine_row -= row % 3, nine_binkan -= col % 3;
		for (i = nine_row; i < nine_row + 3; i++) {
			for (j = nine_binkan; j < nine_binkan + 3; j++) {
				if (sdk[i][j]) num[sdk[i][j]] = 1;
			}
		}
		for (i = num_chk + 1; i < 10; i++) {
			if (!num[i]) {
				sdk[row][col] = i;
				ans.row = row, ans.col = col, ans.num = i;
				push(ans); pop_xy();

				break;
			}
			else error++;
		}
		if (error == 9 - num_chk) {
			sdk[row][col] = 0;
			num_chk = stack[top].num;
			bnk.row = stack[top].row, bnk.col = stack[top].col;
			pop(); push_xy(bnk);
		}
		else num_chk = 0;
		error = 0;
		for (i = 1; i < 10; i++) num[i] = 0;
	}
	printf("\n");
	for (i = 0; i < SUDOKU_SIZE; i++) {
		for (j = 0; j < SUDOKU_SIZE; j++)
			printf("%d ", sdk[i][j]);
		printf("\n");
	}
	return 0;
}

void push(element item) {
	stack[++top] = item;
}
element pop() {
	return stack[top--];
}