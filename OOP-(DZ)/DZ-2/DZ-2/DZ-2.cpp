#include <iostream>
#include <string>

using namespace std;

class Person
{
protected: 

    string  name;
    int age;
    string gender;
    int weight;

public:
    
    void SetName(string name)
    {
        this->name = name;
    }

    void SetAge(int age)
    {
        this->age = age;
    }
    void SetGender(string gender)
    {
        this->gender = gender;
    }

    void SetWeight(int weight)
    {
        this->weight = weight;
    }

    ~Person()
    {};

};

class Student : public Person
{
private:
    
    int year_of_study;
    int& Count()
    {
        static int count = 0;
        return count;
    }

public:

    void setYearOfStudy(int year)
    {       
        year_of_study = year;
        ++Count();       
    }

    void ShowInfoStudent()
    {    
       cout << "Name - " << name << "\n" << "Age - " << age << "\n" << "Gender - " << gender << "\n" << "Weight - " << weight << endl;
       cout << "Years of study - " << year_of_study << endl;
       cout <<"Я по счету " << Count() <<" студент " << endl;
       cout << "\n\n";
    }

   
    ~Student()
    {
        --Count();
    };
};

/// я вот в этот моменте не понял,как мне не писать функцию вывода данных в консиоль несколько раз
/// ну вот как то так,взять из старой функции или функцию целиком + новые данные которые надо вывести 

class Fruit
{
protected:
    string name;
    string color;
    ~Fruit()
    { };
};

class Apple : public Fruit
{
public:

    Apple()
    {
        name = "apple";
        color = "green";
    }

    Apple(string color)
    {
        name = "apple";
        this->color = color;
    }

    string GetName()
    {
        return name;
    }

    string GetColor()
    {
        return color;
    }

    ~Apple()
    {};
};

class Banana : public Fruit
{
   
public:
    string GetName()
    {
        name = "banana";
        return name;
    }

    string GetColor()
    {
        color = "yellow";
        return color;
    }

    ~Banana()
    {};
};

class GrannySmith : public Apple
{
public:

    GrannySmith()
    {
        name = "Granny Smith";
        color = "green";
    }

    string GetName()
    {
        
        return name;
    }

    string GetColor()
    {
       
        return color;
    }


    ~GrannySmith()
    {};
};

int main()
{
    setlocale(LC_ALL, "RU");

    Student a,b,c;
    a.SetAge(25);
    a.SetName("Alex");
    a.SetWeight(85);
    a.SetGender("Male");
    a.setYearOfStudy(2);
    a.ShowInfoStudent();

    b.SetAge(20);
    b.SetName("Bob");
    b.SetWeight(80);
    b.SetGender("Male");
    b.setYearOfStudy(4);
    b.ShowInfoStudent();
    
    c.SetAge(27);
    c.SetName("Anna");
    c.SetGender("Female");
    c.SetWeight(60);
    c.setYearOfStudy(5);
    c.ShowInfoStudent();
    
    Apple aa("red");
    Banana bb;
    GrannySmith cc;

    cout << "My " << aa.GetName() << " is " << aa.GetColor() << ".\n";
    cout << "My " << bb.GetName() << " is " << bb.GetColor() << ".\n";
    cout << "My " << cc.GetName() << " is " << cc.GetColor() << ".\n";
    
    ///Вот здесь описано задание № 3 
    /// 1.Класс игрок:
    /// (свойства) : Имя игрока,количество карт в руке(думаю лучше всего это будет сделать через вектор,потому что навряд ли там будет больше 4-5 карт в руке)
    /// также у игрока будет его собственный банк,т.е то на что он будет делать ставку,и что будет выигрывать
    /// Методы : Ну стоит сделать методы для просмотра количества денег в банке игрока(хотя тут можно выводить это как постоянную информацию в консоль),количества карт и общей суммы очков в руке
    /// также стоит добавить методы для поднятия ставки,паса.
    /// 
    /// 2.Класс Крупье:
    /// (свойства) : у крупье также как и у игрока будут название,банк(количества денег,которые можно потенциально выиграть)
    /// (методы) : я бы первым методом добавил описание правил,потому что 21 немного отличается от БлекДжека и стоит заранее ознакомиться во что ты будешь играть
    /// представление игроков,Если таковых несколько,а скорее всего их будет несколько,сделать ставку/поднять ее.
    /// выдача карт игрока и взятие самому,донабор или просмотр результата с картами,выдача выигранных денег,либо же изьятие проигранных.
    /// 
    /// 3.Класс колода : 
    /// свойства : (интовое)-количество карт,оно неизменно так что можно даже константой поставить,количество колод(на вики описано,Что используют от 1 до 8 колод)
    /// соответственно количество колод,не знаю кому тут выбирать игроку или крупье(если крупье,то можно через рандом сделать выбор от 1 до 8)
    /// если игрок,то тут все просто
    /// методы : пока что из методов,в голову приходит только шафл(перемешивание всех карт и набор до определнной точки)
    /// (т.е как я вижу этот метод,где нибудь в массиве из количества карт(в зависимости от кол-ва колод) выбираем одну карту и перемешиваем все остальные карты,до тех пор пока не найдем нужную)
    /// можно сделдать через булевый тип,всем картам поставить значение фолс,а нужной тру,перемешивание сделать какой нибудь сортировкой,и идти и выбирать карты до трушной карты 
    /// 
    /// 4.Класс игра
    /// честно не знаю как это все обьеденить,наверное класс игрок будет иметь public наследование,потому что там оч много свойств и методов,с которыми нужно взаимодействовать 
    /// крупье скорее всего будет иметь private или protected (еще не совсем разобрался что лучше использовать),т.к у крупье меньше всего свойст и методов,которые надо трогать,их вообще можно задать по дефолту
    /// колода скорее всего тоже будет private или протектед,потому что все что можно будет трогать в колоде это количество колод и перемешиваем все карты или нет?
    /// 
    
    
}
