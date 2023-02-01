#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include<allegro5/allegro_video.h>
//#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
//#include <allegro5/allegro_audio.h>
//#include <allegro5/allegro_acodec.h>


int i, dice, win1, win2, Sw_shown_once = 1, turn;
int Player11, Player12, Player21, Player22;
int LimitCard1, CloseCard1, x2Card1, AgainCard1;
int LimitCard2, CloseCard2, x2Card2, AgainCard2;
int Corr11, Corr12, Corr21, Corr22;
int lockycard1, lockycard2, lockycard3, lockycard4;
int lock1, lock2, lock3, lock4;
int int_variable[28];
char gamestate[20];
int mousex, mousey;
bool ejaze;

//pieces first coordinate:
float xp21, xp22;
float yp21, yp22;
float xp11, xp12;
float yp11, yp12;
float float_variable[24];

// coordinate of corridors
float xcorr1f, xcorr1e, ycorr1f, ycorr1e;
float xcorr2f, xcorr2e, ycorr2f, ycorr2e;
float xlocky1, ylocky1, xlocky2, ylocky2;
float xlocky3, ylocky3, xlocky4, ylocky4;

ALLEGRO_MOUSE_STATE muste;
ALLEGRO_KEYBOARD_STATE ks;
ALLEGRO_DISPLAY* display;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_TIMER* timer;

//Bitmaps
ALLEGRO_BITMAP* bitmap_startmeet = NULL;
ALLEGRO_BITMAP* bitmap_runner = NULL;
ALLEGRO_BITMAP* bitmap_menu = NULL;
ALLEGRO_BITMAP* bitmap_info1 = NULL;
ALLEGRO_BITMAP* bitmap_info2 = NULL;
ALLEGRO_BITMAP* bitmap_info3 = NULL;
ALLEGRO_BITMAP* bitmap_info4 = NULL;
ALLEGRO_BITMAP* bitmap_setting = NULL;
ALLEGRO_BITMAP* bitmap_newgame = NULL;
ALLEGRO_BITMAP* bitmap_board_black = NULL;
ALLEGRO_BITMAP* bitmap_board_yellow = NULL;
ALLEGRO_BITMAP* bitmap_board_red = NULL;
ALLEGRO_BITMAP* bitmap_board_blue = NULL;
ALLEGRO_BITMAP* bitmap_board_green = NULL;
ALLEGRO_BITMAP* bitmap_win1 = NULL;
ALLEGRO_BITMAP* bitmap_win2 = NULL;
ALLEGRO_BITMAP* bitmap_player11 = NULL;
ALLEGRO_BITMAP* bitmap_player12 = NULL;
ALLEGRO_BITMAP* bitmap_player21 = NULL;
ALLEGRO_BITMAP* bitmap_player22 = NULL;
ALLEGRO_BITMAP* bitmap_player11_win = NULL;
ALLEGRO_BITMAP* bitmap_player12_win = NULL;
ALLEGRO_BITMAP* bitmap_player21_win = NULL;
ALLEGRO_BITMAP* bitmap_player22_win = NULL;
ALLEGRO_BITMAP* bitmap_dice1 = NULL;
ALLEGRO_BITMAP* bitmap_dice2 = NULL;
ALLEGRO_BITMAP* bitmap_dice3 = NULL;
ALLEGRO_BITMAP* bitmap_dice4 = NULL;
ALLEGRO_BITMAP* bitmap_dice5 = NULL;
ALLEGRO_BITMAP* bitmap_dice6 = NULL;
ALLEGRO_BITMAP* bitmap_turn2 = NULL;
ALLEGRO_BITMAP* bitmap_turn1 = NULL;
ALLEGRO_BITMAP* bitmap_asker = NULL;
ALLEGRO_BITMAP* bitmap_asker2 = NULL;
ALLEGRO_BITMAP* bitmap_asker3 = NULL;
ALLEGRO_BITMAP* bitmap_asker4 = NULL;
ALLEGRO_BITMAP* bitmap_asklimit = NULL;
ALLEGRO_BITMAP* bitmap_closeask = NULL;
ALLEGRO_BITMAP* bitmap_which = NULL;
ALLEGRO_BITMAP* bitmap_corridor = NULL;
ALLEGRO_BITMAP* bitmap_lockycard = NULL;
ALLEGRO_BITMAP* bitmap_doubledice = NULL;


