#include <Array.au3>

$n = 9
$numero = "01234567"

;$n = 1983
;$numero = "01234567"

;$n = 9
;$numero = "01234567"

For $k = 1 To $n
   $primero = ($k*2)-1+getSum($numero)
   ;ConsoleWrite("PRIM"&$primero&@CRLF)
   $numero = StringTrimLeft($numero,1)
   $ultimo = getLast($primero)
   $numero &= $ultimo
   ;ConsoleWrite($numero&@CRLF)
Next

ConsoleWrite("RES: "&$numero&@CRLF)


Func getSum($n)
   $total = 0

   For $i = 1 To StringLen($n)
	  $total += StringMid($n,$i,1)
   Next
   ;ConsoleWrite("SUM"&$total&@CRLF)
   Return $total
EndFunc
Func getLast($n)
   Return StringTrimLeft($n,StringLen($n)-1)
EndFunc