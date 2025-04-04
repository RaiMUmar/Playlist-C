#ifndef HELPER_H
#define HELPER_H

#include "givenA3.h"

void addToEnd(A3Song **headLL, A3Song **temp);
int duplicateID(A3Song*headLL, int id);
int findNote(char whichNote[4]);

#endif // HELPER_H