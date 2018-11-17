 #include <Date.au3>


Global $start = [1,1,2018]
Global $end = [31,12,2018]
Global $tramos[][] = [["0-8",100], ["8-15",3000], ["15-20",1500], ["20-24",500]]
Global $capacidad = 500
Global $precio = 0.05
Global $descanso = 0.5

$consumo = 0

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
		 For $l = 0 To UBound($tramos)-1
			If esFinde($k, $j, $i) Then
			   $Ncont = Ncontenedores($tramos[$l][1]*$descanso)
			   ;ConsoleWrite("Ncont: "&$Ncont&@CRLF)
			Else
			   $Ncont = Ncontenedores($tramos[$l][1])
			EndIf
			$consumo += intermedio($tramos[$l][0])*$precio*$Ncont
		 Next
	  Next
   Next
Next


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