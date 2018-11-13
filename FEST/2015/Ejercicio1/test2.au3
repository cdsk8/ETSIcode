For $i = 1 To 10000
   If Not (comp($i)) and (Mod($i,9)=0) Then ConsoleWrite($i&" ")
Next

Func comp($n)
   While True
	  If $n = 1 Then
		 return false
	  ElseIf $n = 89 Then
		 return true
	  EndIf
	  $newN = 0
	  For $i = 0 To StringLen($n)
		 $newN += StringMid($n,$i,1)*StringMid($n,$i,1)
	  Next
	  $n = $newN
   WEnd
EndFunc