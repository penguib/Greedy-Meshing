#include <iostream>
#include <array>

// Tiles are 16 bits
// 00					0000000 	0000000
// isVisited and isAir	 x pos		 y pos

using u8  = uint8_t;
using u16 = uint16_t;


struct Tile {

	using tArray = std::array<u8, 2>;

	tArray GetPosition() const {
		tArray pos;

		// x
		pos[0] = (u8)((m_data >> 7) & 0x7f);
		
		// y
		pos[1] = (u8)(m_data & 0x7f);

		return pos;
	};

	u8 IsVisited() const {
		return m_data >> 15;
	};

	u8 IsAir() const {
		return (m_data >> 14) & 0x1;
	};

	void SetPosition(const tArray& in_position);
	void SetAir(const int in_air);
	void SetVisited(const int in_visitied);

	friend std::ostream& operator<<(std::ostream& out_os, const Tile& in_tile);

private:
	u16 m_data;
};