// OOP_16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class MarvelUniverse {};

class Ability abstract {};

class Good abstract {};

class Bad abstract {};

class Human abstract {};

class Animal abstract {};

class God abstract {};

class SuperHero abstract {};

////////////////////////////////////////////////////////

class IFlyable : public Ability {  // летающий (Тони Старк)
public:
    virtual void Fly() = 0; // летать
};

class ISuperStrongable : public Ability {  // суперсильный (Халк) (Тони Старк)
public:
    virtual void WeightLifting() = 0; //поднятие тяжестей
};

class ISuperSpeedable : public Ability {  //супербыстрый (Халк)
public:
    virtual void Run() = 0; //бегать
};

class IСopyingАppearanceable : public Ability {  //копирование внешности (Мистик)
public:
    virtual void Сopy() = 0; //копирование
};

class IEnduranceable : public Ability {  // выносливость (Халк) (Росомаха)
public:
    virtual void Fight() = 0; //драться
};

class IDexterityable : public Ability {  // ловкость (Халк) (Росомаха)
public:
    virtual void Catch() = 0; //ловить
};

class IHeightenedSensesable : public Ability {  // oбострение чувств (Росомаха)
public:
    virtual void Look() = 0; //смотреть
    virtual void Smell() = 0; //нюхать
};

class IRegenerationable : public Ability {  // регенерация (Грут)
public:
    virtual void SkinRegeneration() = 0; //регенерировать ткани
    virtual void LimbRegeneration() = 0;//регенерировать конечности
};

class IElasticityable : public Ability { // Эластичность (Грут)
public:
    virtual void StretchLimbs() = 0;//растягивать конечности
};

class IIdealPersonable : public Ability {  // Идеальный человек (Капитан Америка)
public:
    virtual void Run() = 0; //бегать
    virtual void Jump() = 0; //прыгать
    virtual void Fight() = 0; //драться
};

class IDarknessManipulationable : public Ability {  // Манипуляции с тьмой (Тор)
public:
    virtual void Hypnosis() = 0; //гипноз
};

////////////////////////////////////////////////////////////////////////

class Mystic : public SuperHero, Good, Human, Animal, public IСopyingАppearanceable { // Мистик
public:
   virtual void Copy() {
       cout << "Идет копирование в Мистик.../n";
    }
};

class Wolverine : public SuperHero, Good, Human, Animal, public IEnduranceable, IDexterityable, IHeightenedSensesable { // Росомаха
public:
    virtual void Fight() {
        cout << "Росомаха наваляет плохим парням.../n";
    }

    virtual void Catch() {
        cout << "Росомаха ловит муху.../n";
    }

    virtual void Look() {
        cout << "Росомаха смотрит вокруг.../n";
    }

    virtual void Smell() {
        cout << "Росомаха нюхает.../n";
    }
};

class TonyStark : public SuperHero, Good, Human, Animal, public IFlyable, ISuperStrongable { // Тони Старк
public:
    virtual void Fly() {
        cout << "Тони Старк летает.../n";
    }

    virtual void WeightLifting() {
        cout << "Тони Старк поднимает машину.../n";
    }
};

class Groot : public SuperHero, Good, Human, Animal, public IRegenerationable, IElasticityable { // Грут
public:
    virtual void SkinRegeneration () {
        cout << "Грут регенерирует кожу.../n";
    }
     
    virtual void LimbRegeneration (){
        cout << "Грут регенерирует ногу.../n";
    }

    virtual void StretchLimbs() {
        cout << "Грут растягивает руки.../n";
    }
};

class Hulk : public SuperHero, Good, Human, public ISuperStrongable, ISuperSpeedable, IEnduranceable, IDexterityable { // Халк
public:
    virtual void WeightLifting() {
        cout << "Халк поднимает слона.../n";
    }

    virtual void Run() {
        cout << "Халк убегает.../n";
    }

    virtual void Fight() {
        cout << "Халк дерется с кем-то.../n";
    }

    virtual void Catch() {
        cout << "Халк ловит падающюю звезду.../n";
    }
};

class СapitanAmerica : public SuperHero, Good, Human, public IIdealPersonable { // Капитан Америка
public:
    virtual void Run() {
        cout << "Капитан Америка доганяет поезд.../n";
    }

    virtual void Fight() {
        cout << "Капитан Америка дерется с кем-то.../n";
    }

    virtual void Jump() {
        cout << "Капитан Америка пригает.../n";
    }
};

class Thor : public SuperHero, Bad, God, public IDarknessManipulationable { // Тор
public:
    virtual void Gipnisis() {
        cout << "Тор манипулирует темной сущностью человека.../n";
    }

};

int main()
{
    setlocale(0, "");

    Mystic m;
    m.Copy();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
