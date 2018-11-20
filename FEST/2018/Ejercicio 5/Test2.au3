Const $L1[] = ["  ","  "," /","\ ","\/"]
Const $L2[] = ["  ","/\","/ "," \","  "]

Global $n = 6
Global $k = 2


Global $count = 0

Local $nada[$n/2]
rec($nada, 0, 0)

ConsoleWrite("Cantidad: "&$count&@CRLF)

Func rec($corte, $add, $picos)
   $pos = primerCero($corte)
   If $add <> 0 And $pos <> -1 Then $corte[$pos] = $add
   If $add <> 0 Then dibujar($corte)
   If $pos = -1 Then
	  If $picos = $k Then
		 $count += 1
		 ;ConsoleWrite("Combinacion: "&@CRLF)
		 ;dibujar($corte)
	  EndIf
   Else
	  If $add = 0 Or $add = 1 Or $add = 3 Then rec($corte,1,$picos+1)
	  If ($add = 0 Or $add = 1 Or $add = 3) And $pos <> ($n/2)-1 Then
		 ConsoleWrite("Puesto una dos: "&&@)
		 rec($corte,2,$picos)
	  EndIf
	  If $add = 2 Or $add = 4 Then rec($corte,3,$picos+1)
	  If ($add = 2 Or $add = 4) And $pos <> ($n/2)-1 Then rec($corte,4,$picos+1)
   EndIf
EndFunc


Func primerCero($corte)
   For $i = 0 To ($n/2)-1
	  If $corte[$i] = 0 Then Return $i
   Next
   Return -1
EndFunc

Func dibujar($corte)
   $up = ""
   $dw = ""
   $na = "CMP: "
   For $i = 0 To ($n/2)-1
	  $na &= $corte[$i]
	  $up &= $L1[$corte[$i]]
	  $dw &= $L2[$corte[$i]]
   Next
   ConsoleWrite($na&@CRLF&$up&@CRLF&$dw&@CRLF)
EndFunc