#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct Polyclinic
{
    char* FIO ;
    int specialty;
    int qualification;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Menu(int* c)
{
    cout << "Диалоговое окно:" << endl;
    cout << "1)Распечатать информацию в табличном виде" << endl;
    cout << "2)Добавить нового врача" << endl;
    cout << "3)Найти врача по ФИО" << endl;
    cout << "4)Фильтр по квалификации и специальности" << endl;
    cout << "5)Сортировка по алфавиту" << endl;
    cout << "6)Сохранить на диск" << endl;
    cout << "7)Считать из диска" << endl;
    cout << "8)Завершить работу" << endl;
    cout << "Введите число от 1 до 8" << endl;
    cin >> *(c);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Polyclinic* AddStruct(Polyclinic* Obj,int amount)
{
    if (amount == 0)
    {
        Obj = new Polyclinic[amount + 1];
    }
    else
    {
        Polyclinic* tempObj = new Polyclinic[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i];
        }
        delete[] Obj;

        Obj = tempObj;
    }
    return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void One(Polyclinic* Obj,int amount)
{
    cout << "№" << '\t'
         << setw(12)<< setprecision(3) << "ФИО\t\t\t"
         << setw(23) << setprecision(3) << "Специальность\t"
         << setw(12) << setprecision(3) << "Квалификация"<< endl;

    cout << "=============================================================================" << endl;

    for (int i = 0; i < amount; i++)
    {
        cout << i+1 << '\t'
             << setw(14) << setprecision(3) << Obj[i].FIO
             << setw(8) << setprecision(3) << Obj[i].specialty
             << setw(14) << setprecision(3) << Obj[i].qualification << endl;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int getSpec()
{
    while (true)
    {
        cout << "Специальность(1-терапевт, 2-кардиолог, 3-стоматолог): ";
        int a;
        cin >> a;

        if (cin.fail() or (a < 1) or (a > 3))
        {
            cin.clear();
            cin.ignore(32767,'\n');
        }
        else
            return a;
    }
}

int getQual()
{
    while (true)
    {
        cout << "Квалификация(0-высшая, 1-первая, 2-вторая): ";
        int a;
        cin >> a;

        if (cin.fail() or (a < 0) or (a > 2))
        {
            cin.clear();
            cin.ignore(32767,'\n');
        }
        else
            return a;
    }
}

char * getFIO(){
    int i;
    char *str;
    str = new char[40];
    char *Obj = new char[40];
    do{
        cout<<"ФИО: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"Зачем вы ввели не буквы..."<<endl<<"Повторите ввод!!!"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
}

void Two(Polyclinic* Obj,int amount)
{
    Obj[amount].FIO=new char[40];
    Obj[amount].FIO = getFIO();

    Obj[amount].specialty = getSpec();
    cin.get();

    Obj[amount].qualification = getQual();
    cin.get();

    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Three(Polyclinic* Obj, int amount)
{
    char n[40];
    cout << "Введите ФИО:" << endl;
    cin.get();
    cin.getline(n, 40, '\n');

    cout << setw(12) << setprecision(3) << "Специальность\t"
         << setw(12) << setprecision(3) << "Квалификация"<< endl;
    for (int i = 0; i < amount; i++)
    {
        if (strcmp(Obj[i].FIO, n) == 0)
        {
            cout << setw(8) << setprecision(3) << Obj[i].specialty << '\t'
                 << setw(12) << setprecision(3) << Obj[i].qualification << endl;
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Four(Polyclinic* Obj, int amount)
{
    int s;
    cout << "Специальность(1-терапевт, 2-кардиолог, 3-стоматолог):" << endl;
    cin >> s;
    while(s<=0 or s>3)
    {
        cout << "Специальность(1-терапевт, 2-кардиолог, 3-стоматолог):" << endl;
        cin >> s;
    }

    int q;
    cout << "Квалификация(0-высшая, 1-первая, 2-вторая):" << endl;
    cin >> q;
    while(q<0 or q>2)
    {
        cout << "Квалификация(0-высшая, 1-первая, 2-вторая):" << endl;
        cin >> q;
    }

    cout << "№" << '\t'
         << setw(12)<< setprecision(3) << "ФИО\t\t\t"
         << setw(23) << setprecision(3) << "Специальность\t"
         << setw(12) << setprecision(3) << "Квалификация"<< endl;

    cout << "=============================================================================" << endl;

    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].specialty == s && Obj[i].qualification == q)
        {
            cout << i+1 << '\t'
                 << setw(14) << setprecision(3) << Obj[i].FIO
                 << setw(8) << setprecision(3) << Obj[i].specialty
                 << setw(14) << setprecision(3) << Obj[i].qualification << endl;
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Five(Polyclinic* Obj, int amount)
{
    char a[30];
    int b, c;
    for (int i = 0; i < amount - 1; i++)
        for(int j=i+1;j<amount;j++)
        {
            if(strcmp(Obj[i].FIO,Obj[j].FIO)>0)
            {   strcpy(a,Obj[i].FIO);
                strcpy(Obj[i].FIO,Obj[j].FIO);
                strcpy(Obj[j].FIO,a);

                b = Obj[i].specialty;
                Obj[i].specialty = Obj[j].specialty;
                Obj[j].specialty = b;

                c = Obj[i].qualification;
                Obj[i].qualification = Obj[j].qualification;
                Obj[j].qualification = c;
            }
        }

    cout << "№" << '\t'
         << setw(12)<< setprecision(3) << "ФИО\t\t\t"
         << setw(23) << setprecision(3) << "Специальность\t"
         << setw(12) << setprecision(3) << "Квалификация"<< endl;

    cout << "=============================================================================" << endl;

    for (int i = 0; i < amount; i++)
    {
        cout << i+1 << '\t'
             << setw(14) << setprecision(3) << Obj[i].FIO
             << setw(8) << setprecision(3) << Obj[i].specialty
             << setw(14) << setprecision(3) << Obj[i].qualification << endl;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Six(Polyclinic* Obj, int amount, string OOP)
{
    ofstream record(OOP, ios::app);

    if (record)
    {
        for (int i = 0; i < amount; i++)
        {
            record << Obj[i].FIO << ' ';
            record << Obj[i].specialty << ' ';
            record << Obj[i].qualification << endl;
        }
    }
    else
        cout << "Ошибка открытия!" << endl;

    record.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Seven(Polyclinic* (&Obj), int& amount, string OOP)
{
    string way = "OOP.txt";

    ifstream fin;
    fin.open(way);

    if (!fin.is_open()) {
        cout << "ERROR! Файл не открылся!" << endl;
    } else {
        cout << "Файл открылся!" << endl;
        cout << "ФИО | Специальность | Квалификация" << endl;

        string str;
        while (!fin.eof())
        {
            str = "";
            getline(fin, str);
            cout << str << endl;
        }

//        char ch;
//        while (fin.get(ch))
//        {
//            cout << ch;
//        }
    }
    fin.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main() {
    setlocale(LC_ALL, "rus");
    Polyclinic *OurPolyclinic = 0;
    int polyclinicAmount = 0;
    int YesOrNot = 0;

    do {
        OurPolyclinic = AddStruct(OurPolyclinic, polyclinicAmount);
        Two(OurPolyclinic, polyclinicAmount);
        polyclinicAmount++;
        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> YesOrNot;
    } while (YesOrNot != 0);

    One(OurPolyclinic, polyclinicAmount);
    int c;
    do {
        Menu(&c);
        switch (c) {
            case 1:
                One(OurPolyclinic, polyclinicAmount);
                break;
            case 2:
                OurPolyclinic = AddStruct(OurPolyclinic, polyclinicAmount);
                Two(OurPolyclinic, polyclinicAmount);
                polyclinicAmount++;
                break;
            case 3:
                Three(OurPolyclinic, polyclinicAmount);
                break;
            case 4:
                Four(OurPolyclinic, polyclinicAmount);
                break;
            case 5:
                Five(OurPolyclinic, polyclinicAmount);
                break;
            case 6:
                Six(OurPolyclinic, polyclinicAmount, "OOP.txt");
                break;
            case 7:
                Seven(OurPolyclinic, polyclinicAmount, "OOP.txt");
                break;
        }
    } while (c != 8);
    return 0;
}
