#alias m="make"
#LINUX : source .bashrc
#IOS : source .bash_profile

#HOW_TO_USE
#m : ctags를 실행하고 소스를 컴파일함.
#m makein : makein.cpp 소스를 컴파일함

#m vin <number> : 인풋 데이터를 vi로 연다.
#m vout <number> : 아웃풋 데이터를 vi로 연다.
#m vmakein : makein.cpp를 vi로 연다.

#m ed <number> : 인풋 데이터와 아웃풋 데이터를 비교한다.
#m e : 소스를 실행한다.

#m c : 실행파일 삭제.
#m cmakein: makein 실행파일 삭제.
TARGET = lab
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
ifeq (vin,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(word 2,$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)# 무슨 뜻인지 모르지만 m vin 2에서 '2'를 명령처리해주지 않는 역할을 해준다.
endif
ifeq (vout,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(word 2,$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)# 무슨 뜻인지 모르지만 m vout 2에서 '2'를 명령처리해주지 않는 역할을 해준다.
endif
ifeq (ed,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(word 2,$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)# 무슨 뜻인지 모르지만 m ed 2에서 '2'를 명령처리해주지 않는 역할을 해준다.
endif

$(TARGET):
	ctags -R
	clang++ $(TARGET_CPP) -o $(TARGET_EXE)
makein:
	clang++ makein.cpp -o makein.out
v:
	vi $(TARGET_CPP)
vin:
	$(call in_txt,$(RUN_ARGS))
#@echo $(call in_txt,$(RUN_ARGS))
#vi $(TARGET_IN).txt
vout:
	$(call out_txt,$(RUN_ARGS))
vmakein:
	vi makein.cpp
ed:
	$(call diff,$(RUN_ARGS))
e:
	./$(TARGET_EXE)
emakein:
	./makein.out
c:
	rm $(TARGET_EXE)
cmakein:
	rm makein.out
