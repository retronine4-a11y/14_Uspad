#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int age;
    string group;

public:
    Student()
    {
        name = "Unknown";
        age = 0;
        group = "Unknown";
    }

    Student(string n, int a, string g)
    {
        name = n;
        age = a;
        group = g;
    }

    void Show()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Group: " << group << endl;
    }
};

class Aspirant : public Student
{
private:
    string dissertationTopic;
    int writtenPages;

public:
    Aspirant(string n, int a, string g, string topic)
        : Student(n, a, g)
    {
        dissertationTopic = topic;
        writtenPages = 0;
    }

    void WriteDissertation(int pages)
    {
        if (pages > 0)
        {
            writtenPages += pages;
            cout << "Written pages: " << writtenPages << endl;
        }
        else
        {
            cout << "Invalid number of pages!" << endl;
        }
    }

    void DefendDissertation()
    {
        if (writtenPages >= 100)
        {
            cout << "Dissertation defended successfully!" << endl;
        }
        else
        {
            cout << "Not enough pages to defend the dissertation!" << endl;
        }
    }

    void Show()
    {
        Student::Show();
        cout << "Dissertation topic: " << dissertationTopic << endl;
        cout << "Written pages: " << writtenPages << endl;
    }
};

class Passport
{
protected:
    string fullName;
    string birthDate;
    string passportNumber;
    string nationality;

public:
    Passport()
    {
        fullName = "";
        birthDate = "";
        passportNumber = "";
        nationality = "Україна";
    }

    Passport(string name, string birth, string number, string country)
    {
        fullName = name;
        birthDate = birth;
        passportNumber = number;
        nationality = country;
    }

    void Input()
    {
        cout << "Enter full name: ";
        getline(cin, fullName);

        cout << "Enter birth date: ";
        getline(cin, birthDate);

        cout << "Enter passport number: ";
        getline(cin, passportNumber);

        cout << "Enter nationality: ";
        getline(cin, nationality);
    }

    void Show()
    {
        cout << "\nPassport information:" << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Birth date: " << birthDate << endl;
        cout << "Passport number: " << passportNumber << endl;
        cout << "Nationality: " << nationality << endl;
    }
};

class ForeignPassport : public Passport
{
private:
    string foreignPassportNumber;
    string visas[10];
    int countVisas;

public:
    ForeignPassport()
    {
        foreignPassportNumber = "";
        countVisas = 0;
    }

    void InputForeign()
    {
        Input();

        cout << "Enter foreign passport number: ";
        getline(cin, foreignPassportNumber);

        cout << "Enter number of visas: ";
        cin >> countVisas;
        cin.ignore();

        for (int i = 0; i < countVisas; i++)
        {
            cout << "Enter visa " << i + 1 << ": ";
            getline(cin, visas[i]);
        }
    }

    void ShowForeign()
    {
        Show();

        cout << "\nForeign passport information:" << endl;
        cout << "Foreign passport number: " << foreignPassportNumber << endl;

        cout << "Visas:" << endl;
        for (int i = 0; i < countVisas; i++)
        {
            cout << visas[i] << endl;
        }
    }
};

int main()
{
    Aspirant aspirant("Ivan", 25, "KN-21", "Artificial Intelligence");

    cout << "Student information:" << endl;
    aspirant.Show();

    cout << endl;

    aspirant.WriteDissertation(30);
    aspirant.WriteDissertation(40);
    aspirant.WriteDissertation(35);

    cout << endl;

    aspirant.DefendDissertation();

    //

    ForeignPassport passport;

    passport.InputForeign();

    cout << "\n------------------------" << endl;

    passport.ShowForeign();
}
