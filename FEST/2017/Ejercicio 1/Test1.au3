ConsoleWrite("Posicion final: "&iter(9, 10)&@CRLF)
;ConsoleWrite("Posicion final: "&iter(21, 1000000)&@CRLF)


Func iter($p, $pasos)
   Local $array[$pasos+($p*2)]
   For $i = 0 To UBound($array)-1
	  $array[$i] = $i + 2
   Next

   For $i = 1 To $pasos
	  $q = divisor($array[$p])
	  If $q = -1 Then
		 $p += 1
	  Else
		 $array[$p] /= $q
		 $p -= 1
		 $array[$p] += $q
	  EndIf
   Next
   Return $p
EndFunc


Func divisor($n)
   For $i = Int($n/2) To 2 Step -1
	  If Mod($n,$i) = 0 Then Return $i
   Next
   Return -1
EndFunc
;Posicion final: 88407