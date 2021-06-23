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


/*
	0	0	0	1	0	0
	0	0	1	0	0	0
	0	0	0	1	0	0
	0	0	0	0	0	0
	0	0	0	0	0	0


*/

std::vector<Tile> Map::DFS(int row, int col) {
	std::vector<Tile> mesh;

	if (row < 0 || col < 0 || row > m_tiles.size() || col > m_tiles.size())
		return {};

	m_tiles[row][col].SetVisited(1);
	for (int i = (row - 1); i < (row + 1); ++i) {
		for (int j = (col - 1); j < (col + 1); ++j) {
			Tile tile = m_tiles[i][j];

			if (!tile.IsAir() && !tile.IsVisited()) {
				mesh.push_back(tile);
				std::cout << tile << std::endl;
				return DFS(i, j);
			}
		}	
	}

	return mesh;
}

tTileVec Map::FindConnected() {
	tTileVec connected;
	int count = 0;

	for (int i = 0; i < m_tiles.size(); ++i) {
		for (int j = 0; j < m_tiles.size(); ++j) {
			Tile tile = m_tiles[i][j];
			//&& !tile.IsVisited()
			// air is 1
			if (!tile.IsAir()) {
				++count;
				std::cout << tile << std::endl;
				// connected.push_back(DFS(i, j));
			}

		}	
	}

	std::cout << "visited " << count << std::endl;

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
	
	
	for (auto row : m_tiles) {
		for (auto tile : row) {
			std::cout << "[" << (int)(tile.IsVisited()) << "] ";
		}
		std::cout << std::endl;
	}
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