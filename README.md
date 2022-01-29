# ATFS
ATmega File System - Prototyp prostego systemu plików dla Atmegi.

Prosty system plików, który potrafi zapisywać i odczytywać pliki z pamięci EEPROM wbudowanej w mikrokotrolery ATmega, konkretnie te umieszczone w płytkach Arduino.

ATFS_FORMAT formatuje pamięć EEPROM i zapisuje na niej dwa przykładowe pliki TXT.

ATFS_READ odczytuje pliki i podaje ich rozmiar ze sformatowanego EEPROMU

# TO PROTOTYP PROTOTYPU - KONCEPT A NIE W PEŁNI DZIAŁAJĄCY PROGRAM!

# STRUKTURA
Wartości od 200 do 255 służą jako dane sterujące.
Program odczytujący rozpoznaje sformatowaną pamięć przez odczytanie wartości 200 z adresu 1 i 201 z adresu 2, następnie przechodzi do szukania plików.
Nowy plik jest oznaczany wartością 203, gdy program ją wykryje, rozpoczyna odczyt.
Zapisane w pliku dane mogą być wartościami od 1 do 99

ATFS używa następującego sposobu zapisu pliku:

Pierwsze 3 odczytane wartości to rozszerzenie
Po rozszerzeniu wszystkie kolejne wartości to nazwa pliku, kończona wartością 204.
Następnie mamy zawartość pliku. Odczytywana jest ona aż do wartości 205, która oznacza koniec pliku.
