#include <Array.au3>

Const $maxPeso = 8000

;Const $pesos[5] = [7000,1000,400,650,500]
;Const $precios[5] = [1500000,70000,400000,300000,200000]

Const $pesos[8] = [5000,100,3000,300,1500,500,900,800]
Const $precios[8] = [900000,750000,300000,50000,500000,400000,10000,8000]



Local $lista[0]
Global $max = 0
iter($lista,-1)

Func iter($lista,$agregar)
   $puedes = True
   If $agregar <> -1 Then

	  For $i = 0 To UBound($lista)-1
		 If $lista[$i] = $agregar Then $puedes = False
	  Next
	  If $puedes Then
		 ReDim $lista[UBound($lista)+1]
		 $lista[UBound($lista)-1] = $agregar
	  EndIf
   Else
	  For $i = 0 To UBound($pesos)-1
		 iter($lista,$i)
	  Next
   EndIf

   If $puedes Then
	  If peso($lista) < $maxPeso Then
		 $ganas = ganas($lista)
		 If $ganas > $max Then
			$max = $ganas
			ConsoleWrite("Maxima: "&dibujar($lista)&" Ganas:"&$max&"Pesa: "&peso($lista)&@CRLF)
		 EndIf
		 For $i = 0 To UBound($pesos)-1
			If $i <> $agregar Then	   iter($lista,$i)
		 Next
	  EndIf
   EndIf

EndFunc

Func ganas($lista)
   If $lista = null then Return 0
   $total = 0
   For $i = 0 To UBound($lista)-1
	  $total += $precios[$lista[$i]]
   Next
   Return $total
EndFunc

Func peso($lista)
   $total = 0
   For $i = 0 To UBound($lista)-1
	  $total += $pesos[$lista[$i]]
   Next
   Return $total
EndFunc

Func dibujar($lista)
   $txt = ""
   For $i = 0 To UBound($lista)-1
	  $txt &= ($lista[$i]+1)&"  "
   Next
   Return $txt
EndFunc