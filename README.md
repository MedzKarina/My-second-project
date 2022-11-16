# **Projekto dalys**

## **v0.1** 
> :bookmark: v0.11
- Sukurta strukrūta `Studentas`, joje bus įrašoma informacija apie kiekvieną studentą (pvz.: vardas, pavardė, galutinis balas).
- Panaudotos dvi funkcijos: 
  - spausdinimo
  - pildymo
- Sukurtas sąrašas `studentai`.
- Medianos ir vidurkio radimas.
- Buvo sukurtas dar vienas ciklas, kuriame aprašyta sąlyga kaip programa turi elgtis, kai yra nežinomas namų darbų skaičius iš anksto.
- Taip pat buvo panaudoti vektoriai.

## **v0.2** 
> :bookmark: v0.21
- Paliktas failas tik su vektoriumi.
- Dabar vartotojas turi pasirinkima: 
  - ar failai bus įvedinėjami ranka 
  - ar skaitomi iš failo.
- Yra tikrinimas ar failas nėra tuščias.
- Taip pat sveikojo skaičiaus patikra.

## **v0.3** 
> :bookmark: v0.31
- Studentai padalinami į dvi kategorijas: 
  - studentai, kurių galutinis balas < 5.0 - `nuskriaustukai`
  - studentai, kurių galutinis balas >= 5.0 - `kietiakiai`
- Jie išvedami į atskirus failus.
- Atliekama greičio analizė:
<img width="313" alt="v04" src="https://user-images.githubusercontent.com/91346039/199539302-0ed431df-c8ed-49f1-907e-ec9e624d9afa.png">

## **v0.4** 
> :bookmark: v0.41
- Patobulinta `v0.3` versija.
- Programoje naudojama dinaminė duomenų struktūra - `std::list`.
- Atlikti spartos matavimai:
<img width="313" alt="v04" src="https://user-images.githubusercontent.com/91346039/199539697-be4faa6d-8bbe-4d80-80b5-b47d249d29a7.png">

**Testų metu naudoto kompiuterio parametrai:** CPU: AMD Ryzen 5 Microsoft Surface (R) Edition 2.20 GHz, 8gb RAM, SSD.

## **v0.4.1** 
> :bookmark: v0.42
Patobulinta `v0.4` versijos realizacija.
- Išmatuojama veikimo sparta priklausomai nuo naudojamo vieno iš dviejų konteinerių:
  - std::vector
  - std::list
- Programoje matuojami šie atliekami žingsniai:
  - duomenų nuskaitymas iš failų
  - studentų grupavimas į dvi grupes
- Analizė atliekama iš failų sudarytų iš 1 000, 10 000, 100 000, 1 000 000 įrašų.
<Jei failas jau egzistuoja anksčiau direktorijoje sukurtame "files/" aplankale, programos veikimo greičio analizė atliekama su jau sugeneruotu failu.
Jei failas dar neegzistuoja, pirmiausia failas sugeneruojamas ir tik tuomet vykdoma programos spartos analizė.>
<img src="https://user-images.githubusercontent.com/91346039/202247096-309f0873-733b-4008-bef9-b4d41dcbbef2.png" width=40% height=40%>

## **v1.0** 
> :bookmark: v1.0
- Šioje versijoje optimizuojama rūšiavimo (grupavimo) realizacija: std::vector ir std::list konteinerių tipams išmatuojama programos veikimo sparta, priklausomai nuo studentų skirstymo į dvi kategorijas strategijos:
   - 1 strategija: Bendro "students" konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "stupid" ir "smart". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame "students" ir viename iš suskaidytų ("stupid" arba "smart").
   - 2 strategija: Bendro "students" konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "stupid". Tokiu būdu, jei studentas yra nelaimingas "stupid", jį turime įkelti į naująjį "stupid" konteinerį ir ištrinti iš bendro "students" konteinerio. Po šio žingsnio "students" konteineryje liks vien tik protingi "smart".
Ant vieno fiksuoto konteinerio - vector studentų rūšiavimo (dalijimo) procedūrai paspartinti, t. y. optimizuoti pritaikytas algoritmas std::stable_partition: visi elementai, kurių galutinis vidurkis > 5 eina prieš tuos, kurie netenkina sąlygos (galutinis vidurkis < 5).
Parengta naudojimosi instrukcija, t. y. aprašyti pagrindiniai žingsniai.
Parengta įdiegimo instrukcija, t. y. sukurtas cmake CMakeLists.txt (bet kokios OS atveju).

## Išvados
Naudojant 1 strategiją programos vykdymo greitis gana spartus, tačiau 1 strategija yra neefektyvi užimamos atminties atžvilgiu. Naudojant tiek std::vector, tiek std::list konteinerius duomenų nuskaitymo sparta yra panaši. List'ų struktūra sudėtingesnė, todėl skirstant studentus į dvi grupes/kategorijas, jie yra lėtesni nei vektoriai.
Atminties atveju 2 strategija efektyvesnė, tačiau dažni trynimai gali būti "skausmingi".

## Įdiegimo instrukcija:
Parsisiųsti norimą programos versijos (v1.0) kodą iš Releases;
Kodą sukompiliuoti per komandinę eilutę arba pasirinktą IDE. Naudojant CMakeLists.txt:
cmake .
cmake --build .

## Naudojimosi instrukcija:
- Paleidus programą įvedamas studentų skaičius. 
- Pagal tai bus sugeneruojami failai su atsitiktinais studentų sąrašais.
- Atliekama programos veikimo greičio (spartos) analizė.
<Jei failas jau egzistuoja anksčiau direktorijoje sukurtame "files/" aplankale, programos veikimo greičio analizė atliekama su jau sugeneruotu failu.
Jei failas dar neegzistuoja, pirmiausia failas sugeneruojamas ir tik tuomet vykdoma programos spartos analizė.>
