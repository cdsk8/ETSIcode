$maximo = 10000000
$res = 0

For $i = 1 To $maximo
   If comp($i) Then $res += 1
   If Mod($res,10000) = 0 Then
	  ConsoleWrite($res&@CRLF)
   EndIf
Next

ConsoleWrite($res&@CRLF)

Func comp($n)
   Do
	  $newN = 0
	  For $i = 0 To StringLen($n)
		 $newN += StringMid($n,$i,1) * StringMid($n,$i,1)
	  Next
	  $n = $newN
   Until $n == 1 or $n == 89
   Return $n == 89
EndFunc