#include "tile.h"


void Tile::SetPosition(const tArray& in_position) {
	int bitmask = 0xC000;
	m_data &= bitmask;
	
	m_data |= (in_position[0] << 7);
	m_data |= in_position[1];
}

void Tile::SetAir(const int in_air) {
	int bitmask = 0xBFFF;

	m_data &= bitmask;
	m_data |= (in_air << 14);
}

void Tile::SetVisited(const int in_visitied) {
	int bitmask = 0x8000;

	m_data &= bitmask;
	m_data |= (in_visitied << 15);
}

 std::ostream& operator<< (std::ostream& out_os, const Tile& in_tile) {
	 
	 auto position = in_tile.GetPosition();

	 std::cout << "(" << (int)position[0] << ", " << (int)position[1] << ") | Air: " << (int)(in_tile.IsAir());
	 
	 return out_os;
 }