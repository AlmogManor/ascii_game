typedef struct Position {
		int x, y, z;
} Position;


typedef struct Model {
		Position position;
		
		char* lines[];
} Model;


