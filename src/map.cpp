#include "map.h"
#include <random>
#include <ctime>
#include "linkedlist.h"

Map* Map::s_instance = nullptr;
u8 tileSize = 10;

Map::Map() {
	std::srand(std::time(0));

	for (u8 x = 0; x < m_dimensions; ++x) {
		std::array<Tile, 10> row;
		
		for (u8 y = 0; y < m_dimensions; ++y) {
			Tile tile;

			int air = std::rand() % 2;
			tile.SetAir(air);

			tile.SetPosition({ x, y });
			row[y] = tile;
		}

		m_tiles.push_back(row);
	}
}

Map::~Map() {}

void Map::Randomize() {}
void Map::Clear() {}
void Map::SetDimensions(const u8 in_x, const u8 in_y) {}

void Map::Print() {
	for (auto row : m_tiles) {
		for (auto tile : row) {
			std::cout << "[" << (int)(tile.IsAir()) << "] ";
		}
		std::cout << std::endl;
	}
}

tTileVec Map::FindConnected(const tTileVec& out_vec = {}) {
	tTileVec connected;

	for (int i = 0; i < m_tiles.size(); ++i) {
		for (int j = 0; j < m_tiles.size(); ++j) {
			
			Tile tile = m_tiles[i][j];
			auto position = tile.GetPosition();

			auto isCorner = [this](const Tile::tArray& in_position) -> bool {
				int x = in_position[0];
				int y = in_position[1];

				if (x == 0 || x == (m_dimensions - 1) || y == 0 || y == (m_dimensions - 1))
					return true;
				return false;
			};
			//
			if (!(int)tile.IsVisited()) {
				
				if (isCorner(position)) {

				}
			}
		}	
	}

	return connected;
}

void Map::Mesh() {
	int tiles = m_tiles.size();

	for (int i = 0; i < tiles; ++i) {
		
		for (int j = 0; j < tiles; ++j) {
			auto position = m_tiles[i][j].GetPosition();
			std::cout <<  "(" << (int)position[0] << ", " << (int)position[1] << "), ";
		}	
		std::cout << std::endl;
	}

	FindConnected();
}


// [1] [0] [0] [0] [1] [0] [0] [1] [1] [1]
// [1] [0] [1] [1] [0] [1] [1] [1] [0] [1]
// [1] [1] [1] [1] [1] [1] [0] [0] [1] [1]
// [1] [0] [1] [1] [0] [0] [1] [1] [1] [0]
// [0] [0] [1] [0] [0] [1] [1] [1] [1] [1]
// [1] [0] [1] [0] [1] [0] [0] [1] [0] [1]
// [0] [0] [1] [1] [1] [1] [1] [1] [0] [1]
// [1] [1] [1] [0] [1] [1] [0] [0] [1] [1]
// [0] [0] [1] [1] [0] [0] [1] [0] [1] [0]
// [1] [0] [0] [0] [1] [1] [0] [1] [0] [0]


/*


*/