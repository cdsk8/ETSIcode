#include <Array.au3>

;$n = 1983
;Global $numero[8] = [0,1,2,3,4,5,6,7]

;$n = 5
;Global $numero[8] = [1,5,9,7,7,6,3,4]

$n = 1990
Global $numero[8] = [7,6,5,4,3,2,1,0]

$original = print($numero)
For $k = 1 To $n
   $primero = ($k*2)-1+getSum($numero)
   ;ConsoleWrite("PRIM"&$primero&@CRLF)
   $numero = correr($numero)
   $ultimo = getLast($primero)
   $numero[7] = $ultimo
   ;ConsoleWrite($numero&@CRLF)
Next

ConsoleWrite("RES: "&(print($numero)-$original)&@CRLF)


Func getSum($n)
   $total = 0

   For $i = 0 To UBound($n)-1
	  $total += $n[$i]
   Next
   ;ConsoleWrite("SUM"&$total&@CRLF)
   Return $total
EndFunc
Func getLast($n)
   Return StringTrimLeft($n,StringLen($n)-1)
EndFunc
Func correr($n)
   Local $nn[8]
	  For $i = 0 To 6
		 $nn[$i] = $n[$i+1]
	  Next
   Return $nn
EndFunc
Func print($n)
   $txt = ""
   For $i = 0 To 7
	  $txt &= $n[$i]
   Next
   Return $txt
EndFunc