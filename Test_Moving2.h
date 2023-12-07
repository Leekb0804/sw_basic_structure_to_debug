#ifndef __TESTMOVING2_H__
#define __TESTMOVING2_H__

#include <Windows.h>
#include "calculatorDST2.h"

extern int npcCurPosX2, npcCurPosY2;
extern unsigned long long NPC_current_2;
int npc2_state_flag;

void ShowNpcBlock2();
void DeleteBlock2();
int NPC_moveLeft2();
int NPC_moveRight2();
int NPC_moveUp2();
int NPC_moveDown2();
int NpcMoving2();
int CheckNPCState2();
int NPC2_die();


#endif
