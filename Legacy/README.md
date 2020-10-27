## Zamówione komponenty:

##### ESP:
https://allegro.pl/oferta/esp32-lite-4mb-flash-wifi-bluetooth-lolin32-8644932107?snapshot=MjAyMC0wNy0wNlQyMDozMzo0My44NTFaO2J1eWVyO2JmNWIyM2VlOWI3MTRmNjhiYjM2NmViOGY4ODlmYmExZDliNTQxZDYwYmZjMGE4M2Y0OTRlZWQ3NTBlNGFkODU%3D

alternatywa Ali (przetestowana)

https://www.aliexpress.com/item/33006577783.html?spm=a2g0s.9042311.0.0.4f6f4c4dRUueju

##### Koszyczki pod baterię:
https://allegro.pl/oferta/koszyk-pojemnik-uchwyt-na-1x-18650-ogniwo-3164-9423389445?snapshot=MjAyMC0wNy0wNlQyMDozMzo0My44NTFaO2J1eWVyOzdmZGJlNmFhMTk4MGNmMTQzN2JkYTY1Y2RmODc3MTBjMmI0NDdhNDI3ZTU4MDg2OWE1ZTMwY2Q2Nzg3OGY0ZWE%3D

##### Baterie - wychodzi na to że mają maksymalnie 1800 mAh. Można podciągnąć do góry wydajność kupując firmowe np. sony 2250 mAh:
https://allegro.pl/oferta/akumulator-bateria-4800mah-18650-li-ion-3-7v-szare-9260214771?snapshot=MjAyMC0wNy0wNlQyMDozMzo0My44NTFaO2J1eWVyOzAyZDFhMzJkYjc0NGY2OTYxMmE0NzY2OWVkZjM5MDRmYzZiMmUxMWNkOGVlNDE5NDI0MDY4MDNmN2YwYzZmYjA%3D

##### Ogniwo słoneczne:
https://allegro.pl/oferta/ogniwo-sloneczne-fotowoltaiczne-2w-6v-os2-pv-9325281596?snapshot=MjAyMC0wNy0wNlQyMDozMzo0My44NTFaO2J1eWVyOzEwMzEwMTY2Yjg4ZmZmZTA1YWQxNGNhYjI1NjExNWM5ZmY1OGQzOWYyZTMzNDc1NWYxNDU2ODExZWViOTYyMTE%3D

alternatywa Ali - przetestowane - maks 100mA, nie nadają się na ten projekt. Trzeba kupić większe.

https://www.aliexpress.com/item/33007861569.html?spm=a2g0s.9042311.0.0.4f6f4c4dRUueju

##### USB: (do rozcięcia do zlutowania z ogniwem)
https://allegro.pl/oferta/kabel-do-ladowania-micro-usb-2a-szybkie-ladowanie-8927500521?snapshot=MjAyMC0wNy0wNlQyMDozMzo0My44NTFaO2J1eWVyO2M5NTg4M2I1ODYyZmViMmE3ODM4NGZlY2NiZWU0ZWY5NmExM2NmZDBjMTQ4N2U2YzIwMjM5OWM5YmEyYWU5NzI%3D

##### czytnik kart microSD - zły - mimo że opisany jest jako pracujący na 3.3V to działa tylko na 5V. Zamówiony drugi. Drugi okazał się być czytnikiem SD a nie microSD. Zamówiony trzeci i w końcu trafiony. Tylko już niedostępny na allegro.

https://allegro.pl/oferta/modul-czytnik-kart-microsd-micro-sd-arduino-avr-fv-7587212548?snapshot=MjAyMC0wOC0yNFQxMTowMToyOS4yMjdaO2J1eWVyOzY5NDFiOWRiZmMwZGJjZjVjN2VjNGI3NmNkZGIxNGI5YmIxNDI0NTFlOTMwYjg5NzAwZDEzNmY3MzE2YmU5MDg%3D

