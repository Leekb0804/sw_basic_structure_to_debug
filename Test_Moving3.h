#ifndef __TESTMOVING3_H__
#define __TESTMOVING3_H__

#include <Windows.h>
#include "calculatorDST3.h"

extern int npcCurPosX3, npcCurPosY3;
extern unsigned long long NPC_current_Time3;
int npc3_state_flag;

void ShowNpcBlock3();
void DeleteBlock3();
int NPC_moveLeft3();
int NPC_moveRight3();
int NPC_moveUp3();
int NPC_moveDown3();
int NpcMoving3();
int CheckNPCState3();
int NPC3_die();
#endif
