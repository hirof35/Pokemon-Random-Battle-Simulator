#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include"pokemon_game.h"
int main() {
    // 乱数の初期化
    srand(time(NULL));

    printf("--- ランダムバトル開始！ ---\n");

    // ランダムに2体のポケモンを選択
    PokemonPtr player1 = getRandomPokemon();
    PokemonPtr player2 = getRandomPokemon();

    printf("\n--- 対戦ポケモン ---\n");
    printf("プレイヤー1: %s\n", player1->name);
    printf("プレイヤー2: %s\n", player2->name);

    // バトルを実行
    battle(player1, player2);

    return 0;
}
