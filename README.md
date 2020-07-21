# 알고리즘

v1 : 상위 폴더에서 글로벌하게 접근할 수 있도록 변경.  
v0 : 일일이 알고리즘 폴더를 만든 뒤 해당폴더에서 실행문을 실행시켜야 작동됨.

## 알고리즘 폴더 소개
숫자로 시작하는 폴더는 백준의 알고리즘 내용이고,
해시로 시작하는 폴더는 SW Expert academy 알고리즘입니다.

>16236_babyshark 에서 16236은 <https://www.acmicpc.net/problem/16236> 을 의미한다. 접속하면 아기상어 문제라는 것을 알 수 있다.

>AWXRQm6qfL0DFAUo_breakbrick 에서 AWXRQm6qfL0DFAUo는<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo> 를 의미한다. 접속하면 벽돌깨기 문제라는 것을 알 수 있다.

## 단축키 설정
Makefile, algo.sh는 vim 명령어를 보다 간결하게 입력하기 위해 만든 간단한 스크립트이다.
```
Makefile 사용법 :
1. 원하는 폴더에 Makefile 복사본을 붙여넣기
2. Makefile을 열고 target값을 지정한다.
3. ~/.bash_profile 에서 alias m='make'를 입력후 source ~/bash_profile.
```

```
algo.sh 사용법 :
1. 최초 home 위치에 algo.sh를 옮긴다.
2. ~/.bash_profile 에서 alias m='~/algo.sh'를 입력후 source ~/bash_profile.
3. 원하는 target 값을 쉘에서 export target="원하는값"이라고 명령을 한다.
```

이후 기본적인 알고리즘 소스는 target으로 지정된 값과 같은 이름을 가진 파일을 다룬다.

```
target=baby
${target}.cpp는 baby.cpp
${target}.out는 baby.out
${target}_in.txt는 baby_in.txt
${target}_out.txt는 baby_out.txt
```

설정이 끝나면 아래와 같은 명령어를 사용 할 수 있다.
```
m : ${target}.cpp 파일을 ${target}.out을 컴파일한다
m cm : makein.cpp 파일을 컴파일한다.
m ct : test.cpp 파일을 컴파일한다.

m v : ${target}.cpp를 vi 편집기로 실행한다.
m vm: makein.cpp를 vi 편집기로 실행한다.
m vt: test.cpp를 vi 편집기로 실행한다.

m vin # : ${target}_in#.txt를 vi 편집기로 실행한다.(#은 옵션인자이며 숫자)
m vout # : ${target}_out#.txt를 vi 편집기로 실행한다.(#은 옵션인자이며 숫자)

m e : ${target}.out을 실행한다.
m em : makein.out을 실행한다.
m et : test.out을 실행한다.
m ed # : diff를 실행하여 ${target}.out의 결과와 ${target}_out#.txt 비교한다.
```
## format.cpp 설명
format을 원하는 이름으로 대체하여 사용한다. 예)format.cpp -> baby.cpp  
양식을 따로 제안하는 이유는 다음과 같은 이유이다.  
1. 파일에 입력 데이터를 읽기 위해서.
2. 한번에 여러번 테스트를 진행하기 위해서.  

구현 내용은 아래와 같다.

```
#include<iostream>
#define debug
#define FILENAME "target_in.txt"
#define FILE_CIN
using namespace std;
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	// Here to code your algorithm.
#ifdef FILE_CIN
	}
#endif
	return 0;
}
```
#define에 대해 설명하자면...  

debug는 디버깅용으로 진행사항을 출력하고, 제출할때 코멘트를 달아 한꺼번에 지우기 위한 변수이다.  예시로 아래와 같이 사용 할 수 있다.
```
vector<int> vec;
#ifdef debug
for(int i=0;i<vec.size();i++)
  cout<<vec[i]<<' ';
cout<<endl;
#endif
```
FILENAME 다음에 오는 파일은 "target_in.txt"는 원하는 내용으로 바꿔서 진행하면 된다.  예시로 무작위 길이의 배열을 받아 출력을 하는 알고리즘을 5번 테스트하고 싶다면, 해당 입력데이터는 다음과 같이 작성할 수 있다.
```
5
1 2 3 4
5 6 7
8 9 10 11 12
13 14 15
16 17 18 19 20
```
