#ifndef _POKEMON_GAME_H
#define _POKEMON_GAME_H

typedef struct {
    char name[50];
    int hp;
    int max_hp; // 最大HPを保持しておくとリセットに便利
    int attack;
} Pokemon;

typedef Pokemon* PokemonPtr;

// extern宣言：実体は別の場所にありますよ、という合図
extern Pokemon pokemon_data[];

PokemonPtr getRandomPokemon(void);
void battle(PokemonPtr, PokemonPtr);

#endif