https://allegro.pl/oferta/czytnik-kart-sd-interfejs-spi-arduino-9608972332?snapshot=MjAyMC0wOC0yNVQxNzowMzoyNy4xOTNaO2J1eWVyO2MyODJkZDY0MjljMzQ1NDA5ZjQzOTE1YjIxYTJiOTAwZjM4Nzc3YWU5YmFlOWM4ZTBjZmJhNGY1NDExNmRkMWU%3D

##### karty microSD (różne pojemności)
https://allegro.pl/oferta/karta-pamieci-microsd-1gb-sdhc-micro-sd-gw-fv-8995743207

https://allegro.pl/oferta/karta-pamieci-microsd-2gb-sdhc-micro-sd-gw-fv-7950284934

https://allegro.pl/oferta/karta-pamieci-4gb-micro-sd-microsd-sdhc-fv-gw-7814324566

https://allegro.pl/oferta/karta-pamieci-microsd-8gb-sdhc-gwarancja-fv-7643739086

https://allegro.pl/oferta/karta-pamieci-microsd-16gb-sdhc-gwarancja-fv-7643757943

## Bazowe założenia
Główną ideą całego projektu jest jego udostępnienie na zasadach licencji CC-BY. Założenie takie generuje pewne cechy produktu, które muszą zostać jak najlepiej spełnione, aby projekt miał sens. W przeciwnym wypadku urządzenie to nie będzie miało możliwości zostać użyte poza projektem „Rozszerzona Rzeczywistość”.

### 1.	Łatwość konfiguracji i montażu
Pierwszym założeniem dla projektu jest możliwość realizacji scenariusza i produkcji urządzenia przez jak największą liczbę osób lub instytucji. Ze względu na to, że wielu z potencjalnych przyszłych użytkowników nie posiada umiejętności technicznych, główną ideą jest zapewnienie jak najmniejszego stopnia skomplikowania.

Docelowym pomysłem jest używanie gotowych modułów, nawet kosztem wydajności energetycznej rozwiązań (gotowe moduły zamiast indywidualnej budowy komponentów). W miarę możliwości najlepszym rozwiązaniem była by możliwość zaprojektowania systemu który można podłączyć na zasadzie „pająka” bez potrzeba tworzenia płytek prototypowych czy nawet lutowania.

Tak samo zaprogramowanie urządzenia powinno być jak najłatwiejsze. W najprostszym scenariuszu użycia powinno pozawalać na postępowanie krok po kroku za instrukcją, bez jakiejkolwiek wiedzy z zakresu stosowanych rozwiązań, aby pozwolić jak największej ilości osób na wykorzystanie urządzenia.

### 2.	Cena
Bazowe założenia uwzględniają również cenę gotowego urządzenia. Docelowy koszt produkcji rzędu kilkuset złotych zdecydowanie ograniczy liczbę zastosowań. Produkcja 5 urządzeń w cenie np. 500 zł będzie kosztem nieakceptowalnym dla indywidualnego artysty oraz bardzo nieciekawą opcją dla mniejszych festiwali, ponieważ pieniądze takie można zainwestować w lepszy sposób.

### 3.	Dostępność komponentów
Wszystkie komponenty użyte w projekcie powinny w miarę możliwości posiadać alternatywę, oraz przede wszystkim być powszechnie (również branżowo) dostępne. Projekt wyklucza używanie nietypowych i rzadkich komponentów.

### 4.	Scenariusz user-friendly
Poza kwestiami związanymi z produkcją i wdrożeniem rozwiązania dla organizatorów wydarzeń, w scenariuszach użycia oraz scenariuszach funkcjonalno-użytkowych należy założyć jak najprostszą ścieżkę dla użytkownika końcowego – korzystnie z urządzenia musi być łatwe i nie angażujące, ponieważ projektowane urządzenie i scenariusze są tylko narzędziem do przekazywania treści, a nie treścią samą w sobie.
Najlepszym rozwiązaniem będzie ograniczenie interakcji docelowego użytkownika/zwiedzającego do podłączenia się przez bluetooth/wifi, włączenia aplikacji (lub przeglądarki) oraz ewentualne naciśnięcia jednego przycisku.

