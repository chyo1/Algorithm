#include <stdio.h>
int main(void) {
	int T, H, W, N;
	int i, room_H, room_W, room;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d%d%d", &H, &W, &N);
		room_W = N / H;

		if (N%H == 0) room_H = H;
		else room_H = N - room_W * H, room_W++;
		room = room_H * 100 + room_W;
		printf("%d\n", room);
	}
	return 0;
}