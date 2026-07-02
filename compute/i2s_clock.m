% Räkna ut I2S klockan
HSE = 24; % MHz (Konstant: kan ej ändras)
FREFDIV = 1;
FBDIV = 49;
POSTDIV1 = 1;
POSTDIV2 = 3;
FRAC = 2550137;
PREDIV = 1;
FINDIV = 8;

FFOUT = (HSE * (FBDIV + FRAC/(2^24)))/FREFDIV;
PLL7 = FFOUT/(POSTDIV1 * POSTDIV2)

I2S_CLK = PLL7/(PREDIV * FINDIV)

%Källa I2S frekvenstabell: RM0457 (rev 5) sida 4598 och sida 4599
%Källa formler: RM0457 (rev 5) sida 978 och sida 979
