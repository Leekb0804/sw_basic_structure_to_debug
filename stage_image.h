#ifndef __STAGE_IMAGE_H__
#define __STAGE_IMAGE_H__

#define letter_WIDTH 32 //새 정의 변수
#define letter_HEIGHT 20 //새 정의 변수
#define letter 1 //새 정의 변수
#define Empty 0 //새 정의 변수
#define total_Maps 6 //새 정의 변수



/*기존 변수, 함수, 정의 (추가할 필요X)*/
#include "define_state.h"
// #define GBOARD_ORIGIN_X 0
// #define GBOARD_ORIGIN_Y 0

#include <stdio.h>
#include <Windows.h>
#include <time.h>

//int game_round = 0; //기존에 있던 게임 라운드 변수

#include "cursor.h"
// void SetCurrentCursorPos(int x, int y)
// {
// 	COORD pos = { x, y };

// 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
// }



/*map.h*/
/*새로운 함수들
상황에 따라 호출만 하면 됨.

1. printf("Game Over")대신 GameOver_Mapdrawing();호출하기
2. 다음 스테이지 넘어가는거 완성하면 NextStage_Mapdrawing();호출하고 그 안에 넘어가는 함수 호출하기
3. 게임 클리어시 Clear_Letterdrawing(); 호출
*/
void draw_GameOver_letterMaps();
void draw_NextStage_letterMaps();
void draw_AllClear(int i);
void GameOver_Mapdrawing(); //게임 오버할 때 호출
void NextStage_Mapdrawing(); //다음 스테이지로 넘어갈때 호출
void Clear_Letterdrawing(); //클리어할 때 호출

// 12월 04일 이경빈이 추가 스테이지 출력하는 화면 공백으로 초기화하는 함수 추가
void draw_Stagemap_reset();		//스테이지출력했던 화면 공백으로 초기화

/*map.c*/
//새로운 맵들


/*실험용 (추가X)*/
// int main() {
// 	//GameOver_Mapdrawing(); //게임오버할때 같이 호출.
// 	//NextStage_Mapdrawing(); //스테이지 표시 맵
// 	Clear_Letterdrawing(); //게임 마무리할때 ALL Clear 표시
// }

#endif
