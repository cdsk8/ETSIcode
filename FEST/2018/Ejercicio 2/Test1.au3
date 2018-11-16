Global $tama = 100


Global $original = generar($tama)
Global $resultado[$tama][$tama]

For $i = 0 To $tama-1
   For $j = 0 To $tama-1
	  $resultado[$i][$j] = suavi($i,$j)
   Next
Next
ConsoleWrite("Suma: "&suma($resultado)&@CRLF)



Func suavi($i,$j)
   $total = 0
   $n = 0

   For $ii = -1 To 1
	  For $jj = -1 To 1
		 If ($i+$ii) >= 0 And ($i+$ii) < $tama And ($j+$jj) >= 0 And ($j+$jj) < $tama Then
			$total += $original[$i+$ii][$j+$jj]
			$n += 1
		 EndIf
	  Next
   Next

   Return Int($total/$n)
EndFunc


Func generar($n)
   Local $matriz[$n][$n]
   $ii = 1
   For $i = 0 To $n-1
	  For $j = 0 To $n-1
		 $matriz[$i][$j] = $ii
		 $ii += 1
	  Next
   Next
   Return $matriz
EndFunc

Func suma($matriz)
   $total = 0
   For $i = 0 To UBound($matriz)-1
	  For $j = 0 To UBound($matriz)-1
		 $total += $matriz[$i][$j]
	  Next
   Next
   Return $total
EndFunc