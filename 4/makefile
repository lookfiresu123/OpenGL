objects_make_line = main.o make_line.o calculation.o
objects_make_polygon = main.o make_polygon.o calculation.o
objects_make_triangles = main.o make_triangles.o make_polygon.o
objects_make_quads = main.o make_quads.o make_polygon.o
objects_make_stereoscopic = main.o make_stereoscopic.o make_polygon.o
objects_make_bitmap = main.o make_bitmap.o
objects_make_list = main.o make_list.o
objects_example_4_30 = main.o example_4_30.o
objects_data_plot = main.o data_plot.o

vpath %.c src
vpath %.h src
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects_data_plot)
	g++ -g -Wall $(objects_data_plot) -o main -lGL -lglut -lGLU

# make for main.cpp
main.o : data_plot.h
	g++ -c -g -Wall src/main.cpp -o main.o -lGL -lglut -lGLU

# make for make_line.cpp
# make_line.o : make_line.h
# 	g++ -c -g -Wall src/make_line.cpp -o make_line.o -lGL -lglut -lGLU

# make for make_triangles.cpp
# make_triangles.o : make_triangles.h
# 	g++ -c -g -Wall src/make_triangles.cpp -o make_triangles.o -lGL -lglut -lGLU

# make for make_quads.cpp
# make_quads.o : make_quads.h
# 	g++ -c -g -Wall src/make_quads.cpp -o make_quads.o -lGL -lglut -lGLU

# make for make_stereoscopic.cpp
# make_stereoscopic.o : make_stereoscopic.h
# 	g++ -c -g -Wall src/make_stereoscopic.cpp -o make_stereoscopic.o -lGL -lglut -lGLU

# make for make_bitmap.cpp
# make_bitmap.o : make_bitmap.h
# 	g++ -c -g -Wall src/make_bitmap.cpp -o make_bitmap.o -lGL -lglut -lGLU

# make for make_list.cpp
# make_list.o : make_list.h
# 	g++ -c -g -Wall src/make_list.cpp -o make_list.o -lGL -lglut -lGLU

# make for make_polygon.cpp
# make_polygon.o : make_polygon.h
# 	g++ -c -g -Wall src/make_polygon.cpp -o make_polygon.o -lGL -lglut -lGLU

# make for calculation.cpp
# calculation.o : type.h
# 	g++ -c -g -Wall src/calculation.cpp -o calculation.o -lGL -lglut -lGLU

# make for example_4_30.cpp
# example_4_30.o :
# 	g++ -c -g -Wall src/example_4_30.cpp -o example_4_30.o -lGL -lglut -lGLU

# make for data_plot.cpp
data_plot.o :
	g++ -c -g -Wall src/data_plot.cpp -o data_plot.o -lGL -lglut -lGLU
	
.PHONY : clean
clean :
	rm  main $(objects_data_plot)
