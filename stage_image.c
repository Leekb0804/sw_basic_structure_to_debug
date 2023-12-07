#include "stage_image.h"

extern int game_round;

int GameOver_letter_map[letter_HEIGHT][letter_WIDTH] =
{
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,Empty,letter,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
};

int Clear_letter_map[total_Maps][letter_HEIGHT][letter_WIDTH] =
{
	//1
	{ {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty }},


	//2
{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} },

//3
{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty},
{Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,letter,letter,Empty,Empty,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,Empty},
{Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} },


//4
{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,letter,Empty,letter,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter},
{letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,letter,letter,letter,letter,Empty,letter,letter,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} },


//5
{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,letter,letter,letter,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty},
{letter,letter,letter,letter,Empty,letter,letter,letter,Empty,letter,letter,letter,letter,letter,letter,Empty,Empty,letter,Empty,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter},
{letter,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,Empty,letter,letter,Empty,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,Empty,letter,letter},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} },


{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,letter,letter,letter,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} }
};

int NextStage_letter_map[total_Maps][letter_HEIGHT][letter_WIDTH] =
{
	//stage 1
	{
	{Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
	{ Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty },
	{ Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty }
	},


	//stage2
	{
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
	},


	//stage3
{
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
},


//stage4
{
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
},


//stage 5
{
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty},
{Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty},
{Empty,letter,Empty,letter,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,letter,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty},
{Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty},
{Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
},

{
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
}
};


void draw_GameOver_letterMaps()		//게임 오버 화면 출력
{
	int x, y;
	int cursX, cursY;

	for (y = 0; y < letter_HEIGHT; y++) {
		for (x = 0; x < letter_WIDTH; x++)
		{
			cursX = x * 2 + GBOARD_ORIGIN_X; /*GBOARD_ORIGIN_X*/;
			cursY = y + GBOARD_ORIGIN_Y; /*GBOARD_ORIGIN_Y*/;

			SetCurrentCursorPos(cursX, cursY);

			if (GameOver_letter_map[y][x] == letter)
			{
				printf("■");
			}
			else { printf("  "); }
		}
	}
	SetCurrentCursorPos((GBOARD_ORIGIN_X/*BOARD_ORIGIN_X*/ + letter_WIDTH * 2 + 1), letter_HEIGHT + 1);
}

void draw_NextStage_letterMaps()		//다음 스테이지 화면 출력
{
	int x, y;
	int cursX, cursY;

	for (y = 0; y < letter_HEIGHT; y++) {
		if (y >= 8)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		for (x = 0; x < letter_WIDTH; x++)
		{
			cursX = x * 2 + GBOARD_ORIGIN_X; /*GBOARD_ORIGIN_X*/;
			cursY = y + GBOARD_ORIGIN_Y; /*GBOARD_ORIGIN_Y*/;

			SetCurrentCursorPos(cursX, cursY);

			if (NextStage_letter_map[game_round][y][x] == letter)
			{
				printf("■");
			}
			else { printf("  "); }
		}
	}
	Sleep(3000);
	//여기에 다음 스테이지로 넘어가는 함수 호출
}

void draw_AllClear(int i) { //클리어 화면 출력
	int x, y;
	int cursX, cursY;

	for (y = 0; y < letter_HEIGHT; y++) {
		for (x = 0; x < letter_WIDTH; x++)
		{
			cursX = x * 2 + GBOARD_ORIGIN_X; /*GBOARD_ORIGIN_X*/;
			cursY = y + GBOARD_ORIGIN_Y; /*GBOARD_ORIGIN_Y*/;

			SetCurrentCursorPos(cursX, cursY);

			if (Clear_letter_map[i][y][x] == letter)
			{
				printf("■");
			}
			else { printf("  "); }
		}
	}
	SetCurrentCursorPos((GBOARD_ORIGIN_X/*BOARD_ORIGIN_X*/ + letter_WIDTH * 2 + 1), letter_HEIGHT + 1);
}

void GameOver_Mapdrawing() {
	int a = 12;
	int b = 15;
	SetCurrentCursorPos(0, letter_HEIGHT + 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), b);
	//printf("Player Score = %d"); //최종 플레이어 점수 넣기
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		draw_GameOver_letterMaps();
		Sleep(1000); //1초마다 색깔 바꾸기
		if (a == 12) a = 15;
		else a = 12;
	}
}

void NextStage_Mapdrawing() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	draw_NextStage_letterMaps();
}

void Clear_Letterdrawing() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	for (int i = 0; i < 5; i++) { //폭죽 터지는 애니메이션
		draw_AllClear(i);
		Sleep(800); //0.8초의 딜레이
	}
	int a = 10;
	int b = 15;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), b);
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		draw_AllClear(5);
		Sleep(1000); //클리어 메세지 색깔 1초마다 바꾸기
		if (a == 10) a = 15;
		else a = 10;
	}
}


// 12월 04일 이경빈이 수정 (stage map reset 함수 추가)
void draw_Stagemap_reset()		//스테이지출력했던 화면 공백으로 초기화
{
	int x, y;
	int cursX, cursY;

	for (y = 0; y < letter_HEIGHT; y++) {
		if (y >= 8)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		for (x = 0; x < letter_WIDTH; x++)
		{
			cursX = x * 2 + GBOARD_ORIGIN_X; /*GBOARD_ORIGIN_X*/;
			cursY = y + GBOARD_ORIGIN_Y; /*GBOARD_ORIGIN_Y*/;

			SetCurrentCursorPos(cursX, cursY);
			printf("  ");
		}
	}
	//여기에 다음 스테이지로 넘어가는 함수 호출
}