bool done = false;
bool redraw = true;
bool newgame = true;
bool loadgame = false;
bool running = true;
bool run_startmeet = true;
bool run_meet = true;
bool run_menu = false;
bool run_newgame = false;
bool run_board = false;
bool run_info1 = false;
bool run_info2 = false;
bool run_info3 = false;
bool run_info4 = false;
bool run_setting = false;
bool run_board_black = true;
bool run_board_yellow = false;
bool run_board_red = false;
bool run_board_blue = false;
bool run_board_green = false;
bool run_win = false;
bool run_win1 = false;
bool run_win2 = false;
//Function buttons_mouse
int mouse_positon(int x1, int x2, int y1, int y2) {
	if (mousex >= x1 && mousex <= x2 && mousey >= y1 && mousey <= y2)
		return 1;
	else return 0;
}
//Function coordinates of mouse
void mouse_pos() {
	al_get_mouse_state(&muste);
	mousex = muste.x;
	mousey = muste.y;
	//printf("%d----------%d\n", mousex, mousey);
	//printf(" % d, % d, % d, % d, % d, % d, % d, % d\n", LimitCard1, LimitCard2, AgainCard1, AgainCard2, CloseCard1, CloseCard2, x2Card1, x2Card2);
}
//Function for setting
void setting_open() {
	while (1) {

		mouse_pos();
		al_draw_bitmap(bitmap_setting, 0, 0, 0);
		al_flip_display();
		//exit setting
		if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(784, 819, 31, 81) == 1) {
			break;
		}
		//run blue board
		if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(321, 355, 218, 253) == 1) {
			run_board_blue = true;
			run_board_red = false;
			run_board_black = false;
			run_board_green = false;
			run_board_yellow = false;
			bitmap_menu = al_load_bitmap("menu_blue.png");
			bitmap_win1 = al_load_bitmap("win1_blue.png");
			bitmap_win2 = al_load_bitmap("win2_blue.png");
			bitmap_newgame = al_load_bitmap("newgame_blue.png");
			bitmap_player11 = al_load_bitmap("blue1.png");//pieces
			bitmap_player12 = al_load_bitmap("blue2.png");
			bitmap_player21 = al_load_bitmap("blue3.png");
			bitmap_player22 = al_load_bitmap("blue4.png");
			bitmap_dice1 = al_load_bitmap("minus1_blue.png");//dice
			bitmap_dice2 = al_load_bitmap("minus2_blue.png");
			bitmap_dice3 = al_load_bitmap("minus3_blue.png");
			bitmap_dice4 = al_load_bitmap("plus1_blue.png");
			bitmap_dice5 = al_load_bitmap("plus2_blue.png");
			bitmap_dice6 = al_load_bitmap("plus3_blue.png");
			bitmap_turn1 = al_load_bitmap("turn1_blue.png");
			bitmap_turn2 = al_load_bitmap("turn2_blue.png");
			bitmap_corridor = al_load_bitmap("corridor_blue.png");
			bitmap_lockycard = al_load_bitmap("lockycard_blue.png");

		}
		//run red board
		if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(365, 401, 218, 253) == 1) {
			run_board_red = true;
			run_board_blue = false;
			run_board_black = false;
			run_board_green = false;
			run_board_yellow = false;
			bitmap_menu = al_load_bitmap("menu_red.png");
			bitmap_win1 = al_load_bitmap("win1_red.png");
			bitmap_win2 = al_load_bitmap("win2_red.png");
			bitmap_newgame = al_load_bitmap("newgame_red.png");
			bitmap_player11 = al_load_bitmap("red1.png");//pieces
			bitmap_player12 = al_load_bitmap("red2.png");
			bitmap_player21 = al_load_bitmap("red3.png");
			bitmap_player22 = al_load_bitmap("red4.png");
			bitmap_dice1 = al_load_bitmap("minus1_blue.png");//dice
			bitmap_dice2 = al_load_bitmap("minus2_blue.png");
			bitmap_dice3 = al_load_bitmap("minus3_blue.png");
			bitmap_dice4 = al_load_bitmap("plus1_blue.png");
			bitmap_dice5 = al_load_bitmap("plus2_blue.png");
			bitmap_dice6 = al_load_bitmap("plus3_blue.png");
			bitmap_turn1 = al_load_bitmap("turn1_red.png");
			bitmap_turn2 = al_load_bitmap("turn2_red.png");
			bitmap_corridor = al_load_bitmap("corridor_blue.png");
			bitmap_lockycard = al_load_bitmap("lockycard_blue.png");
		}
		//run black board
		if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(413, 450, 218, 253) == 1) {
			run_board_black = true;
			run_board_red = false;
			run_board_blue = false;
			run_board_green = false;
			run_board_yellow = false;
			bitmap_menu = al_load_bitmap("menu_black.png");
			bitmap_win1 = al_load_bitmap("win1_black.png");
			bitmap_win2 = al_load_bitmap("win2_black.png");
			bitmap_newgame = al_load_bitmap("newgame_black.png");
			bitmap_player11 = al_load_bitmap("black1.png");//pieces
			bitmap_player12 = al_load_bitmap("black2.png");
			bitmap_player21 = al_load_bitmap("black3.png");
			bitmap_player22 = al_load_bitmap("black4.png");
			bitmap_dice1 = al_load_bitmap("minus1_black.png");//dice
			bitmap_dice2 = al_load_bitmap("minus2_black.png");
			bitmap_dice3 = al_load_bitmap("minus3_black.png");
			bitmap_dice4 = al_load_bitmap("plus1_black.png");
			bitmap_dice5 = al_load_bitmap("plus2_black.png");
			bitmap_dice6 = al_load_bitmap("plus3_black.png");
			bitmap_turn1 = al_load_bitmap("turn1_black.png");
			bitmap_turn2 = al_load_bitmap("turn2_black.png");
			bitmap_corridor = al_load_bitmap("corridor_black.png");
			bitmap_lockycard = al_load_bitmap("lockycard_black.png");
		}
		//run green board
		if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(463, 499, 218, 253) == 1) {
			run_board_green = true;
			run_board_red = false;
			run_board_blue = false;
			run_board_black = false;
			run_board_yellow = false;
			bitmap_menu = al_load_bitmap("menu_green.png");
			bitmap_win1 = al_load_bitmap("win1_green.png");
			bitmap_win2 = al_load_bitmap("win2_green.png");
			bitmap_newgame = al_load_bitmap("newgame_green.png");
			bitmap_player11 = al_load_bitmap("green1.png");//pieces
			bitmap_player12 = al_load_bitmap("green2.png");
			bitmap_player21 = al_load_bitmap("green3.png");
			bitmap_player22 = al_load_bitmap("green4.png");
			bitmap_dice1 = al_load_bitmap("minus1_green.png");//dice
			bitmap_dice2 = al_load_bitmap("minus2_green.png");
			bitmap_dice3 = al_load_bitmap("minus3_green.png");
			bitmap_dice4 = al_load_bitmap("plus1_green.png");
			bitmap_dice5 = al_load_bitmap("plus2_green.png");
			bitmap_dice6 = al_load_bitmap("plus3_green.png");
			bitmap_turn1 = al_load_bitmap("turn1_green.png");
			bitmap_turn2 = al_load_bitmap("turn2_green.png");
			bitmap_corridor = al_load_bitmap("corridor_green.png");
			bitmap_lockycard = al_load_bitmap("lockycard_green.png");
		}
		//run yellow board
		if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(509, 548, 218, 253) == 1) {
			run_board_yellow = true;
			run_board_red = false;
			run_board_blue = false;
			run_board_black = false;
			run_board_green = false;
			bitmap_menu = al_load_bitmap("menu_yellow.png");
			bitmap_win1 = al_load_bitmap("win1_yellow.png");
			bitmap_win2 = al_load_bitmap("win2_yellow.png");
			bitmap_newgame = al_load_bitmap("newgame_yellow.png");
			bitmap_player11 = al_load_bitmap("yellow1.png");//pieces
			bitmap_player12 = al_load_bitmap("yellow2.png");
			bitmap_player21 = al_load_bitmap("yellow3.png");
			bitmap_player22 = al_load_bitmap("yellow4.png");
			bitmap_dice1 = al_load_bitmap("minus1_yellow.png");//dice
			bitmap_dice2 = al_load_bitmap("minus2_yellow.png");
			bitmap_dice3 = al_load_bitmap("minus3_yellow.png");
			bitmap_dice4 = al_load_bitmap("plus1_yellow.png");
			bitmap_dice5 = al_load_bitmap("plus2_yellow.png");
			bitmap_dice6 = al_load_bitmap("plus3_yellow.png");
			bitmap_turn1 = al_load_bitmap("turn1_yellow.png");
			bitmap_turn2 = al_load_bitmap("turn2_yellow.png");
			bitmap_corridor = al_load_bitmap("corridor_yellow.png");
			bitmap_lockycard = al_load_bitmap("lockycard_yellow.png");
		}
	}
}

int evenchecker(int number) {//1 for even ....0 for odd
	if (number % 2 == 0) return 1;
	else return 0;

}

int suptaghsim(int number, int x) {
	if (number % x != 0) return number / x + 1;
	else	return number / x;
}

int random_number(int min_num, int max_num)//tabe digari baraye bedast avardan adad random
{
	int array[500];
	for (i = 0; i < 500; i++) {
		array[i] = rand() % (max_num - min_num);
		array[i] += min_num;
	}
	i = rand() % 500;
	return(array[i]);
}

int DiceRand() {
	srand(time(0));
	int x, temp[500], j, k;
	for (int i = 0; i < 500; i++) {
		temp[i] = rand() % 6 - 2;
		if (temp[i] == 0) temp[i] = (-3);
	}
	j = rand() % 500;
	k = rand() % 500;
	if (temp[j] > temp[k]) {
		return temp[j];
	}
	else return temp[k];
}

int corrcoordinate(int temp, float* x, float* y) { //finding corridor coordinate to apply graphics
	///////////
	// corridor 1 first
	if (evenchecker(suptaghsim(temp, 9)) == 1) {
		if (temp % 9 != 0) *x = 748 - ((temp % 9) - 1) * 45.5;
		else *x = 757 - 8 * 45.7;
	}
	else
	{
		if (temp % 9 != 0) *x = 383 + ((temp % 9) - 1) * 45.5;
		else *x = 383 + 8 * 45.7;
	}
	*y = 453 - (suptaghsim(temp, 9) - 1) * 43.05;

}

