CC_GCC = g++

CFLAGS = -Wall -g -O2 -lpthread -lwiringPi -std=c++11

OBJS = Notes.o Songs.o SoundPlayer.o WirelessCommunication.o Main.o
 
OBJ_LINK_LIST:= $(OBJS)

%.o: %.cpp
	$(CC_GCC) $(CFLAGS) -o $@ -c $< 

main: $(OBJ_LINK_LIST)
	$(CC_GCC) -o main $(OBJ_LINK_LIST) $(CFLAGS)

clean:
	rm -f main $(OBJ_LINK_LIST)

