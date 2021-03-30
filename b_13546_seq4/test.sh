TARGET=seq4
TARGET_IN=${TARGET}_in
sss(){
    echo $TARGET_IN$1".txt"
}
sss $1
