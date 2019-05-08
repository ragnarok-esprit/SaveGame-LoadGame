/**
* @file save.c
* @brief save game state
* @author Ragnarok INC
* @version 1.0
* @date AMay 8 , 2019
*
* Testing program for saving the game if player choose to Exit
*
*/

#include "fonction.h"
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
/**
* @brief To write on file game status  .
* @param ennemis the ennemi
* @param perso le personage 
* @param vie la vie du personnage
* @param SDL_Rect camera -> rectangle camera
* @return Nothing
*/
void savee(ennemis ennemi,perso perso,vie vie,SDL_Rect camera)
{
FILE *f;
f=fopen("save.bin","wb");
saves saves;
saves.ennemi=ennemi;
saves.camera=camera;
saves.perso=perso;
saves.vie=vie;
fwrite(&saves,sizeof(saves),1,f);
fclose(f);
}

/**
* @brief To read from file game status  .
* @param ennemis the ennemi
* @param perso le personage 
* @param vie la vie du personnage
* @param SDL_Rect camera -> rectangle camera
* @param continuer pour continer a jouer
* @param save pour sauvegarder 
* @return Nothing
*/
void load(ennemis *ennemi,perso *perso ,vie *vie,SDL_Rect *camera,int *continuer,int *save)
{
FILE *f;
f=fopen("save.bin","rb");
saves saves;
fread(&saves,sizeof(saves),1,f);
fclose(f);
*ennemi=saves.ennemi;
*camera=saves.camera;
*perso=saves.perso;
vie->nb=saves.vie.nb;
}
