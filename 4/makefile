objects = main.o make_line.o calculation.o

vpath %.c src
vpath %.h src
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects)
	g++ -g -Wall $(objects) -o main -lGL -lglut -lGLU
main.o : make_line.h
	g++ -c -g -Wall src/main.cpp -o main.o -lGL -lglut -lGLU
make_line.o : make_line.h
	g++ -c -g -Wall src/make_line.cpp -o make_line.o -lGL -lglut -lGLU
calculation.o : type.h
	g++ -c -g -Wall src/calculation.cpp -o calculation.o -lGL -lglut -lGLU
.PHONY : clean
clean :
	rm  main $(objects)