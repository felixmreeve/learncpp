OBJECTS = main.o GC.o GameManager.o Renderable.o Background.o Player.o Head.o BodyPart.o Food.o Circle.o Sprite.o Eye.o
COMPILER = g++
PROGNAME = main
OUTPUT = -o
OPTIONS = -Wall -c -save-temps=obj
HEADERS = GC.h GameManager.h Background.h Player.h Food.h Circle.h Sprite.h Eye.h 

$(PROGNAME): $(OBJECTS)
	$(COMPILER) $(OBJECTS) -Wall -l SDL2 -l SDL2_image -l SDL2_ttf -l m $(OUTPUT) $(PROGNAME)
	rm -rf *.s
	rm -rf *.ii
	echo DONE!

main.o: main.cpp GC.cpp GameManager.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) main.cpp

GC.o: GC.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) GC.cpp

GameManager.o: GameManager.cpp Food.cpp Player.cpp Eye.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) GameManager.cpp

Renderable.o: Renderable.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) Renderable.cpp

Background.o: Background.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) Background.cpp

Player.o: Player.cpp Renderable.cpp Head.cpp BodyPart.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) Player.cpp

Head.o: Head.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) Head.cpp

BodyPart.o: BodyPart.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) BodyPart.cpp

Food.o: Food.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) Food.cpp

Circle.o: Circle.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) Circle.cpp

Sprite.o: Sprite.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) Sprite.cpp

Eye.o: Eye.cpp $(HEADERS)
	$(COMPILER) $(OPTIONS) Eye.cpp

clean:
	rm -rf *.s
	rm -rf *.ii
	rm $(OBJECTS)