void Savegame() {
	int_variable[0] = win1;
	int_variable[1] = win2;
	int_variable[2] = Sw_shown_once;
	int_variable[3] = turn;
	int_variable[4] = Player11;
	int_variable[5] = Player12;
	int_variable[6] = Player21;
	int_variable[7] = Player22;
	int_variable[8] = LimitCard1;
	int_variable[9] = CloseCard1;
	int_variable[10] = x2Card1;
	int_variable[11] = AgainCard1;
	int_variable[12] = LimitCard2;
	int_variable[13] = CloseCard2;
	int_variable[14] = x2Card2;
	int_variable[15] = AgainCard2;
	int_variable[16] = Corr11;
	int_variable[17] = Corr12;
	int_variable[18] = Corr21;
	int_variable[19] = Corr21;
	int_variable[20] = lockycard1;
	int_variable[21] = lockycard2;
	int_variable[22] = lockycard3;
	int_variable[23] = lockycard4;
	int_variable[24] = lock1;
	int_variable[25] = lock2;
	int_variable[26] = lock3;
	int_variable[27] = lock4;

	float_variable[0] = xp11;
	float_variable[1] = xp12;
	float_variable[2] = yp11;
	float_variable[3] = yp12;
	float_variable[4] = xp21;
	float_variable[5] = xp22;
	float_variable[6] = yp21;
	float_variable[7] = yp22;
	float_variable[8] = xcorr1f;
	float_variable[9] = xcorr1e;
	float_variable[10] = ycorr1f;
	float_variable[11] = ycorr1e;
	float_variable[12] = xcorr2f;
	float_variable[13] = xcorr2e;
	float_variable[14] = ycorr2f;
	float_variable[15] = ycorr2e;
	float_variable[16] = xlocky1;
	float_variable[17] = ylocky1;
	float_variable[18] = xlocky2;
	float_variable[19] = ylocky2;
	float_variable[20] = xlocky3;
	float_variable[21] = ylocky3;
	float_variable[22] = xlocky4;
	float_variable[23] = ylocky4;

	FILE* savefile;
	savefile = fopen("savegame.dat", "wb");
	if (!savefile) {
		printf("Can't open file");
		exit(1);
	}
	fwrite(int_variable, sizeof(int), 28, savefile);
	fwrite(float_variable, sizeof(float), 24, savefile);
	fclose(savefile);
}

void Loadgame() {
	FILE* loadfile = fopen("savegame.dat", "rb");
	if (!loadfile) {
		printf("Can't open file");
		exit(1);
	}
	fread(int_variable, sizeof(int), 28, loadfile);
	fread(float_variable, sizeof(float), 24, loadfile);
	fclose(loadfile);
	win1 = int_variable[0];
	win2 = int_variable[1];
	Sw_shown_once = int_variable[2];
	turn = int_variable[3];
	Player11 = int_variable[4];
	Player12 = int_variable[5];
	Player21 = int_variable[6];
	Player22 = int_variable[7];
	LimitCard1 = int_variable[8];
	CloseCard1 = int_variable[9];
	x2Card1 = int_variable[10];
	AgainCard1 = int_variable[11];
	LimitCard2 = int_variable[12];
	CloseCard2 = int_variable[13];
	x2Card2 = int_variable[14];
	AgainCard2 = int_variable[15];
	Corr11 = int_variable[16];
	Corr12 = int_variable[17];
	Corr21 = int_variable[18];
	Corr21 = int_variable[19];
	lockycard1 = int_variable[20];
	lockycard2 = int_variable[21];
	lockycard3 = int_variable[22];
	lockycard4 = int_variable[23];
	lock1 = int_variable[24];
	lock2 = int_variable[25];
	lock3 = int_variable[26];
	lock4 = int_variable[27];

	xp11 = float_variable[0];
	xp12 = float_variable[1];
	yp11 = float_variable[2];
	yp12 = float_variable[3];
	xp21 = float_variable[4];
	xp22 = float_variable[5];
	yp21 = float_variable[6];
	yp22 = float_variable[7];
	xcorr1f = float_variable[8];
	xcorr1e = float_variable[9];
	ycorr1f = float_variable[10];
	ycorr1e = float_variable[11];
	xcorr2f = float_variable[12];
	xcorr2e = float_variable[13];
	ycorr2f = float_variable[14];
	ycorr2e = float_variable[15];
	xlocky1 = float_variable[16];
	ylocky1 = float_variable[17];
	xlocky2 = float_variable[18];
	ylocky2 = float_variable[19];
	xlocky3 = float_variable[20];
	ylocky3 = float_variable[21];
	xlocky4 = float_variable[22];
	ylocky4 = float_variable[23];

}

void gm_defaults() {
	win1 = 0, win2 = 0, Sw_shown_once = 1, turn = 5;
	Player11 = 1, Player12 = 1, Player21 = 81, Player22 = 81;
	LimitCard1 = 1, CloseCard1 = 1, x2Card1 = 1, AgainCard1 = 1;
	LimitCard2 = 1, CloseCard2 = 1, x2Card2 = 1, AgainCard2 = 1;
	ejaze = false;
	//nasb rahro ha
	Corr11 = random_number(2, 40);
	Corr12 = random_number(42, 81);
	Corr21 = random_number(42, 81);
	Corr22 = random_number(2, 40);

	corrcoordinate(Corr11, &xcorr1f, &ycorr1f);
	corrcoordinate(Corr21, &xcorr2f, &ycorr2f);
	corrcoordinate(Corr12, &xcorr1e, &ycorr1e);
	corrcoordinate(Corr22, &xcorr2e, &ycorr2e);
	//do{
	lockycard1 = random_number(2, 40);
	//} while (lockycard1 != Corr11 && lockycard1 != Corr12 && lockycard1 != Corr21 && lockycard1 != Corr22);
	//do{
	lockycard2 = random_number(42, 81);
	//} while (lockycard2 != Corr11 && lockycard2 != Corr12 && lockycard2 != Corr21 && lockycard2 != Corr22);
	//do{
	lockycard3 = random_number(42, 81);
	//} while (lockycard2 != Corr11 && lockycard2 != Corr12 && lockycard2 != Corr21 && lockycard2 != Corr22);
	//do{
	lockycard4 = random_number(2, 40);
	//} while (lockycard4 != Corr11 && lockycard4 != Corr12 && lockycard4 != Corr21 && lockycard4 != Corr22);

	corrcoordinate(lockycard1, &xlocky1, &ylocky1);
	corrcoordinate(lockycard2, &xlocky2, &ylocky2);
	corrcoordinate(lockycard3, &xlocky3, &ylocky3);
	corrcoordinate(lockycard4, &xlocky4, &ylocky4);

	lock1 = random_number(0, 4);
	lock2 = random_number(0, 4);
	lock3 = random_number(0, 4);
	lock4 = random_number(0, 4);

	//pieces first coordinate:
	xp21 = 755, xp22 = 720;
	yp21 = 70, yp22 = 70;
	xp11 = 425, xp12 = 390;
	yp11 = 500, yp12 = 500;
}

void playercoordinates() {// finding the exact pieces position
	//p11
	if (evenchecker(suptaghsim(Player11, 9)) == 1) {
		if (Player11 % 9 != 0) xp11 = 757 - ((Player11 % 9) - 1) * 45.7;
		else xp11 = 757 - 8 * 45.7;
	}
	else
	{
		if (Player11 % 9 != 0) xp11 = 390 + ((Player11 % 9) - 1) * 45.7;
		else xp11 = 390 + 8 * 45.7;
	}
	yp11 = 458 - (suptaghsim(Player11, 9) - 1) * 43.2;
	//p12
	if (evenchecker(suptaghsim(Player12, 9)) == 1) {
		if (Player12 % 9 != 0) xp12 = 757 - ((Player12 % 9) - 1) * 45.7;
		else xp12 = 757 - 8 * 45.7;
	}
	else
	{
		if (Player12 % 9 != 0) xp12 = 390 + ((Player12 % 9) - 1) * 45.7;
		else xp12 = 390 + 8 * 45.7;
	}
	yp12 = 458 - (suptaghsim(Player12, 9) - 1) * 43.2;




	//p21
	if (evenchecker(suptaghsim(Player21, 9)) == 0) {
		if (Player21 % 9 != 0) xp21 = 757 - (9 - (Player21 % 9)) * 45.7;
		else xp21 = 757;
	}
	else
	{
		if (Player21 % 9 != 0) xp21 = 390 + (9 - (Player21 % 9)) * 45.7;
		else xp21 = 390;
	}


	yp21 = 113 + (9 - suptaghsim(Player21, 9)) * 43.5;
	//p22
	if (evenchecker(suptaghsim(Player22, 9)) == 0) {
		if (Player22 % 9 != 0) xp22 = 757 - (9 - (Player22 % 9)) * 45.7;
		else xp22 = 757;
	}
	else
	{
		if (Player22 % 9 != 0) xp22 = 390 + (9 - (Player22 % 9)) * 45.7;
		else xp22 = 390;
	}


	yp22 = 113 + (9 - suptaghsim(Player22, 9)) * 43.5;

}

