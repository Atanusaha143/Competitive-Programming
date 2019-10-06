#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c, d, e, f, g;

    cin >> a >> b >> c >> d;

    e= ((a*2)+(b*3)+(c*4)+(d*1))/(2+3+4+1);

    cout << "Media: "<< fixed << setprecision(1) << e << endl;

    if(e>=7.0)
    {
        cout << "Aluno aprovado." << endl;
    }
    else if(e<5.0)
    {
        cout << "Aluno reprovado." << endl;
    }
    else
    {
        cout << "Aluno em exame." << endl;
        cin >> f;
        cout << "Nota do exame: " << f << endl;
        g= (e+f)/2;

        if(g>=5.0)
        {
             cout << "Aluno aprovado." << endl;
        }
        else
        {
             cout << "Aluno reprovado." << endl;
        }

        cout << "Media final: "<< fixed << setprecision(1) << g << endl;
    }

    return 0;
 }