### 5.	Uniwersalność instalacji
Pomysł zakłada jak najszersze użycie urządzenia. Dlatego projekt techniczny powinien zakładać jak najwięcej możliwości montażu oraz zasilania urządzenia.
Scenariusz użycia powinien być natomiast na tyle elastyczny, aby móc spełnić jak najwięcej wymagań organizatora.

### 6.	Kwestia modułowości
Dobrym założeniem - chociaż nie koniecznym, jest analiza możliwości stworzenia urządzenia modułowego – tak by w zależności od potrzeb można było rezygnować z niektórych komponentów w celu ograniczenia kosztów, jednak rozwiązania modułowe są znacznie trudniejsze w realizacji i pomysł ten może być za skomplikowany, biorąc pod uwagę dostępne zasoby czasowe.
 
## Urządzenie

### 1.	Bazowy mikrokontroler
~~Na ten moment projekt bazuje na module ESP32-WROOM w wersji płytki prototypowej LOLIN32. Posiada ona pełną funkcjonalność płytki ESP32-WROOM z dodatkową bardzo atrakcyjną funkcją wbudowanego kontrolera ładowania baterii 18650.
Poza tym posiada (co istotne z punktu widzenia projektu):~~
- ~~moduł Wifi~~
- ~~moduł Bluetooth~~
- ~~4 MB pamięci Flash~~

~~Drugą opcją jest użycie Raspbbery Pi Zero W. Trudniejsza podłączenie elektroniki, wyższa cena, ale za to znacznie łatwiejsza konfiguracja Captiver Portal, Wifi AP, oraz większe możliwości stworzenia strony Captive portal (normalny dostęp do kart SD).~~

Rozważone zostały dwa rozwiązania. Pierwsze bazowało na układzie mikrokontrolera z modułami WiFi, drugie natomiast na bazie mikrokomputera Raspberry Pi.

Po wstępnym przeglądzie dostępnych rozwiązań do testów trafiły poniższe urządzenia:
- mikrokontroler WEMOS Lolin32 Lite
- Raspberry Pi Zero W

Porównanie obu rozwiązań poniżej:
| Element | Lolin32 Lite | +/- | Raspberry Pi Zero W | +/- |
| --- | --- | :---: | --- | :---: |
| Cena zestawu | ~70 zł w polsce, ~45 zł aliexpress (wersja kompletna z zasilaniem solarnym) | + | ~150 zł (brak zamienników) | - |
| Urządzenia alternatywne| dostępne | + | brak innych rozwiązań | - |
| Dostępność | globalna, w wielu sztukach | + | globalna, jednorazowo można kupić tylko 1 sztukę | - |
| Moduły | Wifi i Bluetooth | + | Wifi i Bluetooth | + |
| Pobór mocy | 80 mA w trybie czuwania, 150 mA w transmisji WiFi | + | 250 mA | - |
| Wymiary | 50 x 25 x 7 mm | + | 65 x 30 x 5 mm | - |
| Obsługa HTTPS | nie | - | nie | - |
| Pamięć | 4 Mb lub zależna od karty SD | + | Zależna od karty SSD | + |
| Łatwość złożenia | średnia | +/- | wysoka | + |
| Łatwość pierwotnej konfiguracji | wysoka | + | niska | - |
| Łatwość rekonfiguracji | niska | - | wysoka | + |

Wynikiem analizy powyższych elementów jest decyzja o kontynuacji projektu bazując na module Lolin32. Mimo małej ilości dostępnej pamięci, trudniejszej rekonfiguracji i nieco większej fizycznej złożoności, moduł ten zdecydowanie lepiej spełnia pierwotne założenia projektu.

