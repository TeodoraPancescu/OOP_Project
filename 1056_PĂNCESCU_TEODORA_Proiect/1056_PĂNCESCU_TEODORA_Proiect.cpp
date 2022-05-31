#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//6. 2 Exceptii Custom

class ExceptieCustomCarte : public exception {
public:
	const char* what()const throw() {
		return "Numarul de capitole trebuie sa fie mai mic decat 40 si mai mare decat 0. \n";
	}
};

class ExceptieCustomCarte1 : public exception {
public:
	const char* what()const throw() {
		return "Pretul trebuie sa fie mai mare decat 0 si mai mic decat 9000. \n";
	}
};

//1.Conceptul de clasa abstracta

class Abstracta
{
public:
	virtual int returneazaNrCumparari() = 0;
};

//1.Clasa Parinte

class Carte {
	string denumire;
	string autor;
	//2. char*
	char* editura;
	int nrExemplare;
	int nrCapitole;
	//2. int*
	int* nrPagini;
	float pret;

public:

	//3.Constructor Default()

	Carte() {
		this->denumire = "Necunoscuta";
		this->autor = "Anonim";
		this->editura = new char[strlen("Necunoscuta") + 1];
		strcpy_s(this->editura, strlen("Necunoscuta") + 1, "Necunoscuta");
		this->nrExemplare = 0;
		this->nrCapitole = 0;
		this->nrPagini = new int[this->nrCapitole];
		for (int i = 0; i < this->nrCapitole; i++)
			this->nrPagini[i] = 0;
		this->pret = 0;
	}

	//3.Constructorul cu toti parametrii si validari

	Carte(string denumire, string autor, const char* editura, int nrExemplare, int nrCapitole, int* nrPagini, float pret) {
		if (denumire.empty()) {
			throw new exception("Denumire este necompletata.");
		}
		else {
			this->denumire = denumire;
		}
		if (autor.empty()) {
			throw new exception("Autor este necompletat.");
		}
		else {
			this->autor = autor;
		}
		if (editura == nullptr)
			throw new exception("Editura este invalida");
		else
		{
			this->editura = new char[strlen(editura) + 1];
			strcpy_s(this->editura, strlen(editura) + 1, editura);
		}
		if (nrExemplare < 0) {
			throw new exception("nrExemplare este invalid");
		}
		else {
			this->nrExemplare = nrExemplare;
		}
		if (nrCapitole < 0) {
			throw new exception("nrCapitole este invalid");
		}
		else {
			this->nrCapitole = nrCapitole;
		}
		if (nrPagini == nullptr)
			throw new exception("Vectorul de pagini este invalid");
		else
		{
			this->nrPagini = new int[this->nrCapitole];
			for (int i = 0; i < this->nrCapitole; i++) {
				this->nrPagini[i] = nrPagini[i];
			}
		}
		if (pret < 0) {
			throw new exception("Pret este invalid");
		}
		else {
			this->pret = pret;
		}
	}

	//3.Constructorul Fara Char* Si Cu Validari 

	Carte(string denumire, string autor, int nrExemplare, int nrCapitole, int* nrPagini, float pret) {
		if (denumire.empty()) {
			throw new exception("Denumire este necompletata.");
		}
		else {
			this->denumire = denumire;
		}
		if (autor.empty()) {
			throw new exception("Autor este necompletat.");
		}
		else {
			this->autor = autor;
		}
		if (nrExemplare < 0) {
			throw new exception("nrExemplare este invalid");
		}
		else {
			this->nrExemplare = nrExemplare;
		}
		if (nrCapitole < 0) {
			throw new exception("nrCapitole este invalid");
		}
		else {
			this->nrCapitole = nrCapitole;
		}
		if (nrPagini == nullptr)
			throw new exception("Vectorul de pagini este invalid");
		else
		{
			this->nrPagini = new int[this->nrCapitole];
			for (int i = 0; i < this->nrCapitole; i++) {
				this->nrPagini[i] = nrPagini[i];
			}
		}
		if (pret < 0) {
			throw new exception("Pret este invalid");;
		}
		else {
			this->pret = pret;
		}

	}