void doingturn(int turn, int dice) { //turn1:11  turn2:12   turn3:21   turn4:22
	if (win1 != 2 && turn == 1) {
		Player11 += dice;
		if (Player11 < 1) {//yani az safhe nazane birun
			Player11 = 1;
		}
		else if (Player11 > 81) {
			Player11 = 81;
		}
		if (Player11 == 41) {
			win1++;
			if (run_board_black)
				bitmap_player11 = al_load_bitmap("blackwin.png");
			if (run_board_yellow)
				bitmap_player11 = al_load_bitmap("yellowwin.png");
			if (run_board_blue)
				bitmap_player11 = al_load_bitmap("bluewin.png");
			if (run_board_red)
				bitmap_player11 = al_load_bitmap("redwin.png");
			if (run_board_green)
				bitmap_player11 = al_load_bitmap("greenwin.png");
		}
		if (Player11 == Player21) {
			Player21 = 82;
		}
		else if (Player11 == Player22) {
			Player22 = 82;
		}
		//luckycards
		if (Player11 == lockycard1) {
			if (lock1 == 0)
				LimitCard1++;
			else if (lock1 == 1)
				AgainCard1++;
			else if (lock1 == 2)
				CloseCard1++;
			else if (lock1 == 3)
				x2Card1++;
			lock1 = -1;
		}
		else if (Player11 == lockycard2) {
			if (lock2 == 0)
				LimitCard1++;
			else if (lock2 == 1)
				AgainCard1++;
			else if (lock2 == 2)
				CloseCard1++;
			else if (lock2 == 3)
				x2Card1++;
			lock2 = -1;
		}
		else if (Player11 == lockycard3) {
			if (lock3 == 0)
				LimitCard1++;
			else if (lock3 == 1)
				AgainCard1++;
			else if (lock3 == 2)
				CloseCard1++;
			else if (lock3 == 3)
				x2Card1++;
			lock3 = -1;
		}
		else if (Player11 == lockycard4) {
			if (lock4 == 0)
				LimitCard1++;
			else if (lock4 == 1)
				AgainCard1++;
			else if (lock4 == 2)
				CloseCard1++;
			else if (lock4 == 3)
				x2Card1++;
			lock4 = -1;
		}

	}//Player11
	else if (win1 != 2 && turn == 2) {

		Player12 += dice;
		if (Player12 < 1) {//yani az safhe nazane birun
			Player12 = 1;
		}
		else if (Player12 > 81) {
			Player12 = 81;
		}
		if (Player12 == 41) {
			win1++;
			if (run_board_black)
				bitmap_player12 = al_load_bitmap("blackwin.png");
			if (run_board_yellow)
				bitmap_player12 = al_load_bitmap("yellowwin.png");
			if (run_board_blue)
				bitmap_player12 = al_load_bitmap("bluewin.png");
			if (run_board_red)
				bitmap_player12 = al_load_bitmap("redwin.png");
			if (run_board_green)
				bitmap_player12 = al_load_bitmap("greenwin.png");
		}
		if (Player12 == Player21) {
			Player21 = 82;
		}
		else if (Player12 == Player22) {
			Player22 = 82;
		}
		//lockycards
		if (Player12 == lockycard1) {
			if (lock1 == 0)
				LimitCard1++;
			else if (lock1 == 1)
				AgainCard1++;
			else if (lock1 == 2)
				CloseCard1++;
			else if (lock1 == 3)
				x2Card1++;
			lock1 = -1;
		}
		else if (Player12 == lockycard2) {
			if (lock2 == 0)
				LimitCard1++;
			else if (lock2 == 1)
				AgainCard1++;
			else if (lock2 == 2)
				CloseCard1++;
			else if (lock2 == 3)
				x2Card1++;
			lock2 = -1;
		}
		else if (Player12 == lockycard3) {
			if (lock3 == 0)
				LimitCard1++;
			else if (lock3 == 1)
				AgainCard1++;
			else if (lock3 == 2)
				CloseCard1++;
			else if (lock3 == 3)
				x2Card1++;
			lock3 = -1;
		}
		else if (Player12 == lockycard4) {
			if (lock4 == 0)
				LimitCard1++;
			else if (lock4 == 1)
				AgainCard1++;
			else if (lock4 == 2)
				CloseCard1++;
			else if (lock4 == 3)
				x2Card1++;
			lock4 = -1;
		}
	}//Player21
	else if (win2 != 2 && turn == 3) {//player 2 starting turn:

		Player21 -= dice;
		if (Player21 < 1) {//yani az safhe nazane birun
			Player21 = 1;
		}
		else if (Player21 > 81) {
			Player21 = 81;
		}
		if (Player21 == 41) {
			win2++;
			if (run_board_black)
				bitmap_player21 = al_load_bitmap("blackwin.png");
			if (run_board_yellow)
				bitmap_player21 = al_load_bitmap("yellowwin.png");
			if (run_board_blue)
				bitmap_player21 = al_load_bitmap("bluewin.png");
			if (run_board_red)
				bitmap_player21 = al_load_bitmap("redwin.png");
			if (run_board_green)
				bitmap_player21 = al_load_bitmap("greenwin.png");
		}
		if (Player21 == Player11) {
			Player11 = 0;
		}
		else if (Player21 == Player12) {
			Player12 = 0;
		}
		//lockycards
		if (Player21 == lockycard1) {
			if (lock1 == 0)
				LimitCard2++;
			else if (lock1 == 1)
				AgainCard2++;
			else if (lock1 == 2)
				CloseCard2++;
			else if (lock1 == 3)
				x2Card2++;
			lock1 = -1;
		}
		else if (Player21 == lockycard2) {
			if (lock2 == 0)
				LimitCard2++;
			else if (lock2 == 1)
				AgainCard2++;
			else if (lock2 == 2)
				CloseCard2++;
			else if (lock2 == 3)
				x2Card2++;
			lock2 = -1;
		}
		else if (Player21 == lockycard3) {
			if (lock3 == 0)
				LimitCard2++;
			else if (lock3 == 1)
				AgainCard2++;
			else if (lock3 == 2)
				CloseCard2++;
			else if (lock3 == 3)
				x2Card2++;
			lock3 = -1;
		}
		else if (Player21 == lockycard4) {
			if (lock4 == 0)
				LimitCard2++;
			else if (lock4 == 1)
				AgainCard2++;
			else if (lock4 == 2)
				CloseCard2++;
			else if (lock4 == 3)
				x2Card2++;
			lock4 = -1;
		}
	}//Player21
	else if (win2 != 2 && turn == 4) {
		Player22 -= dice;
		if (Player22 < 1) {//yani az safhe nazane birun
			Player22 = 1;
		}
		else if (Player22 > 81) {
			Player22 = 81;
		}
		if (Player22 == 41) {
			win2++;
			if (run_board_black)
				bitmap_player22 = al_load_bitmap("blackwin.png");
			if (run_board_yellow)
				bitmap_player22 = al_load_bitmap("yellowwin.png");
			if (run_board_blue)
				bitmap_player22 = al_load_bitmap("bluewin.png");
			if (run_board_red)
				bitmap_player22 = al_load_bitmap("redwin.png");
			if (run_board_green)
				bitmap_player22 = al_load_bitmap("greenwin.png");
		}
		if (Player22 == Player11) {
			Player11 = 0;
		}
		else if (Player22 == Player12) {
			Player12 = 0;
		}
		if (Player22 == lockycard1) {
			if (lock1 == 0)
				LimitCard2++;
			else if (lock1 == 1)
				AgainCard2++;
			else if (lock1 == 2)
				CloseCard2++;
			else if (lock1 == 3)
				x2Card2++;
			lock1 = -1;
		}
		else if (Player22 == lockycard2) {
			if (lock2 == 0)
				LimitCard2++;
			else if (lock2 == 1)
				AgainCard2++;
			else if (lock2 == 2)
				CloseCard2++;
			else if (lock2 == 3)
				x2Card2++;
			lock2 = -1;
		}
		else if (Player22 == lockycard3) {
			if (lock3 == 0)
				LimitCard2++;
			else if (lock3 == 1)
				AgainCard2++;
			else if (lock3 == 2)
				CloseCard2++;
			else if (lock3 == 3)
				x2Card2++;
			lock3 = -1;
		}
		else if (Player22 == lockycard4) {
			if (lock4 == 0)
				LimitCard2++;
			else if (lock4 == 1)
				AgainCard2++;
			else if (lock4 == 2)
				CloseCard2++;
			else if (lock4 == 3)
				x2Card2++;
			lock4 = -1;
		}
	}//Player22
}

