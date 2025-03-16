// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

class Powtorka{
    int n = 0;
    int *tab;
    
    public:
    Powtorka(int rozmiar){
        n = rozmiar;
        tab = new int[n];
    }
    ~Powtorka(){
        
    }
    
    void wylosujWartosci(int tab[], int n){
        srand(time(NULL));
        for(int i = 0; i<n; i++){
            tab[i] = rand()%3+1;
        }
        for(int i = 0; i<n; i++){
            cout<<tab[i]<<endl;
        }
    }
    
    void sitoErato(){
        bool A[n];
        for(int i = 0; i<n; i++){
            A[i] = true;
        }
        
        A[0] = A[1] = false;
        
        for(int i = 2; i<=n; i++){
            if(A[i]){
                for(int j = i*i; j<n; j+=i){
                    A[j] = false;
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(A[i]){
                cout<<i<<endl;
            }
        }
    }
    
    int wzorzecWTekscie(string tekst, string wzorzec){
        int wystapieniePierw = -1;
        int licznik = 0;
        
        for(int i = 0; i<=tekst.size() - wzorzec.size(); i++){
            bool dopasowanie = true;
            
            for(int j = 0; j<wzorzec.size(); j++){
                if(wzorzec[j] != tekst[i+j]){
                    dopasowanie = false;
                    break;
                }
            }
            
            if(dopasowanie){
                licznik++;
                if(wystapieniePierw == -1){
                    wystapieniePierw = i+1;
                }
            }
        }
        if(licznik > 0){
            cout<<"Wzorzec wystepuje "<<licznik<<" razy w tekscie\n";
            cout<<"Pierwsze wystapienie (indeks): "<<wystapieniePierw<<endl;
        }
        else{
            cout<<"Brak.";
        }
        return licznik;
    }
    
    int wyszukajLider(int tabl[], int n){
        int do_pary = 0;
        int lider = tabl[0];
        for(int i = 0; i<n; i++){
            if(do_pary > 0){
                if(tabl[i] == lider){
                    do_pary++;
                }
                else{
                    do_pary--;
                }
            }
            else{
                lider = tabl[i];
                do_pary++;
            }
        }
        
        if(do_pary == 0){
            return -1;
        }
        
        int licznik = 0;
        
        for(int i = 0; i<n; i++){
            if(lider == tabl[i]){
                licznik++;
            }
        }
        if(licznik >= n/2){
            return lider;
        }
        return -1;
    }
};

int main() {
    string wzor = "aj";
    string tekst = "lajakowjajsa";
    Powtorka pow = Powtorka(20);
    pow.sitoErato();
    pow.wzorzecWTekscie(tekst, wzor);
    
    int rozmiar;
    cout<<"Dej rozmiar: ";
    cin>>rozmiar;
    int tablica[rozmiar];
    
    pow.wylosujWartosci(tablica, rozmiar);
    
    int lider = pow.wyszukajLider(tablica, rozmiar);
    if(lider == -1){
        cout<<"Brak";
    }
    else{
        cout<<"Lider tablicy: "<<lider<<endl;
    }

    return 0;
}