	//3.Constructor De Copiere

	Carte(const Carte& c) {
		this->denumire = c.denumire;
		this->autor = c.autor;
		if (c.editura != nullptr) {
			this->editura = new char[strlen(c.editura) + 1];
			strcpy_s(this->editura, strlen(c.editura) + 1, c.editura);
		}
		else {
			this->editura = nullptr;
		}
		this->nrExemplare = c.nrExemplare;
		this->nrCapitole = c.nrCapitole;
		this->nrPagini = new int[this->nrCapitole];
		for (int i = 0; i < this->nrCapitole; i++) {
			this->nrPagini[i] = c.nrPagini[i];
		}
		this->pret = c.pret;
	}

	//3.Operatorul Egal

	Carte& operator=(const Carte& cart) {
		if (this != &cart) {
			this->denumire = cart.denumire;
			this->autor = cart.autor;
			if (this->editura != nullptr) {
				delete[]this->editura;
				this->editura = new char[strlen(cart.editura) + 1];
				strcpy_s(this->editura, strlen(cart.editura) + 1, cart.editura);
			}
			this->nrExemplare = cart.nrExemplare;
			this->nrCapitole = cart.nrCapitole;
			if (this->nrPagini != nullptr) {
				delete[] this->nrPagini;
				this->nrPagini = new int[this->nrCapitole];
				for (int i = 0; i < nrCapitole; i++) {
					this->nrPagini[i] = cart.nrPagini[i];
				}
			}
		}
		return *this;
	}

	//3.Destructor

	~Carte() {
		//cout << "S-a apelat destructorul " << endl;
		if (this->editura != nullptr) {
			delete[] this->editura;
		}
		if (this->nrPagini != nullptr) {
			delete[] this->nrPagini;
		}
	}

	//4.Operatorul << 

	friend ostream& operator<<(ostream& out, const Carte& c) {
		out << "Cartea are denumirea " << c.denumire << " autorul " << c.autor << " este de la editura " << (c.editura != nullptr ? c.editura : "--- editura nu este setata ---") <<
			" este in " << c.nrExemplare << " exemplare. " << "Are " << c.nrCapitole << " capitole avand fiecare numarul de pagini ";
		for (int i = 0; i < c.nrCapitole; i++) {
			out << c.nrPagini[i] << " ";
		}
		out << "si pretul este " << c.pret << " lei. " << endl;

		return out;
	}

	//4.Operatorul >>

	friend istream& operator>>(istream& in, Carte& c) {
		cout << "Denumire: "; in >> c.denumire;
		cout << "Autorul: "; in >> c.autor;

		char aux[100];
		cout << "Editura: "; in >> aux;

		if (c.editura != nullptr) {
			delete[] c.editura;
		}

		c.editura = new char[strlen(aux) + 1];
		strcpy_s(c.editura, strlen(aux) + 1, aux);

		cout << "Numar exemplare: "; in >> c.nrExemplare;
		cout << "Numar capitole: "; in >> c.nrCapitole;

		if (c.nrPagini != nullptr) {
			delete[] c.nrPagini;
		}

		c.nrPagini = new int[c.nrCapitole];
		for (int i = 0; i < c.nrCapitole; i++) {
			in >> c.nrPagini[i];
		}

		cout << "Pretul: "; in >> c.pret;
		return in;
	}

	//4.Operatorul ++ (pre) incrementarea numarului de exemplare

	const Carte& operator++() {
		nrExemplare++;

		return *this;
	}

	//4.Operatorul -- (post) decrementarea numarului de exemplare

	const Carte operator--(int) {
		Carte aux(*this);

		nrExemplare--;

		return aux;
	}

	//4.Operatorul + (ex: cout<<c5+2;)

	int operator+(int x) {
		return nrCapitole + x;
	}

	//4.Operatorul + (ex: cout<<5+c3;)

	friend Carte operator+(float x, Carte c) {
		Carte aux = c;
		aux.pret += x;
		return aux;
	}

	//4.Operatorul += (ex. c1+=5;)

	void operator+=(int x) {
		nrExemplare += x;
	}

