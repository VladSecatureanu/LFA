#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int getIndex(string *c , string s, int n)
{
    for(int i = 0;i<n ; i++)
    {
        if(c[i]==s)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ifstream f("intrare.txt");
    int nrStari , nrTranzitii;
    f>>nrStari;
    string *stari = new string[nrStari];
    string s1 , s2 , s3;
    for(int i = 0;i<nrStari;i++)
    {
        f>>stari[i];
    }

    f>>nrTranzitii;

    string *tranzitii = new string[nrTranzitii];
    for(int i = 0;i<nrTranzitii;i++)
    {
        f>>tranzitii[i];
    }

    int m[nrStari][nrTranzitii];
    for(int i = 0;i<nrStari ;i++)
    {
        for(int j = 0 ;j<nrTranzitii ; j++)
        {
            m[i][j] = 0;
        }
    }
    string stareInitiala;
    f>>stareInitiala;
    int nrStariFinale;
    f>>nrStariFinale;
    string *stariFinale = new string[nrStariFinale];
    for(int i = 0 ;i < nrStariFinale;i++)
    {
        f>>stariFinale[i];
    }
    int nrFunctie;
    f>>nrFunctie;
    for(int i = 0 ; i<nrFunctie; i++)
    {

        f>>s1;
        f>>s2;
        f>>s3;

        m[getIndex(stari , s1 , nrStari)][getIndex(tranzitii , s2 , nrTranzitii)] = getIndex(stari , s3, nrStari);

    }

    string cuvant;
    cout<<"Cate tranzitii?";
    int numr;
    cin>>numr;
    int curenta = getIndex(stari , stareInitiala , nrStari);
    while (numr)
    {
        cout<<"Tranzitia e?";cin>>cuvant;
        if(m[curenta][getIndex(tranzitii , cuvant , nrTranzitii)])
        {
            curenta = m[curenta][getIndex(tranzitii , cuvant , nrTranzitii)];
        }
        else
        {
            cout<<"Nu";
            return 0;
        }
        numr--;
    }


    for(int h = 0;h<nrStariFinale;h++)
    {
        if(getIndex(stari , stariFinale[h] , nrStari)== curenta)
        {
            cout<<"Da";
            return 0;
        }
    }

    cout<<"Nu";
    return 0;

    /*for(int i = 0 ;i<nrStari ;i++)
    {
        for(int j = 0 ;j<nrTranzitii;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }*/

}
