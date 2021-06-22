#include <iostream>
#include "map.h"

int main() {

	Map* map = Map::Get();
	map->Print();
	map->Mesh();

	return 0;
}