### 2.	Zasilanie bateryjne
Mimo zasilania przy pomocy ogniw słonecznych wymagane jest również zasilanie urządzenia przy pomocy baterii. Zarówno w celu stabilizacji napięcia zasilającego, jak również w celu zapewnienia zasilania w przypadku złej pogody lub wieczora/nocy.

Po wstępnej analizie rozwiązań i doborze mikrokontrolera wybór pada na baterie 18650. Posiadają dużą pojemność, odpowiednie napięcie zasilania oraz przede wszystkim mikrokontroler posiada wbudowany układ ładowania tego typu baterii.

Przeprowadzone testy pokazały, że moduł może być zasilany z baterii 18650 z dużą skutecznością. W przypadku zasialania z dwóch takich baterii, możliwe jest osiągnięcie czasu pracy na poziomie 40 godzin. Każda kolejna bateria dodana do zestawu przedłuża czas pracy urządzenia. Dlatego w przypadku w przypadku zasilania tylko z baterii, stworzona została dodatkowa obudowa na 4 baterie.

### 3.	„Eko” zasilanie
W celu zapewnienia pracy ciągłej urządzenia oprócz baterii należy rozważyć zasilanie urządzenia przy pomocy odnawialnych źródeł energii (jest to pojęcie mocno na wyraz w przypadku tego projektu). W każdym razie zakładamy autonomiczną pracę urządzenia, więc należy zadbać o możliwość zasilania urządzenia w inny sposób niż tylko bateryjny lub sieciowy.

Na dzień dzisiejszy mamy dwie możliwości – energia solarna lub wiatrowa. Inne opcje są wyjątkowo skomplikowane i poza spektrum tego projektu.

Szukając rozwiązań dostępnych w internecie można zauważyć że energia solarna jest tania i prosta w implementacji. Natomiast energia wiatrowa nie jest nigdzie opisana i jest to rozwiązanie bardzo prototypowe które może być nieskuteczne i drogie.

W takim wypadku skupiłbym się na użyciu tylko i wyłącznie paneli słonecznych w celu zasilenia urządzenia.

Kwestią którą trzeba rozwiązać jest również zasilanie z trzech źródeł – sieciowe, bateryjne i solarne. Na ten moment widziałem tylko projekty które brały pod uwagę zasilanie solarno/akumulatorowe, jednak ze względu na założenia bazowe trzeba zaimplementować możliwość zasilania sieciowego.

### 4.	Inne komponenty
Dodatkowe komponenty nie muszą zostać użyte w aktualnym projekcie ze względów takich samych jak stworzenie modułowego rozwiązania – czyli ograniczenia czasowe.

Komponenty te jednak w najlepszej opcji bazowały by na idei modularności – ze względu na zwiększenie ceny gotowego urządzenia. Na ten moment można pokusić się o założenie że te są to opcje które mogą być zaimplementowane w wersji 2.0, jednak wzięcie ich pod uwagę na tym etapie projektu daje ułatwia drogę do ich dalszego rozwoju.

#### a)	Wyświetlacz
Dodanie modułu wyświetlacza pozawala w pewien sposób odciążyć merytoryczne połączenie urządzenie-telefon. Użycie dowolnych modułów wyświetlaczy (alfanumeryczny, LCD, OLED) pozwoli na przestawienie treści bez angażowania technologicznego zwiedzającego. Możliwe również jest stworzenie autonomicznego punktu wykorzystującego ideę scenariuszy podstawowych gdzie w ograniczonej formie można przekazać dodatkową treść do prezentowanego dzieła.

#### b)	Głośnik
Rozwiązanie to jest tożsame z wykorzystaniem wyświetlacza, jednak wykorzystuje zmysł słuchu w celu przekazania dodatkowych informacji.

