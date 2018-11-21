ConsoleWrite("Resultado: "&calcular(12,5)&@CRLF)

Func calcular($n, $k)
   If $n <> 2*(1+$k) Then Return 0
   $p = 0
   For $i = 0 To $k-1
	  $p += $k-$i
   Next
   Return $p
EndFunc