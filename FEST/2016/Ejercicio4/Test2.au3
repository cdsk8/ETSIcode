#cs
   Esto dificilmente va a terminar en una hora
#ce

#include <Array.au3>

Const $maxPeso = 8000

;Const $pesos[5] = [7000,1000,400,650,500]
;Const $precios[5] = [1500000,70000,400000,300000,200000]

Const $pesos[18] = [7000,200,620,300,3440,220,1777,800,950,2300,1250,1987,5000,2300,800,5300,4300,2100]
Const $precios[18] = [150000,7000,40000,3000,2000,10000,3000,3000,8000,150000,30000,699099,100050,10000,20000,30000,1500]

Local $i[18]

$max = 0

For $i[0] -1 To 17
For $i[1] -1 To 17
For $i[2] -1 To 17
For $i[3] -1 To 17
For $i[4] -1 To 17
For $i[5] -1 To 17
For $i[6] -1 To 17
For $i[7] -1 To 17
For $i[8] -1 To 17
For $i[9] -1 To 17
For $i[10] -1 To 17
For $i[11] -1 To 17
For $i[12] -1 To 17
For $i[13] -1 To 17
For $i[14] -1 To 17
For $i[15] -1 To 17
For $i[16] -1 To 17
For $i[17] -1 To 17
   If peso($i) < $maxPeso Then
	  $ganas = ganas($i)
	  If $ganas > $max Then
		 $max = $ganas
		 ConsoleWrite("Maxima: "&dibujar($i)&"  Ganas:"&$max&"  Pesa: "&peso($i)&@CRLF)
	  EndIf
   EndIf
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next
Next


Func ganas($lista)
   If $lista = null then Return 0
   $total = 0
   For $i = 0 To UBound($lista)-1
	  If $lista[$i] <> -1 Then  $total += $precios[$lista[$i]]
   Next
   Return $total
EndFunc

Func peso($lista)
   $total = 0
   For $i = 0 To UBound($lista)-1
	  If $lista[$i] <> -1 Then  $total += $pesos[$lista[$i]]
   Next
   Return $total
EndFunc

Func dibujar($lista)
   $txt = ""
   For $i = 0 To UBound($lista)-1
	  If $lista[$i] <> -1 Then  $txt &= ($lista[$i]+1)&"  "
   Next
   Return $txt
EndFunc