#include <iostream>
#include <vector>
using namespace std;

class Ability abstract {};

// быть хорошим, или плохим - это интерфейсы, там указатель на супер-героя не обязателен
__interface IGood {
    void DoNiceThings();
};

__interface IBad {
    void DoBadThings();
};

class Race abstract {}; // раса

// людей, зверей, богов и ТД можно вынести в своеобразную расу
class Human abstract : public Race {
    // SuperHero* SuperHero; // тут тоже самое, указатель на супер-героя не нужен
};

class Animal abstract : public Race {
    // SuperHero* SuperHero;
};

class God abstract : public Race {
    // SuperHero* SuperHero;
};

class SuperHero abstract {
    // тут скорее всего будут различные умения и сверх-способности
    vector <Ability*> abilities;
public:
    void AddAbility(Ability* ability) {
        abilities.push_back(ability);
    }
    ~SuperHero() {
        // ability будет уничтожаться отдельно, вне текущего класса
        // тело в деструкторе не нужно
    }
};

////////////////////////////////////////////////////////

class IFlyable : public Ability {  // летающий (например, Тони Старк)
public:
    virtual void Fly() = 0; // летать
};

class ISuperStrongable : public Ability {  // суперсильный (Халк) (Тони Старк)
public:
    virtual void WeightLifting() = 0; // поднятие тяжестей
};

class ISuperSpeedable : public Ability {  //супербыстрый (Халк)
public:
    virtual void Run() = 0; // бегать
};

class IСopyingАppearanceable : public Ability {  // копирование внешности (Мистик)
public:
    virtual void Сopy() = 0; // копирование
};

class IEnduranceable : public Ability {  // выносливость (Халк) (Росомаха)
public:
    virtual void Fight() = 0; // драться
};

class IDexterityable : public Ability {  // ловкость (Халк) (Росомаха)
public:
    virtual void Catch() = 0; // ловить
};

class IHeightenedSensesable : public Ability {  // oбострение чувств (Росомаха)
public:
    virtual void Look() = 0; // смотреть
    virtual void Smell() = 0; // нюхать
};

class IRegenerationable : public Ability {  // регенерация (Грут)
public:
    virtual void SkinRegeneration() = 0; // регенерировать ткани
    virtual void LimbRegeneration() = 0; // регенерировать конечности
};

class IElasticityable : public Ability { // Эластичность (Грут)
public:
    virtual void StretchLimbs() = 0; // растягивать конечности
};

class IIdealPersonable : public Ability {  // Идеальный человек (Капитан Америка)
public:
    virtual void Run() = 0; // бегать
    virtual void Jump() = 0; // прыгать
    virtual void Fight() = 0; // драться
};

class IDarknessManipulationable : public Ability {  // Манипуляции с тьмой (Тор)
public:
    virtual void Hypnosis() = 0; // гипноз
};

////////////////////////////////////////////////////////////////////////

class Mystic : public SuperHero, public IGood, public Human, public Animal, public IСopyingАppearanceable { // Мистик
public:
    Mystic() {
        cout << "Mystic создалась...\n";
    }
    virtual void DoNiceThings() { cout << "some nice things that Mystic do\n"; }

    virtual void Copy() {
        cout << "Идет копирование в Мистик...\n";
    }
};

class Wolverine : public SuperHero, public IGood, public Human, public Animal, public IEnduranceable, public IDexterityable, public IHeightenedSensesable { // Росомаха
public:
    Wolverine() {
        cout << "Wolverine создался...\n";
    }
    virtual void DoNiceThings() { cout << "some nice things that Wolverine do\n"; }

    virtual void Fight() {
        cout << "Росомаха наваляет плохим парням...\n";
    }

    virtual void Catch() {
        cout << "Росомаха ловит муху...\n";
    }

    virtual void Look() {
        cout << "Росомаха смотрит вокруг...\n";
    }

    virtual void Smell() {
        cout << "Росомаха нюхает...\n";
    }
};

class TonyStark : public SuperHero, public IGood, public Human, public Animal, public IFlyable, public ISuperStrongable { // Тони Старк
public:
    TonyStark() {
        cout << "TonyStark создался...\n";
    }
    virtual void DoNiceThings() { cout << "some nice things that TonyStark do\n"; }

    virtual void Fly() {
        cout << "Тони Старк летает...\n";
    }

    virtual void WeightLifting() {
        cout << "Тони Старк поднимает машину...\n";
    }
};

class Groot : public SuperHero, public IGood, public Human, public Animal, public IRegenerationable, public IElasticityable { // Грут
public:
    Groot() {
        cout << "Groot создался...\n";
    }
    virtual void DoNiceThings() { cout << "some nice things that Groot do\n"; }

    virtual void SkinRegeneration() {
        cout << "Грут регенерирует кожу...\n";
    }

    virtual void LimbRegeneration() {
        cout << "Грут регенерирует ногу...\n";
    }

    virtual void StretchLimbs() {
        cout << "Грут растягивает руки...\n";
    }
};

class Hulk : public SuperHero, public IGood, public Human, public ISuperStrongable, public ISuperSpeedable, public IEnduranceable, public IDexterityable { // Халк
public:
    Hulk() {
        cout << "Hulk создался...\n";
    }
    virtual void DoNiceThings() { cout << "some nice things that Hulk do\n"; }

    virtual void WeightLifting() {
        cout << "Халк поднимает слона...\n";
    }

    virtual void Run() {
        cout << "Халк убегает...\n";
    }

    virtual void Fight() {
        cout << "Халк дерётся с кем-то...\n";
    }

    virtual void Catch() {
        cout << "Халк ловит падающюю звезду...\n";
    }
};

class СapitanAmerica : public SuperHero, public IGood, public Human, public IIdealPersonable { // Капитан Америка
public:
    СapitanAmerica() {
        cout << "СapitanAmerica создался...\n";
    }
    virtual void DoNiceThings() { cout << "some nice things that СapitanAmerica do\n"; }

    virtual void Run() {
        cout << "Капитан Америка догоняет поезд...\n";
    }

    virtual void Fight() {
        cout << "Капитан Америка дерётся с кем-то...\n";
    }

    virtual void Jump() {
        cout << "Капитан Америка прыгает...\n";
    }
};

class Thor : public SuperHero, public IDarknessManipulationable { // Тор
public:
    virtual void DoNiceThings() { cout << "some nice things that Thor do\n"; }

    Thor() {
        cout << "Тор создался...\n";
    }
    // вот это я долго искал :)) Gipnosis / Hypnosis :))
    virtual void Hypnosis() {
        cout << "Тор манипулирует тёмной сущностью человека...\n";
    }
};

int main()
{
    setlocale(0, "");

   // Mystic mystic;
    //mystic.Copy();
    Wolverine wolverine;
    wolverine.Catch();
    TonyStark tony;
    tony.Fly();
    Hulk hulk;
    hulk.Run();
    Groot groot;
    groot.LimbRegeneration();
    СapitanAmerica cap;
    cap.Run();
    Thor thor;
    thor.Hypnosis();

    vector <SuperHero*> heroes;
    
    heroes.push_back(&thor);
    heroes.push_back(&tony);
    heroes.push_back(&hulk);
    heroes.push_back(&groot);
    heroes.push_back(&cap);
    heroes.push_back(&wolverine);
    
    
    for (auto hero : heroes) { 
        IFlyable* f = dynamic_cast <IFlyable*> (hero);
        if (f != nullptr) {
            f->Fly();
        }
    }

  }