void refreshboard() {
	///////////////////////////////////////////////////////////////////////////////////////////
	ALLEGRO_FONT* font1 = al_create_builtin_font();
	//font1 = al_load_font("arial.ttf", 40, 0);
	playercoordinates();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//applying players coordinates
	if (run_board_black)
		al_draw_bitmap(bitmap_board_black, 0, 0, 0);
	else if (run_board_blue)
		al_draw_bitmap(bitmap_board_blue, 0, 0, 0);
	else if (run_board_red)
		al_draw_bitmap(bitmap_board_red, 0, 0, 0);
	else if (run_board_yellow)
		al_draw_bitmap(bitmap_board_yellow, 0, 0, 0);
	else if (run_board_green)
		al_draw_bitmap(bitmap_board_green, 0, 0, 0);
	if (Player12 != 41)
		al_draw_bitmap(bitmap_player12, xp12, yp12, 0);
	else al_draw_bitmap(bitmap_player12, 718, 535, 0);
	if (Player11 != 41)
		al_draw_bitmap(bitmap_player11, xp11, yp11, 0);
	else al_draw_bitmap(bitmap_player11, 718, 535, 0);
	if (Player22 != 41)
		al_draw_bitmap(bitmap_player22, xp22, yp22, 0);
	else al_draw_bitmap(bitmap_player22, 382, 49, 0);
	if (Player21 != 41)
		al_draw_bitmap(bitmap_player21, xp21, yp21, 0);
	else al_draw_bitmap(bitmap_player21, 382, 49, 0);

	//corridors
	al_draw_bitmap(bitmap_corridor, xcorr1f, ycorr1f, 0);
	al_draw_bitmap(bitmap_corridor, xcorr1e, ycorr1e, 0);
	al_draw_bitmap(bitmap_corridor, xcorr2e, ycorr2e, 0);
	al_draw_bitmap(bitmap_corridor, xcorr2f, ycorr2f, 0);

	if (lock1 != -1)
		al_draw_bitmap(bitmap_lockycard, xlocky1 + 5, ylocky1 + 3, 0);
	if (lock2 != -1)
		al_draw_bitmap(bitmap_lockycard, xlocky2 + 5, ylocky2 + 3, 0);
	if (lock3 != -1)
		al_draw_bitmap(bitmap_lockycard, xlocky3 + 5, ylocky3 + 3, 0);
	if (lock4 != -1)
		al_draw_bitmap(bitmap_lockycard, xlocky4 + 5, ylocky4 + 3, 0);
	al_draw_textf(font1, al_map_rgb(255, 255, 255), 663, 533, 20, "%d", LimitCard1);
	al_draw_textf(font1, al_map_rgb(255, 255, 255), 676, 87, 20, "%d", LimitCard2);
	al_draw_textf(font1, al_map_rgb(255, 255, 255), 645, 533, 20, "%d", AgainCard1);
	al_draw_textf(font1, al_map_rgb(255, 255, 255), 657, 87, 20, "%d", AgainCard2);
	al_draw_textf(font1, al_map_rgb(255, 255, 255), 527, 533, 20, "%d", CloseCard1);
	al_draw_textf(font1, al_map_rgb(255, 255, 255), 540, 87, 20, "%d", CloseCard2);
	al_draw_textf(font1, al_map_rgb(255, 255, 255), 505, 533, 20, "%d", x2Card1);
	al_draw_textf(font1, al_map_rgb(255, 255, 255), 518, 87, 20, "%d", x2Card2);

	Sw_shown_once = 1;

	al_flip_display();

}
int checkwinner() {
	if (win1 == 2) {
		//strcpy(gamestate, "playerwon");
		run_win = true;
		run_win1 = true;
		return 1;
	}
	else if (win2 == 2) {
		//strcpy(gamestate, "playerwon");
		run_win = true;
		run_win2 = true;
		return 2;
	}
	return 0;
}

void dicetoal(int dice) { //applying dice changes to allegro display

	time_t time1;
	time1 = time(NULL);
	ALLEGRO_FONT* font = al_create_builtin_font();
	if (dice == -1) al_draw_bitmap(bitmap_dice1, 130, 400, 0);
	else if (dice == -2) al_draw_bitmap(bitmap_dice2, 130, 400, 0);
	else if (dice == -3) al_draw_bitmap(bitmap_dice3, 130, 400, 0);
	else if (dice == 1) al_draw_bitmap(bitmap_dice4, 130, 400, 0);
	else if (dice == 2) al_draw_bitmap(bitmap_dice5, 130, 400, 0);
	else if (dice == 3) al_draw_bitmap(bitmap_dice6, 130, 400, 0);

	if (turn == 1 || turn == 2 || turn == 5) {
		al_draw_bitmap(bitmap_turn1, 30, 20, 0);
	}

	else if (turn == 3 || turn == 4 || turn == 6) {
		al_draw_bitmap(bitmap_turn2, 30, 20, 0);
	}
	if ((turn == 5 && x2Card1 > 0 && AgainCard1) || (turn == 6 && x2Card2 > 0 && AgainCard2 > 0)) al_draw_bitmap(bitmap_asker3, 80, 150, 0);//player has both cards
	else if ((turn == 5 && x2Card1 > 0) || (turn == 6 && x2Card2 > 0)) al_draw_bitmap(bitmap_asker2, 80, 150, 0);//player has just 2x card
	else if ((turn == 5 && AgainCard1) || (turn == 6 && AgainCard2 > 0)) al_draw_bitmap(bitmap_asker4, 80, 150, 0);//player has just again card
	else al_draw_bitmap(bitmap_asker, 80, 150, 0);//there is no card for player
	al_flip_display();
}

int closethedoor() {//applying close luckycard function
	if ((turn == 1 || turn == 2) && CloseCard1 > 0) {
		al_draw_bitmap(bitmap_closeask, 300, 100, 0);
		al_flip_display();
		while (1) {
			al_get_keyboard_state(&ks);
			if (al_key_down(&ks, ALLEGRO_KEY_Y)) {
				return 1;
				CloseCard1--;
			}
			else if (al_key_down(&ks, ALLEGRO_KEY_N))  return 0;
		}
	}
	if ((turn == 3 || turn == 4) && CloseCard2 > 0) {
		al_draw_bitmap(bitmap_closeask, 300, 100, 0);
		al_flip_display();
		while (1) {
			al_get_keyboard_state(&ks);
			if (al_key_down(&ks, ALLEGRO_KEY_Y)) {
				return 1;
				CloseCard2--;
			}
			else if (al_key_down(&ks, ALLEGRO_KEY_N))  return 0;
		}
	}
}

