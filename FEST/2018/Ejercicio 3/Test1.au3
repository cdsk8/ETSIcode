 #include <Date.au3>


Global $start = [1,1,2018]
Global $end = [31,12,2018]
Global $tramos[][] = [["0-8",100], ["8-15",3000], ["15-20",1500], ["20-24",500]]
Global $capacidad = 500
Global $precio = 0.05
Global $descanso = 0.5

$nDiasL = Ndias(False)
$nDiasF = Ndias(True)

ConsoleWrite($nDiasL&"  "&$nDiasF&@CRLF)

$consumo = 0

For $i = 0 To UBound($tramos)-1
   $dif = intermedio($tramos[$i][0])
   ConsoleWrite("DIF: "&$dif&@CRLF)
   $consumo += $dif*$precio*Ncontenedores($tramos[$i][1])
Next

$consumo = ($nDiasL*$consumo)+($nDiasF*$consumo*$descanso)

ConsoleWrite($consumo&@CRLF)


Func Ncontenedores($users)
   $num = 1
   While $capacidad * $num < $users
	  $num += 1
   WEnd
   Return $num
EndFunc
Func intermedio($text)
   $n = StringSplit($text,"-")
   Return $n[2]-$n[1]
EndFunc
Func esFinde($d,$m,$y)
   $n = _DateToDayOfWeekISO($y, $m, $d)
   Return $n = 6 or $n = 7
EndFunc
Func NdiasMes($m, $y)
   Return _DateDaysInMonth ($y, $m )
EndFunc

Func Ndias($finde)
   $n = 0
   For $i = $start[2] To $end[2]
	  $mIni = 1
	  If $i = $start[2] Then $mIni = $start[1]
	  $mFin = 12
	  If $i = $end[2] Then $mFin = $end[1]

	  For $j = $mIni To  $mFin
		 $dIni = 1
		 If $j = $start[1] Then $dIni = $start[0]
		 $dFin = NdiasMes($j, $i)
		 If $j = $end[1] Then $dFin = $end[0]

		 For $k = $dIni To $dFin
			If $finde Then
			   If esFinde($k, $j, $i) Then $n += 1
			Else
			   If Not esFinde($k, $j, $i) Then $n += 1
			EndIf
		 Next
	  Next
   Next
   Return $n
EndFunc