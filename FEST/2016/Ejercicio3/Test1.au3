$res = 0
For $i = 2 to 100
   If iter($i,1) Then
	  $res +=1
	  ConsoleWrite("Verifico: "&$i&@CRLF)
   EndIf
Next
ConsoleWrite("Total: "&$res&@CRLF)

Func iter($target, $actual)
   If $actual = $target Then
	  Return true
   ElseIf $actual > $target Then
	  Return False
   Else
	  $a = iter($target, $actual+5)
	  $b = iter($target, $actual*3)
	  return $a or $b
   EndIf
EndFunc