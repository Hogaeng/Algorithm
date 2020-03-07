#alias m="make"
#LINUX : source .bashrc
#IOS : source .bash_profile

#HOW_TO_USE
#m : ctags를 실행하고 소스를 컴파일함.
#m m : makein.cpp 소스를 컴파일함

#m vin <number> : 인풋 데이터를 vi로 연다.
#m vout <number> : 아웃풋 데이터를 vi로 연다.
#m vm : makein.cpp를 vi로 연다.

#m ed <number> : 인풋 데이터와 아웃풋 데이터를 비교한다.
#m e : 실행파일을 를 실행한다.
#m em : makein.out을 실행한다.

#m c : 실행파일 삭제.
#m cm: makein 실행파일 삭제.
TARGET = baseball
TARGET_CPP = $(TARGET).cpp
TARGET_EXE = $(TARGET).out
TARGET_OUT = $(TARGET)_out
TARGET_IN = $(TARGET)_in
define in_txt
    vi $(TARGET_IN)${1}.txt
endef

define out_txt
    vi $(TARGET_OUT)${1}.txt
endef

define diff
	./$(TARGET_EXE) | diff ./$(TARGET_OUT)${1}.txt -
endef

firstw = $(firstword $(MAKECMDGOALS))
ifeq ($(firstw),$(filter $(firstw), vin vout ed))
  RUN_ARGS := $(word 2,$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif
#(RUN_ARGS)는 @:와 같은 명령어로 정의한다는 의미. 밑에 쓰여있는 m:어쩌구~~~, v:~~~ 와 같은 정의.
# eval은 뒤에 따라오는 텍스트 내용을 makefile의 한 구문으로 실행하겠다는 의미. evaluate의 eval이다.
# @는명령어를 쉘에 에코하지 않겠다는 의미. 사일런트
# :는 무조건 정상 실행하는 명령어. 아무런 일을 하지 않고 정상실행을 할 뿐이다.
# ;는 쉘 명령어를 구분하는 명령어. C언어에서 쓰이는 세미콜론과 똑같은 의미이다.

$(TARGET):
	ctags -R
	g++-9 $(TARGET_CPP) -o $(TARGET_EXE)
#clang++ $(TARGET_CPP) -o $(TARGET_EXE)
m:
	clang++ makein.cpp -o makein.out
mt:
	g++-9 test.cpp -o test.out
v:
	vi $(TARGET_CPP)
vt:
	vi test.cpp
vm:
	vi makein.cpp
vin:
	$(call in_txt,$(RUN_ARGS))
vout:
	$(call out_txt,$(RUN_ARGS))
e:
	./$(TARGET_EXE)
ed:
	$(call diff,$(RUN_ARGS))
em:
	./makein.out
et:
	./test.out
c:
	rm $(TARGET_EXE)
cm:
	rm makein.out
