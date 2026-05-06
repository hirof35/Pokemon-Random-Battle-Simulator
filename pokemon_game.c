#include "pokemon_game.h"
#include <stdio.h>
#include <stdlib.h>

// 初期化データに「最大HP」の値も追加します
Pokemon pokemon_data[] = {
    {"フシギダネ", 45, 45, 49},
    {"ヒトカゲ",   39, 39, 52},
    {"ゼニガメ",   44, 44, 48},
    {"ピカチュウ", 35, 35, 55},
    {"ラッキー",  250, 250, 5}
};

#define NUM_POKEMON (sizeof(pokemon_data) / sizeof(pokemon_data[0]))

PokemonPtr getRandomPokemon(void) {
    int index = rand() % NUM_POKEMON;
    // 配列内の実体のHPを最大値まで回復させる
    pokemon_data[index].hp = pokemon_data[index].max_hp;
    return &pokemon_data[index];
}

void battle(PokemonPtr p1, PokemonPtr p2) {
    // 自分自身と戦うことになった場合の無限ループ・即死防止
    if (p1 == p2) {
        printf("同じ個体同士では戦えません。\n");
        return;
    }

    printf("\n--- バトル開始: %s vs %s ---\n", p1->name, p2->name);

    PokemonPtr attacker = (rand() % 2 == 0) ? p1 : p2;
    PokemonPtr defender = (attacker == p1) ? p2 : p1;

    while (p1->hp > 0 && p2->hp > 0) {
        printf("\n%s の攻撃！", attacker->name);

        // ダメージ計算
        defender->hp -= attacker->attack;

        printf(" %s に %d のダメージ！\n", defender->name, attacker->attack);
        printf("%s HP: %d | %s HP: %d\n", p1->name, p1->hp, p2->name, p2->hp);

        if (defender->hp <= 0) {
            printf("\n%s は倒れた！ %s の勝利！\n", defender->name, attacker->name);
            break;
        }

        printf(">> [Enter] で次のターンへ...");
        // 入力待ちの確実な処理
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        // 攻守交代
        PokemonPtr temp = attacker;
        attacker = defender;
        defender = temp;
    }
}
