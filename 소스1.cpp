#include<iostream>
#include<cstdlib>     // cstdlib 라이브러리에는 rand(), srand() 와 같은 난수 생성 함수가 내장되어 있다.
#include<ctime>     // ctime 라이브러리에는 시간을 다루는 함수들이 존재. srand 의 seed 값을 매번 다르게 지정하기 위한 수단. 
// seed 값의 전달 인자에 현재 시간을 넣어준다. >> 프로그램이 매번 돌아갈 때 마다 다른 난수를 생성해낸다.
using namespace std;

class Random {     //Random 클래스 생성
public:     // 접근 지정자 (공개) : 어디에서든 사용 가능
	int next();     // next 멤버 함수 선언   
	int nextInRange(int a, int b);     // nectInRange 멤버 함수 선언
};

int Random::next() {     // 함수 구현 : 0~32767까지 랜덤으로
	return rand() / 2 * 2;     // 짝수 숫자를 리턴함
}

int Random::nextInRange(int a, int b) {     // 함수 구현 : a~b까지 랜덤으로
	return (rand() % (b - a + 1) + a) / 2 * 2 + 1;
	// 홀수 숫자를 뽑아 리턴함
}

int main() {
	Random n;     // 객체 생성    
	srand((unsigned)time(NULL));     // srand 의 seed 값을 프로그램을 실행할 때 마다 다르게 지정
	cout << "-- 0에서 32767까지의 짝수 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; ++i) {     // 정수 10개를 뽑기 위한 반복문 작성
		int x = n.next();     // next 멤버 함수 호출
		cout << x << " ";     // 짝수 랜덤 정수 10개의 결과 출력
	}
	cout << endl;

	cout << "== 2에서 30까지의 홀수 랜덤 정수 10개 (단, 중복되는 값이 없어야 함) == " << endl;

	int* arr = new int[10];     // 배열 형태로 메모리 할당 * new : 메모리에 객체를 동적으로 할당 >> 위치에 대한 포인터 반환

	for (int i = 0; i < 10; ++i) {     // 정수 10개를 뽑기 위한 반복문 작성
		arr[i] = n.nextInRange(2, 30);     // nextInRange 멤버 함수 호출 (2에서 30까지 범위 지정), 호출 이후 arr 배열에 저장 (중복을 없애기 위해 배열 사용) 
		for (int j = 0; j < i; j++) {     // 중복이 있는지 없는지 확인하기 위한 반복문 작성
			if (arr[i] == arr[j]) {     // 만약 중복되는 값이 있다면
				i--;     // i 번째 수를 재생성
			}
			else if (arr[i] == 31 or arr[j] == 31) {     // 31이 나오는 경우 제외
				i--;     // i 번째 수 재생성
			}
		}
	}
	for (int i = 0; i < 10; i++)     // 뽑힌 정수 10개를 출력하기 위한 반복문 작성
		cout << arr[i] << " ";     // 배열에 저장된 홀수값 출력
	delete[] arr;     // new로 할당받은 메모리 반환
	cout << endl;
}
