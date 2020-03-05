//이동생성자, 복사생성자,일반생성자 테스트 코드 
#include<iostream>
using namespace std;
struct Q{
    int s;
    Q(int s) : s(s){
	cout<<"일반생성자"<<endl;
    }
    Q(const Q &a) : s(a.s){
	cout<<"복사생성자"<<endl;
    }
    Q(){
	//Q f를 생성하기 위한 생성자. 
	//자동으로 생성되는 기본생성자이지만,
	//이미 한번 만든 생성자가 있는 sturct, class는 자동으로 기본생성자를 생성하지 않는다.
	cout<<"기본생성자"<<endl;
	//자동으로 생성된 기본생성자는 아무런 명령이 없다.
    }
    bool operator+(const Q){
    }
};

int main(void){
    Q a(2);//일반생성자
    Q b(a);//복사생성자
    Q c(Q(3));//일반생성자. 객체 Q(3)을 만들고 복사를 하지 않고 이름을 c라고 붙여버림. 복사 생략(copy elision).
    Q d=Q(4);//일반생성자. 평범하게 객체를 생성하는 방법
    Q *e=new Q(5);//일반생성자. 평범하게 포인터에 객체를 연결시키는 방법
    Q f;//기본생성자로 생성된 객체
    cout<<d.s<<endl;
}
