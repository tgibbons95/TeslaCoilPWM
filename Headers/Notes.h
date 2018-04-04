#include <string>

// Beats for standard sheet music
#define SIXTEENTH_NOTE	6
#define EIGHTH_NOTE	12
#define QUARTER_NOTE	24
#define HALF_NOTE	48
#define WHOLE_NOTE	96

// Piano Notes frequencies in microseconds (divided by two)
#define A0 18182
#define B0 16198
#define C1 15289
#define D1 13621
#define E1 13621
#define F1 11454
#define G1 10204
#define A1 9091
#define B1 8099
#define C2 7645
#define D2 6810
#define E2 6067
#define F2 5727
#define G2 5102
#define A2 4545
#define B2 4050
#define C3 3822
#define D3 3405
#define E3 3034
#define F3 2863
#define G3 2551
#define A3 2273
#define B3 2025
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012
#define C5 956
#define D5 851
#define E5 758
#define F5 716
#define G5 638
#define A5 568
#define B5 506
#define C6 478
#define D6 426
#define E6 379
#define F6 358
#define G6 319
#define A6 284
#define B6 253
#define C7 239
#define D7 213
#define E7 190
#define F7 179
#define G7 159
#define A7 142
#define B7 127
#define C8 119

#define A_sharp0 17161
#define C_sharp1 14431
#define D_sharp1 12856
#define F_sharp1 10811
#define G_sharp1 9631
#define A_sharp1 8581
#define C_sharp2 7215
#define D_sharp2 6428
#define F_sharp2 5405
#define G_sharp2 4816
#define A_sharp2 4290
#define C_sharp3 3608
#define D_sharp3 3214
#define F_sharp3 2703
#define G_sharp3 2408
#define A_sharp3 2145
#define C_sharp4 1804
#define D_sharp4 1607
#define F_sharp4 1351
#define G_sharp4 1204
#define A_sharp4 1073
#define C_sharp5 902
#define D_sharp5 804
#define F_sharp5 676
#define G_sharp5 602
#define A_sharp5 536
#define C_sharp6 451
#define D_sharp6 402
#define F_sharp6 338
#define G_sharp6 301
#define A_sharp6 268
#define C_sharp7 225
#define D_sharp7 201
#define F_sharp7 169
#define G_sharp7 150
#define A_sharp7 134

int HandleA(std::string szCommand, int iPosition);
int HandleB(std::string szCommand, int iPosition);
int HandleC(std::string szCommand, int iPosition);
int HandleD(std::string szCommand, int iPosition);
int HandleE(std::string szCommand, int iPosition);
int HandleF(std::string szCommand, int iPosition);
int HandleG(std::string szCommand, int iPosition);
int ConvertCharsToNoteFrequency(std::string szCommand, int iPosition);

