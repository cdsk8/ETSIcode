#include <Array.au3>
Const $camino[][] = [[10, 11],[13, 1],[6, 13],[8, 10],[5, 3],[12, 5],[15, 12],[8, 2],[10, 4],[12, 3],[10, 6],[12, 6],[8, 6],[7, 8],[14, 10],[9, 13],[13, 10],[8, 12],[13, 12]]

$max = 0
For $i = 0 To UBound($camino)-1
   If $camino[$i][0] > $max Then $max = $camino[$i][0]
   If $camino[$i][1] > $max Then $max = $camino[$i][1]
Next
$max -= 1

Global $ocurrencias[$max+1]
For $i = 0 To $max
   $ocurrencias[$i] = 0
Next
For $i = 0 To UBound($camino)-1
   $ocurrencias[$camino[$i][0]-1] += 1
   $ocurrencias[$camino[$i][1]-1] += 1
Next

Global $apetencias[$max+1]
$actual = 0
For $i = $max To 0 Step -1
   For $j = 0 To UBound($ocurrencias)-1
	  If $ocurrencias[$j] = $i Then
		 $apetencias[$actual] = $j
		 $actual += 1
	  EndIf
   Next
Next

Global $min = 9999
Global $tipo = "le"

iter(getCiudades(), -1)

Func iter($almacenes, $agregar)
   $puedes = True
   If $agregar <> -1 Then
	  $puedes = Not $almacenes[$agregar]
	  If $puedes Then $almacenes[$agregar] = True
   EndIf

   If $puedes Then
	  $numero = getNumero($almacenes)
	  If $numero <= $min and dibujar($almacenes) <> $tipo Then
		 If comprobar($almacenes) Then
			$min = $numero
			$tipo = dibujar($almacenes)
			ConsoleWrite("MIN: "&$numero&"  Almacenes: "&dibujar($almacenes)&@CRLF)
		 EndIf
		 For $i = 0 To $max
			;iter($almacenes,$apetencias[$i])
			iter($almacenes,$i)
		 Next
	  EndIf
   EndIf
EndFunc

Func getNumero($lista)
   $n = 0
   For $i = 0 To UBound($lista)-1
	  If $lista[$i] = True Then $n += 1
   Next
   return $n
EndFunc

Func comprobar($almacenes)
   $caminos = getCaminos()
   For $i = 0 To UBound($camino)-1
	  If esta($camino[$i][0], $almacenes) or esta($camino[$i][1], $almacenes) Then
		 $caminos[$i] = True
	  EndIf
   Next
   For $i = 0 To UBound($caminos)-1
	  If Not $caminos[$i] Then Return False
   Next
   Return True
EndFunc

Func esta($nucleo, $almacenes)
   Return $almacenes[$nucleo-1]
EndFunc

Func dibujar($lista)
   $txt = ""
   For $i = 0 To UBound($lista)-1
	  If $lista[$i] Then $txt &= ($i+1)&" "
   Next
   return $txt
EndFunc

Func getCiudades()
   Local $map[$max+1]
   For $i = 0 To $max
	  $map[$i] = False
   Next
   Return $map
EndFunc
Func getCaminos()
   Local $map[UBound($camino)]
   For $i = 0 To UBound($camino)-1
	  $map[$i] = False
   Next
   Return $map
EndFunc