int limiter() {//applying limit luckycard function   0:player not using limit card      1:the next turn has been cangee successfully
	ALLEGRO_FONT* font1 = al_create_builtin_font();
	if (((turn == 1 || turn == 2) && LimitCard1 > 0) || ((turn == 3 || turn == 4) && LimitCard2 > 0)) al_draw_bitmap(bitmap_asklimit, 80, 150, 0);
	al_flip_display();
	if (((turn == 1 || turn == 2) && LimitCard1 > 0) || ((turn == 3 || turn == 4) && LimitCard2 > 0)) {
		while (true) {
			al_get_keyboard_state(&ks);
			if (al_key_down(&ks, ALLEGRO_KEY_N)) return 0;
			else if (al_key_down(&ks, ALLEGRO_KEY_Y)) {
				al_draw_bitmap(bitmap_which, 80, 150, 0);
				if (turn == 3 || turn == 4) {
					al_draw_text(font1, al_map_rgb(200, 160, 150), xp11, yp11, 20, "1");
					al_draw_text(font1, al_map_rgb(200, 160, 150), xp12, yp12, 20, "2");
				}
				else if (turn == 1 || turn == 2) {
					al_draw_text(font1, al_map_rgb(200, 160, 150), xp21, yp21, 20, "1");
					al_draw_text(font1, al_map_rgb(200, 160, 150), xp22, yp22, 20, "2");
				}
				al_flip_display();
				while (true) {
					al_get_keyboard_state(&ks);
					if ((turn == 1 || turn == 2) && LimitCard1 > 0 && al_key_down(&ks, ALLEGRO_KEY_1)) {
						turn = 4;
						LimitCard1--;
						return 1;
					}
					else if ((turn == 1 || turn == 2) && LimitCard1 > 0 && al_key_down(&ks, ALLEGRO_KEY_2)) {
						turn = 3;
						LimitCard1--;
						return 1;
					}
					else if ((turn == 3 || turn == 4) && LimitCard2 > 0 && al_key_down(&ks, ALLEGRO_KEY_1)) {
						turn = 2;
						LimitCard2--;
						return 1;
					}
					else if ((turn == 3 || turn == 4) && LimitCard2 > 0 && al_key_down(&ks, ALLEGRO_KEY_2)) {
						turn = 1;
						LimitCard2--;
						return 1;
					}
				}
			}
		}
		return 0;
	}
	return 0;
}

int turner() {   //switching the turns(considering limitation)
	if (!limiter()) {//checking limit function
		if (turn == 1 || turn == 2) {
			turn = 6;
			strcpy(gamestate, "asking");
		}

		else if (turn == 3 || turn == 4) {
			turn = 5;
			strcpy(gamestate, "asking");
		}
	}
	return turn;
}

int turn_to_pl_name() {
	if (turn == 1) return &Player11;
	if (turn == 2) return &Player12;
	if (turn == 3) return &Player21;
	if (turn == 4) return &Player22;
}

void corridors(int* playerpos) {//applying corridor function if available
	// bug= agar karbar bere dakhel corridor va daste baad harkat nade
	// debugged..
	time_t time1;
	time1 = time(NULL);
	int a = random_number(1, 2);
	if (*playerpos == Corr11 || *playerpos == Corr22) {
		if (closethedoor() == 1) {
			refreshboard();
			return 0;
		}
		refreshboard();
		if (a == 1) *playerpos = Corr12;
		else *playerpos = Corr21;
		while (true) { if (time(NULL) - time1 > 1.5) break; }
	}
	else if (*playerpos == Corr21 || *playerpos == Corr12) {
		if (closethedoor() == 1) {
			refreshboard();
			return 0;
		}refreshboard();
		if (a == 1) *playerpos = Corr11;
		else *playerpos = Corr22;
		while (true) {
			if (time(NULL) - time1 > 1.5) break;
		}
	}
}

void choosetoturn() {
	int sw_justonetime = 1;
	//applyable_turn();
	ALLEGRO_FONT* font = al_create_builtin_font();
	while (!strcmp(gamestate, "asking")) {
		al_get_keyboard_state(&ks);
		if (al_key_down(&ks, ALLEGRO_KEY_ESCAPE)) {
			running = false;
			break;
		}
		if (al_key_down(&ks, ALLEGRO_KEY_TAB) && (turn == 5 || turn == 1 || turn == 2) && AgainCard1 > 0) {
			AgainCard1--;
			break;
		}
		if (al_key_down(&ks, ALLEGRO_KEY_TAB) && (turn == 6 || turn == 3 || turn == 4) && AgainCard2 > 0) {
			AgainCard2--;
			break;
		}
		if ((al_key_down(&ks, ALLEGRO_KEY_LSHIFT) || al_key_down(&ks, ALLEGRO_KEY_RSHIFT)) && (turn == 6 || turn == 3 || turn == 4) && x2Card2 > 0 && sw_justonetime) {
			dice *= 2;
			sw_justonetime = 0;
			x2Card2--;
			al_draw_bitmap(bitmap_which, 80, 150, 0);
			al_flip_display();
		}
		else if ((al_key_down(&ks, ALLEGRO_KEY_LSHIFT) || al_key_down(&ks, ALLEGRO_KEY_RSHIFT)) && (turn == 5 || turn == 1 || turn == 2) && x2Card1 > 0 && sw_justonetime) {
			dice *= 2;
			sw_justonetime = 0;
			x2Card1--;
			al_draw_bitmap(bitmap_which, 80, 150, 0);
			al_flip_display();
		}
		if (turn == 5) {//which piece
			if (win1 > 0 && Player11 == 41) {//if one piece won use the other one
				turn = 2;
				strcpy(gamestate, "gaming");
			}
			else if (win1 > 0 && Player12 == 41) {//if one piece won use the other one
				turn = 1;
				strcpy(gamestate, "gaming");
			}
			else if (al_key_down(&ks, ALLEGRO_KEY_1)) {
				turn = 1;
				strcpy(gamestate, "gaming");
			}
			else if (al_key_down(&ks, ALLEGRO_KEY_2)) {
				turn = 2;
				strcpy(gamestate, "gaming");
			}
		}
		else if (turn == 6) {//which piece
			if (win2 > 0 && Player21 == 41) {//if one piece won use the other one
				turn = 4;
				strcpy(gamestate, "gaming");
			}
			else if (win2 > 0 && Player22 == 41) {//if one piece won use the other one
				turn = 3;
				strcpy(gamestate, "gaming");
			}
			else if (al_key_down(&ks, ALLEGRO_KEY_1)) {
				turn = 3;
				strcpy(gamestate, "gaming");
			}
			else if (al_key_down(&ks, ALLEGRO_KEY_2)) {
				turn = 4;
				strcpy(gamestate, "gaming");
			}
		}
	}
}

