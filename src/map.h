#include <iostream>
#include <vector>
#include <array>
#include "tile.h"

using u8  	   = uint8_t;
using u16 	   = uint16_t;
using tTileVec = std::vector<std::vector<Tile>>;

class Map {
public:

	static Map* Get() {
		if (!s_instance)
			s_instance = new Map();
		return s_instance;
	}

	void Randomize();
	void Clear();
	void SetDimensions(const u8 in_x, const u8 in_y);
	void Print();
	void Mesh();

private:
	Map();
	~Map();

	tTileVec FindConnected();
	std::vector<Tile> DFS(int row, int col);

	static Map* s_instance;
	std::vector<std::array<Tile, 10>> m_tiles;

	int m_dimensions = 10;
};