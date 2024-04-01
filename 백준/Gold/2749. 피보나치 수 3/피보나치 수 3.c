#include <stdio.h>

typedef struct H {
	unsigned long long a, b, c, d;
}H;

H mul(H A, H B) {
	H R={
		(A.a*B.a + A.b*B.c) % 1000000,
		(A.a*B.b + A.b*B.d) % 1000000,
		(A.c*B.a + A.d*B.c) % 1000000,
		(A.c*B.b + A.d*B.d) % 1000000
	};
	return R;
}
unsigned long long int N;
int main() {
	
	scanf("%lld", &N);
	H cal = { 1,1,1,0 };
	H r = { 1,0,0,1 };
	for (; N > 0; N = N >> 1) { // 비트 왼쪽으로 이동, 2의 거듭제곱만큼 작아짐
		if (N & 1) { 
			// 비트연산자, 짝수일 때 0, 홀수일 때 1 반환
			// 홀수일 때는 곱해야함
			r = mul(r, cal);
		}
		cal = mul(cal, cal);
		// 거듭제곱 계산
	}
	printf("%lld", r.b);
	return 0;
}