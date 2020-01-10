///Teodorescu Stefan, grupa 254
#include <iostream>
#include <vector>
using namespace std;

class Dosar
{
    static int contorIF;
    int nr_inregIF;
    static int contorIF2;
    int nr_inregIF2;
    static int contorID;
    int nr_inregID;
    static int contorID2;
    int nr_inregID2;
    string nume;
    float medie_bac;
    bool pasaport;
    float nota_mate;
    string absolvit;
    float medie_abs; // pentru prima fac
    float notaIF;
    float notaIF2;
    float notaID;
    float notaID2;
    float MAIF;
    float MAIF2;
    float MAID;
    float MAID2;
public:
    Dosar(bool IF, bool IF2, bool ID, bool ID2)
    {
        if (IF)
        {
            nr_inregIF = ++contorIF;
        }
        else nr_inregIF = 0;
        if (IF2)
        {
            nr_inregIF2 = ++contorIF2;
        }
        else nr_inregIF2 = 0;
        if (ID)
        {
            nr_inregID = ++contorID;
        }
        else nr_inregID = 0;
        if (ID2)
        {
            nr_inregID2 = ++contorID2;
        }
        else nr_inregID2 = 0;
    }
    ~Dosar()
    {
        if (nr_inregIF) contorIF--;
        if (nr_inregIF2) contorIF2--;
        if (nr_inregID) contorID--;
        if (nr_inregID2) contorID2--;
    }
    friend istream &operator>>(istream &in, Dosar d)
    {
        cout << "Numele (fara spatiu): ";
        cin >> d.nume;
        cout << "Media bac: ";
        cin >> d.medie_bac;
        cout << "Carte de Identitate (0) / Pasaport (1)? ";
        cin >> d.pasaport;
        if (d.nr_inregID)
        {
            cout << "Nota la mate de la bac: ";
            cin >> d.nota_mate;
        }
        if (d.nr_inregIF2 || d.nr_inregID2)
        {
            cout << "Programul de studii absolvit: ";
            cin >> d.absolvit;
            cout << "Media absolvire: ";
            cin >> d.medie_abs;
        }
        if (d.nr_inregIF)
        {
            cout << "Nota luata la scris la IF: ";
            cin >> d.notaIF;
            d.MAIF = 0.8 * d.notaIF + 0.2 * d.medie_bac;
        }
        if (d.nr_inregIF2)
        {
            cout << "Nota luata la oral la IF2: ";
            cin >> d.notaIF2;
            d.MAIF2 = 0.6 * d.notaIF2 + 0.4 * d.medie_bac;
        }
        if (d.nr_inregID)
        {
            cout << "Nota luata la oral la ID: ";
            cin >> d.notaID;
            d.MAID = 0.6 * d.notaID + 0.4 * d.medie_abs;
        }
        if (d.nr_inregID2)
        {
            cout << "Nota luata la oral la ID2: ";
            cin >> d.notaID2;
            d.MAID2 = 0.6 * d.notaID2 + 0.4 * d.medie_abs;
        }
        return in;
    };
    friend ostream &operator<<(ostream &out, Dosar d)
    {
        cout << "Nume: " << d.nume << endl;
        cout << "Medie bac: " << d.medie_bac << endl;
        if (d.pasaport) cout << "Inregistrat cu pasaportul" << endl;
        else cout << "Inregistrat cu actul de identitate" << endl;
        if (d.nr_inregID)
        {
            cout << "Nota la mate de la bac: " << d.nota_mate << endl;
        }
        if (d.nr_inregIF2 || d.nr_inregID2)
        {
            cout << "Programul de studii absolvit: " << d.absolvit << endl;
            cout << "Media absolvire: " << d.medie_abs << endl;
        }
        if (d.nr_inregIF)
        {
            cout << "Numarul legitimatiei la IF: " << d.nr_inregIF << endl;
            cout << "Nota luata la scris la IF: " << d.notaIF << endl;
            cout << "Media de admitere la IF: " << d.MAIF << endl;
        }
        if (d.nr_inregIF2)
        {
            cout << "Numarul legitimatiei la IF2: IF2_" << d.nr_inregIF2 << endl;
            cout << "Nota luata la oral la IF2: " << d.notaIF2 << endl;
            cout << "Media de admitere la IF2: " << d.MAIF2 << endl;
        }
        if (d.nr_inregID)
        {
            cout << "Numarul legitimatiei la ID: ID_" << d.nr_inregID << endl;
            cout << "Nota luata la oral la ID: " << d.notaID << endl;
            cout << "Media de admitere la ID: " << d.MAID << endl;
        }
        if (d.nr_inregID2)
        {
            cout << "Numarul legitimatiei la ID2: ID2_" << d.nr_inregID2 << endl;
            cout << "Nota luata la oral la ID2: " << d.notaID2 << endl;
            cout << "Media de admitere la ID2: " << d.MAID2 << endl;
        }
        return out;
    };

};

class Program
{
    int nr_locuri;
    int procent_taxa;
public:
    friend istream &operator>>(istream &in, Program p)
    {
        cout << "Numarul de locuri: ";
        cin >> p.nr_locuri;
        cout << "Procentul pentru locurile in regim cu taxa pentru a 2-a facultate: ";
        cin >> p.procent_taxa;
        return in;
    };
};

class IF:public Program
{
    vector<Dosar> candidati;
};
class ID:public Program
{
    vector<Dosar> candidati;
};

class IF2:public Program
{
    vector<Dosar> candidati;
};

class ID2:public Program
{
    vector<Dosar> candidati;
};

int Dosar::contorIF = 0;
int Dosar::contorIF2 = 0;
int Dosar::contorID = 0;
int Dosar::contorID2 = 0;
int main()
{
    vector <Dosar> dosare;
    int n;
    bool o1, o2, o3, o4;
    cout << "Numarul de candidati: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Optiune IF? (0 sau 1)";
        cin >> o1;
        cout << "Optiune IF2? (0 sau 1)";
        cin >> o2;
        cout << "Optiune ID? (0 sau 1)";
        cin >> o3;
        cout << "Optiune ID2? (0 sau 1)";
        cin >> o4;
        Dosar d(o1,o2,o3,o4);
        cin >> d;
        dosare.push_back(d);
    } // afisare cu iterator
    return 0;
}
