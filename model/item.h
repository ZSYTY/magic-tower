#ifndef ITEM_H
#define ITEM_H

struct monster {
    int id, health, attack, defence, gold, exp;
    monster(int _id, int _health, int _attack, int _defence, int _gold, int _exp): id(_id), health(_health), attack(_attack), defence(_defence), gold(_gold), exp(_exp){}
    monster() {}
};

struct medicine {
    int id, health, attack, defence;
    medicine(int _id, int _health, int _attack, int _defence): id(_id), health(_health), attack(_attack), defence(_defence){}
    medicine() {}
};

struct weapon {
    int id, attack;
    weapon(int _id, int _attack): id(_id), attack(_attack) {}
    weapon() {}
};

struct armour {
    int id, defence;
    armour(int _id, int _defence): id(_id), defence(_defence) {}
    armour() {}
};

#endif // ITEM_H
