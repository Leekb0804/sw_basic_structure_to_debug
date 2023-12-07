#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "map.h"
#include "cursor.h" //getcursor, setcursor 함수들을 파일로 따로 뺐음
#include "player.h"

#include "bomb.h"
#include "define_state.h"
#include "Test_Moving.h"
#include "Test_Moving2.h"
#include "Test_Moving3.h"
#include "calculatorDST.h"
#include "calculatorDST2.h"
#include "calculatorDST3.h"
#include "stage_image.h"



unsigned long long start_game_time;
unsigned long long current_game_time;
unsigned long long stage_start_time;

int player_item_range;

extern BombHead* bombHead;
extern BOOMHead* boomhead;

extern int npcCurPosX, npcCurPosY;
extern int npcCurPosX2, npcCurPosY2;
extern int npcCurPosX3, npcCurPosY3;
extern unsigned long long NPC_current_Time;
extern unsigned long long NPC_current_Time2;
extern unsigned long long NPC_current_Time3;
extern int npc1_state_flag = 0;
extern int npc2_state_flag = 0;
extern int npc3_state_flag = 0;

extern Map_box_head* map_box_head;             //폭탄이 모두 터진 후 박스를 없애기 위한 맵 박스 구조체 배열의 헤드 선언

extern int mapModel[HEIGHT][WIDTH];
extern int mapModel2[HEIGHT][WIDTH];
extern int mapModel3[HEIGHT][WIDTH];

extern int bomb_max ;
extern int player_bomb_len;

int game_round;

