all:
	g++ horse.cpp userhorse.cpp comphorse.cpp willsDriver.cpp -o run
	./run 

run_yifan:
	g++ horse.cpp comphorse_yifan.cpp racetrack.cpp yifansDriver.cpp -o run_yifan_exec
	./run_yifan_exec

run_zach:
	g++ main.cpp user.cpp game.cpp horse.cpp stable.cpp shop.cpp item.cpp inventory.cpp -o run_zachs
	./run_zachs