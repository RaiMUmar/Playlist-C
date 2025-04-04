musicalLL: deletePlayList.o deleteASongGivenId.o countNotesInASong.o playSongGivenName.o playSongGivenId.o addNewSong.o createPlayList.o playPlayList.o helper.o mainA3.o 
	gcc ./deletePlayList.o ./deleteASongGivenId.o ./countNotesInASong.o ./playSongGivenName.o ./playSongGivenId.o ./addNewSong.o ./createPlayList.o ./playPlayList.o ./helper.o ./mainA3.o -o bin/musicalLL

mainA3.o: ./src/mainA3.c
	gcc -Wall -std=c99 -Iinclude ./src/mainA3.c -c 

helper.o: ./src/helper.c 
	gcc -Wall -std=c99 -Iinclude ./src/helper.c -c

playPlayList.o: ./src/playPlayList.c
	gcc -Wall -std=c99 -Iinclude ./src/playPlayList.c -c 

createPlayList.o: ./src/createPlayList.c
	gcc -Wall -std=c99 -Iinclude ./src/createPlayList.c -c 

addNewSong.o: ./src/addNewSong.c
	gcc -Wall -std=c99 -Iinclude ./src/addNewSong.c -c

playSongGivenId.o: ./src/playSongGivenId.c 
	gcc -Wall -std=c99 -Iinclude ./src/playSongGivenId.c -c

playSongGivenName.o: ./src/playSongGivenName.c 
	gcc -Wall -std=c99 -Iinclude ./src/playSongGivenName.c -c

countNotesInASong.o: ./src/countNotesInASong.c 
	gcc -Wall -std=c99 -Iinclude ./src/countNotesInASong.c -c

deleteASongGivenId.o: ./src/deleteASongGivenId.c 
	gcc -Wall -std=c99 -Iinclude ./src/deleteASongGivenId.c -c

deletePlayList.o: ./src/deletePlayList.c 
	gcc -Wall -std=c99 -Iinclude ./src/deletePlayList.c -c

clean:
	rm -f *.o bin/musicalLL
