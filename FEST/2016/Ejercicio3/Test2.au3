Global $max = 7000
Global $numeros[$max]

For $i = 0 To $max-1
   $numeros[$i] = False
Next

iter(1)

$res = 0
For $i = 0 To $max-1
   If $numeros[$i] then $res += 1
Next
ConsoleWrite("Total: "&($res-1)&@CRLF)

Func iter($actual)
   If $actual <= $max Then
	  If Not $numeros[$actual] Then
		 $numeros[$actual] = True
		 iter($actual+5)
		 iter($actual*3)
	  EndIf
   EndIf
EndFunc