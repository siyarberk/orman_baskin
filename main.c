#include "ft_thread.h"
#include  "ft_thread2.h"

void* mesaj_yaz(void* adres) {
    t_zarf *p = (t_zarf*)adres;
    if (p->type == TYPE_CHAMPION) {
        t_champion *champion = (t_champion*)p->data;
        printf("[CHAMPION] isim:%s, level:%d\n",champion->name,champion->level);
    }
    if (p->type == TYPE_BASKIN) {
        t_baskin *baskin = (t_baskin*)p->data;
        printf("[BASKIN],objektif calindi mi?:%d ,objektifden gelen xp:%d",baskin->is_stole,baskin->xp_obtained);

    }if (p->type == TYPE_OBJEKTIF) {
        t_objektif *objektif = (t_objektif*)p->data;
        printf("[OBJEKTIF] objektif:%s, gold:%d\n",objektif->name,objektif->gold);
    }
    return NULL;
}



int main(void) {
    pthread_t t1,t2,t3;
    t_objektif objektif = {
        "Baron",
        500
    };

    t_champion champion = {
        "Yasuo",
        20
    };

    t_baskin baskin = {
        false,
        0
    };
    t_zarf p1 = {
        TYPE_CHAMPION,
        &champion
    };
    t_zarf p2 = {
        TYPE_BASKIN,
        &baskin
    };
    t_zarf p3 = {
        TYPE_OBJEKTIF,
        &objektif
    };
    pthread_create(&t1,NULL,mesaj_yaz,&p1);
    pthread_create(&t2,NULL,mesaj_yaz,&p2);
    pthread_create(&t3,NULL,mesaj_yaz,&p3);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    return 0;
}