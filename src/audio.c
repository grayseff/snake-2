#include "audio.h"
#include "raylib.h"

static Sound eat_sound;
static Music music;
static Sound death;

void InitAudio(void)
{
    InitAudioDevice();

    eat_sound = LoadSound("assets/apple_bite.ogg");
    death = LoadSound("assets/GameOver.ogg");
    music = LoadMusicStream("assets/nes_05-hectic.wav");

    PlayMusicStream(music);
}
void UpdateAudio(void)
{
    UpdateMusicStream(music);
}
void PlayEatSound(void)
{
    PlaySound(eat_sound);
}

void UpdateMusic(void)
{
    UpdateMusicStream(music);
}
void PlayDeathSound(void){
    PlaySound(death);
}
void DestroyAudio(void)
{
    UnloadSound(eat_sound);
    UnloadMusicStream(music);
    UnloadSound(death);
    CloseAudioDevice();
}
