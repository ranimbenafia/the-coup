#include "ennemi.h"



int main(int argc, char** argv)
{
    SDL_Surface* screen = NULL;

	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
	screen = SDL_SetVideoMode(W_Screen, H_Screen, CMode, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE /*| SDL_FULLSCREEN */);
        SDL_WM_SetCaption("THE COUP",NULL);

	Enemy enemy;
    
    SDL_Surface* backg = NULL;
    backg = IMG_Load("paground.png");
    SDL_BlitSurface(backg, NULL, screen, NULL);
    SDL_Flip(screen);

	enemy.spriteleft = IMG_Load("dr.gif");
	enemy.spriteright = IMG_Load("ga.gif");
	enemy.dst.x = 50;
	enemy.dst.y = 300;

	//Hide Cursor
	//SDL_ShowCursor(SDL_DISABLE);

	int continuer = 1;
	while(continuer)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		int i;

		for(i = 0; i<MAX_FRAMES; i++)
		{
			enemy.frame.x = i*SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteright, &enemy.frame,screen, &enemy.dst);  

			SDL_Flip(screen);
			SDL_Delay(200);
		}
		for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			enemy.frame.x  = i*SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteleft, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(200);
		}

		switch(event.key.keysym.sym)
		{
			case SDLK_RIGHT:
                          break;
                        case SDLK_ESCAPE:
			    continuer =0;
                          break;
		}

	}
       
        SDL_FreeSurface( backg);
        //SDL_FreeSurafce( spriteleft); 
       // SDL_FreeSurafce( spriteright);
       
	SDL_Quit();
return 0;
}
