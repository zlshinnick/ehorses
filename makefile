run_will:
	g++ horse.cpp userhorse.cpp comphorse.cpp willsDriver.cpp -o run
	./run 

run_yifan:
	g++ horse.cpp comphorse_yifan.cpp racetrack.cpp userhorse.cpp user.cpp yifansDriver.cpp -o runy
	./runy

run_zach:
	g++ main.cpp user.cpp userhorse.cpp game.cpp horse.cpp stable.cpp shop.cpp item.cpp market.cpp inventory.cpp bred_horse.cpp -o run_zachs
	./run_zachs

run_race:
	g++ -c raceGraphics.cpp -I"C:\SFML-2.5.1\include"
	g++ raceGraphics.o -o raceGraphics -L"C:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
	./raceGraphics