	//4.Operatorul + (ex. cout<< c5+c2;)

	Carte operator+(Carte& carte) {
		Carte aux(*this);

		aux.denumire = aux.denumire + "-" + carte.denumire;

		return aux;
	}

	//4.Operatorul ==

	bool operator ==(Carte c) {
		return this->pret == c.pret;
	}

	//4.Operatorul cast

	explicit operator int() {
		return nrExemplare;
	}

	//4.Operatorul index[]

	int& operator[](int index) {
		if (index >= 0 && index < nrCapitole) {
			return nrPagini[index];
		}
		else {
			throw new exception("Eroare: index < 0 sau index > nrPagini");
		}
	}

	//4.Operatorul <

	friend bool operator <(int valoarepret, Carte c) {
		return valoarepret < c.pret;
	}

	//6.Setteri, getteri si validare prin exceptiile custom

	string getDenumire() {
		return this->denumire;
	}
	string getAutor() {
		return this->autor;
	}
	float getPret() {
		return this->pret;
	}
	int getNrCapitole() {
		return this->nrCapitole;
	}
	int getNrExemplare() {
		return this->nrExemplare;
	}
	void setDenumire(string denumire) {
		if (denumire.empty()) {
			throw new exception("Denumirea primita ca input este invalida.");
		}
		else {
			this->denumire = denumire;
		}
	}
	void setAutor(string autor) {
		if (autor.empty()) {
			throw new exception("Autorul primit ca input este invalid.");
		}
		else {
			this->autor = autor;
		}
	}
	void setPret(float pret) {
		if (pret <= 0 || pret >= 9000) {
			throw ExceptieCustomCarte1();
		}
		else {
			this->pret = pret;
		}
	}
	void setNrCapitole(int nrCapitole) {
		if (nrCapitole <= 0 || nrCapitole >= 40) {
			throw ExceptieCustomCarte();
		}
		else {
			this->nrCapitole = nrCapitole;
		}
	}

	void scrieinfisierbinar(ofstream& fisier) {
		int dim = denumire.size() + 1;
		fisier.write((char*)&dim, sizeof(dim));
		fisier.write(denumire.c_str(), dim);

		dim = autor.size() + 1;
		fisier.write((char*)&dim, sizeof(dim));
		fisier.write(autor.c_str(), dim);

		dim = strlen(editura) + 1;
		fisier.write((char*)&dim, sizeof(dim));
		fisier.write(editura, dim);

		fisier.write((char*)&this->nrExemplare, sizeof(this->nrExemplare));

		fisier.write((char*)&this->nrCapitole, sizeof(this->nrCapitole));

		for (int i = 0; i < nrCapitole; i++) {
			fisier.write((char*)&this->nrPagini[i], sizeof(int));
		}

		fisier.write((char*)&this->pret, sizeof(this->pret));
	}

	void citiredinfisierbinar(ifstream& fisier) {
		int dim = 0;
		fisier.read((char*)&dim, sizeof(dim));
		char aux[100];
		fisier.read(aux, dim);
		denumire = aux;


		dim = 0;
		fisier.read((char*)&dim, sizeof(dim));
		fisier.read(aux, dim);
		autor = aux;


		dim = 0;
		fisier.read((char*)&dim, sizeof(dim));
		fisier.read(aux, dim);
		if (editura != nullptr) {
			delete[] editura;
		}

		this->editura = new char[dim];
		strcpy_s(this->editura, dim, aux);

		fisier.read((char*)&this->nrExemplare, sizeof(this->nrExemplare));

		fisier.read((char*)&this->nrCapitole, sizeof(this->nrCapitole));

		if (nrPagini != nullptr) {
			delete[] nrPagini;
		}

		this->nrPagini = new int[nrCapitole];
		for (int i = 0; i < nrCapitole; i++) {
			fisier.read((char*)&this->nrPagini[i], sizeof(int));
		}

		fisier.read((char*)&this->pret, sizeof(this->pret));
	}
};

//1.Clasa Copil 1 (Mostenire)

class CarteDeBucate : public Carte {
public:
	bool EsteCautata;