int main(void)
{
	q3 = (Queue3*)calloc(((WIDTH * 1) * (HEIGHT * 1)), sizeof(Queue3));
	safety3 = (Queue3*)calloc(((WIDTH * 1) * (HEIGHT * 1)), sizeof(Queue3));

	q2 = (Queue2*)calloc(((WIDTH * 1) * (HEIGHT * 1)), sizeof(Queue2));
	safety2 = (Queue2*)calloc(((WIDTH * 1) * (HEIGHT * 1)), sizeof(Queue2));

	q = (Queue*)calloc(((WIDTH * 1) * (HEIGHT * 1)), sizeof(Queue));
	safety = (Queue*)calloc(((WIDTH * 1) * (HEIGHT * 1)), sizeof(Queue));

	Sleep(500);
	
	system("mode con:cols=100 lines=40 | title 포포폭탄");

	RemoveCursor();

	start_game_time = clock();
	//bombHead1 = makeBombHead();
	//bombHead2 = makeBombHead();

	player_item_range = 1;


	//generateMap();

	bombHead = (BombHead*)malloc(sizeof(bombHead));
	bombHead->next = NULL;
	boomhead = (BOOMHead*)malloc(sizeof(BOOMHead));
	boomhead->next = NULL;

	map_box_head = generate_map_box_head();


	NPC_current_Time = 0;

	for (game_round = 1; game_round < 6; game_round++)
	{
		bomb_max = 1;
		player_bomb_len = 1;

		stage_start_time = clock();
		PlayerState = 1;
		PlayerCurPosX = arrX_to_cursorX(WIDTH - 3);		//get_Player_starting_point_x();
		PlayerCurPosY = arrY_to_cursorY(HEIGHT - 3);  //get_Player_starting_point_y();

		npcCurPosX = 2 * 2 + GBOARD_ORIGIN_X;
		npcCurPosY = 2 + GBOARD_ORIGIN_Y;

		npcCurPosX2 = 14 * 2 + GBOARD_ORIGIN_X;
		npcCurPosY2 = 2 + GBOARD_ORIGIN_Y;

		npcCurPosX3 = 2 * 2 + +GBOARD_ORIGIN_X;
		npcCurPosY3 = 14 + +GBOARD_ORIGIN_Y;

		NPC_current_Time = 0;
		NPC_current_Time2 = 0;
		NPC_current_Time3 = 0;


		npc1_state_flag = 0;
		npc2_state_flag = 0;
		npc3_state_flag = 0;

		if (game_round == 0)
		{
			
			bombHead->next = NULL;
			boomhead->next = NULL;
			/*TimeCheck();
			TimeCheck_BOOM();*/
			set_mapModel_spiral();
			reset_npcMapModel();
			draw_Stagemap_reset();
			NextStage_Mapdrawing();
			draw_Stagemap_reset();
			SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
			printf("                      \n");
			printf("                         \n");
		}
		else if (game_round == 1)
		{
			bombHead->next = NULL;
			boomhead->next = NULL;
			TimeCheck();
			TimeCheck_BOOM();
			set_mapModel_eye();
			reset_npcMapModel();
			draw_Stagemap_reset();
			NextStage_Mapdrawing();
			draw_Stagemap_reset();
			SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
			printf("                      \n");
			printf("                         \n");
		}
		else if (game_round == 2)
		{
			bombHead->next = NULL;
			boomhead->next = NULL;
			TimeCheck();
			TimeCheck_BOOM();
			set_mapModel_snail();
			reset_npcMapModel();
			draw_Stagemap_reset();
			NextStage_Mapdrawing();
			draw_Stagemap_reset();
			SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
			printf("                      \n");
			printf("                         \n");
		}
		else if (game_round == 3)
		{
			bombHead->next = NULL;
			boomhead->next = NULL;
			TimeCheck();
			TimeCheck_BOOM();
			set_mapModel_symmetry();
			reset_npcMapModel();
			draw_Stagemap_reset();
			NextStage_Mapdrawing();
			draw_Stagemap_reset();
			SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
			printf("                      \n");
			printf("                         \n");
		}
		else if (game_round == 4)
		{
			bombHead->next = NULL;
			boomhead->next = NULL;
			TimeCheck();
			TimeCheck_BOOM();
			set_mapModel_popopoktan();
			reset_npcMapModel();
			draw_Stagemap_reset();
			NextStage_Mapdrawing();
			draw_Stagemap_reset();
			SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
			printf("                      \n");
			printf("                         \n");
		}
		else if (game_round == 5)
		{
			bombHead->next = NULL;
			boomhead->next = NULL;
			TimeCheck();
			TimeCheck_BOOM();
			set_mapModel_firework();
			reset_npcMapModel();
			draw_Stagemap_reset();
			NextStage_Mapdrawing();
			draw_Stagemap_reset();
			SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
			printf("                      \n");
			printf("                         \n");
		}
		drawMaps();

		while (1)
		{
			SetCurrentCursorPos(80, 44);
			printf("                         ");
			SetCurrentCursorPos(80, 44);
			printf("main before current_game_time = clock() X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));

			current_game_time = clock();

			SetCurrentCursorPos(80, 43);
			printf("                         ");
			SetCurrentCursorPos(80, 43);
			printf("main before TimeCheck return X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));

			TimeCheck();
			remove_generate_item_all_map_box_struct(map_box_head);
			TimeCheck_BOOM();

			SetCurrentCursorPos(80, 42);
			printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
			SetCurrentCursorPos(80, 42);
			printf("main before if(CheckPlayerState) return X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));

			if (CheckPlayerState() == 1)
				Sleep(10000);
			if (game_round == 0 && CheckNPCState() == 2) {
				return;
			}
			if (game_round == 1 && (CheckNPCState() == 2 || CheckNPCState2() == 2)) {
				return;
			}
			if (game_round == 2 && (CheckNPCState() == 2 || CheckNPCState2() == 2 || CheckNPCState3() == 2)) {
				return;
			}
			SetCurrentCursorPos(80, 41);
			printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
			SetCurrentCursorPos(80, 41);
			printf("main before if(game_round == 0) X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));

			PlayerControl();


			/*NpcMoving();
			NpcMoving2();
			NpcMoving3();*/

			if (game_round == 0) {
				if (CheckNPCState() != 1 && npc1_state_flag == 0) {
					SetCurrentCursorPos(80, 36);
					printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
					SetCurrentCursorPos(80, 36);
					printf("main X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
					NpcMoving();
				}
				if (npc1_state_flag == 1)
				{
					//printf("next stage!!!\n");
					Sleep(3000);
					break;
				}
			}
			else if (game_round == 1) {
				SetCurrentCursorPos(80, 40);
				printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
				SetCurrentCursorPos(80, 40);
				printf("main before before  before if X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
				if (CheckNPCState() != 1 && npc1_state_flag == 0) {
					NpcMoving();
					SetCurrentCursorPos(80, 39);
					printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
					SetCurrentCursorPos(80, 39);
					printf("main npc_moving X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
				}
				SetCurrentCursorPos(80, 38);
				printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
				SetCurrentCursorPos(80, 38);
				printf("main before before if X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
				if (CheckNPCState2() != 1 && npc2_state_flag == 0) {
					NpcMoving2();
				}
				SetCurrentCursorPos(80, 37);
				printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
				SetCurrentCursorPos(80, 37);
				printf("main before if X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
				if (npc1_state_flag == 1) {
					SetCurrentCursorPos(80, 36);
					printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
					SetCurrentCursorPos(80, 36);
					printf("main X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
					NPC1_die();
				}
				if (npc2_state_flag == 1) {
					NPC2_die();
				}
				if (npc1_state_flag == 1 && npc2_state_flag == 1) {
					//printf("next stage!!!\n");
					Sleep(3000);
					break;
				}
			}
			else if (game_round == 2) {
				if (CheckNPCState() != 1 && npc1_state_flag == 0) {
					NpcMoving();
				}
				if (CheckNPCState2() != 1 && npc2_state_flag == 0) {
					NpcMoving2();
				}
				if (CheckNPCState3() != 1 && npc3_state_flag == 0) {
					NpcMoving3();
				}
				if (npc1_state_flag == 1) {
					NPC1_die();
				}
				if (npc2_state_flag == 1) {
					NPC2_die();
				}
				if (npc3_state_flag == 1) {
					NPC3_die();
				}
				if (npc1_state_flag == 1 && npc2_state_flag == 1 && npc3_state_flag == 1) {
					//printf("next stage!!!\n");

					Sleep(3000);
					break;
				}
			}
			else if (game_round == 3) {
				if (CheckNPCState() != 1 && npc1_state_flag == 0) {
					NpcMoving();
				}
				if (npc1_state_flag == 1)
				{
					//printf("next stage!!!\n");
					Sleep(3000);
					break;
				}
			}
			else if (game_round == 4) {
				if (CheckNPCState() != 1 && npc1_state_flag == 0) {
					NpcMoving();
				}
				if (CheckNPCState2() != 1 && npc2_state_flag == 0) {
					NpcMoving2();
				}
				if (npc1_state_flag == 1) {
					NPC1_die();
				}
				if (npc2_state_flag == 1) {
					NPC2_die();
				}
				if (npc1_state_flag == 1 && npc2_state_flag == 1) {
					//printf("next stage!!!\n");
					Sleep(3000);
					break;
				}
			}
			else if (game_round == 5) {
				if (CheckNPCState() != 1 && npc1_state_flag == 0) {
					NpcMoving();
				}
				if (CheckNPCState2() != 1 && npc2_state_flag == 0) {
					NpcMoving2();
				}
				if (CheckNPCState3() != 1 && npc3_state_flag == 0) {
					NpcMoving3();
				}
				if (npc1_state_flag == 1) {
					NPC1_die();
				}
				if (npc2_state_flag == 1) {
					NPC2_die();
				}
				if (npc3_state_flag == 1) {
					NPC3_die();
				}
				if (npc1_state_flag == 1 && npc2_state_flag == 1 && npc3_state_flag == 1) {
					//printf("next stage!!!\n");

					Sleep(3000);
					break;
				}
			}
			
			/*SetCurrentCursorPos(0, 20);
			for (int i = 0; i < HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					printf("%4d", NPCmapModel[i][j]);
				}
				printf("\n");
			}*/

			/*SetCurrentCursorPos(0, 23);
			for (int i = 0; i < HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					printf("%4d", mapModel[i][j]);
				}
				printf("\n");
			}*/

			

			if (game_round >= 3)
				sky_bomb_drop();
		}
	}
	Clear_Letterdrawing();
	while (1)
	{
		Sleep(10000);
	}

	return (0);
}
