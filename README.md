# Circuitul_Calului
    Problema propusă.
Circuitul calului: Se dă o tablă de șah de N x N elemente pe care se află un cal la coordonatele
(i,j). Se cere să se scrie un program care determină mutările calului (respectând săritura calului
din jocul de șah) astfel încât toate pozițiile tablei să fie acoperite.

    Motivație.
Problema calului este o problemă ce pune în discuție un algoritm care ar putea contribui la dezvoltarea unui program care să "joace" cu un jucator real și chiar să exceleze în acest sens. Desigur, această problemă este un procent minuscul care ar putea contribui la dezvoltarea programului respectiv, dar în același timp este o provocare la adresa tinerilor programatori. În plus în timpul soluționării problemei se aprofundează cunoștințe legate de algoritmică și logică, și se exploatează posibilitățile limbajulșui C++ .

    Metode de soluționare.
Pentru soluționarea problemei am decis să folosim 2 algoritmi: algoritmul lui Warnsdorff și un algoritm propriu ce utilizează Backtracking-ul ca principiu.

    Algoritmul lui Warnsdorff.
Algoritmul dat funcționează pe principiul ciclului Hamiltonian, se face mutarea calului pe celula care conține cele mai puține posibilități de avansare. Spre deosebire de problem ciclului Hamiltonian, Algoritmul lui Warnsdorff are performanță liniară. În plus am evitat vizitări duble ale celulelor. Din cauza faptului că poziția de start este aleatoare, există posibilitatea ca algoritmul să eșueze.

    Algoritmul ce utilizează Backtracking.
Folosim o funcție recursivă ce parcurge fiecare celulă adiacentă pozitiei calului în mod recursiv, până se umple tabla de șah.

    Ghid utilizare.
Pentru a rula aplicația se utilizează linia de comandă sau terminalul. 
În prima fază se acesează doar executabilul cal (./cal) care oferă informații adiționale privind rularea programului.
La rulare sub forma "./cal algos" se afișeză ce-i doi algoritmi folosiți.
La rularea completă "./cal N i, j, algoritm" se afișează infomații despre datele introduse, o bară de progres, algoritmul lui Warnsdorff: optiuni bune, timul în care s-a găsit și o tablă parcursă aleasă aleatoriu, algoritmul ce utilizează backtracking: timpul in care s-a gasit(daca s-a gasit) și tabla parcursă.

    Surse.
https://www.geeksforgeeks.org/warnsdorffs-algorithm-knights-tour-problem/
https://en.cppreference.com/
https://stackoverflow.com/