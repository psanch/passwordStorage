#include <stdio.h>
#include <stdlib.h>

int main(){
	system("python ./salter.py 12"); //generates 12 new salts
	int x = system("python ./updater.py 3"); //updates used_salts to 3\
}