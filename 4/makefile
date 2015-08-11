objects_make_line = main.o make_line.o calculation.o
objects_make_polygon = main.o make_polygon.o calculation.o
objects_make_triangles = main.o make_triangles.o make_polygon.o


vpath %.c src
vpath %.h src
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects_make_triangles)
	g++ -g -Wall $(objects_make_triangles) -o main -lGL -lglut -lGLU
main.o : make_triangles.h
	g++ -c -g -Wall src/main.cpp -o main.o -lGL -lglut -lGLU
# make_line.o : make_line.h
# 	g++ -c -g -Wall src/make_line.cpp -o make_line.o -lGL -lglut -lGLU
make_triangles.o : make_triangles.h
	g++ -c -g -Wall src/make_triangles.cpp -o make_triangles.o -lGL -lglut -lGLU
make_polygon.o : make_polygon.h
	g++ -c -g -Wall src/make_polygon.cpp -o make_polygon.o -lGL -lglut -lGLU
# calculation.o : type.h
# 	g++ -c -g -Wall src/calculation.cpp -o calculation.o -lGL -lglut -lGLU
.PHONY : clean
clean :
	rm  main $(objects_make_triangles)