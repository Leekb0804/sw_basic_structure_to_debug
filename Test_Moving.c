#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "Test_Moving.h"
#include "cursor.h"
#include "map.h"
#include "calculatorDST.h"
#include "player.h"
#include "define_state.h"
#include "bomb.h"

#define flagTime 4000

int npcCurPosX, npcCurPosY;
unsigned long long NPC_current_Time;
extern unsigned long long current_game_time;
extern int npc1_bomb_exist_count = 0;
extern int npc1_state_flag;

int npc1_bomb_max = 1;

void ShowNpcBlock()
{
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // 보라

	printf("★");
}

void DeleteBlock()
{

	SetCurrentCursorPos(npcCurPosX, npcCurPosY);
	printf("  ");
}

int NPC_moveLeft() {


	if (mapModel[cursorY_to_arrY(npcCurPosY)][cursorX_to_arrX(npcCurPosX)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 어두운 빨강
		printf("⊙");
	}
	else
		DeleteBlock();
	npcCurPosX -= 2;

	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	ShowNpcBlock();
	return 0;

}

int NPC_moveRight() {

	if (mapModel[cursorY_to_arrY(npcCurPosY)][cursorX_to_arrX(npcCurPosX)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 어두운 빨강
		printf("⊙");
	}
	else
		DeleteBlock();
	npcCurPosX += 2;
	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	ShowNpcBlock();

	return 0;

}

int NPC_moveUp() {

	if (mapModel[cursorY_to_arrY(npcCurPosY)][cursorX_to_arrX(npcCurPosX)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 어두운 빨강
		printf("⊙");
	}
	else
		DeleteBlock();
	npcCurPosY -= 1;
	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	ShowNpcBlock();

	return 0;
}

int NPC_moveDown() {

	if (mapModel[cursorY_to_arrY(npcCurPosY)][cursorX_to_arrX(npcCurPosX)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 어두운 빨강
		printf("⊙");
	}
	else
		DeleteBlock();
	npcCurPosY += 1;
	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	ShowNpcBlock();

	return 0;
}


int NpcMoving()
{
	int preX = 0, preY = 0;
	int npcX, npcY;

	//npcX = npcCurPosX / 2;
	npcX = cursorX_to_arrX(npcCurPosX);
	//npcY = npcCurPosY;
	npcY = cursorY_to_arrY(npcCurPosY);

	int kill_Mode = ShortestDistance(npcX, npcY); // 여기서 one_srt_dist 배열을 만들어줌 (이 배열을 보고 NPC가 움직임)

	int dx = npcX;
	int dy = npcY;

	SetCurrentCursorPos(80, 32);
	printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(80, 32);
	printf("NpcMoving X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));


	SetCurrentCursorPos(npcCurPosX, npcCurPosY);


	while (1) { //이 while문 안에 있는 clock변수들은 신경쓰지 않아도 됨, 아직 테스트중, 아마 1칸씩 움직여야 하니까 while 지우는 방법도 고려

		preX = dx;
		preY = dy;

		if (one_srt_dist[dy][dx + 1] == 1) { // NPC 현재위치 기준 one_srt_dist의 오른쪽이 1이라면 (갈수있는길)
			one_srt_dist[dy][dx] = 0; // 현재 위치의 one_srt_dist를 0으로 초기화 하고

			if (current_game_time - NPC_current_Time > flagTime) {
				NPC_current_Time = clock();
				NPC_moveRight(); //오른쪽으로 이동
			}
			dx += 1;
		}
		else if (one_srt_dist[dy][dx - 1] == 1) {
			one_srt_dist[dy][dx] = 0;

			if (current_game_time - NPC_current_Time > flagTime) {
				NPC_current_Time = clock();
				NPC_moveLeft();
			}
			dx -= 1;
		}
		else if (one_srt_dist[dy + 1][dx] == 1) {
			one_srt_dist[dy][dx] = 0;

			if (current_game_time - NPC_current_Time > flagTime) {
				NPC_current_Time = clock();
				NPC_moveDown();
			}
			dy += 1;
		}
		else if (one_srt_dist[dy - 1][dx] == 1) {
			one_srt_dist[dy][dx] = 0;

			if (current_game_time - NPC_current_Time > flagTime) {
				NPC_current_Time = clock();
				NPC_moveUp();
			}
			dy -= 1;
		}

		if (dx == dstX && dy == dstY) {

			if (current_game_time - NPC_current_Time > flagTime) {
				if (npc1_bomb_exist_count < npc1_bomb_max) {
					npc1_set_bomb();
				}
				//NPCmapModel[dstY][dstX] = STATE_NPC_WARNING;
				NPC_current_Time = clock();
				if (dx < preX) {
					NPC_moveRight();
				}
				else if (dx > preX) {
					NPC_moveLeft();
				}
				else if (dy > preY) {
					NPC_moveUp();
				}
				else if (dy < preY) {
					NPC_moveDown();
				}
			}
		}
		return 0;
	}
}

int CheckNPCState()
{
	// 현재 플레이어 좌표의 정보값에 따라 PlayerState 업데이트
	// 업데이트된 PlayerState 값에 맞게 처리

	////////////추가
	if (checkObject_boom(npcCurPosX, npcCurPosY) == 1)
	{
		SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
		printf("NPC down!\n");
		npc1_state_flag = 1;

		SetCurrentCursorPos(80, 35);
		printf("                         ", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
		SetCurrentCursorPos(80, 35);
		printf("checkObject_boom X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));

		return (1);
	}
	if (checkPlayer_Killed_NPC(npcCurPosX, npcCurPosY, PlayerCurPosX, PlayerCurPosY) == 1) {
		SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
		
		Sleep(700);
		GameOver_Mapdrawing();
		return (2);
	}
	return (0);
}

int NPC1_die() {

	SetCurrentCursorPos(80, 33);
	printf("                         ");
	SetCurrentCursorPos(80, 33);
	printf("NPC1 die X = % d Y = % d", cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));

	SetCurrentCursorPos(npcCurPosX, npcCurPosY);
	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));


	npcCurPosX = 0;
	npcCurPosY = 0;
}
