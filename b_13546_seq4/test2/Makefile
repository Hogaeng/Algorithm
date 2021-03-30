OBJECT = $(wildcard *.c)
find_files = $(wildcard $(dir)/*)
dirs := a b c d
files := $(foreach dir,$(dirs),$(find_files))

set = $(eval $1:=$2)
h = 2
ttt = server client
ifeq (test2, $(word 1, $(MAKECMDGOALS)))
    ARG := $(word 2, $(MAKECMDGOALS))
    $(eval $(ARG):;@:)
endif
    
    

print : *.c
	echo $$
	touch print
object: 
	echo $(OBJECT)
files:
	echo $(files)
set: 
	$(call set,FOO,BAR)
	echo $(FOO)
	$(call set,A,B)
	echo $(A)
test:
	echo $(word 1,$(ttt))
	echo $(word 2,$(ttt))
test2:
	echo $(ARG)
test3:
	@echo hello
