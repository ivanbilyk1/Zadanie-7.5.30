Náhodná permutácia cyklického typu

Ako to funguje
Funkcia random_permutation_cyclic_type prijíma tri argumenty:

*perm: Ukazovateľ na celočíselné pole, v ktorom bude permutácia uložená.
*cyklus: Ukazovateľ na celočíselné pole obsahujúce dĺžky cyklov.
*ncyc: Celé číslo určujúce počet cyklov.
Algoritmus funguje takto:

1. Inicializuje premennú count, ktorá sleduje aktuálnu pozíciu v poli permutácií.
2. Kontroluje neplatné vstupy, napríklad ukazovatele NULL alebo nepozitívne počty cyklov.
3.Nasadí generátor náhodných čísel pomocou aktuálneho času.
4.Iteruje cez každú dĺžku cyklu zadanú v poli cyc.
5.Pre každý cyklus vyplní príslušnú časť permutačného poľa po sebe idúcimi celými číslami reprezentujúcimi prvky cyklu.
6.Premieša permutačné pole
7. Po úspešnom dokončení vráti 1 a v prípade neúspechu 0.
Ako používať
Program vygeneruje a vypíše náhodnú permutáciu zadaného cyklického typu.
