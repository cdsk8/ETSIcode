#include <Array.au3>
$txt = FileRead("reto4.txt")
Global $datos[20][20]

$lista = StringSplit($txt,@LF)
;_ArrayDisplay($lista)
For $i = 1 To $lista[0]
   $columnas = StringSplit($lista[$i], " ")
   For $j = 1 To $columnas[0]
	  $datos[$i-1][$j-1] = StringReplace($columnas[$j],@CR,"")
   Next
Next


$max = 0
Local $tmp[8]
For $i = 0 To 19
   For $j = 0 To 19
	  $tmp[0] = $datos[Sig($i)][Sig($j)] + $datos[Sig($i+1)][Sig($j)] + $datos[Sig($i+2)][Sig($j)] + $datos[Sig($i+3)][Sig($j)]
	  $tmp[1] = $datos[Sig($i)][Sig($j)] + $datos[Sig($i-1)][Sig($j)] + $datos[Sig($i-2)][Sig($j)] + $datos[Sig($i-3)][Sig($j)]
	  $tmp[2] = $datos[Sig($i)][Sig($j)] + $datos[Sig($i)][Sig($j+1)] + $datos[Sig($i)][Sig($j+2)] + $datos[Sig($i)][Sig($j+3)]
	  $tmp[3] = $datos[Sig($i)][Sig($j)] + $datos[Sig($i)][Sig($j-1)] + $datos[Sig($i)][Sig($j-2)] + $datos[Sig($i)][Sig($j-3)]
	  $tmp[4] = $datos[Sig($i)][Sig($j)] + $datos[Sig($i+1)][Sig($j+1)] + $datos[Sig($i+2)][Sig($j+2)] + $datos[Sig($i+3)][Sig($j+3)]
	  $tmp[5] = $datos[Sig($i)][Sig($j)] + $datos[Sig($i-1)][Sig($j-1)] + $datos[Sig($i-2)][Sig($j-2)] + $datos[Sig($i-3)][Sig($j-3)]
	  $tmp[6] = $datos[Sig($i)][Sig($j)] + $datos[Sig($i-1)][Sig($j+1)] + $datos[Sig($i-2)][Sig($j+2)] + $datos[Sig($i-3)][Sig($j+3)]
	  $tmp[7] = $datos[Sig($i)][Sig($j)] + $datos[Sig($i+1)][Sig($j-1)] + $datos[Sig($i+2)][Sig($j-2)] + $datos[Sig($i+3)][Sig($j-3)]
	  For $k = 0 To 7
		 If $tmp[$k] > $max Then
			$max = $tmp[$k]
			ConsoleWrite("Max: "&$max&" start("&$i&","&$j&") direccion: "&$k&@CRLF)
		 EndIf
	  Next
   Next
Next

Func Sig($n)
   If $n < 0 Then
	  return 20+$n
   ElseIf $n > 19 Then
	  return $n-20
   Else
	  return $n
   EndIf
EndFunc