	//3.Constructor Default

	CarteDeBucate() {
		this->EsteCautata = false;
	}

	//3.Constructor Cu Toti Parametrii

	CarteDeBucate(string denumire, string autor, const char* editura, int nrExemplare, int nrCapitole, int* nrPagini, float pret, bool EsteCautata) : Carte(denumire, autor, editura, nrExemplare, nrCapitole, nrPagini, pret) {
		this->EsteCautata = EsteCautata;
	}

	//3.Constructorul De Copiere

	CarteDeBucate(const CarteDeBucate& cdb) :Carte(cdb) {
		this->EsteCautata = cdb.EsteCautata;
	}

	//3.Operatorul Egal

	CarteDeBucate& operator=(const CarteDeBucate& cdb1) {
		if (this != &cdb1) {
			Carte::operator=(cdb1);
			this->EsteCautata = cdb1.EsteCautata;
		}
		return *this;
	}

	//3.Destructor CarteDeBucate

	~CarteDeBucate() {
		//cout << "S-a apelat destructorul CarteDeBucate" << endl;
	}

	//Operatorul <<

	friend ostream& operator<<(ostream& out, const CarteDeBucate& cdb) {
		out << (Carte&)cdb;
		out << "Cartea este cautata? (1-Da sau 0-Nu) " << cdb.EsteCautata << endl;
		return out;
	}

	//Operatorul >>

	friend istream& operator>>(istream& in, CarteDeBucate& cdb) {
		in >> (Carte&)cdb;
		cout << "Este pentru cautata (1-Da sau 0-Nu) "; in >> cdb.EsteCautata;
		return in;
	}

	//4.Operator !

	bool operator!() {
		return !EsteCautata;
	}
};

//1.Clasa Copil 2 (Mostenire)

class CarteBeletristica : public Carte {
public:
	bool EstePentruCopii;

	//3.Constructor Default

	CarteBeletristica() {
		this->EstePentruCopii = false;
	}

	//3.Constructor cu toti parametrii

	CarteBeletristica(string denumire, string autor, const char* editura, int nrExemplare, int nrCapitole, int* nrPagini, float pret, bool EstePentruCopii) : Carte(denumire, autor, editura, nrExemplare, nrCapitole, nrPagini, pret) {
		this->EstePentruCopii = EstePentruCopii;
	}

	//3.Constructorul de copiere

	CarteBeletristica(const CarteBeletristica& cbe) :Carte(cbe) {
		this->EstePentruCopii = cbe.EstePentruCopii;
	}

	//3.Operatorul egal

	CarteBeletristica& operator=(const CarteBeletristica& cbe) {
		if (this != &cbe) {
			Carte::operator=(cbe);
			this->EstePentruCopii = cbe.EstePentruCopii;
		}
		return *this;
	}

	//3.Destructor CarteBeletristica

	~CarteBeletristica() {
		//cout << "S-a apelat destructorul CarteBeletristica" << endl;
	}

	//Operatorul <<

	friend ostream& operator<<(ostream& out, const CarteBeletristica& cbe) {
		out << (Carte&)cbe;
		out << "Cartea este pentru copii? (1-Da sau 0-Nu) " << cbe.EstePentruCopii << endl;
		return out;
	}

	//Operatorul >>

	friend istream& operator>>(istream& in, CarteBeletristica& cbe) {
		in >> (Carte&)cbe;
		cout << "Este pentru copii (1-Da sau 0-Nu) "; in >> cbe.EstePentruCopii;
		return in;
	}
};

//1.Interfata

class ILibrarie {
public:
	virtual void adaugaCarte(Carte car) = 0;

};

//5.O clasa folosind compunerea

class Librarie {
	string nume;
	string oras;
	Carte* carti;
	int nrCarti;
public:

	//3.Constructorul Default

	Librarie() {

		this->nume = "Necunoscut";
		this->oras = "Necunoscut";
		this->nrCarti = 0;
		this->carti = nullptr;
	}

	//3.Constructorul Cu Toti Parametrii