Dodatkowo możliwe jest użycie głośnika w celu cyklicznego odtwarzania dźwięków które może posłużyć jako dodatkowa forma gamifikacji – poszukiwanie miejsca prezentacji bazując na słuchu (np. w obszarach o dużej przestrzeni jak parki czy lasy).

## Podstawowa funkcjonalność urządzenia
Bazując na podstawowych założeniach chcemy osiągnąć produkt który będzie łatwy i w miarę możliwości nieskomplikowany w obsłudze dla końcowego użytkownika. Również musimy mieć na względzie możliwości organizatorów – czyli ograniczenia technologiczne i budżetowe.

~~Ogólnie można przyjąć dwie drogi postępowania – po podłączeniu do urządzenia i włączeniu aplikacji użytkownik może otrzymać dwa rodzaje treści:~~
- ~~docelową treść którą chce przekazać artysta/organizator~~

- ~~treść tekstową~~

~~Mówiąc dowolna treść mam na myśli treść multimedialną – film, zdjęcie, tekst.~~

~~Pierwsze rozwiązanie jest znacznie lepsze dla odbiorcy końcowego, jednak myślę że jest wyjątkowo kłopotliwe dla twórcy. Po pierwsze przekazanie takiej treści na pewno wymagać będzie zaawansowanej wiedzy z zakresu programowania aplikacji, ponieważ każde zastosowanie wymagać będzie napisania od nowa algorytmu który będzie obsługiwać backend komunikacji. Nie wspominając o ile trudniejsze będzie zastosowanie rozwiązania w przypadku bardziej skomplikowanych scenariuszy np. gamifikacyjnych. Dodatkowo rozwiązanie to sprawi że każda wystawa lub festiwal będzie musiał udostępnić własną aplikację tylko w celu obsługi eventu.~~

~~Drugie rozwiązanie jest mniej przyjazne dla użytkownika końcowego (ale też nie wymaga żadnej wiedzy technicznej), ale wyjątkowo proste dla organizatora. Przesyłana po bluetoothie wiadomość jest tylko treścią tekstową. Może to być dowolna treść – w najprostszym przypadku link do strony www – dzięki czemu artyści/organizatorzy którzy dysponują ograniczonym budżetem i/lub umiejętnościami w zakresie programowania mogę udostępnić link do dowolnej strony od social mediów, przez youtube po prosty link do grafiki czy nawet kod zniżkowy na wstęp na festiwal. W bardziej zaawansowanych przypadkach znacznie tańsze i łatwiejsze jest stworzenie prostej witryny która udostępnia stopniowo treści, niż stworzenie aplikacji na wiele systemów o takiej samej funkcjonalności.
W związku z tymi rozważaniami uważam że opracowane urządzenie powinno wysyłać tylko treść tekstową, co pozwoli na ułatwienie użycia dla większej ilości osób lub podmiotów.~~

W wyniku ustaleń bieżącym rozwiązaniem jest zastosowanie funkcjonalności captive portal. Podłączenie do urządzenia odbywać będzie się po sieci WiFi (nie bluetooth), dzięki czemu wystarczy zalogować się do wskazanej sieci, gdzie po podłączeniu użytkownik zostanie automatycznie przekierowany (lub będzie musiał wpisać konkretny adres w przeglądarce - zależne to będzie od telefonu użytkowanika - w wyniku bieżących testów część telefonów wyświetla od razu notyfikacje zaloguj się do sieci wifi, która przekierowuje od razu do webserwera, część natomiast nie) aby dostać się na stronę html (znajdującą się lokalnie na urządzeniu). Rozwiązanie to zmniejsza dostępny stopień skomplikowania strony (również przez ograniczenia ilości miejsca - maks 4 mb), jednak całkowicie wyklucza potrzebę instalacji specjalnej aplikacji (przez odbiorcę) lub jej stworzenia/napisania (przez organizatora). Również dzięki temu projekt staje się niezależnym nośnikiem treści, a nie tylko przekierowaniem dla niej (eliminując skojarzenia z pewną formą mniej przystępnego QR kodu tylko w wersji cyfrowej).

