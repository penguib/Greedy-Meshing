#include <iostream>
#include <vector>

using u8  = uint8_t;
using u16 = uint16_t;

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

private:
	Map();
	~Map();

	static Map* s_instance;
	std::vector<Tile> m_tiles;

	int m_dimensions[2] = { 10, 10 };
};

struct Tile {

	u8* GetPosition() const {
		u8 pos[2];

		// x
		pos[0] = (m_data & (127UL << 7)) >> 7;
		
		// y
		pos[1] = m_data & (127UL << 0);

		return pos;
	};

	u8 IsVisible() const {
		return (m_data & (1UL << 15)) >> 15;
	};

	u8 IsAir() const {
		return (m_data & (1UL << 14)) >> 15;
	}

private:
	u16 m_data;
};

// Tiles are 16 bits
// 00 					0000000 	0000000
// isVisible and isAir	 x pos		 y pos