// STLListaStudentow — użyj listy do przechowywania
// i sortowania zdefiniowanej przez użytkownika klasy
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;
// Student — przykładowa klasa zdefiniowana przez użytkownika
class Student
{
  public:
    Student(const char* pszS, int id)
        : sImie(pszS), ssID(id) {}
    string sImie;
    int ssID;
};
// Do obsługi operacji sortowania
// wymagana jest następująca funkcja
bool operator<(const Student& s1, const Student& s2)
{
    return s1.ssID < s2.ssID;
}
// wyswietlStudentow — iteruj po liście
// i wyświetlaj poszczególne elementy
void wyswietlStudentow(list<Student>& studenci)
{
    // przydziel iterator, który wskazuje
    // pierwszy element na liście
    // list<Student>::iterator iter = studenci.begin();
    auto iter = studenci.begin();
    // kontynuuj pętlę przez listę, aż iterator
    // znajdzie się na końcu listy
    while(iter != studenci.end())
    {
        // pobierz obiekt klasy Student, na który wskazuje iterator
        Student& s = *iter;
        cout << s.ssID << " - " << s.sImie << endl;
        // teraz przenieś iterator do następnego
        // elementu na liście
        iter++;
    }
}
int main(int argc, char* pArgs[])
{
    // zdefiniuj zbiór obiektów klasy Student
    list<Student> studenci;
    // dodaj trzy obiekty klasy Student do listy
    studenci.push_back(Student("Jacek Mały", 10));
    studenci.push_back(Student("Paweł Flis", 5));
    studenci.push_back(Student("Wojtek Biskup", 15));
    // wyświetl listę
    cout << "Oryginalna lista:" << endl;
    wyswietlStudentow(studenci);
    // teraz posortuj listę i wyświetl ją ponownie
    studenci.sort();
    cout << "\nPosortowana lista:" << endl;
    wyswietlStudentow(studenci);
    // aby pozwolić użytkownikowi zobaczyć wynik programu
    // przed zakończeniem programu, poczekaj, aż użytkownik będzie gotowy
    cout << "Naciśnij Enter, aby kontynuować..." << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}