## Scenariusze użycia

![Schemat](/RR_scheme.png)

### 1.	Scenariusze podstawowe
Scenariusze podstawowe opisują najprostsze i najbardziej standardowe formy użycia. Dają dodatkowe możliwości przekazu treści, w sytuacjach które ograniczają media dotychczas stosowane.

#### a)	Zwiedzanie rozproszone
Usytuowanie wielu (lub nawet jednego urządzenia) w dowolnej lokalizacji (przestrzenie publiczne, sklepu, bary, restauracje), pozwoli na przekazanie docelowej treści bez gromadzenia osób w jednej przestrzeni. Korzystając z mediów społecznościowych możliwe jest udostępnienie lokalizacji w których znajdować będą się urządzenia, docierając w sposób pośredni do potencjalnych odbiorców. Rozwiązanie pozwala zachować wszystkie zalecenia dotyczące dystansu społecznego (w obecnej sytuacji) oraz daje dodatkowe możliwości przekazu który nie jest ograniczony ze względu na przestrzeń.
Nawet w przypadku wystawy zlokalizowanej w jednym miejscu zastosowanie rozwiązania daje dodatkowe możliwości w postaci udostępnienia treści w innych regionach miasta, kraju a nawet świata (wystawa odbywająca się w jednym mieście może mieć odbiorców na całym świecie).

#### b)	Komentarz merytoryczny
O ile w przypadku wystaw w galeriach opis czy komentarz merytoryczny jest możliwy do powieszenia obok dzieła, to w większości przypadków gdy dzieło prezentowane jest w przestrzeni publicznej takie możliwości są ograniczone lub całkowicie nie realizowalne. Montaż urządzenia w okolicy instalacji/mappingu/muralu daje możliwość przekazania dodatkowych informacji dla osób które są zaciekawione czymś więcej niż samą formą lub prezentacją dzieła.

#### c)	Rozszerzona ścieżka zwiedzania
Urządzenie można zastosować również dodatkowe medium do przekazania treści. W przypadku indywidualnych artystów, którzy nie są tylko skupieni na jedniej formie, pozwala to udostępnić zwiedzającym dodatkową treść w postaci dzieł których prezentacja w klasycznej, fizycznej formie jest niemożliwa ze względu np. na ograniczenia przestrzenne, lub finansowe.
Festiwale mogą w ten sposób prezentować dodatkowe treści które standardowo nie są atrakcyjne dla zwiedzających oczekujących wrażeń wzrokowo- słuchowych. Związane z tematyką festiwalu w rozszerzonej ścieżce zwiedzania obok obrazów/rzeźb/zdjęć/instalacji mogą pojawić się wiersze czy fragmenty opowiadań.


### 2.	Scenariusze gamifikacji
Scenariusze gamifikacji mają na celu uatrakcyjnienie odbioru treści prezentowanych przez artystę/organizację. Są elementem pośrednim między klasycznym marketingiem a niekomercyjną promocją. Pozwalają również na rozciągnięcie w czasie wydarzenia, co może mieć zastosowanie w przypadku indywidualnych twórców planujących większe wydarzenia, jak i dla organizacji chcących zwiększyć aktywność uczestników w planowanych festiwalach. Scenariusze gamifikacji również są rozszerzeniem dla standardowych możliwości podstawowych scenariuszy zwiedzania. Użycie scenariuszy gamifikacji wymaga zastosowania zewnętrznych form przekazu informacji (np. media społecznościowe).

Pierwszym założeniem technologicznym dla scenariuszy gamifikacji, przy użyciu Captive portal jest zastosowanie plików cookies. Będziemy logować się za każdym razem tak naprawdę na tą samą stronę, z tym samym adresem, więc zapisane pliki coockies powinny działać mimo łączenia się do różnych urządzeń. Problemem może być ESP - posida bardzo ograniczone możliwości przesyłu stron WWW.

