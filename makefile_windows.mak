delgroup:delgroup_server.o delgroup_func.o
		gcc -o delgroup delgroup_func.o delgroup_server.o
delgroup_server.o:delgroup_server.c delgroup_server.h
		gcc -c delgroup_server.c delgroup_server.h
delgroup_func.o:delgroup_server.h delgroup_func.c
		gcc -c delgroup_server.h delgroup_func.c