	Librarie(string nume, string oras, Carte* carti, int nrCarti) {

		this->nume = nume;
		this->oras = oras;
		this->nrCarti = nrCarti;
		this->carti = new Carte[nrCarti];
		for (int i = 0; i < nrCarti; i++) {
			this->carti[i] = carti[i];
		}
	}

	//3.Contructorul De Copiere

	Librarie(const Librarie& libra) {
		this->nume = libra.nume;
		this->nrCarti = libra.nrCarti;
		this->carti = new Carte[libra.nrCarti];
		for (int i = 0; i < nrCarti; i++) {
			this->carti[i] = libra.carti[i];
		}
	}

	//3.Destructor

	~Librarie() {
		/*cout << "S-a apelat destructorul Librarie" << endl;*/
		if (carti != nullptr) {
			delete[] carti;
		}
	}

	//3.Operatorul Egal

	Librarie& operator=(const  Librarie& libra) {
		if (this != &libra) {
			if (this->carti != nullptr) {
				delete[] this->carti;
			}
			this->nume = libra.nume;
			this->nrCarti = libra.nrCarti;
			this->carti = new Carte[libra.nrCarti];
			for (int i = 0; i < nrCarti; i++) {
				this->carti[i] = libra.carti[i];
			}
		}
		return *this;
	}

	//Operatorul << 

	friend ostream& operator<<(ostream& out, const Librarie& l) {
		out << "Nume librarie: " << l.nume << endl;
		out << "Oras librarie:" << l.oras << endl;
		out << "Numar de carti cu titluri diferite disponibile: " << l.nrCarti << endl;
		for (int i = 0; i < l.nrCarti; i++) {
			out << l.carti[i];
		}

		return out;
	}

	//Getter

	Carte* getCarti() {
		Carte* aux = new Carte[nrCarti];
		for (int i = 0; i < nrCarti; i++) {
			aux[i] = carti[i];
		}
		return aux;
	}

	//Implementarea Metodelor De Interfata Extinsa

	void adaugaCarte(Carte car) {
		Carte* aux = new Carte[nrCarti + 1];
		for (int i = 0; i < nrCarti; i++) {
			aux[i] = carti[i];
		}
		aux[nrCarti++] = car;
		delete[] carti;
		carti = aux;
	}

	friend ofstream& operator<<(ofstream& out, const Librarie& lib) {
		int dim = lib.nume.size() + 1;
		out.write((char*)&dim, sizeof(dim));
		out.write(lib.nume.c_str(), dim);

		dim = lib.oras.size() + 1;
		out.write((char*)&dim, sizeof(dim));
		out.write(lib.oras.c_str(), dim);

		out.write((char*)&lib.nrCarti, sizeof(lib.nrCarti));

		for (int i = 0; i < lib.nrCarti; i++) {
			lib.carti[i].scrieinfisierbinar(out);
		}
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Librarie& lib) {
		int dim = 0;
		in.read((char*)&dim, sizeof(dim));
		char aux[100];
		in.read(aux, dim);
		lib.nume = aux;

		dim = 0;
		in.read((char*)&dim, sizeof(dim));
		in.read(aux, dim);
		lib.oras = aux;

		in.read((char*)&lib.nrCarti, sizeof(lib.nrCarti));

		for (int i = 0; i < lib.nrCarti; i++) {
			lib.carti[i].citiredinfisierbinar(in);
		}
		return in;
	}
};

//8.O clasa ca cea de la 5 dar cu denumirea putin schimbata

class Library {
	string nume;
	string oras;
	vector<Carte> vectorCarti;

public:
	Library(string nume, string oras, vector<Carte>vecrtorCarti) {

		if (nume.empty()) {
			throw new exception("Nume invalid!");
		}
		else {
			this->nume = nume;
		}
		if (oras.empty()) {
			throw new exception("Oras invalid!");
		}
		else {
			this->oras = oras;
		}

		this->vectorCarti.clear();
		for (int i = 0; i < vecrtorCarti.size(); i++) {
			this->vectorCarti.push_back(vecrtorCarti[i]);
		}
	}