Druga opcja to rozwiązanie scenariuszowe polegające np. na zbieraniu kodów. Każdy kod zebrany udostępnia kolejną część na zewnętrznej stronie WWW.

#### a)	Zbieranie kolekcji
Scenariusz ten zakłada dodanie atrakcyjnego elementu zbierania różnych dzieł aby utworzyć kolekcję. Bazuje on na grach komputerowych w których jest stały element przedłużający rozgrywkę. Jest na tyle atrakcyjne rozwiązanie że znalazło zastosowanie w funkcjonowaniu miejsc pracy. Organizator udostępniając w mediach społecznościowych kolejne lokalizacje urządzeń angażuje zwiedzających do aktywnego uczestnictwa w wydarzeniu. Scenariusz ten zakłada odwiedzanie miesc wskazanych przez organizatora, w celu zebrania kolejnych (w bazowym założeniu) dzieł, aby na koniec mieć dostęp do całości wystawy.

#### b)	Komponowanie dzieła
Jest to alternatywa dla zbierania kolekcji. Wymaga większego wkładu technologicznego w celu zaprojektowania rozwiązania. Bazuje nie na zbieraniu poszczególnych dzieł, ale na składaniu jednego kompletnego dzieła przez odwiedzenie poszczególnych miejsc wskazanych przez organizatora. Docelowo może to być złożenie obrazu z fragmentów, zebranie całości filmu lub opowiadania.

#### c)	Geocatching
Jest kolejnym rozszerzeniem poprzednich opcji. W tym przypadku zbieranie kolekcji lub fragmentów odbywa się w duchu geocatchingu. Organizator udostępnia w wybranych przez siebie mediach kolejne koordynaty geograficzne, lub nawet same zdjęcia lokalizacji, w celu zaanagażowania uczestników w ich znalezienie. Udostępniane lokalizacje mogą mieć charakter typowo komercyjny (lokalizacje współpracujących galerii lub innych podmiotów) jak i merytoryczny (miejsca powiązane z tematyką dzieła).

### 3.	Scenariusze eventowe
Scenariusze eventowe są skierowane głównie do festiwali w celu dodania dodatkowych narzędzi marketingowych oraz większego zaangażowania uczestników festiwalu. Scenariusze eventowe są dalszym rozszerzeniem scenariuszy gamifikacji. Opierają się głównie na tych samych technikach, jednak ich cel ma znaczenie bardziej komercyjne.

#### a)	System zniżek

Zastosowanie scenariuszy gamifikacji, przy zaangażowaniu dodatkowych środków pozwala na użycie tych scenariuszy w sposób czysto komercyjny. Znalezienie wszystkich elementów dzieła lub kolekcji generuje kod który uprawnia do zniżki np. na wejście na główne wydarzenie.

#### b)	System VIP

Rozwiązanie to tyczy się głównie festiwali muzyczno-artystycznych. Wykonanie zadań przewidzianych w scenariuszach gamifikacyjnych uprawnia do otrzymania wstępu VIP – dostępu na backstage oraz innych przywilejów z tym związanych – oczywiście zakres zależny jest od organizatora oraz artystów.

#### c)	Mechanizm losowania

Nadrzędnie, w przypadku gdy możliwości organizatorów są ograniczone, możliwe jest zastosowanie systemu losowania, gdzie realizacja formy zbierania elementów uprawnia do udziału w losowaniu dla wyżej wymienionych systemów.


## Oprogramowanie

### 1.	Podstawowy dostęp
Na ten moment podstawowym założeniem dostępu do treści jest stworzenie funkcjonalności captive portal. Łącząc się z modułem przez Wifi, wpisując dowolny adres w przeglądarce użytkownik zostanie przekierowany do webservera umieszczonego na płytce.

