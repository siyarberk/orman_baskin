#ifndef ORMAN_BASKIN_FT_THREAD2_H
#define ORMAN_BASKIN_FT_THREAD2_H
#include <stdbool.h>
typedef enum {
    TYPE_OBJEKTIF,
    TYPE_CHAMPION,
    TYPE_BASKIN
}data_type;


typedef struct s_objektif {
    char name[20];
    int gold;
}t_objektif;

typedef struct s_champion {
    char name[20];
    int level;
}t_champion;

typedef struct s_baskin {
    bool is_stole;
    int xp_obtained;
}t_baskin;

typedef struct s_zarf {
    data_type type;
    void* data;
}t_zarf;
#endif //ORMAN_BASKIN_FT_THREAD2_H