/** 
	@file	sanke_SDL.cpp
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	�ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
*/

#include "stdafx.h"
#include "Game.h"

/**
	@brief ���� �Լ�.
*/
int _tmain(int argc, _TCHAR* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);	///< SDL �ʱ�ȭ
	TTF_Init();					///< TTF �ʱ�ȭ

	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE||SDL_DOUBLEBUF); ///< �ֻ��� �� �ʱ�ȭ. 640*480 / 32bpp / ������۸� 
	Game *pGame = new Game(screen);

	while(1) {
		pGame->Update();	///< ���� ����
		SDL_Delay(10);		///< 10ms ������
	}

	SDL_Quit();	///< SDL ����
	TTF_Quit();	///< TTF ����

	delete pGame; ///< Game ��ü ����
	pGame = NULL;

	return 0;
}