##### a) ESP
https://www.youtube.com/watch?v=AHO1zN8c_zU
~~problem - z komentarzy wynika że ten captive portal nie przekierowuje z https, tylko z http. Więc wpisanie czegokolwiek w przeglądarkę automatycznie przekieruje na google które jest na https. Problem do rozwiązania technologicznego (dodanie obsługi https) lub scenariuszowego (wpisanie konkretnego adresu w przeglądarkę)~~

~~Pozwoli to na przekazanie dowolnej strony web. Ze względu na założenie że po podłączeniu do wifi urządzenia nie mamy dostępu do internetu możemy przekazać stronę web w najprostszej tekstowej postaci.~~

*EDIT* Captive portal na ESP nie pozwala na przekierowanie z adresów HTTPS. Większość adresów współcześnie to HTTPS. W niektórych telefonach po podłączeniu do WiFi urządzenia automatycznie pojawi się strona captive portal, ale nie jest to standardem. Dodanie funkcjonalności obsługi Captive portal na ESP to zadanie zdecydowanie zbyt zaawansowane na ten projekt. Dlatego po zalogowaniu się do sieci użytkownik będzie musiał wpisać konkretny adres w przeglądarkę.

~~#### b) RPi Zero W~~
~~https://www.maketecheasier.com/turn-raspberry-pi-captive-portal-wi%E2%80%90fi-access-point/~~

~~*EDIT* Testy pokazały że capitve portal na RPI też nie przekierowuje z HTTPS.~~

Nie stosuje RPi.

### 2.	Obsługa zdjęć
#### a) ESP
~~Tutaj jest pewien problem. Jak do tej pory nie znalazłem żadnego rozwiązania pozwalającego na pobieranie obrazów z zewnętrznej karty SSD. Można zapisać pliki w postaci SPIFFS ale ogranicza to rozmiar całości projektu (razem z obrazami do 4 MB). *EDIT* Sprawdzone - na ten moment należy ograniczyć rozmiar strony wraz z mediami do 4MB na urządzenie.~~

~~Ograniczenia są jednak większe. Płytkę w Arduino IDE należy wybrać nie WEMOS lolin32 tylko ESP32 DEV module i następnie z partition wybrać układ 1mb na program i 3 mb na SPIFFS. wtedy dostępne jest 3 mb na pliki webserwera.~~

~~https://randomnerdtutorials.com/display-images-esp32-esp8266-web-server/~~

~~Wygląda na to że ograniczenie pamięci jest jednak dużo większe niż 4mb, będzie to jeszcze weryfikowane. Dodatkowa kroki to użycie karty SD które może okazać się znacznie łatwiejsze niż wydawałoby się na początku:~~

~~https://randomnerdtutorials.com/build-an-all-in-one-esp32-weather-station-shield/~~

~~Jednak nie jest to takie łatwe. Mam biblioteki które obsługują async webserver z karty sd, ale przykład nie działa, nie ma dokumentacji a kod jest wyjątkowo skomplikowany:~~

~~https://github.com/paidforby/AsyncSDServer~~

Opanowane. Obsługa zdjęć z karty SD działa poprawnie. Pojawiło się za to nowe ograniczenie. Jest limit jednoczesnych podłączeń SPI. Maksymalnie można łączyć się z 5 plikami jednocześnie. Utrudnia to tworzenie większych stron ale jest parę rozwiązań:
- skrypty można zapisywać w pliku HTML lub pakować je w .gz
- style można umieszczać w pliku html zamiast w osobnym css
- pliki graficzne można obsługiwać jako css image sprites
- można budować wielopoziomowe strony (do przetestowania)

~~#### b) RPi~~
~~Brak jakiegokolwiek problemu - wrzucamy dowolną stronę WWW która działa jako captive portal z dowolnymi elementami.~~

Nie stosuje RPi.

