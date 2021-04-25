#include<iostream>
#include<bitset>
using namespace std;


void add(int ac[], int x[], int q)
{
    int i, c = 0;
    for (i = 0; i < q; i++)
    {
        ac[i] = ac[i] + x[i] + c;

        if (ac[i] > 1)
        {
            ac[i] = ac[i] % 2;
            c = 1;
        }

        else
            c = 0;
    }
}

void complemento(int a[], int n)
{
    int i;
    int x[8];
    x[0] = 1;
    for (i = 0; i < n; i++)
    {
        a[i] = (a[i] + 1) % 2;
    }
    add(a, x, n);
}

void res(int ac[], int qr[], int& qn, int q)
{
    int temp, i;
    temp = ac[0];
    qn = qr[0];
    cout << "\t\tcorr\t\t";
    for (i = 0; i < q - 1; i++)
    {
        ac[i] = ac[i + 1];
        qr[i] = qr[i + 1];
    }
    qr[q - 1] = temp;
}


void res(int ac[], int qr[], int qrn)
{
    int i;
    for (i = qrn - 1; i >= 0; i--)
        cout << ac[i];
    cout << " ";
    for (i = qrn - 1; i >= 0; i--)
        cout << qr[i];
}


int main(int argc, char** argv)
{
    int mt[10], br[10], qr[10], re, ac[10] = { 0 };
    int brn, qrn, i, qn, temp;

    cout << "\n Numero de bits= ";
    cin >> brn;
    cout << "\nmultiplicando=";
    for (i = brn - 1; i >= 0; i--)
        cin >> br[i];
    for (i = brn - 1; i >= 0; i--)
        mt[i] = br[i];
    complemento(mt, brn);
    cout << "\nNumero de bits=";
    cin >> qrn;
    re = qrn;
    cout << "Multiplicador=";
    for (i = qrn - 1; i >= 0; i--)
        cin >> qr[i];
    qn = 0;
    temp = 0;
    cout << "qn\tq[n+1]\t\tBR\t\tAC\tQR\t\tre\n";
    cout << "\t\t\tinicial\t\t";
    res(ac, qr, qrn);
    cout << "\t\t" << re << "\n";
    while (re != 0)
    {
        cout << qr[0] << "\t" << qn;
        if ((qn + qr[0]) == 1)
        {
            if (temp == 0)
            {
                add(ac, mt, qrn);
                cout << "\t\tresta BR\t";
                for (i = qrn - 1; i >= 0; i--)
                    cout << ac[i];
                temp = 1;
            }
            else if (temp == 1)
            {
                add(ac, br, qrn);
                cout << "\t\tsuma  BR\t";
                for (i = qrn - 1; i >= 0; i--)
                    cout << ac[i];
                temp = 0;
            }
            cout << "\n\t";
            res(ac, qr, qn, qrn);
        }
        else if (qn - qr[0] == 0)
            res(ac, qr, qn, qrn);
        res(ac, qr, qrn);
        cout << "\t";
        re--;
        cout << "\t" << re << "\n";
    }
    cout << "resultado= ";
    res(ac, qr, qrn);
}