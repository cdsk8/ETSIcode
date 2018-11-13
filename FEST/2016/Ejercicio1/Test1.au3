;Global Const $medicamentos[2] = [1,3]
;Global Const $medicamentos[6] = [2,3,5,8,9,9]
;Global Const $medicamentos[12] = [1,1,1,3,4,9,15,19,19,21,22,25] ;25
Global Const $medicamentos[20] = [1,3,4,8,8,10,10,14,15,16,20,21,22,22,23,24,24,27,31,39]

$posMax = $medicamentos[UBound($medicamentos)-1]
$min = -1
$tmp = 0
For $i = 0 To $posMax
   $tmp = $i
   $pos = $i
   For $j = 0 To UBound($medicamentos)-1
	  $tmp += Abs($medicamentos[$j]-$pos)
	  $pos = $medicamentos[$j]
	  $tmp += Abs($i-$pos)
	  $pos = $i
   Next
   $tmp += Abs($pos)
   If $tmp < $min or $min = -1 Then
	  $min = $tmp
	  ConsoleWrite("Caja en "&$i&" pasos: "&$min&@CRLF)
   EndIf
Next

