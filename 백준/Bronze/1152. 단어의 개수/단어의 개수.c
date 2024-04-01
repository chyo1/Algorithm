#include <stdio.h>
int main() {
	int i, cnt = 0;
	char word[1000001];
	scanf("%[^\n]s", word);

	i = 1; // 첫번 째에 공백이 있는 경우 제외하기 위해
	while (word[i] != NULL) {
		if (i != 0 && word[i] == ' ' && word[i + 1] != NULL) cnt++;
		i++;
	}
	if(i==1&&word[0]==' ') printf("0");
	else printf("%d", cnt + 1);
	return 0;
}