void logicgame() {

	ALLEGRO_FONT* font = al_create_builtin_font();
	if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(830, 869, 89, 145) == 1) {
		run_board = false;
		setting_open();
	}
	refreshboard();
	time_t time1;
	time1 = time(NULL);
	al_get_keyboard_state(&ks);
	al_get_mouse_state(&muste);
	mouse_pos();
	//strcopy(gamestate, "asking");
	if ((!strcmp(gamestate, "gaming") || !strcmp(gamestate, "asking")) && al_key_down(&ks, ALLEGRO_KEY_SPACE)) {//starting next player turn
		ejaze = true;
	}
	if (Sw_shown_once && ejaze) {//dice function applying
		dice = DiceRand();
		dicetoal(dice);
	}


	if (!strcmp(gamestate, "asking") && ejaze) {//asking player to move which mohre
		choosetoturn();
		if (win1 > 0 && (turn == 1 || turn == 2)) {
			while (AgainCard1 > 0) {
				al_get_keyboard_state(&ks);
				al_draw_bitmap(bitmap_doubledice, 80, 150, 0);
				al_flip_display();
				if (al_key_down(&ks, ALLEGRO_KEY_ESCAPE)) {
					running = false;
					break;
				}
				if (al_key_down(&ks, ALLEGRO_KEY_Y) && (turn == 5 || turn == 1 || turn == 2) && x2Card1 > 0) {
					x2Card1--;
					dice *= 2;
					break;
				}
				if (al_key_down(&ks, ALLEGRO_KEY_N) && (turn == 5 || turn == 1 || turn == 2) && x2Card1 > 0) {
					break;
				}
			}
		}
		else if (win2 > 0 && (turn == 3 || turn == 4)) {
			while (AgainCard2 > 0) {
				al_get_keyboard_state(&ks);
				al_draw_bitmap(bitmap_doubledice, 80, 150, 0);
				al_flip_display();
				if (al_key_down(&ks, ALLEGRO_KEY_ESCAPE)) {
					running = false;
					break;
				}
				if (al_key_down(&ks, ALLEGRO_KEY_Y) && (turn == 6 || turn == 3 || turn == 4) && x2Card2 > 0) {
					x2Card2--;
					dice *= 2;
					break;
				}
				if (al_key_down(&ks, ALLEGRO_KEY_N) && (turn == 6 || turn == 3 || turn == 4) && x2Card2 > 0) {
					break;
				}
			}
		}
	}

	printf("\n str:%s   ejaze :%d   turn:%d   dice:%d", gamestate, ejaze, turn, dice);


	if ((!strcmp(gamestate, "gaming")) && ejaze && Sw_shown_once) {//the main game logics


		doingturn(turn, dice);
		refreshboard();
		corridors(turn_to_pl_name());
		Sw_shown_once = 1;
		redraw = true;
		ejaze = false;
		turner();

	}
	if (checkwinner() == 1 || checkwinner() == 2) {//means that somebody won
		run_board = false;
		run_board = true;
	}
	if (mouse_positon(826, 880, 29, 81) == 1) {
		if (al_mouse_button_down(&muste, 1) == 1) {
			Savegame();
			run_board = false;
			run_meet = false;
			run_menu = true;
			gm_defaults();
		}
	}
}