	Library(const Library& library) {

		this->nume = library.nume;
		this->oras = library.oras;
		for (int i = 0; i < library.vectorCarti.size(); i++) {
			this->vectorCarti.push_back(library.vectorCarti[i]);
		}
	}

	~Library() {
		this->vectorCarti.clear();
	}

	Library& operator=(const Library& library) {

		if (this != &library) {

			this->nume = library.nume;
			this->oras = library.oras;
			for (int i = 0; i < library.vectorCarti.size(); i++) {
				this->vectorCarti.push_back(library.vectorCarti[i]);
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Library& ly) {
		out << "Nume librarie: " << ly.nume << endl;
		out << "Oras librarie:" << ly.oras << endl;
		out << "Numar de carti cu titluri diferite disponibile: " << ly.vectorCarti.size() << endl;
		out << "Cartile:" << endl;
		for (int i = 0; i < ly.vectorCarti.size(); i++) {
			out << ly.vectorCarti[i] << endl;
		}

		return out;
	}
};

//1.Conceptul de clasa abstracta

class CarteDezvoltarePersonala : public Carte, public Abstracta {
	int nrCumparari;
public:
	CarteDezvoltarePersonala() {
		this->nrCumparari = 0;
	}

	CarteDezvoltarePersonala(string denumire, string autor, const char* editura, int nrExemplare, int nrCapitole, int* nrPagini, float pret, int nrCumparari) : Carte(denumire, autor, editura, nrExemplare, nrCapitole, nrPagini, pret) {
		this->nrCumparari = nrCumparari;
	}

	CarteDezvoltarePersonala(const CarteDezvoltarePersonala& cdp) : Carte(cdp) {
		this->nrCumparari = cdp.nrCumparari;
	}

	CarteDezvoltarePersonala& operator=(const CarteDezvoltarePersonala& cdp) {
		if (this != &cdp) {
			Carte::operator=(cdp);
			this->nrCumparari = cdp.nrCumparari;
		}
		return *this;
	}

	~CarteDezvoltarePersonala() {
		//cout << "S-a apelat destructorul CarteDezvoltarePErsonala" << endl;
	}

	friend ostream& operator<<(ostream& out, const CarteDezvoltarePersonala& cdp) {
		out << (Carte&)cdp;
		out << "Cartea fost cumparata de " << cdp.nrCumparari << "ori " << endl;
		return out;
	}

	virtual string tipCarte()
	{
		return "Aceasta carte este pentru dezvoltare personala!\n";
	}
	int returneazaNrCumparari()
	{
		return this->nrCumparari;
	}
};

int main() {
	cout << "===== 3.Obiect creat pe baza constructorului cu toti parametrii (Carte) =====" << endl << endl;
	int vectorul[] = { 17, 18, 20 };
	Carte c1("Poesii", "Mihai Eminescu", "Litera", 7, 3, vectorul, 26);
	cout << c1 << endl;
	int vector1[] = { 23, 22, 11, 17, 3 };
	Carte c2("Flori de mucegai", "Tudor Arghezi", "Art", 4, 5, vector1, 19);
	cout << c2 << endl;
	cout << "===== 3.Operatorul = (Carte) =====" << endl << endl;
	c2 = c1;
	cout << c2 << endl;
	cout << "===== 3.Constructorul de copiere (Carte) =====" << endl << endl;
	Carte c3(c2);
	cout << c3 << endl;
	cout << "===== 3.Obiect creat pe baza constructorului fara char* (Carte) =====" << endl << endl;
	int vector2[] = { 55, 67, 23, 88, 19 };
	Carte c4("Ion", "Liviu Rebreanu", 4, 5, vector2, 31);
	cout << c4 << endl;
	cout << "===== 3.Obiect creat pe baza constructorului cu toti parametrii (CarteDeBucate) =====" << endl << endl;
	int vect1[] = { 43, 102, 55, 106 };
	CarteDeBucate cdb("Secretele bunicii", "Marta Paraschiv", "Carusel", 2, 4, vect1, 39, true);
	cout << cdb << endl;
	int vect2[] = { 21, 57, 23, 89, 92, 17 };
	CarteDeBucate cdb1("Arta Culinara", "Jamila Cuisine", "CarteaVeche", 3, 6, vect2, 54, false);
	cout << cdb1 << endl;
	cout << "===== 3.Operatorul = (CarteDeBucate) =====" << endl << endl;
	cdb = cdb1;
	cout << cdb << endl;
	cout << "===== 3.Constructorul de copiere (CarteDeBucate) =====" << endl << endl;
	CarteDeBucate cdb2(cdb1);
	cout << cdb << endl;
	cout << "===== 3.Obiect creat pe baza constructorului cu toti parametrii (CarteBeletristica) =====" << endl << endl;
	int v1[] = { 60, 55, 80, 70, 30, 90, 98, 103 };
	CarteBeletristica cbe("Amintiri din copilarie", "Ion Creanga", "LecturiScolare", 11, 8, v1, 11, true);
	cout << cbe << endl;
	int v2[] = { 78, 55, 79, 90, 43, 37 };
	CarteBeletristica cbe1("Karamel", "Lexi B. Newman", "Stylished", 4, 6, v2, 28, false);
	cout << cbe1 << endl;
	cout << "===== 3.Operatorul = (CarteBeletristica) =====" << endl << endl;
	cbe1 = cbe;
	cout << cbe1 << endl;
	cout << "===== 3.Constructorul de copiere (CarteBeletristica) =====" << endl << endl;
	CarteBeletristica cbe2(cbe1);
	cout << cbe << endl;
	cout << "===== 4.Operatorii ++ si -- pre si post =====" << endl << endl;
	int vector3[] = { 37, 57, 49, 67, 52 };
	Carte c5("Dama cu camelii", "Alexandre Dumas Fiul", "Art", 7, 5, vector3, 39);
	cout << c5-- << endl;
	cout << c5 << endl;
	cout << ++c5 << endl;
	cout << "===== 4.Operatorul + (nrCapitole) =====" << endl << endl;
	cout << c5 + 2 << endl << endl;
	cout << "===== 4.Operatorul + (pret) =====" << endl << endl;
	Carte c6 = 5 + c3;
	cout << c6 << endl << endl;
	cout << "===== 4.Operatorul += (nrExemplare) =====" << endl << endl;
	c1 += 5;
	cout << c1 << endl;
	cout << "===== 4.Operatorul + (denumire) =====" << endl << endl;
	cout << c5 + c2 << endl;
	cout << "===== 4.Operatorul ! =====" << endl << endl;
	if (!cdb) {
		cout << "Cartea nu este cunoscuta" << endl;
	}
	else {
		cout << "Cartea este cunoscuta" << endl;
	}
	cout << cdb << endl;
	cout << "===== 4.Operator == =====" << endl << endl;
	if (c1 == c5) {
		cout << "Cele doua obiecte au acelasi pret!" << endl;
	}
	else {
		cout << "Cele doua obiecte nu au acelasi pret!" << endl << endl;
	}
	/*int nrCapitole = c3;
	cout << "(Cast implicit) Numarul capitole=" << nrCapitole << endl;*/
	cout << "===== 4.(Cast explicit) Numarul capitolelor pentru c3 este " << (int)c3 << "=====" << endl << endl;
	cout << "===== 4.Operatorul index =====" << endl << endl;
	cout << c3[0] << endl << endl;
	cout << "===== 4.Operator < =====" << endl << endl;
	if (10 < c2) {
		cout << "Cartea costa mai mult de 10 lei" << endl;
	}
	else {
		cout << "Cartea nu costa mai mult de 10 lei" << endl << endl;
	}
	cout << endl;
	cout << "===== 5.Refolosire cod mostenire pentrut a returna tot o carte :" << (cbe1 + 10) << " ===== " << endl << endl;
	cout << "===== 5.Compunere =====" << endl << endl;
	int ve1[] = { 78, 19, 23, 56, 78 };
	CarteBeletristica cbe3("Fluturi", "Irina Binder", "ForYou", 5, 5, ve1, 31, false);
	int ve2[] = { 63, 35, 81, 40, 67, 88 };
	CarteBeletristica cbe4("Basme", "Petre Ispirescu", "LecturiScolare", 9, 6, ve2, 15, true);
	int ve3[] = { 41, 64, 19, 49, };
	CarteBeletristica cbe5("Minunata lume noua", "Aldous Huxley", "Top10+", 2, 4, ve3, 29, false);
	Librarie l1("Libris", "Brasov", new Carte[]{ c1 }, 1);
	l1.adaugaCarte(cbe3);
	l1.adaugaCarte(cbe4);
	l1.adaugaCarte(cbe5);
	cout << l1 << endl;
	Librarie l2("Carturesti", "Bucuresti", new Carte[]{ c3 }, 1);
	l2.adaugaCarte(cbe3);
	l2.adaugaCarte(cbe4);
	l2.adaugaCarte(cbe5);
	cout << "===== 6.Setteri, getteri si exceptii Custom (Carte) =====" << endl << endl;
	Carte c7;
	try {
		c7.setDenumire("Cautand-o pe Aleska");
		c7.setAutor("John Green");
		c7.setNrCapitole(100);
		c7.setPret(20);
	}
	catch (ExceptieCustomCarte e) {
		cout << e.what() << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	catch (exception* e) {
		cout << e->what() << endl;
	}
	Carte c8;
	try {
		c8.setDenumire("Minciuni pe canapea");
		c8.setAutor("Irvin Yalom");
		c8.setNrCapitole(20);
		c8.setPret(0);
	}
	catch (ExceptieCustomCarte1 e1) {
		cout << e1.what() << endl;
	}
	catch (exception e1) {
		cout << e1.what() << endl;
	}
	catch (exception* e1) {
		cout << e1->what() << endl;
	}
	cout << "===== 7.Fisiere binare =====" << endl;
	ifstream fisierbinarcitire("fisier.bin", ios::in | ios::binary);
	if (fisierbinarcitire.is_open()) {
		fisierbinarcitire >> l2;
		cout << endl << l2 << endl;
		fisierbinarcitire.close();
	}
	else {
		cout << "Eroare la citire !!";
	}
	ofstream fisierbinarscriere("fisier.bin", ios::out | ios::binary | ios::app);
	if (fisierbinarscriere.is_open()) {
		fisierbinarscriere << l2;
		fisierbinarscriere.close();
	}
	else {
		cout << "Eroare la scriere !!";
	}
	cout << endl;
	cout << "===== 8.Vector STL===== " << endl << endl;
	vector<Carte> car;
	car.push_back(cbe3);
	car.push_back(cbe4);
	car.push_back(cbe5);

	Library library("Libraria.net", "Iasi", car);
	cout << library;
	cout << "===== 9.Late Biding =====" << endl << endl;
	Carte* cp;
	CarteDezvoltarePersonala* cdp = new CarteDezvoltarePersonala();
	cp = cdp;
	cout << cdp->tipCarte() << endl;
	cout << "===== 9.Early Biding =====" << endl << endl;
	CarteDezvoltarePersonala cdp1("Arta Subtila A Nepasarii", "Mark Manson", "LifeStyle", 4, 8, v1, 39, 2);
	CarteDezvoltarePersonala cdp2("Arta Subtila A Seductiei", "Mark Manson", "LifeStyle", 5, 8, v1, 29, 1);
	CarteDezvoltarePersonala cdp3("Arta Subtila A Disperarii", "Mark Manson", "LifeStyle", 2, 8, v1, 33, 1);
	cout << "Numarul de exemplare cumparate din carte <Arta Subtila A Nepasarii> este: " << cdp1.returneazaNrCumparari() << endl << endl;
	cout << "===== 10.Polimorfism in clasa abstracta =====" << endl << endl;
	CarteDezvoltarePersonala* vecCartiDez[3];
	vecCartiDez[0] = &cdp1;
	vecCartiDez[1] = &cdp2;
	vecCartiDez[2] = &cdp3;
	for (int i = 0; i < 3; i++)
	{
		cout << "Numarul de exemplare cumparate pentru aceasta carte este: " << vecCartiDez[i]->returneazaNrCumparari() << endl << endl;
	}
}