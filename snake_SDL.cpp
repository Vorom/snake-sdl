/** 
	@file	sanke_SDL.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	콘솔 응용 프로그램에 대한 진입점을 정의합니다.
*/

#include "stdafx.h"
#include "Game.h"

/**
	@brief 메인 함수.
*/
int _tmain(int argc, _TCHAR* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);	///< SDL 초기화
	TTF_Init();					///< TTF 초기화

	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE||SDL_DOUBLEBUF); ///< 최상위 뷰 초기화. 640*480 / 32bpp / 더블버퍼링 
	Game *pGame = new Game(screen);

	while(1) {
		pGame->Update();	///< 게임 갱신
		SDL_Delay(10);		///< 10ms 딜레이
	}

	SDL_Quit();	///< SDL 종료
	TTF_Quit();	///< TTF 종료

	delete pGame; ///< Game 객체 정리
	pGame = NULL;

	return 0;
}