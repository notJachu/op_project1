#include "types.h"
#include "Windows.h"

void gotoxy(int x, int y) {

	COORD coords = { 0 , 0 };
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
}

char get_symbol(creature_type type) {
	switch (type)
	{
	case WILK:
		return 'W';
		break;
	case LIS:
		return 'L';
		break;
	case TUTEL:
		return 'T';
		break;
	case ANTYLOPA:
		return 'A';
		break;
	case OWCA:
		return 'O';
		break;
	case CYBER_OWCA:
		return 'C';
		break;
	case TRAWA:
		return 't';
		break;
	case MLECZ:
		return 'm';
		break;
	case GUARANA:
		return 'g';
		break;
	case WILCZE_JAGODY:
		return 'j';
		break;
	case BARSZCZ_SOSNOWSKIEGO:
		return 'b';
		break;
	default:
		return '*';
		break;
	}
	return '*';
}


const char* get_name(creature_type type) {
	switch (type)
	{
		case WILK:
			return "Wilk";
			break;
		case LIS:
			return "Lis";
			break;
		case TUTEL:
			return "Tutel";
			break;
		case ANTYLOPA:
			return "Antylopa";
			break;
		case OWCA:
			return "Owca";
			break;
		case CYBER_OWCA:
			return "Cyber Owca";
			break;
		case TRAWA:
			return "Trawa";
			break;
		case MLECZ:
			return "Mlecz";
			break;
		case GUARANA:
			return "Guarana";
			break;
		case WILCZE_JAGODY:
			return "Wilcze Jagody";
			break;
		case BARSZCZ_SOSNOWSKIEGO:
			return "Barszcz Sosnowskiego";
			break;
	   default:
		   return "";

	}
	return "";
}
