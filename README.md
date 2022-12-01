# **Projekto dalys**

# My-second-project

> Ankstesnės atliktos užduoties pagrindu sukurta nauja repozicija, t.y., visa git istorija iki v1.0 yra išlikusi. 

## **v1.1** 
> :bookmark: v1.1
- Naujosios programos v1.1 veikimo principas sukurtas pasiremiant v1.0.
- Pridėtas programos veikimas naudojant "Klases"
- Pridėta laiko analizė naudojant skirtingus kompiliatoriaus optimizavimo flag'us (laikai lentelėje pateikiami sekundėmis):

## Išvados
Didžiausią skirtumą duoda kompiliatoriaus flag'ai. Naudojant Class su mažesniais duomenų kiekiais, dauguma atvejų programa suveikė greičiau. Su didesniais kiekiais galima padaryti tokią pačią išvadą.

# My-first-project

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
- Dabar vartotojas turi pasirinkimą: 
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
> Jei failas jau egzistuoja anksčiau direktorijoje sukurtame "files/" aplankale, programos veikimo greičio analizė atliekama su jau sugeneruotu failu.
> Jei failas dar neegzistuoja, pirmiausia failas sugeneruojamas ir tik tuomet vykdoma programos spartos analizė.

<img src="https://user-images.githubusercontent.com/91346039/202247096-309f0873-733b-4008-bef9-b4d41dcbbef2.png" width=40% height=40%>

## **v1.0** 
> :bookmark: v1.0
- Šioje versijoje optimizuojama rūšiavimo (grupavimo) realizacija: std::vector ir std::list konteinerių tipams išmatuojama programos veikimo sparta, priklausomai nuo studentų skirstymo į dvi kategorijas strategijos:
   - ***1 strategija***: Bendro "studentai" konteinerio (vector ir list tipų) grupavimas į du naujus to paties tipo konteinerius: "nuskriaustukai" ir "kietiakai". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame "studentai" ir viename iš suskaidytų.
   - ***2 strategija***: Bendro "studentai" konteinerio (vector ir list) grupavimas panaudojant tik vieną naują konteinerį: "nuskriaustukai". Tokiu būdu, jei studentas yra "nuskriaustukai", jį turime įkelti į naująjį "nuskriaustukai" konteinerį ir ištrinti iš bendro "studentai" konteinerio. Po šio žingsnio "studentai" konteineryje liks vien tik "kietiakai".
   
<img width="398" alt="Be pavadinimo2" src="https://user-images.githubusercontent.com/91346039/202422783-69f2c392-3a0b-4b44-adf7-d4601be53f52.png">

## Išvados
Naudojant 1 strategiją programos vykdymo greitis gana spartus, tačiau 1 strategija yra neefektyvi užimamos atminties atžvilgiu. Naudojant tiek std::vector, tiek std::list konteinerius duomenų nuskaitymo sparta yra panaši. List'ų struktūra sudėtingesnė, todėl skirstant studentus į dvi grupes/kategorijas, jie yra lėtesni nei vektoriai.
Atminties atveju 2 strategija efektyvesnė.

## Naudojimosi instrukcija:
- Paleidus programą įvedamas studentų skaičius. 
- Pagal tai bus sugeneruojami failai su atsitiktinais studentų sąrašais.
- Atliekama programos veikimo greičio (spartos) analizė.
> Jei failas jau egzistuoja anksčiau direktorijoje sukurtame "files/" aplankale, programos veikimo greičio analizė atliekama su jau sugeneruotu failu.
> Jei failas dar neegzistuoja, pirmiausia failas sugeneruojamas ir tik tuomet vykdoma programos spartos analizė.
