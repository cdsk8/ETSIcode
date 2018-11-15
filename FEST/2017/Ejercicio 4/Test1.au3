#cs
Global $mapa[][] = [[1, 0, 1, 0, 1, 0, 0], _
    [0, 1, 0, 0, 0, 1, 0], _
    [0, 0, 0, 1, 0, 1, 0], _
    [1, 0, 1, 0, 1, 0, 0], _
    [1, 0, 0, 0, 0, 1, 0], _
    [0, 1, 0, 1, 0, 0, 1], _
    [0, 0, 1, 0, 1, 0, 0]]
#ce
#cs
Global $mapa[][] = [[1, 0, 1, 0, 1, 0, 0], _
    [0, 1, 0, 0, 0, 1, 0], _
    [0, 0, 0, 1, 0, 1, 0], _
    [1, 0, 1, 0, 1, 0, 0], _
    [1, 0, 0, 0, 0, 1, 0], _
    [0, 1, 0, 1, 0, 0, 1], _
    [0, 0, 1, 0, 1, 1, 0]]
#ce
;#cs
Global $mapa[][] = [[1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1], _
    [0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0], _
    [0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0], _
    [1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1], _
    [1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1], _
    [0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0], _
    [0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0], _
    [1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1], _
    [0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0], _
    [0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0], _
    [1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1], _
    [1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1], _
    [0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0], _
    [0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0], _
    [1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1]]
;#ce

Global $minimo = -1


iter(int(UBound($mapa,2)/2),int(UBound($mapa,1)/2),0,0)


Func iter($x,$y,$pasos,$recorrido)
   If $recorrido = 0 Then
	  Dim $recorrido[UBound($mapa,1)][UBound($mapa,2)]
	  For $i = 0 To UBound($mapa,1)-1
		 For $j = 0 To UBound($mapa,2)-1
			$recorrido[$i][$j] = True
		 Next
	  Next
   EndIf

   $estado = check($x,$y,$recorrido, $pasos)
   ;ConsoleWrite("("&$x&","&$y&")  Step: "&$pasos&"  Min: "&$minimo&@CRLF)
   If $estado = 0 and ($pasos < $minimo or $minimo = -1) Then
	  $minimo = $pasos
   ElseIf $estado = 2 Then
	  $recorrido[$x][$y] = False
	  iter($x+1,$y,$pasos+1, $recorrido)
	  iter($x,$y+1,$pasos+1, $recorrido)
	  iter($x-1,$y,$pasos+1, $recorrido)
	  iter($x,$y-1,$pasos+1, $recorrido)
   EndIf
EndFunc

ConsoleWrite("Minimo: "&$minimo&@CRLF)

Func check($x,$y, $recorrido, $pasos); 0 = WIN | 1 = no valido | 2 = valido
   If $x < 0 Or $x > UBound($mapa,2)-1 Or $y < 0 Or $y > UBound($mapa,1)-1 Then Return 0
   If ($mapa[$x][$y] = 0 Or ($pasos = 0)) And $recorrido[$x][$y] Then Return 2
   Return 1
EndFunc
