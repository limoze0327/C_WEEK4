#include <iostream>
using namespace std;

class Oval {     // Oval 클래스
private:
    int width;     // 멤버 변수 width = 2A
    int height;     // 멤버 변수 heigjt = 2B
public:
    Oval() {
        width = 1;     // width 변수 초기와
        height = 1;     // height 변수 초기화
    }
    Oval(int a, int b) : Oval() {     // 너비와 높이 값을 매개로 받음 > 이전에 width 와 height를 1로 초기화함 : 위임생성자 사용
        width = a;
        height = b;
    }
    ~Oval() {     // 소멸자 함수 선언
        cout << "Oval 소멸 : " << "width = " << width << ", height = " << height << endl;
    }
    int getA() {     // A = (width/2) 값을 리턴
        return (width / 2);
    }
    int getB() {     // B = (height/2) 값을 리턴
        return (height / 2);
    }
    void Area();     // 넓이 계산을 위한 Area 함수 선언
    void set(int w, int h);     // a의 높이와 너비 지정을 위한 set 함수 선언
};

void Oval::Area() {     
    cout << "타원의 넓이는" << " " << 3.14 * (width / 2) * (height / 2) << "이다." << endl;
}     // 타원의 넓이 계산을 위한 함수

void Oval::set(int w, int h) { //width와 height를 셋 해주는 함수
    width = w;
    height = h;
}

int main() {
    Oval a;     //Oval 형 객체 a 생성자 매개변수 없는 것이 호출되어 1,1 로 width와 height 초기화
    Oval b(3, 4);     //Oval 형 객체 b 3,4 로 width와 height 지정
    a.set(10, 20);     //a의 height와 width 를 10,20으로 셋
    a.Area();     // a 값 계산     
    b.Area();     // b 값 계산
    return 0;
}

