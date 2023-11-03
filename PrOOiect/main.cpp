#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Character {
private:
    string name;
    int hp;
    int dmg;
public:
    ///Constructor
    Character(const string& nume, int hp, int dmg)
            :name(nume), hp(hp), dmg(dmg) {
        this->name = nume;
        this->hp = hp;
        this->dmg = dmg;
        cout << "A fost apelat constructorul C\n";
    }
    ///Destructor
    ~Character() {
        cout << "A fost apelat destructorul C\n";
    }
    void attack (Character& target);
    void heal();
    bool isAlive() const {
        return hp > 0;
    };
    ///Set-eri
    void setName(const string& newName) {
        name=newName;
    }
    void setHp(int newHp) {
        hp=newHp;
    }
    void setDmg(int newDmg) {
        dmg=newDmg;
    }
    ///Get-eri
    string getName() const {
        return name;
    }
    int getHp() const {
        return hp;
    }
    int getDmg() const {
        return dmg;
    }
};

class Enemy : public Character {
private:
    int special;

public:
    Enemy(const string& nume, int hp, int dmg)
            :Character (name, hp, dmg) {
        this->name = nume;
        this->hp = hp;
        this->dmg = dmg;
        cout << "A fost apelat constructorul E";
    }
    ~Enemy() {
        cout << "A fost apelat destructorul E";
    }
};

class Attack {
private:
    string name;
    int dmg;
    double hitChance;
    double critChance;
    double critMultiplier;
public:
    Attack(const string& nume, int dmg, double hitChance, double critChance, double critMultiplier)
        :name(nume), dmg(dmg), hitChance(hitChance), critChance(critChance), critMultiplier(critMultiplier) {
        this->name = nume;
        this->dmg = dmg;
        this->hitChance = hitChance;
        this->critChance = critChance;
        this->critMultiplier = critMultiplier;
        cout << "A fost apelat constructorul A\n";
    }
    ~Attack() {
        cout << "A fot apelat constructorul A\n";
    }
    ///Set-eri
    void setName(const string& newName) {
        name = newName;
    }
    void setDmg(int newDmg) {
        dmg=newDmg;
    }
    void setHitChance(double newHitChance) {
        hitChance = newHitChance;
    }
    void setCritChance(double newCritChance) {
        critChance = newCritChance;
    }
    void setCritMultiplier(double newCritMultiplier) {
        critMultiplier = newCritMultiplier;
    }
    ///Get-eri
    string getName() const {
        return name;
    }
    int getDmg() const {
        return dmg;
    }
    double getHitChance() const {
        return hitChance;
    }
    double getCritChance() const {
        return critChance;
    }
    double getCritMultiplier() const {
        return critMultiplier;
    }
    ///
    bool isHit() const {
        double randomValue = (double) (rand()) / RAND_MAX;
        return randomValue < hitChance;
    }

    bool isCrit() const {
        double randomValue = (double)( rand()) / RAND_MAX;
        return randomValue < critChance;
    }

    int calcDmg() const {
        if(isHit()) {
            if(isCrit()) {
                return (int) (dmg * critMultiplier);
            } else {
                return dmg;
            }
        } else {
            cout << "Miss!";
            return 0;
        }
    }
};

int main() {

    return 0;
}
