$n = 37

For $k = 0 To 100
   $encontrados = 0
   $ii = 0
   $jj = 0
   For $i = 1 To sqrt($k)
	  For $j = 1 To sqrt($k)
		 If ($i * $i)+($j*$j) = $k Then
			If not ($i = $jj and $j = $ii) Then $encontrados += 1

			If $encontrados = 1 Then
			   $ii = $i
			   $jj = $j
			EndIf
		 EndIf
		 If $encontrados = 2 Then
			MsgBox(0,"","Lo "&$k&" encontre: "&$i&" "&$j&" y "&$ii&" "&$jj)
			ExitLoop 2
		 EndIf
	  Next
   Next
Next