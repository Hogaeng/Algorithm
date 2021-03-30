#alias m="make"
#LINUX : source .bashrc
#IOS : source .bash_profile
TARGET = baby
TARGET_CPP = $(TARGET).cpp
TARGET_EXE = $(TARGET).out
TARGET_OUT = $(TARGET)_out
TARGET_IN = $(TARGET)_in
define in_txt
vi $(TARGET_IN)${1}.txt
endef
ifeq (vin,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(word 2,$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)# 무슨 뜻인지 모르지만 m vin 2에서 '2'를 명령처리해주지 않는 역할을 해준다.
endif

$(TARGET):
	ctags -R
	clang++ $(TARGET_CPP) -o $(TARGET_EXE)
	clang++ $(TARGET)_sanga.cpp -o $(TARGET)_sanga.out
makein:
	clang++ makein.cpp -o makein.out
v:
	vi $(TARGET_CPP)
vin:
	$(call in_txt,$(RUN_ARGS))
#@echo $(call in_txt,$(RUN_ARGS))
#vi $(TARGET_IN).txt
vt:
	vi tmp.txt
vs:
	vi $(TARGET)_sanga.cpp
vout:
	vi $(TARGET_OUT).txt
vmakein:
	vi makein.cpp
ed:
	./$(TARGET_EXE) | diff ./$(TARGET_OUT).txt -
e:
	./$(TARGET_EXE)
es:
	./$(TARGET)_sanga.out
ee:
	./$(TARGET_EXE)>tmp.txt
	./$(TARGET)_sanga.out | diff ./tmp.txt -
vj:
	vi $(TARGET).java
j:
	javac $(TARGET).java
je:
	java $(TARGET)
emakein:
	./makein.out
o:
	open $(TARGET_CPP)
c:
	rm $(TARGET_EXE)
cmakein:
	rm makein.out
