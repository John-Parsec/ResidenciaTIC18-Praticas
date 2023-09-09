#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
    float pif;
    double pid;
    float fmax = __FLT_MAX__;
    float fmin = __FLT_MIN__;

    //a)
    cout << "float valor max: " << fmax << endl;
    cout << "float valor min: " << fmin << endl;

    //b)
    pif = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094;
    cout << "pif = " << pif << endl;

    //c)
    cout << setprecision(2) << fixed << "pif = " << pif << endl;
    cout << setprecision(4) << fixed << "pif = " << pif << endl;
    cout << setprecision(8) << fixed << "pif = " << pif << endl;
    cout << setprecision(16) << fixed << "pif = " << pif << endl;

    cout << endl;

    //d)
    pid = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094;
    cout << "pid = " << pid << endl;

    //e)
    cout << setprecision(2) << fixed << "pid = " << pid << endl;
    cout << setprecision(4) << fixed << "pid = " << pid << endl;
    cout << setprecision(8) << fixed << "pid = " << pid << endl;
    cout << setprecision(16) << fixed << "pid = " << pid << endl;

    //f)
    cout << "Maximo do pif e pid: " << endl;
    cout << setprecision(64) << fixed << "pif = " << pif << endl;
    cout << setprecision(64) << fixed << "pid = " << pid << endl;
    //o float mantem 23 casas decimais apos o . e completa o resto com 0 para manter a precisao forcada
    //ja o double mantem 49 casas decimais apos 0 . e completa o resto com 0 para manter a precisao forcada
    //logo, o float possui menos espaco de armazenamento disponivel.
    
    return 0;
}