int main() {

	srand(time(NULL));


	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
	al_init();

	display = al_create_display(900, 600);
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	al_install_mouse();
	al_install_keyboard();

	al_get_mouse_state(&muste);

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	al_init_image_addon();
	bitmap_startmeet = al_load_bitmap("startmeet.png");
	bitmap_menu = al_load_bitmap("menu_black.png");
	bitmap_runner = al_load_bitmap("runner.png");
	bitmap_newgame = al_load_bitmap("newgame_black.png");
	bitmap_info1 = al_load_bitmap("info1.png");
	bitmap_info2 = al_load_bitmap("info2.png");
	bitmap_setting = al_load_bitmap("setting.png");
	bitmap_board_black = al_load_bitmap("board_black.png");
	bitmap_board_yellow = al_load_bitmap("board_yellow.png");
	bitmap_board_red = al_load_bitmap("board_red.png");
	bitmap_board_blue = al_load_bitmap("board_blue.png");
	bitmap_board_green = al_load_bitmap("board_green.png");
	bitmap_win1 = al_load_bitmap("win1_black.png");
	bitmap_win2 = al_load_bitmap("win2_black.png");
	bitmap_player11 = al_load_bitmap("black1.png");//pieces
	bitmap_player12 = al_load_bitmap("black2.png");
	bitmap_player21 = al_load_bitmap("black3.png");
	bitmap_player22 = al_load_bitmap("black4.png");
	bitmap_player11_win = al_load_bitmap("blackwin.png");//pieces
	bitmap_player12_win = al_load_bitmap("blackwin.png");
	bitmap_player21_win = al_load_bitmap("blackwin.png");
	bitmap_player22_win = al_load_bitmap("blackwin.png");
	bitmap_dice1 = al_load_bitmap("minus1_black.png");//dice
	bitmap_dice2 = al_load_bitmap("minus2_black.png");
	bitmap_dice3 = al_load_bitmap("minus3_black.png");
	bitmap_dice4 = al_load_bitmap("plus1_black.png");
	bitmap_dice5 = al_load_bitmap("plus2_black.png");
	bitmap_dice6 = al_load_bitmap("plus3_black.png");
	bitmap_turn1 = al_load_bitmap("turn1_black.png");
	bitmap_turn2 = al_load_bitmap("turn2_black.png");
	bitmap_corridor = al_load_bitmap("corridor_black.png");
	bitmap_asker = al_load_bitmap("asker.png");
	bitmap_asker2 = al_load_bitmap("asker2.png");
	bitmap_asker3 = al_load_bitmap("asker3.png");
	bitmap_asker4 = al_load_bitmap("asker4.png");
	bitmap_asklimit = al_load_bitmap("limitask.png");
	bitmap_closeask = al_load_bitmap("askclose.png");
	bitmap_which = al_load_bitmap("which.png");
	bitmap_lockycard = al_load_bitmap("lockycard_black.png");
	bitmap_doubledice = al_load_bitmap("doubledice.png");


	assert(bitmap_startmeet != NULL);
	assert(bitmap_menu != NULL);
	assert(bitmap_runner != NULL);
	assert(bitmap_newgame != NULL);
	assert(bitmap_board_black != NULL);
	assert(bitmap_win1 != NULL);
	assert(bitmap_win2 != NULL);
	assert(bitmap_info1 != NULL);
	assert(bitmap_info2 != NULL);
	assert(bitmap_setting != NULL);
	assert(bitmap_player11 != NULL);
	assert(bitmap_player12 != NULL);
	assert(bitmap_player12 != NULL);
	assert(bitmap_player22 != NULL);
	assert(bitmap_player11_win != NULL);
	assert(bitmap_player12_win != NULL);
	assert(bitmap_player21_win != NULL);
	assert(bitmap_player22_win != NULL);
	assert(bitmap_dice1 != NULL);
	assert(bitmap_dice2 != NULL);
	assert(bitmap_dice3 != NULL);
	assert(bitmap_dice4 != NULL);
	assert(bitmap_dice5 != NULL);
	assert(bitmap_dice6 != NULL);
	assert(bitmap_turn1 != NULL);
	assert(bitmap_turn2 != NULL);
	assert(bitmap_board_black != NULL);
	assert(bitmap_board_yellow != NULL);
	assert(bitmap_board_red != NULL);
	assert(bitmap_board_blue != NULL);
	assert(bitmap_board_green != NULL);
	assert(bitmap_asker != NULL);
	assert(bitmap_asker2 != NULL);
	assert(bitmap_asker3 != NULL);
	assert(bitmap_asker4 != NULL);
	assert(bitmap_corridor != NULL);
	assert(bitmap_closeask != NULL);
	assert(bitmap_asklimit != NULL);
	assert(bitmap_which != NULL);
	assert(bitmap_lockycard != NULL);

	assert(bitmap_doubledice != NULL);


	time_t time1;
	time1 = time(NULL);

	bool done = false;
	bool redraw = true;


#define KEY_SEEN     1                      //setting up keyboard 
#define KEY_RELEASED 2

	unsigned char key[ALLEGRO_KEY_MAX];
	memset(key, 0, sizeof(key));
	ALLEGRO_EVENT event;

	int sw1 = 0, sw_gm_intro = 0, sw_gm_menu = 0;
	Sw_shown_once = 1;

	while (1) { if (time(NULL) - time1 >= 0.5) break; }

	al_wait_for_event(queue, &event);

	al_start_timer(timer);
	while (running) {
		al_wait_for_event(queue, &event);
		switch (event.type) {
		case ALLEGRO_EVENT_TIMER:
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			while (run_meet) {
				al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
				al_draw_bitmap(bitmap_startmeet, 0, 0, 0);
				al_draw_bitmap(bitmap_runner, 725, 447, 0);
				al_flip_display();
				mouse_pos();

				//run menu
				if (mouse_positon(725, 791, 447, 511) == 1) {
					if (al_mouse_button_down(&muste, 1) == 1) {
						run_menu = true;
						run_meet = false;
					}
				}
			}
			while (run_menu) {
				mouse_pos();
				al_draw_bitmap(bitmap_menu, 0, 0, 0);
				al_flip_display();
				if (mouse_positon(830, 875, 523, 572) == 1) {
					if (al_mouse_button_down(&muste, 1) == 1) {
						running = false;
					}
					break;
				}
				//run newgame
				if (mouse_positon(54, 286, 247, 280) == 1) {
					if (al_mouse_button_down(&muste, 1) == 1) {
						run_menu = false;
						run_meet = false;
						run_newgame = true;
						gm_defaults();
					}
				}
				//run loadgame
				if (mouse_positon(54, 293, 313, 343) == 1) {
					if (al_mouse_button_down(&muste, 1) == 1) {
						run_menu = false;
						run_meet = false;
						run_newgame = false;
						run_board = true;
						Loadgame();
					}
				}
				//run setting
				if (mouse_positon(54, 199, 378, 412) == 1) {
					if (al_mouse_button_down(&muste, 1) == 1) {
						setting_open();
						run_menu = true;
					}
				}
				//run info
				if (mouse_positon(54, 143, 437, 470) == 1) {
					if (al_mouse_button_down(&muste, 1) == 1) {
						run_menu = false;
						run_info1 = true;
					}
				}
			}

			//run info1
			while (run_info1) {
				mouse_pos();
				al_draw_bitmap(bitmap_info1, 0, 0, 0);
				al_flip_display();
				//exit info
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(851, 886, 31, 97) == 1) {
					run_info1 = false;
					run_menu = true;
				}
				//info next page
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(837, 880, 98, 151) == 1 && run_info1) {
					run_info1 = false;
					run_info2 = true;
					run_info3 = false;
					run_info4 = false;
				}
			}
			//run info2
			while (run_info2) {
				mouse_pos();
				al_draw_bitmap(bitmap_info2, 0, 0, 0);
				al_flip_display();
				//exit info
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(851, 886, 31, 97) == 1) {
					run_info2 = false;
					run_menu = true;
				}
				//info Back
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(837, 886, 160, 210) == 1) {
					run_info2 = false;
					run_info1 = true;
					run_info3 = false;
					run_info4 = false;
				}
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(839, 881, 96, 151) == 1) {
					run_info2 = false;
					run_info3 = true;
					run_info4 = false;
					run_info1 = false;
				}
			}
			while (run_info3) {
				mouse_pos();
				al_draw_bitmap(bitmap_info3, 0, 0, 0);
				al_flip_display();
				//exit info
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(851, 886, 31, 97) == 1) {
					run_info3 = false;
					run_menu = true;
				}
				//info Back
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(837, 886, 160, 210) == 1) {
					run_info3 = false;
					run_info2 = true;
					run_info1 = false;
					run_info4 = false;
				}
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(837, 880, 98, 151) == 1) {
					run_info3 = false;
					run_info4 = true;
					run_info2 = false;
					run_info1 = false;
				}
			}
			while (run_info4) {
				mouse_pos();
				al_draw_bitmap(bitmap_info4, 0, 0, 0);
				al_flip_display();
				//exit info
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(851, 886, 31, 97) == 1) {
					run_info4 = false;
					run_menu = true;
				}
				//info Back
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(837, 886, 92, 144) == 1) {
					run_info4 = false;
					run_info3 = true;
					run_info2 = false;
					run_info1 = false;
				}
			}

			while (run_newgame) {
				mouse_pos();
				al_draw_bitmap(bitmap_newgame, 0, 0, 0);
				al_flip_display();
				//exit program
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(832, 878, 30, 86) == 1) {
					running = false;
				}
				//undo newgame
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(832, 878, 100, 156) == 1) {
					run_newgame = false;
					run_menu = true;
				}
				//run board
				if (al_mouse_button_down(&muste, 1) == 1 && mouse_positon(387, 520, 228, 402) == 1) {
					run_newgame = false;
					run_board = true;
					gm_defaults();
				}
			}
			if (run_board) {
				//mouse_pos();

				strcpy(gamestate, "asking");
				while (checkwinner() == 0) {
					logicgame();
					if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) running = false;
					if (run_menu && !run_win)
						break;
				}
			}
			while (run_win) {
				al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
				if (run_win1)
					al_draw_bitmap(bitmap_win1, 0, 0, 0);
				if (run_win2)
					al_draw_bitmap(bitmap_win2, 0, 0, 0);
				al_flip_display();
				mouse_pos();

				//run menu
				if (mouse_positon(709, 771, 448, 509) == 1) {
					if (al_mouse_button_down(&muste, 1) == 1) {
						run_menu = true;
						run_win = false;
						run_win1 = false;
						run_win2 = false;
					}
				}
			}
		case ALLEGRO_EVENT_KEY_DOWN:
			key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
			break;
		case ALLEGRO_EVENT_KEY_UP:
			key[event.keyboard.keycode] &= KEY_RELEASED;
			break;
		}
	}
	al_destroy_display(display);
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_destroy_timer(timer);
	al_destroy_bitmap(bitmap_startmeet);
	al_destroy_bitmap(bitmap_menu);
	al_destroy_bitmap(bitmap_runner);
	al_destroy_bitmap(bitmap_newgame);
	al_destroy_bitmap(bitmap_info1);
	al_destroy_bitmap(bitmap_info2);
	al_destroy_bitmap(bitmap_setting);
	al_destroy_bitmap(bitmap_board_black);
	al_destroy_bitmap(bitmap_board_yellow);
	al_destroy_bitmap(bitmap_board_red);
	al_destroy_bitmap(bitmap_board_blue);
	al_destroy_bitmap(bitmap_board_green);
	al_destroy_bitmap(bitmap_player11);
	al_destroy_bitmap(bitmap_player12);
	al_destroy_bitmap(bitmap_player21);
	al_destroy_bitmap(bitmap_player22);
	al_destroy_bitmap(bitmap_player11_win);
	al_destroy_bitmap(bitmap_player12_win);
	al_destroy_bitmap(bitmap_player21_win);
	al_destroy_bitmap(bitmap_player22_win);
	al_destroy_bitmap(bitmap_dice1);
	al_destroy_bitmap(bitmap_dice2);
	al_destroy_bitmap(bitmap_dice3);
	al_destroy_bitmap(bitmap_dice4);
	al_destroy_bitmap(bitmap_dice5);
	al_destroy_bitmap(bitmap_dice6);
	al_destroy_bitmap(bitmap_turn1);
	al_destroy_bitmap(bitmap_turn2);
	al_destroy_bitmap(bitmap_corridor);
	al_destroy_bitmap(bitmap_asker);
	al_destroy_bitmap(bitmap_asker2);
	al_destroy_bitmap(bitmap_asker3);
	al_destroy_bitmap(bitmap_asker4);
	al_destroy_bitmap(bitmap_asklimit);
	al_destroy_bitmap(bitmap_closeask);
	al_destroy_bitmap(bitmap_which);
	al_destroy_bitmap(bitmap_lockycard);


	return 0;
}